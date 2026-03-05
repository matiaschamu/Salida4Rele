#include "WebManager.h"
#include "../relays/RelayManager.h"
#include "../sensors/SensorManager.h"
#include "../mqtt/MqttManager.h"
#include "../network/WifiManager.h"
#include "../varios/Utils.h"
#include "WebTemplates.h"

/**
 * Constructor de WebManager.
 * @param _relays Puntero al RelayManager.
 * @param _sensors Puntero al SensorManager.
 * @param _mqtt Puntero al MqttManager.
 * @param _wifi Puntero al WifiManager.
 */
WebManager::WebManager(RelayManager* _relays, SensorManager* _sensors, MqttManager* _mqtt, WifiManager* _wifi) 
    : server(80), _relays(_relays), _sensors(_sensors), _mqttManager(_mqtt), _wifi(_wifi) {
    header = "";
    header.reserve(256); // Evitar reasignaciones frecuentes
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
        _client.setNoDelay(true); // Enviar paquetes de inmediato
        currentTime = millis();
        previousTime = currentTime;
        serialPrint("WebServer - New Client.");
        String _currentLine = "";
        _currentLine.reserve(64);
        bool _reset = false;

        while (_client.connected() && currentTime - previousTime <= timeoutTime) {
            currentTime = millis();
            if (_client.available()) {
                char _c = _client.read();
                header += _c;
                if (_c == '\n') {
                    if (_currentLine.length() == 0) {
                        // Acciones según la URL
                        if (header.indexOf("GET /reset") >= 0 && header.indexOf("GET /reset/counter") < 0) _reset = true;
                        
                        if (header.indexOf("GET /reset/counter") >= 0) {
                            resetResetCount();
                            serialPrint("Reset Count - Counter cleared to 0");
                            _client.println("HTTP/1.1 200 OK");
                            _client.println("Content-type:text/html");
                            _client.println("Connection: close");
                            _client.println();
                            _client.println("<html><body><h1>Contador Reseteado</h1><a href=\"/\">Volver</a></body></html>");
                            break;
                        }
                        
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

                        // Enviar cabeceras HTTP mínimas antes del cuerpo
                        _client.println("HTTP/1.1 200 OK");
                        _client.println("Content-type:text/html");
                        _client.println("Connection: close");
                        _client.println();

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
            setCustomResetReason(3);
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
        _client.print(F("<h1 style=\"font-family: 'Helvetica Neue', Arial, sans-serif; font-weight: bold; text-align: center;\">"));
        _client.print(hostName);
        _client.print(F("<br>("));
        _client.print(WiFi.localIP().toString());
        _client.println(F(")</h1>"));

        _client.print(F("<p style=\"text-align: center;\"> Version: "));
        _client.print(versionNumber);
        _client.println(F("</p>"));

        #ifdef BOARD_4OUT_RELAY
        if (_relays != nullptr) {
            for(int _i=1; _i<=4; _i++) {
                bool _state = _relays->getRelayState(_i);
                const char* _name = ""; 
                if(_i==1) _name = relay1Name.c_str();
                else if(_i==2) _name = relay2Name.c_str();
                else if(_i==3) _name = relay3Name.c_str();
                else if(_i==4) _name = relay4Name.c_str();

                _client.print(F("<p"));
                if (_state) _client.print(F(" style=\"color:red;\""));
                _client.print(F(">Relay "));
                _client.print(_i);
                _client.print(F(" estado: "));
                _client.print(_state);
                _client.print(F(" &rarr; "));
                _client.print(_name);
                _client.println(F("</p>"));

                _client.print(F("<p><a href=\"/relay"));
                _client.print(_i);
                if (!_state) {
                    _client.println(F("/on\"><button class=\"button\">OFF</button></a></p>"));
                } else {
                    _client.println(F("/off\"><button class=\"button2\">ON</button></a></p>"));
                }
            }
        }
        #endif

        #if defined(BOARD_DHT22) || defined(BOARD_AHT10)
        if (_sensors != nullptr) {
            _client.println(F("<div class=\"stats-box\">"));
            _client.println(F("<div class=\"stats-title\">Condiciones Actuales</div>"));
            AnalysisManager* _tStats = _sensors->getTemperatureStats();
            AnalysisManager* _hStats = _sensors->getHumidityStats();

            _client.println(F("<div style='margin-top:10px; border-top:1px solid #eee; padding-top:10px;'>"));
            
            _client.print(F("<p style='margin:2px 0; font-size:0.9em;'>Temperatura: <b>"));
            _client.print(_sensors->getTemperature(), 1);
            _client.println(F(" &deg;C</b></p>"));
            
            _client.print(F("<p style='margin:2px 0; font-size:0.8em; color:#666;'>&uarr; "));
            _client.print(_tStats->max, 1);
            _client.print(F(" &deg;C | &darr; "));
            _client.print(_tStats->min, 1);
            _client.println(F(" &deg;C</p>"));
            
            _client.print(F("<p style='margin:10px 0 2px 0; font-size:0.9em;'>Humedad: <b>"));
            _client.print(_sensors->getHumidity(), 1);
            _client.println(F(" %</b></p>"));

            _client.print(F("<p style='margin:2px 0; font-size:0.8em; color:#666;'>&uarr; "));
            _client.print(_hStats->max, 1);
            _client.print(F(" % | &darr; "));
            _client.print(_hStats->min, 1);
            _client.println(F(" %</p>"));

            _client.println(F("</div></div>"));
        }
        #endif

        #if !defined(NO_MQTT)
        if (_mqttManager != nullptr) {
            _client.println(F("<div class=\"foot\" style='padding:8px;'>"));
            if (_mqttManager->isEnabled()) {
                 _client.println(F("<p><input type='checkbox' checked onclick=\"location.href='/mqtt/disable'\"> MQTT habilitado</p>"));
            } else {
                 _client.println(F("<p><input type='checkbox' onclick=\"location.href='/mqtt/enable'\"> MQTT deshabilitado</p>"));
            }
            _client.println(F("</div>"));
        }
        #endif

        _client.println(F("<div class=\"foot\">"));
        int32_t _rssi = WiFi.RSSI();
        _client.print(F("<p class=\"foot\">Nivel de se&ntilde;al Wi-Fi (RSSI): "));
        _client.print(_rssi);
        _client.print(F(" dBm (<b style=\"color:"));
        _client.print(getRSSIColor(_rssi));
        _client.print(F("\">"));
        _client.print(getRSSILevel(_rssi));
        _client.println(F("</b>)</p>"));

        _client.print(F("<p class=\"foot\">Reinicios de la placa: <b>"));
        _client.print(getResetCount());
        _client.println(F("</b> <a href=\"/reset/counter\" style=\"text-decoration:none; background:#ff4444; color:white; padding:1px 6px; border-radius:4px; font-size:0.8em; margin-left:8px; display:inline-block;\">Borrar</a></p>"));
        
        _client.print(F("<p class=\"foot\">Uptime: <b>"));
        _client.print(getUptime());
        _client.println(F("</b></p>"));

        _client.print(F("<p class=\"foot\">Motivo de reinicio: <b>"));
        _client.print(getResetReason());
        _client.println(F("</b></p>"));

        _client.print(F("<p class=\"foot\">MAC Address: <b>"));
        _client.print(getBoardId());
        _client.println(F("</b></p>"));
        
        #if !defined(NO_MQTT)
            String _statusMsg = _mqttManager->getStatus();
            int _attempts = _mqttManager->getFailedAttempts();
            _client.print(F("<p class=\"foot\">MQTT server status: "));
            _client.print(_statusMsg);
            if (_attempts > 0) {
                _client.print(F(" <span style='color:orange; font-weight:bold;'>("));
                _client.print(_attempts);
                _client.print(F("/100)</span>"));
            }
            _client.println(F("</p>"));
        #endif

        #ifdef Report_HealthChecks
              _client.print(F("<p class=\"foot\">Respuesta HealthCheck: <b>"));
              _client.print(_wifi->getLastResponse());
              _client.println(F("</b></p>"));
        #endif

        _client.println(F("</div>"));
        _client.println(F("<p><a href=\"/reset\"><button class=\"button3\">RESET</button></a></p>"));
    } else {
        _client.println("<script>setTimeout(function(){window.location.href='/';}, 20000);</script>");
        _client.println("<p>Reiniciando m&oacute;dulo... Espere 20 segundos por favor.</p>");
    }

    _client.print(FPSTR(WEB_FOOTER));
}
