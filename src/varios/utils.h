#pragma once
#include "config/Config.h"
#include <Arduino.h>

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

