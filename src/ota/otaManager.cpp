#include "otaManager.h"
#include "../varios/utils.h" 

/**
 * Constructor de la clase OTAManager.
 * @param hostname Nombre de red para el dispositivo.
 */
OTAManager::OTAManager(const char* hostname) : _hostname(hostname), _configured(false) {
}

/**
 * Configura los parámetros de ArduinoOTA y define los callbacks de eventos.
 */
void OTAManager::setup() {
    if (_configured) return; // Evitar múltiples configuraciones
    
    // Puerto 8266 para ESP8266, puerto 3232 por defecto es más compatible con ESP32
    #if defined(ESP8266)
    ArduinoOTA.setPort(8266);
    #elif defined(ESP32)
    ArduinoOTA.setPort(3232);
    #else
    ArduinoOTA.setPort(3232);
    #endif
    ArduinoOTA.setHostname(_hostname);

    ArduinoOTA.onStart([]() {
        serialPrint("OTA: Iniciando actualización...");
    });

    ArduinoOTA.onEnd([]() {
        serialPrint("\nOTA: Finalizado.");
    });

    ArduinoOTA.onProgress([](unsigned int _progress, unsigned int _total) {
        Serial.printf("OTA Progreso: %u%%\r", (_progress / (_total / 100)));
    });

    ArduinoOTA.onError([](ota_error_t _error) {
        Serial.printf("OTA Error[%u]: ", _error);
    });

    ArduinoOTA.begin();
    _configured = true;
    serialPrint("OTA: Manager configurado e iniciado.");
}

/**
 * Maneja el proceso de actualización OTA en el loop principal.
 */
void OTAManager::loop() {
    ArduinoOTA.handle();
}
