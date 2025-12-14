#include "webManager.h"
#include "../varios/utils.h"
#include "../relays/RelayManager.h"
#include "../mqtt/mqttManager.h"

WebManager::WebManager(int port) : server(port) {
    previousTime = 0;
    _relays = nullptr;
    _mqttManager = nullptr;
    _temperature = nullptr;
    _humidity = nullptr;
}

void WebManager::setup(RelayManager* relays, MqttManager* mqtt, float* temp, float* hum) {
    _relays = relays;
    _mqttManager = mqtt;
    _temperature = temp;
    _humidity = hum;

    server.begin();
    // SerialPrint es una macro o función en utils.h? Si es macro, asegúrate de incluir utils.h
    // Si es Serial.println estándar:
    SerialPrint("WEBServer - Iniciado"); 
}

void WebManager::loop() {
    WiFiClient client = server.accept();

    if (client) {
        currentTime = millis();
        previousTime = currentTime;
        bool reset = false;
        SerialPrint("WebServer - New Client.");
        String currentLine = "";
        
        while (client.connected() && currentTime - previousTime <= timeoutTime) 
        {
            currentTime = millis();
            if (currentTime < previousTime) {
                previousTime = currentTime; // Protección contra rollover básico
            }

            if (client.available()) {
                char c = client.read();

                #ifdef debug
                    Serial.write(c);
                #endif

                header += c;
                if (c == '\n') {
                    if (currentLine.length() == 0) {
                        // Respuesta HTTP headers
                        client.println("HTTP/1.1 200 OK");
                        client.println("Content-type:text/html");
                        client.println("Connection: close");
                        client.println();
                        
                        // --- PROCESAMIENTO DE PETICIONES ---
                        
                        #ifdef Board_4OutRelay
                        if (_relays != nullptr) {
                            if (header.indexOf("GET /relay1/on") >= 0) _relays->setRelay(1, true);
                            else if (header.indexOf("GET /relay1/off") >= 0) _relays->setRelay(1, false);
                            else if (header.indexOf("GET /relay2/on") >= 0) _relays->setRelay(2, true);
                            else if (header.indexOf("GET /relay2/off") >= 0) _relays->setRelay(2, false);
                            else if (header.indexOf("GET /relay3/on") >= 0) _relays->setRelay(3, true);
                            else if (header.indexOf("GET /relay3/off") >= 0) _relays->setRelay(3, false);
                            else if (header.indexOf("GET /relay4/on") >= 0) _relays->setRelay(4, true);
                            else if (header.indexOf("GET /relay4/off") >= 0) _relays->setRelay(4, false);
                        }
                        #endif

                        if (header.indexOf("GET /reset") >= 0) {
                            reset = true;
                        }

                        #if !defined(NO_MQTT)
                        if (_mqttManager != nullptr) {
                            if (header.indexOf("GET /mqtt/enable") >= 0) {
                                _mqttManager->setEnabled(true);
                                _mqttManager->setup(); 
                            }
                            else if (header.indexOf("GET /mqtt/disable") >= 0) {
                                _mqttManager->setEnabled(false);
                            }
                        }
                        #endif

                        // --- GENERAR HTML ---
                        sendHTML(client, reset);
                        break;
                    } else {
                        currentLine = "";
                    }
                } else if (c != '\r') {
                    currentLine += c;
                }
            }
        }
        header = "";
        client.stop();
        SerialPrint("WebServer - Client disconnected.");

        if (reset) {
            #ifdef Board_4OutRelay
            if (_relays != nullptr) {
                for(int i=1; i<=4; i++) { _relays->setRelay(i, false); delay(50); }
            }
            #endif
            SerialPrint("Reset in 5 sec..");
            delay(5000);
            ESP.restart();
        }
    }
}

