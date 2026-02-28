#pragma once
#include <Arduino.h>

class MqttManager;

class RelayManager {
public:
    /**
     * Constructor de la clase RelayManager.
     */
    RelayManager();

    /**
     * Inicializa los relés en estado apagado y configura el manager de MQTT.
     * @param _mqtt Puntero al MqttManager.
     */
    void setup(MqttManager* _mqtt = nullptr); 
    
    /**
     * Establece el estado de un relé específico.
     * @param _relayIndex Índice del relé (1-4).
     * @param _state Estado deseado (true = ON, false = OFF).
     */
    void setRelay(int _relayIndex, bool _state);
    
    /**
     * Obtiene el estado actual de un relé.
     * @param _relayIndex Índice del relé (1-4).
     * @return true si está encendido, false si está apagado.
     */
    bool getRelayState(int _relayIndex);
    
    /**
     * Actualiza el estado de todos los relés enviando comandos seriales y publica en MQTT.
     */
    void refresh();

    /**
     * Bucle de procesamiento para el manager de relés (no utilizado actualmente).
     */
    void loop();

private:
    bool _relayStatus[4];
    MqttManager* _mqttManager;
    
    // Comandos seriales hexadecimales
    const byte RELAY_CMDS[4][2][4] = {
        { {0xa0, 0x01, 0x00, 0xa1}, {0xa0, 0x01, 0x01, 0xa2} }, // Relé 1 OFF, ON
        { {0xa0, 0x02, 0x00, 0xa2}, {0xa0, 0x02, 0x01, 0xa3} }, // Relé 2
        { {0xa0, 0x03, 0x00, 0xa3}, {0xa0, 0x03, 0x01, 0xa4} }, // Relé 3
        { {0xa0, 0x04, 0x00, 0xa4}, {0xa0, 0x04, 0x01, 0xa5} }  // Relé 4
    };

    void sendSerialCommand(int _idx, bool _state);
};

