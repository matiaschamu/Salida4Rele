#pragma once
#include <Arduino.h>

#if defined(ESP8266)
#include <ESP8266WiFi.h>
#elif defined(ESP32)
#include <WiFi.h>
#endif

#include "../config/Config.h" 

// Declaraciones anticipadas
class RelayManager;
class SensorManager;
class MqttManager;
class WifiManager;

class WebManager 
{
private:
    WiFiServer server;
    
    // Punteros a objetos Manager
    RelayManager* _relays;
    SensorManager* _sensors;
    MqttManager* _mqttManager;
    WifiManager* _wifi;
    
    // Variables internas del servidor
    String header;
    unsigned long currentTime;
    unsigned long previousTime;
    const long timeoutTime = 2000;
    
    // Control de reinicio no bloqueante
    bool _pendingReset;
    unsigned long _resetTime;
    
    /**
     * Envía el contenido HTML de respuesta al cliente.
     * @param _client Cliente al que se envía la respuesta.
     * @param _reset Indica si se debe mostrar un mensaje de reinicio.
     */
    void sendHTML(WiFiClient& _client, bool _reset);

public:
    /**
     * Constructor de WebManager.
     * @param _relays Puntero al RelayManager.
     * @param _sensors Puntero al SensorManager.
     * @param _mqtt Puntero al MqttManager.
     * @param _wifi Puntero al WifiManager.
     */
    WebManager(RelayManager* _relays, SensorManager* _sensors, MqttManager* _mqtt, WifiManager* _wifi);
    
    /**
     * Inicializa el servidor web.
     */
    void setup();

    /**
     * Loop procesador de peticiones del servidor web.
     */
    void loop();
};
