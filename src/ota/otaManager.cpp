#include "OTAManager.h"
// Si usas tu macro SerialPrint, incluye tu utils.h aqui:
#include "varios/utils.h" 

OTAManager::OTAManager(const char* hostname, const char* password) {
    _hostname = hostname;
    _password = password;
}

void OTAManager::setup() {
    // Configuración de puertos y hostname
    ArduinoOTA.setPort(8266);
    ArduinoOTA.setHostname(_hostname);

    if (_password != nullptr) {
        ArduinoOTA.setPassword(_password);
    }

    // Callbacks
    ArduinoOTA.onStart([]() {
        String type;
        if (ArduinoOTA.getCommand() == U_FLASH) {
            type = "sketch";
        } else { // U_SPIFFS
            type = "filesystem";
        }
        // Usando Serial directo o tu macro SerialPrint
        Serial.println("OTA: Start updating " + type);
    });

    ArduinoOTA.onEnd([]() {
        Serial.println("\nOTA: End");
    });

    ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
        Serial.printf("OTA Progress: %u%%\r", (progress / (total / 100)));
    });

    ArduinoOTA.onError([](ota_error_t error) {
        Serial.printf("OTA Error[%u]: ", error);
        if (error == OTA_AUTH_ERROR) Serial.println("Auth Failed");
        else if (error == OTA_BEGIN_ERROR) Serial.println("Begin Failed");
        else if (error == OTA_CONNECT_ERROR) Serial.println("Connect Failed");
        else if (error == OTA_RECEIVE_ERROR) Serial.println("Receive Failed");
        else if (error == OTA_END_ERROR) Serial.println("End Failed");
    });

    ArduinoOTA.begin();
    SerialPrint ("OTA: Configurado e Iniciado");
}

void OTAManager::handle() {
    ArduinoOTA.handle();
}