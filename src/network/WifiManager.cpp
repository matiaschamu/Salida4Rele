#include "config/Config.h"
#include "WifiManager.h"
#include "varios/Utils.h"

/**
 * Constructor de la clase WifiManager.
 * @param _ssid Nombre de la red Wi-Fi.
 * @param _password Contraseña de la red Wi-Fi.
 */
WifiManager::WifiManager(const char* _ssid, const char* _password) {
    IPAddress _localIP(IP1, IP2, IP3, IP4);
    IPAddress _gateway(IP1, IP2, IP3, 1);
    IPAddress _subnet(255, 255, 255, 0);
    IPAddress _primaryDNS(IP1, IP2, IP3, 1);

    this->_ssid = _ssid;
    this->_password = _password;
    this->_ip = _localIP;
    this->_gw = _gateway;
    this->_subnet = _subnet;
    this->_dns = _primaryDNS;
}

/**
 * Configura la conexión Wi-Fi con IP estática y hostname.
 */
void WifiManager::setup() {
    serialPrint("WIFI - Configurando WiFI");
    WiFi.mode(WIFI_STA);
    WiFi.disconnect();
    serialPrint("WIFI - Desconectado");
    delay(500);

    if (!WiFi.config(_ip, _gw, _subnet, _dns)) {
        serialPrint("WIFI - Fallo configuracion IP Estatica");
    }

    serialPrint("WIFI - Connecting to ->" + String(_ssid));
    WiFi.hostname(hostName);
    serialPrint("WIFI - Status  : " + String(WiFi.status()));

    serialPrint("WIFI - Conectando a: ");
    serialPrint(_ssid);

    WiFi.begin(_ssid, _password);

    unsigned long _startMillis = millis();
    while (WiFi.status() != WL_CONNECTED && (millis() - _startMillis) < 60000) {
        serialPrint(".");
        delay(500);
    }

    if (WiFi.status() == WL_CONNECTED) {
        serialPrint("\nWIFI - Conectado");
        serialPrint("WIFI - IP: ");
        serialPrint(WiFi.localIP());
        serialPrint("WIFI - RSSI: ");
        serialPrint(WiFi.RSSI());
    } else {
        serialPrint("\nWIFI - Error de conexion. Reiniciando...");
        delay(5000);
        ESP.restart();
    }
}

#ifdef ESP8266
#include <ESP8266HTTPClient.h>
#elif defined(ESP32)
#include <HTTPClient.h>
#endif

/**
 * Mantiene la conexión Wi-Fi activa, reconectando si es necesario.
 */
void WifiManager::loop() {
    if (WiFi.status() != WL_CONNECTED) {
        setup();
    }
}

/**
 * Realiza una petición HTTP GET a la URL proporcionada.
 * @param _url URL a la que se realizará la petición.
 */
void WifiManager::httpGet(String _url) {
    if ((WiFi.status() == WL_CONNECTED)) {
        WiFiClient _client;
        HTTPClient _http;

        serialPrint("Iniciando cliente HTTP");

        if (_http.begin(_client, _url)) {
            serialPrint(_url);
            int _httpCode = _http.GET();

            if (_httpCode > 0) {
                serialPrint(_httpCode);
                if (_httpCode == HTTP_CODE_OK || _httpCode == HTTP_CODE_MOVED_PERMANENTLY) {
                    String _payload = _http.getString();
                    serialPrint(_payload);
                }
            } else {
                serialPrint("[HTTP] Error on HTTP request");
                serialPrint("[HTTP] GET... failed, error: %s\n" + _http.errorToString(_httpCode));
            }
            _http.end();
        } else {
            serialPrint("[HTTP] Unable to connect\n");
        }
    }
}

