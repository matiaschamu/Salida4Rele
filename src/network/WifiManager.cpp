#include "Config/Config.h"
#include "WifiManager.h"
#include "Varios/Utils.h"

/**
 * Constructor de la clase WifiManager.
 * @param _ssid Nombre de la red Wi-Fi.
 * @param _password Contraseña de la red Wi-Fi.
 */
WifiManager::WifiManager(const char* _ssid, const char* _password) 
{
    IPAddress _localIP(IP1, IP2, IP3, IP4);
    IPAddress _gateway(IP1, IP2, IP3, 1);
    IPAddress _subnet(255, 255, 255, 0);
    IPAddress _primaryDNS(IP1, IP2, IP3, 1);

    this->_ssid = _ssid;
    this->_password = _password;
    this->_ip = _localIP;
    this->_gw = _gateway;
    this->_subnet = _subnet;
    this->_subnet = _subnet;
    this->_dns = _primaryDNS;
    this->_lastResponse = "Ninguna";
    this->_lastReconnectAttempt = 0;
    this->_wasConnected = false;
    this->_disconnectedSince = 0;
    this->_currentReconnectInterval = 10000; // 10 segundos iniciales
}

/**
 * Configura la conexión Wi-Fi con IP estática y hostname.
 */
void WifiManager::setup() 
{
    serialPrint("WIFI - Configurando WiFi");
    WiFi.mode(WIFI_STA);
    WiFi.disconnect();
    
    if (!WiFi.config(_ip, _gw, _subnet, _dns)) 
    {
        serialPrint("WIFI - Fallo configuracion IP Estatica");
    }

    WiFi.hostname(hostName);
    WiFi.begin(_ssid, _password);
    serialPrint("WIFI - Iniciando conexion a: " + String(_ssid));
    _lastReconnectAttempt = millis();
}

#ifdef ESP8266
#include <ESP8266HTTPClient.h>
#elif defined(ESP32)
#include <HTTPClient.h>
#endif

/**
 * Mantiene la conexión Wi-Fi activa, reconectando si es necesario.
 */
void WifiManager::loop() 
{
    bool _isConnected = (WiFi.status() == WL_CONNECTED);
    unsigned long _now = millis();

    // Detectar cambio de estado de conexión
    if (_isConnected && !_wasConnected) 
    {
        serialPrint("\nWIFI - Conectado");
        serialPrint("WIFI - IP: " + WiFi.localIP().toString());
        serialPrint("WIFI - RSSI: " + String(WiFi.RSSI()));
        _wasConnected = true;
        _disconnectedSince = 0;
        _currentReconnectInterval = 10000; // Resetear intervalo al conectar
    } 
    else if (!_isConnected && _wasConnected) 
    {
        serialPrint("WIFI - Desconectado");
        _wasConnected = false;
        _disconnectedSince = _now;
    }

    if (!_isConnected) 
    {
        // Watchdog de WiFi: Si pasan más de 5 minutos sin conexión, reiniciar por hardware
        if (_disconnectedSince > 0 && (_now - _disconnectedSince > 300000)) 
        {
            serialPrint("WIFI - CRITICO: Mas de 5 min sin conexion. Reiniciando...");
            setCustomResetReason(1);
            ESP.restart();
        }

        if (_now - _lastReconnectAttempt > _currentReconnectInterval) 
        {
            serialPrint("WIFI - Reintentando conexion (Intervalo: " + String(_currentReconnectInterval / 1000) + "s)...");
            WiFi.begin(_ssid, _password);
            _lastReconnectAttempt = _now;

            // Backoff: Incrementar intervalo hasta un máximo de 5 minutos
            if (_currentReconnectInterval < 300000) 
            {
                _currentReconnectInterval *= 2;
                if (_currentReconnectInterval > 300000) _currentReconnectInterval = 300000;
            }
        }
    }
}

/**
 * Realiza una petición HTTP GET a la URL proporcionada.
 * @param _url URL a la que se realizará la petición.
 */
