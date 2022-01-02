#include <Arduino.h>
#include <ESP8266WiFi.h>
//#include <WiFi.h>
#include <ESP8266HTTPClient.h>
#include <PubSubClient.h>

//#define debug

void setup_wifi();
void callback(char *, byte *, unsigned int);
void reconnect();
void SerialPrint();
void SerialPrint(String);
void SerialPrint(char);
String convertToString(char *, int);
String convertToString(byte *, int);

#pragma region "Configuracion" //////////////////////////////////////////////////////////

const char *ssid = "Domotic";
const char *password = "Mato19428426";

IPAddress gateway(192, 168, 1, 1);
IPAddress subnet(255, 255, 255, 0);
IPAddress primaryDNS(192, 168, 1, 1);
//IPAddress secondaryDNS(8, 8, 4, 4);

const char *mqtt_server = "192.168.1.10";
const char *mqtt_user = "matias";
const char *mqtt_pass = "Mato19428426.";

/* //Placa1
//#define Report_IP_DuckDNS
IPAddress local_IP(192, 168, 1, 11);
const char *hostName = "ESP_Living";
String Relay1_Name = "Luz Living";
String Relay1_MQTT_Command = "Acantilados/Luz/Living/Comando";
String Relay1_MQTT_Status = "Acantilados/Luz/Living/Estado";
String Relay2_Name = "Luz Frente";
String Relay2_MQTT_Command = "Acantilados/Luz/Frente/Comando";
String Relay2_MQTT_Status = "Acantilados/Luz/Frente/Estado";
String Relay3_Name = "Luz Ventanal";
String Relay3_MQTT_Command = "Acantilados/Luz/Ventanal/Comando";
String Relay3_MQTT_Status = "Acantilados/Luz/Ventanal/Estado";
String Relay4_Name = "Luz Arcada";
String Relay4_MQTT_Command = "Acantilados/Luz/Arcada/Comando";
String Relay4_MQTT_Status = "Acantilados/Luz/Arcada/Estado"; */

/* //Placa2
//#define Report_IP_DuckDNS
IPAddress local_IP(192, 168, 1, 12);
const char *hostName = "ESP_Living2";
String Relay1_Name = "Luz PuertaEnt";
String Relay1_MQTT_Command = "Acantilados/Luz/PuertaEnt/Comando";
String Relay1_MQTT_Status = "Acantilados/Luz/PuertaEnt/Estado";
String Relay2_Name = "Luz Entrada";
String Relay2_MQTT_Command = "Acantilados/Luz/Entrada/Comando";
String Relay2_MQTT_Status = "Acantilados/Luz/Entrada/Estado";
String Relay3_Name = "Luz Habitacion";
String Relay3_MQTT_Command = "Acantilados/Luz/Habitacion/Comando";
String Relay3_MQTT_Status = "Acantilados/Luz/Habitacion/Estado";
String Relay4_Name = "Luz CaraSur";
String Relay4_MQTT_Command = "Acantilados/Luz/CaraSur/Comando";
String Relay4_MQTT_Status = "Acantilados/Luz/CaraSur/Estado"; */

//Placa3
//#define Report_IP_DuckDNS
IPAddress local_IP(192, 168, 1, 13);
const char *hostName = "ESP_Galeria";
String Relay1_Name = "Luz Comedor";
String Relay1_MQTT_Command = "Acantilados/Luz/Comedor/Comando";
String Relay1_MQTT_Status = "Acantilados/Luz/Comedor/Estado";
String Relay2_Name = "Luz Cocina";
String Relay2_MQTT_Command = "Acantilados/Luz/Cocina/Comando";
String Relay2_MQTT_Status = "Acantilados/Luz/Cocina/Estado";
String Relay3_Name = "Luz Galeria";
String Relay3_MQTT_Command = "Acantilados/Luz/Galeria/Comando";
String Relay3_MQTT_Status = "Acantilados/Luz/Galeria/Estado";
String Relay4_Name = "Luz Farolas";
String Relay4_MQTT_Command = "Acantilados/Luz/Farolas/Comando";
String Relay4_MQTT_Status = "Acantilados/Luz/Farolas/Estado";

