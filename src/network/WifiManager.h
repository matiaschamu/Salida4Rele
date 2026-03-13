#pragma once
#include <Arduino.h>

#if defined(ESP8266)
#include <ESP8266WiFi.h>
#elif defined(ESP32)
#include <WiFi.h>
#endif

class WifiManager 
{
public:
    // Constructor que recibe toda la config de red
    WifiManager(const char* ssid, const char* password);
    
    void setup();
    void loop(); 
    void httpGet(String _url);
    String getLastResponse() { return _lastResponse; }
    
    /**
     * Realiza un ping al router local principal (192.168.1.1).
     * Intenta una conexión TCP al puerto 80 para verificar disponibilidad.
     * @return true si el router responde
     */
    bool pingRouterLocal();
    
    /**
     * Verifica si se debe ejecutar un reset por falta de conectividad.
     * Reset code: 4 (Ping Timeout - Router 192.168.1.1)
     * Solo resetea tras 5 minutos sin comunicación exitosa con router.
     * @return true si se debe resetear
     */
    bool shouldResetDueToConnectivity();

private:
    const char* _ssid;
    const char* _password;
    IPAddress _ip, _gw, _subnet, _dns, _dns2;
    String _lastResponse;
    unsigned long _lastReconnectAttempt;
    unsigned long _disconnectedSince;
    unsigned long _currentReconnectInterval;
    bool _wasConnected;
    unsigned long _lastSuccessfulPing;
    unsigned long _pingFailureStartTime;
    bool _pingFailureInProgress;
    static const uint32_t PING_FAILURE_TIMEOUT = 300000; // 5 minutos
};

