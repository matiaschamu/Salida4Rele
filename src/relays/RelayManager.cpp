#include "Config/Config.h"
#include "RelayManager.h"
#include "Varios/Utils.h"
#include "Mqtt/MqttManager.h"

/**
 * Constructor de la clase RelayManager.
 */
RelayManager::RelayManager() 
{
    for (int _i = 0; _i < 4; _i++) 
    {
        _relayStatus[_i] = false;
    }
    _mqttManager = nullptr;
}

/**
 * Inicializa los relés en estado apagado y configura el manager de MQTT.
 * @param _mqtt Puntero al MqttManager.
 */
void RelayManager::setup(MqttManager* _mqtt) 
{
    _mqttManager = _mqtt;
    for (int _i = 1; _i <= 4; _i++) 
    {
        setRelay(_i, false);
    }
}

/**
 * Establece el estado de un relé específico.
 * @param _relayIndex Índice del relé (1-4).
 * @param _state Estado deseado (true = ON, false = OFF).
 */
void RelayManager::setRelay(int _relayIndex, bool _state) 
{
    if (_relayIndex < 1 || _relayIndex > 4) return;
    
    int _idx = _relayIndex - 1;
    _relayStatus[_idx] = _state;
    sendSerialCommand(_idx, _state);
}

/**
 * Obtiene el estado actual de un relé.
 * @param _relayIndex Índice del relé (1-4).
 * @return true si está encendido, false si está apagado.
 */
bool RelayManager::getRelayState(int _relayIndex) 
{
    if (_relayIndex < 1 || _relayIndex > 4) return false;
    return _relayStatus[_relayIndex - 1];
}

/**
 * Actualiza el estado de todos los relés enviando comandos seriales y publica en MQTT.
 */
void RelayManager::refresh() 
{
#ifdef BOARD_4OUT_RELAY
    if (relay1Name != "") 
    { 
        sendSerialCommand(0, _relayStatus[0]); 
        if (_mqttManager != nullptr) _mqttManager->publish(relay1MqttStatus.c_str(), _relayStatus[0] ? "ON" : "OFF");
        delay(50); 
    }
    if (relay2Name != "") 
    { 
        sendSerialCommand(1, _relayStatus[1]); 
        if (_mqttManager != nullptr) _mqttManager->publish(relay2MqttStatus.c_str(), _relayStatus[1] ? "ON" : "OFF");
        delay(50); 
    }
    if (relay3Name != "") 
    { 
        sendSerialCommand(2, _relayStatus[2]); 
        if (_mqttManager != nullptr) _mqttManager->publish(relay3MqttStatus.c_str(), _relayStatus[2] ? "ON" : "OFF");
        delay(50); 
    }
    if (relay4Name != "") 
    { 
        sendSerialCommand(3, _relayStatus[3]); 
        if (_mqttManager != nullptr) _mqttManager->publish(relay4MqttStatus.c_str(), _relayStatus[3] ? "ON" : "OFF");
        delay(50); 
    }
#endif
}

/**
 * Envía un comando binario por el puerto serial para controlar un relé.
 * @param _idx Índice del relé (0-3).
 * @param _state Estado a enviar (true = ON, false = OFF).
 */
void RelayManager::sendSerialCommand(int _idx, bool _state) 
{
    int _cmdType = _state ? 1 : 0;
    Serial.write(RELAY_CMDS[_idx][_cmdType], 4);
}

/**
 * Bucle de procesamiento para el manager de relés (no utilizado actualmente).
 */
void RelayManager::loop() 
{
    // Por ahora vacío, el refresh lo llamamos desde el timer del main
}
