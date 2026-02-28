#pragma once
#include <Arduino.h>
#include <ArduinoOTA.h>

/**
 * Clase OTAManager
 * Gestiona las actualizaciones inalámbricas (Over-The-Air).
 */
class OTAManager {
public:
    /**
     * Constructor de la clase OTAManager.
     * @param hostname Nombre de red para el dispositivo (por defecto "ESP-Relay").
     */
    OTAManager(const char* hostname = "ESP-Relay");
    
    /**
     * Configura ArduinoOTA e inicia el servicio.
     */
    void setup();
    
    /**
     * Procesa las peticiones OTA en el bucle principal.
     */
    void loop();

private:
    const char* _hostname;
    bool _configured;
};