void WifiManager::httpGet(String _url) 
{
    if ((WiFi.status() == WL_CONNECTED)) 
    {
        WiFiClient _client;
        HTTPClient _http;

        serialPrint("HTTP - Iniciando peticion a: " + _url);
        
        // Establecer timeout corto para no bloquear el sistema
        _http.setTimeout(3000); 

        if (_http.begin(_client, _url)) 
        {
            yield(); // Ceder tiempo antes de la petición
            int _httpCode = _http.GET();
            yield(); // Ceder tiempo después de la petición

            if (_httpCode > 0) 
            {
                serialPrint("HTTP Code: " + String(_httpCode));
                if (_httpCode == HTTP_CODE_OK || _httpCode == HTTP_CODE_MOVED_PERMANENTLY) 
                {
                    _lastResponse = _http.getString();
                    serialPrint("HTTP Response: " + _lastResponse);
                } 
                else 
                {
                    _lastResponse = "HTTP " + String(_httpCode);
                }
            } 
            else 
            {
                _lastResponse = "Error " + _http.errorToString(_httpCode);
                serialPrint("HTTP - Error: " + _lastResponse);
            }
            _http.end();
        } 
        else 
        {
            serialPrint("HTTP - No se pudo conectar");
        }
    }
}

/**
 * Realiza un ping al router local principal (192.168.1.1).
 * @return true si el ping fue exitoso
 */
bool WifiManager::pingRouterLocal()
{
    if (WiFi.status() != WL_CONNECTED)
    {
        return false;
    }
    
    IPAddress _routerIP;
    _routerIP.fromString("192.168.1.1");
    
    WiFiClient _client;
    _client.setTimeout(2000);
    bool _result = _client.connect(_routerIP, 80);
    if (_result) { _client.stop(); }
    
    if (_result)
    {
        serialPrint("PING - Router Local OK (192.168.1.1)");
        _lastSuccessfulPing = millis();
        
        // Reset de la ventana de fallos
        if (_pingFailureInProgress)
        {
            serialPrint("PING - Recuperada comunicación con router. Reset de contador.");
            _pingFailureInProgress = false;
            _pingFailureStartTime = 0;
        }
    }
    else
    {
        serialPrint("PING - FALLO: Router Local (192.168.1.1)");
        
        // Log detallado del estado del WiFi
        serialPrint("PING - DEBUG WiFi Status:");
        serialPrint("  Status: " + String(WiFi.status()) + " (3=Connected)");
        serialPrint("  SSID: " + WiFi.SSID());
        serialPrint("  IP: " + WiFi.localIP().toString());
        serialPrint("  Gateway: " + WiFi.gatewayIP().toString());
        serialPrint("  Subnet: " + WiFi.subnetMask().toString());
        serialPrint("  DNS1: " + WiFi.dnsIP(0).toString());
        serialPrint("  DNS2: " + WiFi.dnsIP(1).toString());
        serialPrint("  RSSI: " + String(WiFi.RSSI()) + " dBm");
        serialPrint("  Channel: " + String(WiFi.channel()));
        
        // Iniciar contador de fallos si es la primera vez
        if (!_pingFailureInProgress)
        {
            _pingFailureInProgress = true;
            _pingFailureStartTime = millis();
            serialPrint("PING - Iniciando contador de fallos de conectividad (5 min)");
        }
    }
    
    return _result;
}

/**
 * Verifica si se debe ejecutar un reset por falta de conectividad.
 * Solo resetea si pierde el router local después de 5 minutos de intentos fallidos.
 * @return true si se debe resetear
 */
bool WifiManager::shouldResetDueToConnectivity()
{
    if (!_pingFailureInProgress)
    {
        return false;
    }
    
    unsigned long _now = millis();
    unsigned long _elapsedTime = _now - _pingFailureStartTime;
    
    // Mostrar progreso cada 10 segundos
    static unsigned long _lastProgressReport = 0;
    if (_now - _lastProgressReport > 10000)
    {
        _lastProgressReport = _now;
        uint32_t _remainingSeconds = (PING_FAILURE_TIMEOUT - _elapsedTime) / 1000;
        serialPrint("PING - Fallos continuos. Tiempo hasta reset: " + 
                   String(_remainingSeconds) + "s");
    }
    
    // Verificar si se alcanzó el timeout
    if (_elapsedTime >= PING_FAILURE_TIMEOUT)
    {
        serialPrint("PING - TIMEOUT CRÍTICO: Sin comunicación con router 192.168.1.1 por 5 minutos");
        serialPrint("PING - Ejecutando RESET del dispositivo...");
        return true;
    }
    
    return false;
}

