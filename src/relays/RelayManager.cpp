#include "config/config.h"
#include "RelayManager.h"
#include "varios/utils.h"

RelayManager::RelayManager() {
    // Inicializar estados en false
    for(int i=0; i<4; i++) _relayStatus[i] = false;
}

void RelayManager::setup() {
    // Inicializar apagados
    for(int i=1; i<=4; i++) setRelay(i, false);
}

void RelayManager::setRelay(int relayIndex, bool state) {
    if (relayIndex < 1 || relayIndex > 4) return;
    
    int idx = relayIndex - 1; // Ajustar a índice 0-3
    _relayStatus[idx] = state;
    
    // Enviamos el comando inmediatamente al cambiar
    sendSerialCommand(idx, state);
}

bool RelayManager::getRelayState(int relayIndex) {
    if (relayIndex < 1 || relayIndex > 4) return false;
    return _relayStatus[relayIndex - 1];
}

void RelayManager::refresh() {
    // Replica la lógica de RELAY_Loop del main: enviar comandos si el nombre no está vacío
    // Se agregan delays para no saturar el puerto serie, igual que tenías antes.
    
#ifdef Board_4OutRelay
    if (Relay1_Name != "") { sendSerialCommand(0, _relayStatus[0]); delay(50); }
    if (Relay2_Name != "") { sendSerialCommand(1, _relayStatus[1]); delay(50); }
    if (Relay3_Name != "") { sendSerialCommand(2, _relayStatus[2]); delay(50); }
    if (Relay4_Name != "") { sendSerialCommand(3, _relayStatus[3]); delay(50); }
#endif
}

void RelayManager::sendSerialCommand(int idx, bool state) {
    // state: 0 = OFF, 1 = ON
    int cmdType = state ? 1 : 0;
    Serial.write(RELAY_CMDS[idx][cmdType], 4);
    
    // Opcional: Log
    // SerialPrint("Relay " + String(idx + 1) + " -> " + String(state ? 1 : 0));
}

void RelayManager::loop() {
    // Por ahora vacío, el refresh lo llamamos desde el timer del main
}