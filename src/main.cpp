#include <Arduino.h>
#include "main.h"
#include "config/Config.h"
#include "varios/Utils.h"
#include "network/WifiManager.h"
#include "ota/OTAManager.h"
#include "relays/RelayManager.h"
#include "sensors/SensorManager.h"
#include "mqtt/MqttManager.h"
#include "web/WebManager.h"

// Instancias de los Managers
WifiManager wifi(ssid, password);
OTAManager ota;
RelayManager relays;
SensorManager sensorManager;
MqttManager mqttManager(&relays);
WebManager webManager(&relays, &sensorManager, &mqttManager, &wifi);

// Timers para tareas periódicas
unsigned long lastMsg10seg = 0;
unsigned long lastMsgDiag = 0;
int lastMsg1min = 0;
int lastMsg5min = 0;

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

  sensorManager.setup(&mqttManager);
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
    lastMsg1min = 0;
    lastMsg5min = 0;
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

    sensorManager.refresh();
  }

  // Verifica si ha pasado 1 minuto
  if (lastMsg1min > 4)
  {
    serialPrint("60SEG Update (DuckDNS)");
    lastMsg1min = 0;

    #ifdef Report_IP_DuckDNS
    wifi.httpGet(urlDuckDns);
    #endif
  }
  else
  {
    lastMsg1min++;
  }

  // Verifica si han pasado 5 minutos
  if (lastMsg5min > 28)
  {
    serialPrint("5MIN Update (HealthChecks)");
    lastMsg5min = 0;

    #ifdef Report_HealthChecks
    wifi.httpGet(urlHealthChecks);
    #endif
  }
  else
  {
    lastMsg5min++;
  }

  // Tareas cada 5 segundos (Diagnósticos MQTT)
  if (_now - lastMsgDiag > 5000) {
    lastMsgDiag = _now;
    mqttManager.publishDiagnostics(&wifi);
  }

  delay(1); // Mínimo delay para estabilidad manteniendo máxima fluidez
}

