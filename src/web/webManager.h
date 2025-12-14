#pragma once
#include <Arduino.h>

#if defined(ESP8266)
#include <ESP8266WiFi.h>
#elif defined(ESP32)
#include <WiFi.h>
#endif

#include "../config/config.h" 

// Declaraciones anticipadas (Forward declarations) para evitar dependencias circulares
class RelayManager;
class MqttManager;

class WebManager {
private:
    WiFiServer server;
    
    // Punteros a objetos y variables externas
    RelayManager* _relays;
    MqttManager* _mqttManager;
    
    // Punteros a variables de sensores
    float* _temperature;
    float* _humidity;
    
    // Variables internas del servidor
    String header;
    unsigned long currentTime;
    unsigned long previousTime;
    const long timeoutTime = 2000;
    
    // Helper privado para generar el HTML
    void sendHTML(WiFiClient& client, bool reset);

public:
    WebManager(int port);
    
    // Método de configuración para inyectar dependencias
    void setup(RelayManager* relays, MqttManager* mqtt, float* temp, float* hum);
    
    // El loop principal del webserver
    void loop();
};