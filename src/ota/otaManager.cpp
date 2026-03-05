#include "OTAManager.h"
#include "varios/Utils.h" 

/**
 * Constructor de la clase OTAManager.
 */
OTAManager::OTAManager() {
    _hostname = "ESP-Relay";
}

/**
 * Configura los parámetros de ArduinoOTA y define los callbacks de eventos.
 * @param _hostname Nombre de red asignado al dispositivo.
 */
void OTAManager::setup(const char* _hostname) {
    this->_hostname = _hostname;
    ArduinoOTA.setPort(8266);
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
    serialPrint("OTA: Manager configurado e iniciado.");
}

/**
 * Maneja el proceso de actualización OTA en el loop principal.
 */
void OTAManager::loop() {
    ArduinoOTA.handle();
}
