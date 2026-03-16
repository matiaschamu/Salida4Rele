#include "Config/Config.h"
#include "MqttManager.h"
#include "../network/WifiManager.h"
#include "Varios/Utils.h"

extern unsigned long lastMsg10seg;

// Puntero global estático para acceder a la instancia desde el callback
static MqttManager* instance = nullptr;

MqttManager::MqttManager(RelayManager* relays) : _relays(relays) 
{
    instance = this; // Guardamos la referencia a esta instancia
    _failedAttempts = 0;
    _currentReconnectInterval = 5000; // 5 segundos iniciales
}

/**
 * Configura los parámetros iniciales del cliente MQTT.
 */
void MqttManager::setup() 
{
    #if defined(NO_MQTT)
    return;
    #endif

    serialPrint("MQTT - Configurando MQTT");
    _mqttClient.setClient(_wifiClient);
    _mqttClient.setServer(mqttServer, mqttPort);
    _mqttClient.setCallback(MqttManager::callback);
    
    _clientId = String(hostName); 
}

/**
 * Ejecuta el procesamiento de mensajes y reconexión automática de MQTT.
 */
void MqttManager::loop() 
{
    #if defined(NO_MQTT)
    return;
    #endif

    if (!_mqttClient.connected()) 
    {
        reconnect();
    }
    _mqttClient.loop();
}

/**
 * Gestiona el reintento de conexión al servidor MQTT de forma no bloqueante.
 */
void MqttManager::reconnect() 
{
    // Solo intentar si WiFi tiene IP (está realmente conectado)
    if (WiFi.status() != WL_CONNECTED || WiFi.localIP().toString() == "0.0.0.0") return;

    static unsigned long lastAttempt = 0;
    unsigned long _now = millis();
    
    // Usar el intervalo actual de backoff
    if (_now - lastAttempt < _currentReconnectInterval) return;
    lastAttempt = _now;

    serialPrint("MQTT - Intentando Conexion (Intervalo: " + String(_currentReconnectInterval / 1000) + "s)...");
    serialPrint("MQTT - Estado: " + String(_mqttClient.state()));

    // Configurar un timeout corto para evitar bloqueos largos del WebServer
    _wifiClient.setTimeout(500); 
    yield();
    
    bool _connected = _mqttClient.connect(_clientId.c_str(), mqttUser, mqttPass);
    
    yield();
    _wifiClient.setTimeout(5000); // Restaurar timeout por defecto

    if (_connected) 
    {
        serialPrint("MQTT - Conectado");
        _failedAttempts = 0;
        _currentReconnectInterval = 15000; // Resetear a 15s al conectar (Priority Beta)
        subscribeToTopics();
        // No publicamos diagnósticos aquí para no bloquear el inicio de la conexión
    } 
    else 
    {
        _failedAttempts++;
        
        // Mantener intervalo fijo (entre 15 y 30 segundos) para no saturar al broker
        _currentReconnectInterval = 15000;

        String _errorMsg = "MQTT - Fallo conexion (Intento " + String(_failedAttempts) + "/10) rc=" + String(_mqttClient.state());
        serialPrint(_errorMsg);

        // Acción de Recuperación: Si tras 10 intentos el MQTT no conecta pero el WiFi sigue activo, refrescar WiFi
        if (_failedAttempts >= 10) 
        {
            serialPrint("MQTT - CRITICO: 10 fallos continuos. Refrescando pila WiFi...");
            WiFi.disconnect();
            WiFi.begin(ssid, password);
            _failedAttempts = 0;
        }
    }
}

/**
 * Obtiene la cantidad de intentos fallidos de conexión.
 * @return Número de intentos fallidos.
 */
int MqttManager::getFailedAttempts() 
{
    return _failedAttempts;
}

/**
 * Se suscribe a los tópicos de comando configurados.
 */
void MqttManager::subscribeToTopics() 
{
    #ifdef BOARD_4OUT_RELAY
    // Suscribir a los temas configurados en Config.h/cpp
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
void MqttManager::publish(const char* topic, const char* payload) 
{
    if (_mqttClient.connected()) 
    {
        serialPrint("MQTT - Publicando en " + String(topic) + ": " + String(payload));  
        bool _result = _mqttClient.publish(topic, payload);
        serialPrint("resultado " + String(_result));
    }
}

/**
 * Función de retrollamada (callback) para procesar mensajes entrantes de MQTT.
 * @param topic Tópico donde se recibió el mensaje.
 * @param payload Puntero al contenido del mensaje.
 * @param length Longitud del contenido.
 */
void MqttManager::callback(char* topic, byte* payload, unsigned int length) 
{
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
bool MqttManager::isConnected() 
{
    return _mqttClient.connected();
}


/**
 * Devuelve un string descriptivo del estado actual de la conexión MQTT.
 * @return Mensaje de estado.
 */
String MqttManager::getStatus() 
{
    int _s = _mqttClient.state();
    switch (_s) 
    {
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

/**
 * Publica todos los datos de diagnóstico del sistema por MQTT.
 * @param _wifi Puntero al WifiManager para obtener la última respuesta HTTP.
 */
void MqttManager::publishDiagnostics(WifiManager* _wifi) 
{
    if (!_mqttClient.connected()) return;

    String _baseTopic = "Acantilados/Hardware/" + String(hostName);

    // RSSI y Señal
    int32_t _rssi = WiFi.RSSI();
    String _diagRSSI = String(_rssi) + " dBm (" + getRSSILevel(_rssi) + ")";
    publish((_baseTopic + "/rssi").c_str(), _diagRSSI.c_str());

    // IP Address
    publish((_baseTopic + "/ip").c_str(), WiFi.localIP().toString().c_str());

    // Reinicios
    publish((_baseTopic + "/reset_count").c_str(), String(getResetCount()).c_str());

    // Motivo de reinicio
    publish((_baseTopic + "/reset_reason").c_str(), getResetReason().c_str());

    // MAC Address
    publish((_baseTopic + "/mac").c_str(), getBoardId().c_str());

    // HealthCheck Response (si está disponible)
    if (_wifi != nullptr) {
        publish((_baseTopic + "/health_response").c_str(), _wifi->getLastResponse().c_str());
    }

    // Versión del Firmware
    publish((_baseTopic + "/version").c_str(), versionNumber.c_str());

    serialPrint("MQTT - Diagnosticos publicados en " + _baseTopic);
}

/**
 * Publica exclusivamente el tiempo de actividad (uptime) por MQTT.
 */
void MqttManager::publishUptime() 
{
    if (!_mqttClient.connected()) return;

    String _baseTopic = "Acantilados/Hardware/" + String(hostName);
    publish((_baseTopic + "/uptime").c_str(), getUptime().c_str());
}

