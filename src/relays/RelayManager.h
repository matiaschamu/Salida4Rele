#pragma once
#include <Arduino.h>

class RelayManager {
public:
    RelayManager();
    void setup(); 
    
    // Método para cambiar estado (index 1-4)
    void setRelay(int relayIndex, bool state);
    
    // Obtener estado actual
    bool getRelayState(int relayIndex);
    
    // Envia los comandos seriales actuales (para el ciclo de 10s)
    void refresh();

    void loop();

private:
    bool _relayStatus[4]; // Guardamos estado de los 4 relés (0 a 3)
    
    // Comandos seriales hexadecimales
    const byte RELAY_CMDS[4][2][4] = {
        { {0xa0, 0x01, 0x00, 0xa1}, {0xa0, 0x01, 0x01, 0xa2} }, // Relé 1 OFF, ON
        { {0xa0, 0x02, 0x00, 0xa2}, {0xa0, 0x02, 0x01, 0xa3} }, // Relé 2
        { {0xa0, 0x03, 0x00, 0xa3}, {0xa0, 0x03, 0x01, 0xa4} }, // Relé 3
        { {0xa0, 0x04, 0x00, 0xa4}, {0xa0, 0x04, 0x01, 0xa5} }  // Relé 4
    };

    void sendSerialCommand(int relayIndex, bool state);
};