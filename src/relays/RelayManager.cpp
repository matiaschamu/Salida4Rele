#include "RelayManager.h"
#include "config/config.h"
#include "varios/utils.h"


RelayManager::RelayManager() {
    // Inicializar estados en false
    for(int i=0; i<4; i++) _relayStatus[i] = false;
}

void RelayManager::setup() {
    // En tu código original enviabas comandos de apagado al inicio
    for(int i=1; i<=4; i++) setRelay(i, false);
}

void RelayManager::setRelay(int relayIndex, bool state) {
    if (relayIndex < 1 || relayIndex > 4) return;
    
    int idx = relayIndex - 1; // Ajustar a índice de array 0-3
    _relayStatus[idx] = state;
    
    sendSerialCommand(idx, state);
}

bool RelayManager::getRelayState(int relayIndex) {
    if (relayIndex < 1 || relayIndex > 4) return false;
    return _relayStatus[relayIndex - 1];
}

void RelayManager::sendSerialCommand(int idx, bool state) {
    // state: 0 = OFF (índice 0 en array interno), 1 = ON (índice 1)
    int cmdType = state ? 1 : 0;
    
    Serial.write(RELAY_CMDS[idx][cmdType], 4);
    
    // Debug opcional
    // Serial.printf("Relay %d -> %s\n", idx+1, state ? "ON" : "OFF");
}

void RelayManager::loop() 
{
    
}