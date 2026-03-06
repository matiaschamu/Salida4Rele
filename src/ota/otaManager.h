#pragma once
#include <Arduino.h>
#include <ArduinoOTA.h>

/**
 * Clase OTAManager
 * Gestiona las actualizaciones inalámbricas (Over-The-Air).
 */
class OTAManager 
{
public:
    /**
     * Constructor de la clase OTAManager.
     */
    OTAManager();
    
    /**
     * Configura ArduinoOTA con el hostname proporcionado.
     * @param _hostname Nombre de red para el dispositivo.
     */
    void setup(const char* _hostname);
    
    /**
     * Procesa las peticiones OTA en el bucle principal.
     */
    void loop();

private:
    const char* _hostname;
};
