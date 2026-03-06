#include "SensorManager.h"
#include "Varios/Utils.h"
#include "Mqtt/MqttManager.h"

/**
 * Constructor de SensorManager.
 * Inicializa los valores por defecto.
 */
SensorManager::SensorManager() 
    : _temperature(0), _humidity(0), _heatIndex(0), 
      _dewPoint(0), _absoluteHumidity(0), _perception(0), 
      _statusAht(false), _mqttManager(nullptr)
#if defined(BOARD_AHT10)
      , _aht(AHT10_ADDRESS_0X38)
#endif
{
}

/**
 * Configura los sensores según la placa definida.
 * @param _mqtt Puntero al manager de MQTT.
 */
void SensorManager::setup(MqttManager* _mqtt) 
{
    _mqttManager = _mqtt;

    #if defined(BOARD_DHT22)
    _dht.setup(DHT_PIN, DHTesp::DHT22);
    #endif

    #if defined(BOARD_AHT10)
    _statusAht = _aht.begin(0, 2);
    _aht.setCycleMode();
    #endif
}

/**
 * Realiza la lectura de los sensores y publica los datos en MQTT si está disponible y configurado.
 */
void SensorManager::refresh() 
{
    float _t = NAN;
    float _h = NAN;

    #if defined(BOARD_DHT22)
    TempAndHumidity _val = _dht.getTempAndHumidity();
    _t = _val.temperature + calibrationOffset; 
    _h = _val.humidity;
    #endif

    #if defined(BOARD_AHT10)
    _t = _aht.readTemperature(true) + calibrationOffset;
    _h = _aht.readHumidity(true);
    #endif

    if (!isnan(_t) && !isnan(_h)) 
    {
        _temperature = _t;
        _humidity = _h;
        
        // Actualizar estadísticas de máximos y mínimos
        _tempStats.setValue(_t);
        _humStats.setValue(_h);

        // Cálculos avanzados si hay soporte DHTesp
        #if defined(BOARD_DHT22) || defined(BOARD_AHT10)
        _heatIndex = _dht.computeHeatIndex(_t, _h);
        _dewPoint = _dht.computeDewPoint(_t, _h);
        _absoluteHumidity = _dht.computeAbsoluteHumidity(_t, _h);
        _perception = _dht.computePerception(_t, _h);
        #endif

        serialPrint("Temperatura: " + String(_temperature) + " °C");
        serialPrint("Humedad: " + String(_humidity) + " %");

        // Publicación MQTT (Solo si la placa tiene definidos los tópicos)
        #if !defined(NO_MQTT)
        if (_mqttManager != nullptr) 
        {
            #ifdef BOARD_TEMP_HUMEDAD_PB
            _mqttManager->publish(temperatureMqttStatus.c_str(), String(_temperature, 2).c_str());
            _mqttManager->publish(humidityMqttStatus.c_str(), String(_humidity, 2).c_str());
            _mqttManager->publish(heatIndexMqttStatus.c_str(), String(_heatIndex, 2).c_str());
            _mqttManager->publish(dewPointMqttStatus.c_str(), String(_dewPoint, 2).c_str());
            _mqttManager->publish(absoluteHumidityMqttStatus.c_str(), String(_absoluteHumidity, 2).c_str());
            _mqttManager->publish(perceptionMqttStatus.c_str(), String(_perception, 2).c_str());
            #endif

            #ifdef BOARD_TEMP_HUMEDAD_GALERIA
            _mqttManager->publish(temperatureMqttStatus.c_str(), String(_temperature, 2).c_str());
            _mqttManager->publish(humidityMqttStatus.c_str(), String(_humidity, 2).c_str());
            _mqttManager->publish(heatIndexMqttStatus.c_str(), String(_heatIndex, 2).c_str());
            _mqttManager->publish(dewPointMqttStatus.c_str(), String(_dewPoint, 2).c_str());
            _mqttManager->publish(absoluteHumidityMqttStatus.c_str(), String(_absoluteHumidity, 2).c_str());
            _mqttManager->publish(perceptionMqttStatus.c_str(), String(_perception, 2).c_str());
            #endif

            #ifdef BOARD_TEMP_HUMEDAD_EXTERIOR
            _mqttManager->publish(temperatureMqttStatus.c_str(), String(_temperature, 2).c_str());
            _mqttManager->publish(humidityMqttStatus.c_str(), String(_humidity, 2).c_str());
            _mqttManager->publish(heatIndexMqttStatus.c_str(), String(_heatIndex, 2).c_str());
            _mqttManager->publish(dewPointMqttStatus.c_str(), String(_dewPoint, 2).c_str());
            _mqttManager->publish(absoluteHumidityMqttStatus.c_str(), String(_absoluteHumidity, 2).c_str());
            _mqttManager->publish(perceptionMqttStatus.c_str(), String(_perception, 2).c_str());
            #endif
        }
        #endif
    } 
    else 
    {
        serialPrint("Error al leer los sensores.");
    }
}