/* //Placa4
//#define Report_IP_DuckDNS
IPAddress local_IP(192, 168, 1, 14);
const char *hostName = "ESP_Garage";
String Relay1_Name = "Luz Garage";
String Relay1_MQTT_Command = "Acantilados/Luz/Garage/Comando";
String Relay1_MQTT_Status = "Acantilados/Luz/Garage/Estado";
String Relay2_Name = "Luz LateralGarage";
String Relay2_MQTT_Command = "Acantilados/Luz/LateralGarage/Comando";
String Relay2_MQTT_Status = "Acantilados/Luz/LateralGarage/Estado";
String Relay3_Name = "Luz Servicio";
String Relay3_MQTT_Command = "Acantilados/Luz/Servicio/Comando";
String Relay3_MQTT_Status = "Acantilados/Luz/Servicio/Estado";
String Relay4_Name = "Luz Lavadero";
String Relay4_MQTT_Command = "Acantilados/Luz/Lavadero/Comando";
String Relay4_MQTT_Status = "Acantilados/Luz/Lavadero/Estado"; */

/* //Placa5
#define Report_IP_DuckDNS
IPAddress local_IP(192, 168, 1, 15);
const char *hostName = "ESP_Tablero";
String Relay1_Name = "Bomba Agua";
String Relay1_MQTT_Command = "Acantilados/Servicios/BombaAgua/Comando";
String Relay1_MQTT_Status = "Acantilados/Servicios/BombaAgua/Estado";
String Relay2_Name = "";
String Relay2_MQTT_Command = "";
String Relay2_MQTT_Status = "";
String Relay3_Name = "";
String Relay3_MQTT_Command = "";
String Relay3_MQTT_Status = "";
String Relay4_Name = "";
String Relay4_MQTT_Command = "";
String Relay4_MQTT_Status = ""; */

/* //Placa6
//#define Report_IP_DuckDNS
IPAddress local_IP(192, 168, 1, 16);
const char *hostName = "ESP_1erPiso";
String Relay1_Name = "Luz 1er Piso";
String Relay1_MQTT_Command = "Acantilados/Luz/PlantaAlta/Comando";
String Relay1_MQTT_Status = "Acantilados/Luz/PlantaAlta/Estado";
String Relay2_Name = "Luz Reflector";
String Relay2_MQTT_Command = "Acantilados/Luz/Reflector/Comando";
String Relay2_MQTT_Status = "Acantilados/Luz/Reflector/Estado";
String Relay3_Name = "Resistencia Termo";
String Relay3_MQTT_Command = "Acantilados/Servicios/ResistenciaTermo/Comando";
String Relay3_MQTT_Status = "Acantilados/Servicios/ResistenciaTermo/Estado";
String Relay4_Name = "";
String Relay4_MQTT_Command = "";
String Relay4_MQTT_Status = ""; */

#pragma endregion /////////////////////////////////////////////////////////////////////

bool Relay1Status = false;
bool Relay2Status = false;
bool Relay3Status = false;
bool Relay4Status = false;

byte Relay1_OFF[] = {0xa0, 0x01, 0x00, 0xa1};
byte Relay1_ON[] = {0xa0, 0x01, 0x01, 0xa2};
byte Relay2_OFF[] = {0xa0, 0x02, 0x00, 0xa2};
byte Relay2_ON[] = {0xa0, 0x02, 0x01, 0xa3};
byte Relay3_OFF[] = {0xa0, 0x03, 0x00, 0xa3};
byte Relay3_ON[] = {0xa0, 0x03, 0x01, 0xa4};
byte Relay4_OFF[] = {0xa0, 0x04, 0x00, 0xa4};
byte Relay4_ON[] = {0xa0, 0x04, 0x01, 0xa5};

int status = WL_IDLE_STATUS;
WiFiClient espClient;
PubSubClient client(espClient);
long lastMsg = 0;
long lastMsg1min = 0;
char msg[50];
int value = 0;

#pragma region "web server Config"
WiFiServer server(80);
String header;
// Current time
unsigned long currentTime = millis();
// Previous time
unsigned long previousTime = 0;
// Define timeout time in milliseconds (example: 2000ms = 2s)
const long timeoutTime = 2000;
#pragma endregion

void setup()
{
  Serial.begin(115200);
  //pinMode(LED_BUILTIN, OUTPUT); // Initialize the BUILTIN_LED pin as an output
  SerialPrint("Configurando WiFI");
  setup_wifi();
  SerialPrint("Estableciendo servidor MQTT");
  client.setServer(mqtt_server, 1883);
  SerialPrint("Declarando el Callback");
  client.setCallback(callback);
  SerialPrint("Setup done");
  server.begin();
}

