#pragma once
#include "config/Config.h"
#include <Arduino.h>
#include <EEPROM.h>

// Direcciones en EEPROM donde se guarda el contador de reinicios
#define EEPROM_RESET_COUNT_ADDR   0
#define EEPROM_CUSTOM_RESET_ADDR   4
#define EEPROM_SIZE                8

/**
 * Imprime un mensaje por el puerto serial si el modo debug está habilitado.
 * @param _msg Mensaje a imprimir (cualquier tipo de dato).
 */
template <typename T>
void serialPrint(T _msg) {
    #ifdef debug
        Serial.println(_msg);
    #endif
}

/**
 * Imprime una línea en blanco por el puerto serial si el modo debug está habilitado.
 */
inline void serialPrint() {
    #ifdef debug
        Serial.println();
    #endif
}

/**
 * Convierte un arreglo de bytes a un objeto String.
 * @param _a Puntero al arreglo de bytes.
 * @param _size Tamaño del arreglo.
 * @return String con el contenido del arreglo.
 */
inline String convertToString(const byte *_a, int _size) {
    String _s = ""; 
    _s.concat((const char*)_a, (unsigned int)_size); 
    return _s;
}

/**
 * Convierte un arreglo de caracteres (char*) a un objeto String.
 * @param _a Puntero al arreglo de caracteres.
 * @param _size Tamaño del arreglo.
 * @return String con el contenido del arreglo.
 */
inline String convertToString(const char *_a, int _size) {
    String _s = ""; 
    _s.concat(_a, (unsigned int)_size);
    return _s;
}

/**
 * Inicializa la EEPROM. Debe llamarse en setup() antes de usar las funciones de EEPROM.
 */
void initEeprom();

/**
 * Lee el contador de reinicios almacenado en EEPROM.
 * @return Número de reinicios acumulados.
 */
uint32_t getResetCount();

/**
 * Incrementa en 1 el contador de reinicios y lo persiste en EEPROM.
 */
void incrementResetCount();

/**
 * Retorna el tiempo de actividad de la placa formateado.
 * @return String con formato "Xd Xh Xm Xs".
 */
String getUptime();

/**
 * Actualiza el contador interno de uptime para manejar desbordamientos.
 * Debe llamarse frecuentemente en el loop principal.
 */
void refreshUptime();

/**
 * Retorna el motivo del último reinicio de la placa.
 * @return String con el motivo descriptivo.
 */
String getResetReason();

/**
 * Retorna la dirección MAC de la placa para identificación.
 * @return String con la MAC Address.
 */
String getBoardId();

/**
 * Guarda un código de motivo de reinicio personalizado en EEPROM.
 * @param _code Código del motivo (1: WiFi, 2: MQTT, 3: Manual).
 */
void setCustomResetReason(uint8_t _code);

/**
 * Carga el motivo de reinicio personalizado desde EEPROM a memoria y lo limpia.
 * Debe llamarse en el setup() después de initEeprom().
 */
void loadCustomResetReason();

/**
 * Resetea el contador de reinicios acumulados a cero en la EEPROM.
 */
void resetResetCount();

/**
 * Obtiene el nivel de señal WiFi en formato texto (Excelente, Buena, etc.).
 * @param _rssi Valor del RSSI recibido.
 * @return String descriptivo del nivel.
 */
String getRSSILevel(int32_t _rssi);

/**
 * Obtiene el color asociado al nivel de señal WiFi para la interfaz web.
 * @param _rssi Valor del RSSI recibido.
 * @return String con el código hexadecimal del color.
 */
String getRSSIColor(int32_t _rssi);
