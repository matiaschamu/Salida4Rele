#include "config/Config.h"
#include "MqttManager.h"
#include "varios/Utils.h"

extern unsigned long lastMsg10seg;

// Puntero global estático para acceder a la instancia desde el callback
static MqttManager* instance = nullptr;

MqttManager::MqttManager(RelayManager* relays) : _relays(relays) {
    _enabled = true;
    instance = this; // Guardamos la referencia a esta instancia
    _failedAttempts = 0;
}

/**
 * Configura los parámetros iniciales del cliente MQTT.
 */
void MqttManager::setup() {
    #if defined(NO_MQTT)
        _enabled = false;
        return;
    #endif

    if (!_enabled) return;

    serialPrint("MQTT - Configurando MQTT");
    _mqttClient.setClient(_wifiClient);
    _mqttClient.setServer(mqtt_server, mqtt_port);
    _mqttClient.setCallback(MqttManager::callback);
    
    _clientId = String(hostName); 
}

/**
 * Ejecuta el procesamiento de mensajes y reconexión automática de MQTT.
 */
void MqttManager::loop() {
    #if defined(NO_MQTT)
        return;
    #endif

    if (!_enabled) return;

    if (!_mqttClient.connected()) {

        reconnect();
    }
    _mqttClient.loop();

}

/**
 * Gestiona el reintento de conexión al servidor MQTT de forma no bloqueante.
 */
void MqttManager::reconnect() {
    if (!_enabled) return;

    static unsigned long lastAttempt = 0;
    unsigned long _now = millis();
    
    // Intento cada 5 segundos no bloqueante (mejor que delay en loop)
    if (_now - lastAttempt < 5000) return;
    lastAttempt = _now;

    serialPrint("MQTT - Intentando Conexion...");
    serialPrint("MQTT - Estado: " + String(_mqttClient.state()));

    if (_mqttClient.connect(_clientId.c_str(), mqtt_user, mqtt_pass)) {
        serialPrint("MQTT - Conectado");
        _failedAttempts = 0;
        subscribeToTopics();
    } else {
        _failedAttempts++;

        String _errorMsg = "MQTT - Fallo conexion (Intento " + String(_failedAttempts) + "/" + String(_maxRetries) + ") rc=" + String(_mqttClient.state());
        serialPrint(_errorMsg);

        if (_failedAttempts >= _maxRetries) {
            serialPrint("!!! CRITICO: Demasiados fallos MQTT. Reiniciando sistema para recuperar pila TCP/IP...");
            delay(1000); 
            ESP.restart();
        }
    }
}

/**
 * Obtiene la cantidad de intentos fallidos de conexión.
 * @return Número de intentos fallidos.
 */
int MqttManager::getFailedAttempts() {
    return _failedAttempts;
}

/**
 * Se suscribe a los tópicos de comando configurados.
 */
void MqttManager::subscribeToTopics() {
    #ifdef BOARD_4OUT_RELAY
        // Suscribir a los temas configurados en config.h/cpp
        if (relay1MqttCommand != "") _mqttClient.subscribe(relay1MqttCommand.c_str());
        if (relay2MqttCommand != "") _mqttClient.subscribe(relay2MqttCommand.c_str());
        if (relay3MqttCommand != "") _mqttClient.subscribe(relay3MqttCommand.c_str());
        if (relay4MqttCommand != "") _mqttClient.subscribe(relay4MqttCommand.c_str());
        serialPrint("MQTT - Suscripciones actualizadas");
    #endif
}

/**
 * Publica un mensaje en un tópico específico.
 * @param topic Tópico de destino.
 * @param payload Contenido del mensaje.
 */
void MqttManager::publish(const char* topic, const char* payload) {
    if (_enabled && _mqttClient.connected()) {
        serialPrint("MQTT - Publicando en " + String(topic) + ": " + String(payload));  
        bool result = _mqttClient.publish(topic, payload);
        serialPrint("resultado " + String(result));
    }
}

/**
 * Función de retrollamada (callback) para procesar mensajes entrantes de MQTT.
 * @param topic Tópico donde se recibió el mensaje.
 * @param payload Puntero al contenido del mensaje.
 * @param length Longitud del contenido.
 */
void MqttManager::callback(char* topic, byte* payload, unsigned int length) {
    serialPrint("MQTT - Message arrived: ");
    String _mTopic = convertToString(topic, strlen(topic));
    String _mPayload = convertToString(payload, length); // Ojo: en tu código usabas sizeof(payload) que es incorrecto para punteros, usa length
    serialPrint(_mTopic + " -> " + _mPayload);

    // Usamos 'instance' para acceder a los objetos miembros (como _relays)
    if (instance == nullptr || instance->_relays == nullptr) return;

    #ifdef BOARD_4OUT_RELAY
        bool _state = (_mPayload == "ON" || _mPayload.indexOf("ON") >= 0 || (char)payload[1] == 'N'); // Lógica adaptada de tu código original (check 'N')

        if (_mTopic == relay1MqttCommand) instance->_relays->setRelay(1, _state);
        else if (_mTopic == relay2MqttCommand) instance->_relays->setRelay(2, _state);
        else if (_mTopic == relay3MqttCommand) instance->_relays->setRelay(3, _state);
        else if (_mTopic == relay4MqttCommand) instance->_relays->setRelay(4, _state);
        
        serialPrint(String("Relay Set via MQTT: ") + (_state ? "ON" : "OFF"));
    #endif
    lastMsg10seg = 0; // Reiniciamos el temporizador de 10s
}

/**
 * Indica si el cliente está actualmente conectado al servidor MQTT.
 * @return true si está conectado.
 */
bool MqttManager::isConnected() {
    return _mqttClient.connected();
}

/**
 * Verifica si el servicio MQTT está habilitado.
 * @return true si está habilitado.
 */
bool MqttManager::isEnabled() {
    return _enabled;
}

/**
 * Habilita o deshabilita el servicio MQTT.
 * @param state Nuevo estado deseado.
 */
void MqttManager::setEnabled(bool state) {
    _enabled = state;
    if (!state) {
        _mqttClient.disconnect();
        _failedAttempts = 0;
    }
}

/**
 * Devuelve un string descriptivo del estado actual de la conexión MQTT.
 * @return Mensaje de estado.
 */
String MqttManager::getStatus() {
    if (!_enabled) return "Deshabilitado por usuario";
    
    int _s = _mqttClient.state();
    switch (_s) {
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
        default: return String(_s);
    }
}