void setup_wifi()
{
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);

  if (WiFi.config(local_IP, gateway, subnet, primaryDNS) == false)
  {
    Serial.println("Configuration failed.");
  }

  SerialPrint();
  SerialPrint("Connecting to ");
  SerialPrint(ssid);
  WiFi.hostname(hostName);
  SerialPrint("WIFI Status  : ");
  Serial.print(WiFi.status());
  SerialPrint("Conectando...");
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED)
  {
    SerialPrint(".");
    delay(100);
  }

  SerialPrint("");
  SerialPrint("WiFi connected");
  SerialPrint("IP address: ");
  SerialPrint(WiFi.localIP().toString());

  Serial.print("RRSI: ");
  Serial.println(WiFi.RSSI());
}

void callback(char *topic, byte *payload, unsigned int length)
{
  SerialPrint("Message arrived: ");
  String mTopic = convertToString(topic, strlen(topic));
  String mPayload = convertToString(payload, sizeof(payload));
  SerialPrint(mTopic);
  SerialPrint(mPayload);
  SerialPrint();

  if (mTopic == Relay1_MQTT_Command)
  {
    if ((char)payload[1] == 'N')
    {
      Relay1Status = true;
      SerialPrint("Relay1_ON");
    }
    else
    {
      Relay1Status = false;
      SerialPrint("Relay1_OFF");
    }
    lastMsg = 0;
  }
  else if (mTopic == Relay2_MQTT_Command)
  {
    if ((char)payload[1] == 'N')
    {
      Relay2Status = true;
      SerialPrint("Relay2_ON");
    }
    else
    {
      Relay2Status = false;
      SerialPrint("Relay2_OFF");
    }
    lastMsg = 0;
  }
  else if (mTopic == Relay3_MQTT_Command)
  {
    if ((char)payload[1] == 'N')
    {
      Relay3Status = true;
      SerialPrint("Relay3_ON");
    }
    else
    {
      Relay3Status = false;
      SerialPrint("Relay3_OFF");
    }
    lastMsg = 0;
  }
  else if (mTopic == Relay4_MQTT_Command)
  {
    if ((char)payload[1] == 'N')
    {
      Relay4Status = true;
      SerialPrint("Relay4_ON");
    }
    else
    {
      Relay4Status = false;
      SerialPrint("Relay4_OFF");
    }
    lastMsg = 0;
  }
}

String convertToString(char *a, int size)
{
  int i;
  String s = "";
  for (i = 0; i < size; i++)
  {
    s = s + a[i];
  }
  return s;
}
String convertToString(byte *a, int size)
{
  int i;
  String s = "";
  for (i = 0; i < size; i++)
  {
    s = s + a[i];
  }
  return s;
}

