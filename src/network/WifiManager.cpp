#include "config/config.h"
#include "WifiManager.h"
#include "varios/utils.h"

WifiManager::WifiManager(const char* ssid, const char* password) {

    IPAddress local_IP(IP1, IP2, IP3, IP4);
    IPAddress gateway(IP1, IP2, IP3, 1);
    IPAddress subnet(255, 255, 255, 0);
    IPAddress primaryDNS(IP1, IP2, IP3, 1);
    // IPAddress secondaryDNS(8, 8, 4, 4);

    _ssid = ssid;
    _password = password;
    _ip = local_IP;
    _gw = gateway;
    _subnet = subnet;
    _dns = primaryDNS;
    //_dns2 = secondaryDNS;
}

void WifiManager::setup() {
    SerialPrint("WIFI - Configurando WiFI");
    WiFi.mode(WIFI_STA);
    WiFi.disconnect();
    SerialPrint("WIFI - Desconectado");
    delay(500);

    // Configuración IP estática
    if (!WiFi.config(_ip, _gw, _subnet, _dns)) {
        SerialPrint("WIFI - Fallo configuracion IP Estatica");
    }

    // SerialPrint();
    SerialPrint("WIFI - Connecting to ->" + String(_ssid));
    // SerialPrint(ssid);
    WiFi.hostname(hostName);
    SerialPrint("WIFI - Status  : " + String(WiFi.status()));
    // SerialPrint(WiFi.status());

    SerialPrint("WIFI - Conectando a: ");
    SerialPrint(_ssid);

    WiFi.begin(_ssid, _password);

    unsigned long startMillis = millis();
    while (WiFi.status() != WL_CONNECTED && (millis() - startMillis) < 60000) {
        SerialPrint(".");
        delay(500);
    }

    if (WiFi.status() == WL_CONNECTED) {
        SerialPrint("\nWIFI - Conectado");
        SerialPrint("WIFI - IP: ");
        SerialPrint(WiFi.localIP());
        SerialPrint("WIFI - RSSI: ");
        SerialPrint(WiFi.RSSI());
    } else {
        SerialPrint("\nWIFI - Error de conexion. Reiniciando...");
        delay(5000);
        ESP.restart();
    }
}

void WifiManager::loop() {
    // Verifica si no está conectado a WiFi
    if (WiFi.status() != WL_CONNECTED)
    {
        setup();
    }
}