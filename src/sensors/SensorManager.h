#pragma once
#include <Arduino.h>
#include "config/Config.h"
#include "../analysis/AnalysisManager.h"

#if defined(BOARD_DHT22) || defined(BOARD_AHT10)
#include <DHTesp.h>
#endif

#if defined(BOARD_AHT10)
#include <AHT10.h>
#endif

class MqttManager; // Forward declaration

/**
 * Clase SensorManager
 * Gestiona la lectura de sensores (DHT22/AHT10) y la publicación de datos por MQTT.
 */
class SensorManager {
public:
    /**
     * Constructor de SensorManager.
     */
    SensorManager();

    /**
     * Inicializa los sensores y el manager de MQTT.
     * @param _mqtt Puntero al MqttManager.
     */
    void setup(MqttManager* _mqtt = nullptr);

    /**
     * Realiza una lectura de sensores y publica los resultados en MQTT.
     */
    void refresh();

    // Getters para los valores de los sensores
    /**
     * Obtiene la temperatura actual leída por el sensor.
     * @return Temperatura en grados Celsius.
     */
    float getTemperature() const { return _temperature; }
    /**
     * Obtiene la humedad relativa actual leída por el sensor.
     * @return Humedad relativa en porcentaje (%).
     */
    float getHumidity() const { return _humidity; }
    /**
     * Obtiene el índice de calor (sensación térmica).
     * @return Índice de calor en grados Celsius.
     */
    float getHeatIndex() const { return _heatIndex; }
    /**
     * Obtiene el punto de rocío calculado.
     * @return Punto de rocío en grados Celsius.
     */
    float getDewPoint() const { return _dewPoint; }
    /**
     * Obtiene la humedad absoluta calculada.
     * @return Humedad absoluta en g/m³.
     */
    float getAbsoluteHumidity() const { return _absoluteHumidity; }
    /**
     * Obtiene la percepción térmica (descripción cualitativa).
     * @return Valor de percepción térmica.
     */
    byte getPerception() const { return _perception; }
    
    /**
     * Obtiene el manager de estadísticas de temperatura.
     * @return Puntero al AnalysisManager de temperatura.
     */
    AnalysisManager* getTemperatureStats() { return &_tempStats; }

    /**
     * Obtiene el manager de estadísticas de humedad.
     * @return Puntero al AnalysisManager de humedad.
     */
    AnalysisManager* getHumidityStats() { return &_humStats; }

private:
    float _temperature;
    float _humidity;
    float _heatIndex;
    float _dewPoint;
    float _absoluteHumidity;
    byte _perception;
    bool _statusAht;

    AnalysisManager _tempStats;
    AnalysisManager _humStats;

    MqttManager* _mqttManager;

    #if defined(BOARD_DHT22) || defined(BOARD_AHT10)
    DHTesp _dht;
    #endif

    #if defined(BOARD_AHT10)
    AHT10 _aht;
    #endif
};
