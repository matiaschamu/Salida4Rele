#pragma once
#include <Arduino.h>

/**
 * Clase AnalysisManager
 * Gestiona el análisis de datos, manteniendo valores actuales, máximos y mínimos.
 */
class AnalysisManager
{
public:
    float value = 0, max = 0, min = 0, max1h = 0, min1h = 0, max6h = 0, min6h = 0, max12h = 0, min12h = 0, trend1h = 0, trend6h = 0, trend12h = 0;
    String timeMax = "", timeMin = "";

    AnalysisManager();
    ~AnalysisManager();
    
    /**
     * Establece el nuevo valor y actualiza los máximos y mínimos
     * @param value Nuevo valor a analizar
     */
    void setValue(float value);
};


