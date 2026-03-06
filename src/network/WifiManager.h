#pragma once
#include <Arduino.h>

#if defined(ESP8266)
#include <ESP8266WiFi.h>
#elif defined(ESP32)
#include <WiFi.h>
#endif

class WifiManager {
public:
    // Constructor que recibe toda la config de red
    WifiManager(const char* ssid, const char* password);
    
    void setup();
    void loop(); 
    void httpGet(String _url);
    String getLastResponse() { return _lastResponse; }

private:
    const char* _ssid;
    const char* _password;
    IPAddress _ip, _gw, _subnet, _dns, _dns2;
    String _lastResponse;
    unsigned long _lastReconnectAttempt;
    unsigned long _disconnectedSince;
    unsigned long _currentReconnectInterval;
    bool _wasConnected;
};

