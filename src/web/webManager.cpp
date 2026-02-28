#include "WebManager.h"
#include "../relays/RelayManager.h"
#include "../sensors/SensorManager.h"
#include "../mqtt/MqttManager.h"
#include "../varios/Utils.h"
#include "WebTemplates.h"

/**
 * Constructor de WebManager.
 * @param _relays Puntero al RelayManager.
 * @param _sensors Puntero al SensorManager.
 * @param _mqtt Puntero al MqttManager.
 */
WebManager::WebManager(RelayManager* _relays, SensorManager* _sensors, MqttManager* _mqtt) 
    : server(80), _relays(_relays), _sensors(_sensors), _mqttManager(_mqtt) {
    header = "";
    currentTime = 0;
    previousTime = 0;
}

/**
 * Inicializa el servidor web.
 */
void WebManager::setup() {
    server.begin();
    serialPrint("WebServer - Iniciado en puerto 80");
}

/**
 * Loop procesador de peticiones del servidor web.
 */
void WebManager::loop() {
    WiFiClient _client = server.available();

    if (_client) {
        currentTime = millis();
        previousTime = currentTime;
        serialPrint("WebServer - New Client.");
        String _currentLine = "";
        bool _reset = false;

        while (_client.connected() && currentTime - previousTime <= timeoutTime) {
            currentTime = millis();
            if (_client.available()) {
                char _c = _client.read();
                header += _c;
                if (_c == '\n') {
                    if (_currentLine.length() == 0) {
                        // Acciones según la URL
                        if (header.indexOf("GET /reset") >= 0) _reset = true;
                        
                        #ifdef BOARD_4OUT_RELAY
                        if (_relays != nullptr) {
                            if (header.indexOf("GET /relay1/on") >= 0) _relays->setRelay(1, true);
                            if (header.indexOf("GET /relay1/off") >= 0) _relays->setRelay(1, false);
                            if (header.indexOf("GET /relay2/on") >= 0) _relays->setRelay(2, true);
                            if (header.indexOf("GET /relay2/off") >= 0) _relays->setRelay(2, false);
                            if (header.indexOf("GET /relay3/on") >= 0) _relays->setRelay(3, true);
                            if (header.indexOf("GET /relay3/off") >= 0) _relays->setRelay(3, false);
                            if (header.indexOf("GET /relay4/on") >= 0) _relays->setRelay(4, true);
                            if (header.indexOf("GET /relay4/off") >= 0) _relays->setRelay(4, false);
                        }
                        #endif

                        #if !defined(NO_MQTT)
                        if (_mqttManager != nullptr) {
                            if (header.indexOf("GET /mqtt/enable") >= 0) _mqttManager->setEnabled(true);
                            if (header.indexOf("GET /mqtt/disable") >= 0) _mqttManager->setEnabled(false);
                        }
                        #endif

                        sendHTML(_client, _reset);
                        break;
                    } else {
                        _currentLine = "";
                    }
                } else if (_c != '\r') {
                    _currentLine += _c;
                }
            }
        }
        header = "";
        _client.stop();
        serialPrint("WebServer - Client disconnected.");

        if (_reset) {
            #ifdef BOARD_4OUT_RELAY
            if (_relays != nullptr) {
                for(int _i=1; _i<=4; _i++) { _relays->setRelay(_i, false); delay(50); }
            }
            #endif
            serialPrint("Reset in 5 sec..");
            delay(5000);
            ESP.restart();
        }
    }
}

/**
 * Envía el contenido HTML al cliente.
 * @param _client Referencia al objeto WiFiClient.
 * @param _reset Indica si se solicitó un reinicio.
 */
