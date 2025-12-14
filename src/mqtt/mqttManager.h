#pragma once
#include <Arduino.h>
#include <PubSubClient.h>
#if defined(ESP8266)
#include <ESP8266WiFi.h>
#elif defined(ESP32)
#include <WiFi.h>
#endif

// Incluimos RelayManager para poder controlarlos desde el callback
#include "../relays/RelayManager.h"

class MqttManager {
public:
    // Constructor recibe puntero a RelayManager para actuar sobre ellos
    MqttManager(RelayManager* relays);

    void setup();
    void loop();
    
    // Métodos públicos para publicar
    void publish(const char* topic, const char* payload);
    
    // Gestión de estado
    bool isConnected();
    String getStatus();
    int getFailedAttempts();
    
    // Habilitar/Deshabilitar MQTT
    bool isEnabled();
    void setEnabled(bool state);
     

private:
    RelayManager* _relays;
    WiFiClient _wifiClient;
    PubSubClient _mqttClient;

    int _failedAttempts;

    const int _maxRetries = 20;

    bool _enabled;
    String _clientId;

    void reconnect();
    void subscribeToTopics();

    // Callback estático necesario para PubSubClient
    static void callback(char* topic, byte* payload, unsigned int length);
};