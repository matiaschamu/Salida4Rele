#pragma once
#include <Arduino.h>
#include "config.h" // Asegurate de que aquí esté definido 'debug' si lo usas

// Esta función acepta CUALQUIER tipo de dato (String, int, char, float...)
// gracias al "template <typename T>"
template <typename T>
void SerialPrint(T msg) {
    #ifdef debug
        Serial.println(msg);
    #endif
}

// Sobrecarga especial para cuando llamas a SerialPrint() vacío (para salto de línea)
inline void SerialPrint() {
    #ifdef debug
        Serial.println();
    #endif
}

inline String convertToString(const byte *a, int size) {
    // 1. Creamos el objeto String vacío.
    String s = ""; 
    
    // 2. Usamos el método concat(const char*, unsigned int)
    // El cast a (const char*) y a (unsigned int) es necesario para coincidir 
    // con la firma pública del método.
    s.concat((const char*)a, (unsigned int)size); 
    
    return s;
}

inline String convertToString(const char *a, int size) {
    String s = ""; 
    
    // Usamos el método concat(const char*, unsigned int)
    s.concat(a, (unsigned int)size);
    
    return s;
}