void WebManager::sendHTML(WiFiClient& _client, bool _reset) {
    _client.print(FPSTR(WEB_HEADER_START));
    _client.print(FPSTR(WEB_STYLE));
    _client.print(FPSTR(WEB_BODY_START));

    if (!_reset) {
        _client.println("<h1 style=\"font-family: 'Helvetica Neue', Arial, sans-serif; font-weight: bold; text-align: center;\">" + String(hostName) + "<br>(" + WiFi.localIP().toString() + ")</h1>");
        _client.println("<p  style=\"text-align: center;\"> Version: " + String(versionNumber) + "</p>");

        #ifdef BOARD_4OUT_RELAY
        if (_relays != nullptr) {
            for(int _i=1; _i<=4; _i++) {
                bool _state = _relays->getRelayState(_i);
                String _name = ""; 
                if(_i==1) _name = relay1Name;
                else if(_i==2) _name = relay2Name;
                else if(_i==3) _name = relay3Name;
                else if(_i==4) _name = relay4Name;

                if (!_state) {
                    _client.println("<p>Relay " + String(_i) + " estado: " + String(_state) + " &rarr; " + _name + "</p>");
                    _client.println("<p><a href=\"/relay" + String(_i) + "/on\"><button class=\"button\">OFF</button></a></p>");
                } else {
                    _client.println("<p style=color:red;>Relay " + String(_i) + " estado: " + String(_state) + " &rarr; " + _name + "</p>");
                    _client.println("<p><a href=\"/relay" + String(_i) + "/off\"><button class=\"button2\">ON</button></a></p>");
                }
            }
        }
        #endif

        #if defined(BOARD_DHT22) || defined(BOARD_AHT10)
        if (_sensors != nullptr) {
            _client.println("<div class=\"stats-box\">");
            _client.println("<div class=\"stats-title\">Condiciones Actuales</div>");
            _client.println("<p>Temperatura: <b>" + String(_sensors->getTemperature(), 1) + " grados</b></p>");
            _client.println("<p>Humedad: <b>" + String(_sensors->getHumidity(), 1) + " %</b></p>");
            
            AnalysisManager* _tStats = _sensors->getTemperatureStats();
            _client.println("<div style='font-size: 0.8em; color: #888; margin-top:10px;'>");
            _client.println("Máx: " + String(_tStats->getMaxValue(), 1) + "°C | Mín: " + String(_tStats->getMinValue(), 1) + "°C");
            _client.println("</div>");

            AnalysisManager* _hStats = _sensors->getHumidityStats();
            _client.println("<div style='font-size: 0.8em; color: #888;'>");
            _client.println("Máx: " + String(_hStats->getMaxValue(), 1) + "% | Mín: " + String(_hStats->getMinValue(), 1) + "%");
            _client.println("</div>");
            _client.println("</div>");
        }
        #endif

        #if !defined(NO_MQTT)
        if (_mqttManager != nullptr) {
            _client.println("<div class=\"foot\" style='padding:8px;'>");
            if (_mqttManager->isEnabled()) {
                 _client.println("<p><input type='checkbox' checked onclick=\"location.href='/mqtt/disable'\"> MQTT habilitado</p>");
            } else {
                 _client.println("<p><input type='checkbox' onclick=\"location.href='/mqtt/enable'\"> MQTT deshabilitado</p>");
            }
            _client.println("</div>");
        }
        #endif

        _client.println("<div class=\"foot\">");
        int32_t _rssi = WiFi.RSSI();
        String _signalStrength = (_rssi >= -60) ? "Muy fuerte" : (_rssi >= -70) ? "Fuerte" : (_rssi >= -80) ? "Moderada" : (_rssi >= -90) ? "Debil" : "MuyDébil";
        _client.println("<p class=\"foot\">Nivel de se&ntilde;al Wi-Fi (RSSI): " + String(_rssi) + " dBm (" + _signalStrength + ")</p>");
        
        #if !defined(NO_MQTT)
            String _statusMsg = _mqttManager->getStatus();
            int _attempts = _mqttManager->getFailedAttempts();
            if (_attempts > 0) _statusMsg += " <span style='color:orange; font-weight:bold;'>(" + String(_attempts) + "/20)</span>";
            _client.println("<p class=\"foot\">MQTT server status: " + _statusMsg + "</p>");
        #endif

        #ifdef Report_IP_DuckDNS
              _client.println("<p class=\"foot\">DuckDNS Updated every 1 min: " + urlDuckDns + "</p>");
        #else
            _client.println("<p class=\"foot\">DuckDNS Updated disabled</p>");
        #endif
        
        #ifdef Report_HealthChecks
              _client.println("<p class=\"foot\">HealthChecks Updated every 5 min: " + urlHealthChecks + "</p>");
        #else
              _client.println("<p class=\"foot\">HealthChecks Updated disabled</p>");
        #endif

        _client.println("</div>");
        _client.println("<p><a href=\"/reset\"><button class=\"button3\">RESET</button></a></p>");
    } else {
        _client.println("<script>setTimeout(function(){window.location.href='/';}, 5000);</script>");
        _client.println("<p>Reseting in 5 sec... Reloading page in 5 sec</p>");
    }

    _client.print(FPSTR(WEB_FOOTER));
}