void reconnect()
{
  while (!client.connected())
  {
    SerialPrint("Intentando MQTT Conexion...");

    if (client.connect(hostName, mqtt_user, mqtt_pass))
    {
      SerialPrint("Conectado");
      if (Relay1_MQTT_Command != "")
      {
        SerialPrint("Suscribiendo en " + Relay1_MQTT_Command + " ...");
        while (client.subscribe(Relay1_MQTT_Command.c_str()) == false)
        {
        }
        SerialPrint("Suscripcion OK");
      }

      if (Relay2_MQTT_Command != "")
      {
        SerialPrint("Suscribiendo en " + Relay2_MQTT_Command + " ...");
        while (client.subscribe(Relay2_MQTT_Command.c_str()) == false)
        {
        }
        SerialPrint("Suscripcion OK");
      }

      if (Relay3_MQTT_Command != "")
      {
        SerialPrint("Suscribiendo en " + Relay3_MQTT_Command + " ...");
        while (client.subscribe(Relay3_MQTT_Command.c_str()) == false)
        {
        }
        SerialPrint("Suscripcion OK");
      }

      if (Relay4_MQTT_Command != "")
      {
        SerialPrint("Suscribiendo en " + Relay4_MQTT_Command + " ...");
        while (client.subscribe(Relay4_MQTT_Command.c_str()) == false)
        {
        }
        SerialPrint("Suscripcion OK");
      }
    }
    else
    {
      SerialPrint("Fallo conexion MQTT");
      SerialPrint(client.state());
      SerialPrint("Intentando en 5 seg...");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

void SerialPrint()
{
  int a = 0;
  a = a;
#ifdef debug
  Serial.println();
#endif
}
void SerialPrint(String msg)
{
  int a = 0;
  a = a;
#ifdef debug
  Serial.println(msg);
#endif
}
void SerialPrint(char msg)
{
  int a = 0;
  a = a;
#ifdef debug
  Serial.println(msg);
#endif
}

void loop()
{
  if (!client.connected())
  {
    reconnect();
  }
  client.loop();

  long now = millis();

#pragma region "Control relays"
  if (now - lastMsg > 5000)
  {
    lastMsg = now;
    ++value;

    if (Relay1_Name != "")
    {
      if (Relay1Status == true)
      {
        Serial.write(Relay1_ON, sizeof(Relay1_ON));
        client.publish(Relay1_MQTT_Status.c_str(), "ON");
        SerialPrint("Relay 1 -> 1");
      }
      else
      {
        Serial.write(Relay1_OFF, sizeof(Relay1_OFF));
        client.publish(Relay1_MQTT_Status.c_str(), "OFF");
        SerialPrint("Relay 1 -> 0");
      }
    }
    delay(50);
    if (Relay2_Name != "")
    {
      if (Relay2Status == true)
      {
        Serial.write(Relay2_ON, sizeof(Relay2_ON));
        client.publish(Relay2_MQTT_Status.c_str(), "ON");
        SerialPrint("Relay 2 -> 1");
      }
      else
      {
        Serial.write(Relay2_OFF, sizeof(Relay2_OFF));
        client.publish(Relay2_MQTT_Status.c_str(), "OFF");
        SerialPrint("Relay 2 -> 0");
      }
    }
    delay(50);
    if (Relay3_Name != "")
    {
      if (Relay3Status == true)
      {
        Serial.write(Relay3_ON, sizeof(Relay3_ON));
        client.publish(Relay3_MQTT_Status.c_str(), "ON");
        SerialPrint("Relay 3 -> 1");
      }
      else
      {
        Serial.write(Relay3_OFF, sizeof(Relay3_OFF));
        client.publish(Relay3_MQTT_Status.c_str(), "OFF");
        SerialPrint("Relay 3 -> 0");
      }
    }
    delay(50);
    if (Relay4_Name != "")
    {
      if (Relay4Status == true)
      {
        Serial.write(Relay4_ON, sizeof(Relay4_ON));
        client.publish(Relay4_MQTT_Status.c_str(), "ON");
        SerialPrint("Relay 4 -> 1");
      }
      else
      {
        Serial.write(Relay4_OFF, sizeof(Relay4_OFF));
        client.publish(Relay4_MQTT_Status.c_str(), "OFF");
        SerialPrint("Relay 4 -> 0");
      }
    }
  }
#pragma endregion

#pragma region "DuckDNS"
  if (now - lastMsg1min > 60000)
  {
    lastMsg1min = now;
#ifdef Report_IP_DuckDNS
    if ((WiFi.status() == WL_CONNECTED))
    {
      String urlRequest = "http://www.duckdns.org/update/acantilados/f4be5f35-a9c4-4837-b709-f38afbfaaabd";
      Serial.println(urlRequest);

      HTTPClient http;
      WiFiClient client;
      http.begin(client, urlRequest);
      int httpCode = http.GET();

      if (httpCode > 0)
      { //Check for the returning code

        String payload = http.getString();
        Serial.println(httpCode);
        Serial.println(payload);
      }
      else
      {
        Serial.println("Error on HTTP request");
      }
      http.end();
    }
#endif
  }
#pragma endregion

#pragma region "web server"

  WiFiClient client = server.available(); // Listen for incoming clients

  if (client)
  { // If a new client connects,
    currentTime = millis();
    previousTime = currentTime;
    Serial.println("New Client."); // print a message out in the serial port
    String currentLine = "";       // make a String to hold incoming data from the client
    while (client.connected() && currentTime - previousTime <= timeoutTime)
    { // loop while the client's connected
      currentTime = millis();
      if (client.available())
      {                         // if there's bytes to read from the client,
        char c = client.read(); // read a byte, then
        Serial.write(c);        // print it out the serial monitor
        header += c;
        if (c == '\n')
        { // if the byte is a newline character
          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0)
          {
            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();

            // turns the GPIOs on and off
            if (header.indexOf("GET /relay1/on") >= 0)
            {
              Relay1Status = 1;
            }
            else if (header.indexOf("GET /relay1/off") >= 0)
            {
              Relay1Status = 0;
            }
            else if (header.indexOf("GET /relay2/on") >= 0)
            {
              Relay2Status = 1;
            }
            else if (header.indexOf("GET /relay2/off") >= 0)
            {
              Relay2Status = 0;
            }
            else if (header.indexOf("GET /relay3/on") >= 0)
            {
              Relay3Status = 1;
            }
            else if (header.indexOf("GET /relay3/off") >= 0)
            {
              Relay3Status = 0;
            }
            else if (header.indexOf("GET /relay4/on") >= 0)
            {
              Relay4Status = 1;
            }
            else if (header.indexOf("GET /relay4/off") >= 0)
            {
              Relay4Status = 0;
            }
            lastMsg = 0;

                        // Display the HTML web page
            client.println("<!DOCTYPE html><html>");
            client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
            client.println("<link rel=\"icon\" href=\"data:,\">");
            // CSS to style the on/off buttons
            // Feel free to change the background-color and font-size attributes to fit your preferences
            client.println("<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}");
            client.println(".button { background-color: #4CAF50; border: none; color: white; padding: 16px 40px;");
            client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}");
            client.println(".button2 {background-color: #555555;}</style></head>");

            // Web Page Heading
            client.println("<body><h1>" + String(hostName) + " Web Server (" + WiFi.localIP().toString() + ")</h1>");

            if (Relay1Status == 0)
            {
              client.println("<p>Relay 1 estado: " + String(Relay1Status) + " --> " + Relay1_Name + "</p>");
              client.println("<p><a href=\"/relay1/on\"><button class=\"button\">ON</button></a></p>");
            }
            else
            {
              client.println("<b style=""color:red;"">Relay 1 estado: " + String(Relay1Status) + " --> " + Relay1_Name + "</b>");
              client.println("<p><a href=\"/relay1/off\"><button class=\"button button2\">OFF</button></a></p>");
            }

            if (Relay2Status == 0)
            {
              client.println("<p>Relay 2 estado: " + String(Relay2Status) + " --> " + Relay2_Name + "</p>");
              client.println("<p><a href=\"/relay2/on\"><button class=\"button\">ON</button></a></p>");
            }
            else
            {
              client.println("<b style=""color:red;"">Relay 2 estado: " + String(Relay2Status) + " --> " + Relay2_Name + "</b>");
              client.println("<p><a href=\"/relay2/off\"><button class=\"button button2\">OFF</button></a></p>");
            }

            if (Relay3Status == 0)
            {
              client.println("<p>Relay 3 estado: " + String(Relay3Status) + " --> " + Relay3_Name + "</p>");
              client.println("<p><a href=\"/relay3/on\"><button class=\"button\">ON</button></a></p>");
            }
            else
            {
              client.println("<b style=""color:red;"">Relay 3 estado: " + String(Relay3Status) + " --> " + Relay3_Name + "</b>");
              client.println("<p><a href=\"/relay3/off\"><button class=\"button button2\">OFF</button></a></p>");
            }

            if (Relay4Status == 0)
            {
              client.println("<p>Relay 4 estado: " + String(Relay4Status) + " --> " + Relay4_Name + "</p>");
              client.println("<p><a href=\"/relay4/on\"><button class=\"button\">ON</button></a></p>");
            }
            else
            {
              client.println("<b style=""color:red;"">Relay 4 estado: " + String(Relay4Status) + " --> " + Relay4_Name + "</b>");
              client.println("<p><a href=\"/relay4/off\"><button class=\"button button2\">OFF</button></a></p>");
            }

#ifdef Report_IP_DuckDNS
            client.println("<p>DuckDNS Updated every 1 min: http://www.duckdns.org/update/acantilados/f4be5f35-a9c4-4837-b709-f38afbfaaabd   </p>");
#endif
#ifndef Report_IP_DuckDNS
            client.println("<p>DuckDNS Updated disabled</p>");
#endif

            client.println("</body></html>");

            // The HTTP response ends with another blank line
            client.println();
            // Break out of the while loop
            break;
          }
          else
          { // if you got a newline, then clear currentLine
            currentLine = "";
          }
        }
        else if (c != '\r')
        {                   // if you got anything else but a carriage return character,
          currentLine += c; // add it to the end of the currentLine
        }
      }
    }
    // Clear the header variable
    header = "";
    // Close the connection
    client.stop();
    Serial.println("Client disconnected.");
    Serial.println("");
  }

#pragma endregion
}