void WebManager::sendHTML(WiFiClient& client, bool reset) {
    client.println("<!DOCTYPE html><html>");
    client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
    // ... (Mantén aquí todos tus estilos CSS) ...
    client.println("<link rel=\"icon\" href=\"data:,\">");
    client.println("<style>body{font-family: \"Helvetica Neue\", Arial, sans-serif; background-color: #f9f9f9; color: #333; margin: 0; padding: 0;}");
    client.println(".container{max-width: 600px; margin: 0 auto; padding: 20px; background-color: #fff; border-radius: 5px; box-shadow: 0px 0px 5px rgba(0,0,0,0.2);}");
    
    client.println("h1{font-size: 36px; margin-bottom: 20px; color: #007bff; background-color: #f0f0f0; padding: 10px 20px; border-radius: 5px;}");
    client.println("p{font-size: 18px;margin: 10px 0;color: #666;}");

    client.println(".button{width:100px; text-align: center; display: inline-block;background-color: #007bff;color: #fff;padding: 12px 24px;font-size: 18px;text-decoration: none;margin: 5px;cursor: pointer;border: none;outline: none;transition: background-color 0.3s ease;border-radius: 5px;}");
    client.println(".button:hover{background-color: #004a99;}");
    client.println(".button2{width:100px; text-align: center; display: inline-block;background-color: #4CAF50;color: #fff;padding: 12px 24px;font-size: 18px;text-decoration: none;margin: 5px;cursor: pointer;border: none;outline: none;transition: background-color 0.3s ease;border-radius: 5px;}");
    client.println(".button2:hover{background-color: #2f6a31;}");
    client.println(".button3{width:100px; text-align: center; display: inline-block;background-color: #FF0000;color: #fff;padding: 12px 24px;font-size: 18px;text-decoration: none;margin: 5px;cursor: pointer;border: none;outline: none;transition: background-color 0.3s ease;border-radius: 5px;}");
    client.println(".button3:hover{background-color: #990000;}");

    client.println(".foot{font-size: 12px;background-color: #f0f0f0;border-radius: 5px;}</style></head>");
    
    client.println("<body><div class=\"container\">");

    if (!reset) {
        client.println("<h1 style=\"font-family: 'Helvetica Neue', Arial, sans-serif; font-weight: bold; text-align: center;\">" + String(hostName) + "<br>(" + WiFi.localIP().toString() + ")</h1>");
        client.println("<p  style=\"text-align: center;\"> Version: " + String(Numero_Version) + "</p>");

        #ifdef Board_4OutRelay
        if (_relays != nullptr) {
            // Lógica de botones de Relés
            // Nota: Para acceder a variables globales como Relay1_Name, asegúrate de que estén disponibles en config.h o pásalas también.
            // Asumiremos que Relay1_Name son defines o constantes globales visibles.
            for(int i=1; i<=4; i++) {
                bool state = _relays->getRelayState(i);
                String name = ""; 
                if(i==1) name = Relay1_Name;
                else if(i==2) name = Relay2_Name;
                else if(i==3) name = Relay3_Name;
                else if(i==4) name = Relay4_Name;

                if (state == 0) {
                    client.println("<p>Relay " + String(i) + " estado: " + String(state) + " &rarr; " + name + "</p>");
                    client.println("<p><a href=\"/relay" + String(i) + "/on\"><button class=\"button\">OFF</button></a></p>");
                } else {
                    client.println("<p style=\"color:red;\">Relay " + String(i) + " estado: " + String(state) + " &rarr; " + name + "</p>");
                    client.println("<p><a href=\"/relay" + String(i) + "/off\"><button class=\"button2\">ON</button></a></p>");
                }
            }
        }
        #endif

        #if defined(Board_DHT22) || defined(Board_AHT10)
        if (_temperature != nullptr && _humidity != nullptr) {
            client.println("<p>Temperatura: " + String(*_temperature) + " grados" + "</p>");
            client.println("<p>Humedad: " + String(*_humidity) + " %" + "</p>");
        }
        #endif

        #if !defined(NO_MQTT)
        if (_mqttManager != nullptr) {
            client.println("<div class=\"foot\" style='padding:8px;'>");

            if (_mqttManager->isEnabled()) {
                 client.println("<p><input type='checkbox' checked onclick=\"location.href='/mqtt/disable'\"> MQTT habilitado</p>");
            } else {
                 client.println("<p><input type='checkbox' onclick=\"location.href='/mqtt/enable'\"> MQTT deshabilitado</p>");
            }
            client.println("</div>");
        }
        #endif

        client.println("<div class=\"foot\">");
        int32_t rssi = WiFi.RSSI();
        String signalStrength = (rssi >= -60) ? "Muy fuerte" : (rssi >= -70) ? "Fuerte" : (rssi >= -80) ? "Moderada" : (rssi >= -90) ? "Debil" : "MuyDébil";
        client.println("<p class=\"foot\">Nivel de se&ntilde;al Wi-Fi (RSSI): " + String(rssi) + " dBm (" + signalStrength + ")</p>");
        
#if !defined(NO_MQTT)
    // El método getStatus() ya se encarga de decir si está "Deshabilitado" 
    // o de devolver el error/estado de conexión.
    String statusMsg = _mqttManager->getStatus();
    int attempts = _mqttManager->getFailedAttempts();

    if (attempts > 0) {
                statusMsg += " <span style='color:orange; font-weight:bold;'>(" + String(attempts) + "/20)</span>";
            }

    client.println("<p class=\"foot\">MQTT server status: " +statusMsg + "</p>");
#endif



        // Links DuckDNS/HealthChecks (si son macros globales funcionarán, si son variables locales en main, debes pasarlas)
        #ifdef Report_IP_DuckDNS
              client.println("<p class=\"foot\">DuckDNS Updated every 1 min: " + urlDuckDNS + "</p>");
        #else
            client.println("<p class=\"foot\">DuckDNS Updated disabled</p>");
        #endif
        
#ifdef Report_HealthChecks
              client.println("<p class=\"foot\">HealthChecks Updated every 5 min: " + urlHealthChecks + "</p>");
#else
              client.println("<p class=\"foot\">HealthChecks Updated disabled</p>");
#endif



        client.println("</div>");
        client.println("<p><a href=\"/reset\"><button class=\"button3\">RESET</button></a></p>"); // Define button3 style in CSS above if missing
    } else {
        client.println("<script>setTimeout(function(){window.history.back();}, 20000);</script>");
        client.println("<p>Reseting in 5 sec... Reloading page in 20 sec</p>");
    }
    client.println("</body></html>");
}