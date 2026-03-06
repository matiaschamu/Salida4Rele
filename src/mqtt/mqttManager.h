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

class WifiManager;

class MqttManager 
{
public:
    /**
     * Constructor de MqttManager.
     * @param relays Puntero al RelayManager para ejecución de comandos.
     */
    MqttManager(RelayManager* relays);

    /**
     * Configura el servidor MQTT y establece el callback de mensajes.
     */
    void setup();

    /**
     * Procesa los mensajes entrantes y mantiene la conexión MQTT.
     */
    void loop();
    
    // Métodos públicos para publicar
    /**
     * Publica un mensaje en un tópico específico.
     * @param topic Tópico de destino.
     * @param payload Contenido del mensaje.
     */
    void publish(const char* topic, const char* payload);

    /**
     * Publica todos los datos de diagnóstico del sistema por MQTT.
     * @param _wifi Puntero al WifiManager para obtener la última respuesta HTTP.
     */
    void publishDiagnostics(WifiManager* _wifi);
    
    /**
     * Publica exclusivamente el tiempo de actividad (uptime) por MQTT.
     */
    void publishUptime();
    
    // Gestión de estado
    bool isConnected();
    String getStatus();
    int getFailedAttempts();
    
    // Habilitar/Deshabilitar MQTT
    bool isEnabled();
    void setEnabled(bool _state);
     

private:
    RelayManager* _relays;
    WiFiClient _wifiClient;
    PubSubClient _mqttClient;

    int _failedAttempts;
    unsigned long _currentReconnectInterval;

    const int _maxRetries = 20;

    bool _enabled;
    String _clientId;

    void reconnect();
    void subscribeToTopics();

    // Callback estático necesario para PubSubClient
    static void callback(char* topic, byte* payload, unsigned int length);
};

