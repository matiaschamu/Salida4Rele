#include <Arduino.h>
#include "main.h"
#include "Config/Config.h"
#include "Varios/Utils.h"
#include "Network/WifiManager.h"
#include "Ota/OtaManager.h"
#include "Relays/RelayManager.h"
#include "Sensors/SensorManager.h"
#include "Mqtt/MqttManager.h"
#include "Web/WebManager.h"

// Instancias de los Managers
WifiManager wifi(ssid, password);
OTAManager ota;
RelayManager relays;
#if defined(BOARD_DHT22) || defined(BOARD_AHT10)
SensorManager sensorManager;
#endif
MqttManager mqttManager(&relays);
WebManager webManager(&relays, 
    #if defined(BOARD_DHT22) || defined(BOARD_AHT10)
    &sensorManager, 
    #else
    nullptr, 
    #endif
    &mqttManager, &wifi);

// Timers para tareas periódicas
unsigned long lastMsg10seg = 0;
unsigned long lastMsgUptime = 0;
unsigned long lastMsgDiag10m = 0;
unsigned long lastMsgDuckDNS = 0;
unsigned long lastMsgHealthChecks = 0;

/**
 * Inicialización principal del sistema.
 */
void setup()
{
  Serial.begin(115200);
  serialPrint("");
  serialPrint("Iniciando Salida 4 Relés...");

  initEeprom();
  incrementResetCount();
  loadCustomResetReason();
  serialPrint("Reset count: " + String(getResetCount()));

  serialPrint("WIFI - Ingresando Setup:");
  wifi.setup();
  
  #ifdef BOARD_4OUT_RELAY
  relays.setup(&mqttManager);
  #endif

  #if defined(BOARD_DHT22) || defined(BOARD_AHT10)
  sensorManager.setup(&mqttManager);
  #endif
  ota.setup(hostName);
  mqttManager.setup();
  webManager.setup();

  serialPrint("Setup Finalizado.");
}

/**
 * Bucle principal de ejecución.
 */
void loop()
{
  refreshUptime();
  unsigned long _now = millis();

  // Gestión de Managers
  wifi.loop();
  ota.loop();
  mqttManager.loop();
  webManager.loop();

  // Manejo de desbordamiento de millis()
  if (_now < lastMsg10seg)
  {
    serialPrint("TIMER - ROLLOVER");
    lastMsg10seg = 0;
    lastMsgDuckDNS = 0;
    lastMsgHealthChecks = 0;
    lastMsgUptime = 0;
    lastMsgDiag10m = 0;
  }

  // Tareas cada 5 segundos (Uptime MQTT)
  if (_now - lastMsgUptime > 5000)
  {
    lastMsgUptime = _now;
    mqttManager.publishUptime();
  }

  // Verifica si han pasado 10 segundos
  if (_now - lastMsg10seg > 10000)
  {
    serialPrint("");
    serialPrint("10SEG -> Syncing sensors and relays");
    lastMsg10seg = _now;

    #ifdef BOARD_4OUT_RELAY
    relays.refresh();
    #endif

    #if defined(BOARD_DHT22) || defined(BOARD_AHT10)
    sensorManager.refresh();
    #endif
  }

  // Tareas cada 2 minutos (HealthChecks)
  if (_now - lastMsgHealthChecks > 120000)
  {
    lastMsgHealthChecks = _now;
    serialPrint("2MIN Update (HealthChecks)");

    #ifdef REPORT_HEALTH_CHECKS
    wifi.httpGet(urlHealthChecks);
    #endif
  }

  // Tareas cada 5 minutos (DuckDNS)
  if (_now - lastMsgDuckDNS > 300000)
  {
    lastMsgDuckDNS = _now;
    serialPrint("5MIN Update (DuckDNS)");

    #ifdef REPORT_IP_DUCKDNS
    wifi.httpGet(urlDuckDns);
    #endif
  }

  // Detectar salto de estado de MQTT para forzar publicación inicial
  static bool _wasMqttConnected = false;
  bool _isMqttConnected = mqttManager.isConnected();
  
  if (_isMqttConnected && !_wasMqttConnected)
  {
    serialPrint("MQTT - Nueva conexion detectada. Forzando reporte completo...");
    lastMsgDiag10m = 0; // Fuerza entrar al if de abajo
  }
  _wasMqttConnected = _isMqttConnected;

  // Tareas cada 10 minutos (Diagnósticos MQTT completos)
  if ((_now - lastMsgDiag10m > 600000) || (lastMsgDiag10m == 0 && _isMqttConnected))
  {
    serialPrint("10MIN Update (MQTT Diagnostics)");
    mqttManager.publishDiagnostics(&wifi);
    lastMsgDiag10m = _now;
    if (lastMsgDiag10m == 0) lastMsgDiag10m = 1; // Evitar que siga entrando si _now es 0
  }

  delay(1); // Mínimo delay para estabilidad manteniendo máxima fluidez
}

