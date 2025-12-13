#pragma once
#include <Arduino.h>
#include <ArduinoOTA.h>

class OTAManager {
public:
    // Constructor: le pasamos el hostname para no depender de variables globales dentro de la clase
    OTAManager(const char* hostname, const char* password = nullptr);
    
    void setup();
    void handle();

private:
    const char* _hostname;
    const char* _password;
};