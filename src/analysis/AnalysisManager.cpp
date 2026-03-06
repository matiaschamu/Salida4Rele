#include "AnalysisManager.h"

/**
 * Constructor de la clase AnalysisManager.
 */
AnalysisManager::AnalysisManager()
{
}

/**
 * Destructor de la clase AnalysisManager.
 */
AnalysisManager::~AnalysisManager()
{
}

/**
 * Establece el nuevo valor y actualiza los máximos y mínimos.
 * @param _v Nuevo valor a analizar.
 */
void AnalysisManager::setValue(float _value)
{
    value = _value;
    if (value > max) 
    {
        max = value;
    }
    if (value < min || min == 0) 
    {
        min = value;
    }
}


