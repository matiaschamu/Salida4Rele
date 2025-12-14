#include "config/config.h"
#include "mqttManager.h"
#include "varios/utils.h"

extern unsigned long lastMsg10seg;

// Puntero global estático para acceder a la instancia desde el callback
static MqttManager* instance = nullptr;

MqttManager::MqttManager(RelayManager* relays) : _relays(relays) {
    _enabled = true; // Por defecto habilitado, como en tu código original
    instance = this; // Guardamos la referencia a esta instancia
    _failedAttempts = 0;
}

void MqttManager::setup() {
    #if defined(NO_MQTT)
        _enabled = false;
        return;
    #endif

    if (!_enabled) return;

    SerialPrint("MQTT - Configurando MQTT");
    _mqttClient.setClient(_wifiClient);
    _mqttClient.setServer(mqtt_server, mqtt_port);
    _mqttClient.setCallback(MqttManager::callback);
    
    _clientId = String(hostName); 
}

void MqttManager::loop() {
    #if defined(NO_MQTT)
        return;
    #endif

    if (!_enabled) return;

    if (!_mqttClient.connected()) {
        //Serial.println("mqtt no conectado reconectando...");
        reconnect();
    }
    _mqttClient.loop();
    //Serial.print("mqtt es conectado= ");
    //Serial.println(this->isConnected());
}

void MqttManager::reconnect() {
    if (!_enabled) return;

    static unsigned long lastAttempt = 0;
    unsigned long now = millis();
    
    // Intento cada 5 segundos no bloqueante (mejor que delay en loop)
    if (now - lastAttempt < 5000) return;
    lastAttempt = now;

    SerialPrint("MQTT - Intentando Conexion...");
    SerialPrint("MQTT - Estado: " + String(_mqttClient.state()));

    if (_mqttClient.connect(_clientId.c_str(), mqtt_user, mqtt_pass)) {
        SerialPrint("MQTT - Conectado");
        _failedAttempts = 0;
        subscribeToTopics();
    } else {
        _failedAttempts++;

        String errorMsg = "MQTT - Fallo conexion (Intento " + String(_failedAttempts) + "/" + String(_maxRetries) + ") rc=" + String(_mqttClient.state());
        SerialPrint(errorMsg);

        if (_failedAttempts >= _maxRetries) {
            SerialPrint("!!! CRITICO: Demasiados fallos MQTT. Reiniciando sistema para recuperar pila TCP/IP...");
            delay(1000); 
            ESP.restart();
        }
    }
}

int MqttManager::getFailedAttempts() {
    return _failedAttempts;
}

void MqttManager::subscribeToTopics() {
    #ifdef Board_4OutRelay
        // Suscribir a los temas configurados en config.h/cpp
        if (Relay1_MQTT_Command != "") _mqttClient.subscribe(Relay1_MQTT_Command.c_str());
        if (Relay2_MQTT_Command != "") _mqttClient.subscribe(Relay2_MQTT_Command.c_str());
        if (Relay3_MQTT_Command != "") _mqttClient.subscribe(Relay3_MQTT_Command.c_str());
        if (Relay4_MQTT_Command != "") _mqttClient.subscribe(Relay4_MQTT_Command.c_str());
        SerialPrint("MQTT - Suscripciones actualizadas");
    #endif
}

void MqttManager::publish(const char* topic, const char* payload) {
    if (_enabled && _mqttClient.connected()) {
        SerialPrint("MQTT - Publicando en " + String(topic) + ": " + String(payload));  
        bool result = _mqttClient.publish(topic, payload);
        SerialPrint("resultado " + String(result));
    }
}

// Esta función es estática, se llama desde la librería PubSubClient
void MqttManager::callback(char* topic, byte* payload, unsigned int length) {
    SerialPrint("MQTT - Message arrived: ");
    String mTopic = convertToString(topic, strlen(topic));
    String mPayload = convertToString(payload, length); // Ojo: en tu código usabas sizeof(payload) que es incorrecto para punteros, usa length
    SerialPrint(mTopic + " -> " + mPayload);

    // Usamos 'instance' para acceder a los objetos miembros (como _relays)
    if (instance == nullptr || instance->_relays == nullptr) return;

    #ifdef Board_4OutRelay
        bool state = (mPayload == "ON" || mPayload.indexOf("ON") >= 0 || (char)payload[1] == 'N'); // Lógica adaptada de tu código original (check 'N')

        if (mTopic == Relay1_MQTT_Command) instance->_relays->setRelay(1, state);
        else if (mTopic == Relay2_MQTT_Command) instance->_relays->setRelay(2, state);
        else if (mTopic == Relay3_MQTT_Command) instance->_relays->setRelay(3, state);
        else if (mTopic == Relay4_MQTT_Command) instance->_relays->setRelay(4, state);
        
        SerialPrint(String("Relay Set via MQTT: ") + (state ? "ON" : "OFF"));
    #endif
    lastMsg10seg = 0; // Reiniciamos el temporizador de 10s
}

bool MqttManager::isConnected() {
    return _mqttClient.connected();
}

bool MqttManager::isEnabled() {
    return _enabled;
}

void MqttManager::setEnabled(bool state) {
    _enabled = state;
    if (!state) {
        _mqttClient.disconnect();
        _failedAttempts = 0;
    }
}

String MqttManager::getStatus() {
    if (!_enabled) return "Deshabilitado por usuario";
    
    int s = _mqttClient.state();
    switch (s) {
        case -4: return "CONNECTION_TIMEOUT";
        case -3: return "CONNECTION_LOST";
        case -2: return "CONNECT_FAILED";
        case -1: return "DISCONNECTED";
        case 0: return "CONNECTED";
        case 1: return "BAD_PROTOCOL";
        case 2: return "BAD_CLIENT_ID";
        case 3: return "UNAVAILABLE";
        case 4: return "BAD_CREDENTIALS";
        case 5: return "UNAUTHORIZED";
        default: return String(s);
    }
}