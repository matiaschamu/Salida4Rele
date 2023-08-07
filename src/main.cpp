#include <main.h>

//**************************************************   BOARDS   ********************************************

#ifdef Board_4OutRelay_Living
// Placa1
// #define Report_IP_DuckDNS
// #define Report_HealthChecks
const char *hostName = "ESP_Living";
const int webServerPort = 80;
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
String Relay4_MQTT_Status = "Acantilados/Luz/Arcada/Estado";
#endif

#ifdef Board_4OutRelay_Living2
// Placa2
// #define Report_IP_DuckDNS
// #define Report_HealthChecks
const char *hostName = "ESP_Living2";
const int webServerPort = 80;
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
String Relay4_MQTT_Status = "Acantilados/Luz/CaraSur/Estado";
#endif

#ifdef Board_4OutRelay_Comedor
// Placa3
// #define Report_IP_DuckDNS
// #define Report_HealthChecks
const char *hostName = "ESP_Galeria";
const int webServerPort = 80;
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
#endif

#ifdef Board_4OutRelay_Garage
// Placa4
// #define Report_IP_DuckDNS
// #define Report_HealthChecks
const char *hostName = "ESP_Garage";
const int webServerPort = 80;
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
String Relay4_MQTT_Status = "Acantilados/Luz/Lavadero/Estado";
#endif

#ifdef Board_4OutRelay_Tablero
// Placa5
#define Report_IP_DuckDNS
#define Report_HealthChecks
const char *hostName = "ESP_Tablero";
const int webServerPort = 80;
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
String Relay4_MQTT_Status = "";
#endif

#ifdef Board_4OutRelay_1erPiso
// Placa6
// #define Report_IP_DuckDNS
// #define Report_HealthChecks
const char *hostName = "ESP_1erPiso";
const int webServerPort = 80;
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
String Relay4_MQTT_Status = "";
#endif

#ifdef Board_Temp_Humedad_PB
// Placa7
// #define Report_IP_DuckDNS
// #define Report_HealthChecks
const char *hostName = "ESP_TemperaturaPB";
const int webServerPort = 80;
float Calibracion = 0;
String Temperatura_MQTT_Status = "Acantilados/Servicios/Meteorologia/Interior/Living/Temperatura";
String Humedad_MQTT_Status = "Acantilados/Servicios/Meteorologia/Interior/Living/Humedad";
String SensacionTermica_MQTT_Status = "Acantilados/Servicios/Meteorologia/Interior/Living/SensacionTermica";
String PuntoRocio_MQTT_Status = "Acantilados/Servicios/Meteorologia/Interior/Living/PuntoRocio";
String HumedadAbsoluta_MQTT_Status = "Acantilados/Servicios/Meteorologia/Interior/Living/HumedadAbsoluta";
String Percepcion_MQTT_Status = "Acantilados/Servicios/Meteorologia/Interior/Living/PercepcionTermica";
#endif

#ifdef Board_Temp_Humedad_Galeria
// Placa8
// #define Report_IP_DuckDNS
// #define Report_HealthChecks
const char *hostName = "ESP_TemperaturaGaleria";
const int webServerPort = 80;
float Calibracion = 0;
String Temperatura_MQTT_Status = "Acantilados/Servicios/Meteorologia/Exterior/Galeria/Temperatura";
String Humedad_MQTT_Status = "Acantilados/Servicios/Meteorologia/Exterior/Galeria/Humedad";
String SensacionTermica_MQTT_Status = "Acantilados/Servicios/Meteorologia/Exterior/Galeria/SensacionTermica";
String PuntoRocio_MQTT_Status = "Acantilados/Servicios/Meteorologia/Exterior/Galeria/PuntoRocio";
String HumedadAbsoluta_MQTT_Status = "Acantilados/Servicios/Meteorologia/Exterior/Galeria/HumedadAbsoluta";
String Percepcion_MQTT_Status = "Acantilados/Servicios/Meteorologia/Exterior/Galeria/PercepcionTermica";
#endif

#ifdef Board_Temp_Humedad_Exterior
// Placa9
// #define Report_IP_DuckDNS
// #define Report_HealthChecks
const char *hostName = "ESP_TemperaturaExterior";
const int webServerPort = 80;
float Calibracion = 0;
String Temperatura_MQTT_Status = "Acantilados/Servicios/Meteorologia/Exterior/Parque/TemperaturaExterior";
String Humedad_MQTT_Status = "Acantilados/Servicios/Meteorologia/Exterior/Parque/HumedadExterior";
String SensacionTermica_MQTT_Status = "Acantilados/Servicios/Meteorologia/Exterior/Parque/SensacionTermica";
String PuntoRocio_MQTT_Status = "Acantilados/Servicios/Meteorologia/Exterior/Parque/PuntoRocio";
String HumedadAbsoluta_MQTT_Status = "Acantilados/Servicios/Meteorologia/Exterior/Parque/HumedadAbsoluta";
String Percepcion_MQTT_Status = "Acantilados/Servicios/Meteorologia/Exterior/Parque/PercepcionTermica";
#endif

#ifdef Board_4OutRelay_Emmanuel_Living
// Placa1
// #define Report_IP_DuckDNS
// #define Report_HealthChecks
const char *hostName = "Living";
const int webServerPort = 8083;
String Relay1_Name = "Luz Living";
String Relay1_MQTT_Command = "Acantilados/Luz/Living/Comando";
String Relay1_MQTT_Status = "Acantilados/Luz/Living/Estado";
String Relay2_Name = "Luz Dormitorio";
String Relay2_MQTT_Command = "Acantilados/Luz/Frente/Comando";
String Relay2_MQTT_Status = "Acantilados/Luz/Frente/Estado";
String Relay3_Name = "Luz Dorm Superior";
String Relay3_MQTT_Command = "Acantilados/Luz/Ventanal/Comando";
String Relay3_MQTT_Status = "Acantilados/Luz/Ventanal/Estado";
String Relay4_Name = "Luz Garage";
String Relay4_MQTT_Command = "Acantilados/Luz/Arcada/Comando";
String Relay4_MQTT_Status = "Acantilados/Luz/Arcada/Estado";
#endif

#ifdef Board_4OutRelay_Emmanuel_Lavadero
// Placa2
// #define Report_IP_DuckDNS
// #define Report_HealthChecks
const char *hostName = "Lavadero";
const int webServerPort = 8084;
String Relay1_Name = "Luz Cocina";
String Relay1_MQTT_Command = "Acantilados/Luz/Living/Comando";
String Relay1_MQTT_Status = "Acantilados/Luz/Living/Estado";
String Relay2_Name = "Luz Lavadero";
String Relay2_MQTT_Command = "Acantilados/Luz/Frente/Comando";
String Relay2_MQTT_Status = "Acantilados/Luz/Frente/Estado";
String Relay3_Name = "Luz Farolas";
String Relay3_MQTT_Command = "Acantilados/Luz/Ventanal/Comando";
String Relay3_MQTT_Status = "Acantilados/Luz/Ventanal/Estado";
String Relay4_Name = "Bomba Agua";
String Relay4_MQTT_Command = "Acantilados/Luz/Arcada/Comando";
String Relay4_MQTT_Status = "Acantilados/Luz/Arcada/Estado";
#endif

#if defined(Board_DHT22)
#include <DHTesp.h> // Incluir la librería DHTesp
#endif

//**************************************************   Configuracion   ***************************************
#if defined(Board_4OutRelay_Emmanuel_Living) || defined(Board_4OutRelay_Emmanuel_Living)
const String Version = Numero_Version;
const char *ssid = "Camaras";
const char *password = "37615097";
#else
const String Version = Numero_Version;
const char *ssid = "Domotics";
const char *password = "Mato19428426";
#endif

IPAddress local_IP(IP1, IP2, IP3, IP4);
IPAddress gateway(IP1, IP2, IP3, 1);
IPAddress subnet(255, 255, 255, 0);
IPAddress primaryDNS(IP1, IP2, IP3, 1);
// IPAddress secondaryDNS(8, 8, 4, 4);

const char *mqtt_server = "192.168.1.10";
const uint16_t mqtt_port = 1883;
const char *mqtt_user = "matias";
const char *mqtt_pass = "Mato19428426.";

String urlDuckDNS = "http://www.duckdns.org/update/acantilados/f4be5f35-a9c4-4837-b709-f38afbfaaabd";
String urlHealthChecks = "http://hc-ping.com/6b750dde-84ed-424a-b708-7c869b8c5253";

//**************************************************   Inicializacion de variables   ************************
#ifdef Board_4OutRelay
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
#endif

#ifdef Board_DHT22
DHTesp dht;
#endif

#ifdef Board_AHT10
DHTesp dht;
// Adafruit_AHTX0 aht;
AHT10 aht(AHT10_ADDRESS_0X38);
#endif

int status = WL_IDLE_STATUS;
WiFiClient WifiClient;
PubSubClient MQTTClient(WifiClient);
unsigned long lastMsg10seg = 0;
unsigned long lastMsg1min = 0;
unsigned long lastMsg5min = 0;
char msg[50];

DataAnalisis temp;

float temperature = 0, humidity = 0, hIndex = 0, dPoint = 0, AbsoluteH = 0;
byte perception;

//**************************************************   web server Config   *********************************
WiFiServer WEB_Server(webServerPort);
String header;
unsigned long currentTime = millis();
unsigned long previousTime = 0;
const long timeoutTime = 2000;

bool status_AHT;
//**************************************************   CODE SETUP   *****************************************
void setup()
{
  Serial.begin(115200);
  InitOTA();
#if defined(Board_DHT22)
  dht.setup(DHT_PIN, DHTesp::DHT22);
#endif
#if defined(Board_AHT10)
  status_AHT = aht.begin(0, 2);
  aht.setCycleMode();
#endif
  SerialPrint("WIFI - Configurando WiFI");
  WIFI_Setup();

#if defined(Board_4OutRelay_Emmanuel_Living) || defined(Board_4OutRelay_Emmanuel_Living)
#else
  SerialPrint("MQTT - Configurando MQTT");
  MQTT_Setup();
#endif

  WEB_Server.begin();
}

//**************************************************   CODE LOOP   *****************************************
void loop()
{
  // Verifica si no está conectado a WiFi
  if (WiFi.status() != WL_CONNECTED)
  {
    WIFI_Setup();
  }

  ArduinoOTA.handle();

#if defined(Board_4OutRelay_Emmanuel_Living) || defined(Board_4OutRelay_Emmanuel_Living)
#else
  // Verifica si el cliente MQTT no está conectado
  if (!MQTTClient.connected())
  {
    MQTT_Reconnect();
  }
  MQTTClient.loop();
#endif

  WEBSERVER_Loop();

  unsigned long now = millis();
  if (now < lastMsg10seg)
  {
    lastMsg10seg = 0;
    lastMsg1min = 0;
    lastMsg5min = 0;
  }

  // Verifica si han pasado 10 segundos
  if (now - lastMsg10seg > 10000)
  {
    lastMsg10seg = now;

#ifdef Board_4OutRelay
    RELAY_Loop();
#endif

#if defined(Board_DHT22) || defined(Board_AHT10)
    TEMPERATURA_loop(temperature, humidity, hIndex, dPoint, AbsoluteH, perception);
    MQTTClient.publish(Temperatura_MQTT_Status.c_str(), String(temperature, 2).c_str());
    MQTTClient.publish(Humedad_MQTT_Status.c_str(), String(humidity, 2).c_str());
    MQTTClient.publish(SensacionTermica_MQTT_Status.c_str(), String(hIndex, 2).c_str());
    MQTTClient.publish(PuntoRocio_MQTT_Status.c_str(), String(dPoint, 2).c_str());
    MQTTClient.publish(HumedadAbsoluta_MQTT_Status.c_str(), String(AbsoluteH, 2).c_str());
    MQTTClient.publish(Percepcion_MQTT_Status.c_str(), String(perception, 2).c_str());
#endif
  }

  // Verifica si ha pasado 1 minuto
  if (now - lastMsg1min > 60000)
  {
    lastMsg1min = now;
#ifdef Report_IP_DuckDNS
    HTTP_Get(urlDuckDNS);
#endif
  }

  // Verifica si han pasado 5 minutos
  if (now - lastMsg5min > 300000)
  {
    lastMsg5min = now;
#ifdef Report_HealthChecks
    HTTP_Get(urlHealthChecks);
#endif
  }
}

//**************************************************   WIFI   **********************************************
void WIFI_Setup()
{
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(500);

  if (WiFi.config(local_IP, gateway, subnet, primaryDNS) == false)
  {
    SerialPrint("WIFI - Configuration failed.");
  }

  SerialPrint();
  SerialPrint("WIFI - Connecting to ");
  SerialPrint(ssid);
  WiFi.hostname(hostName);
  SerialPrint("WIFI - Status  : ");
  SerialPrint(WiFi.status());
  SerialPrint("WIFI - Conectando...");
  WiFi.begin(ssid, password);

  unsigned long startMillis = millis();
  while (WiFi.status() != WL_CONNECTED && (millis() - startMillis) < 60000)
  {
    SerialPrint(".");
    delay(500);
  }

  if (WiFi.status() == WL_CONNECTED)
  {
    SerialPrint("");
    SerialPrint("WIFI - connected");
    SerialPrint("WIFI - IP address: ");
    SerialPrint(WiFi.localIP().toString());
    SerialPrint("WIFI - RRSI: ");
    SerialPrint(WiFi.RSSI());
  }
  else
  {
    SerialPrint("");
    SerialPrint("WIFI - Connection timeout");
    SerialPrint("WIFI - Performing hard reset...");
    delay(5000);
    ESP.restart();
  }
}

//**************************************************   MQTT   ***********************************************
void MQTT_Setup()
{
  MQTTClient.setServer(mqtt_server, mqtt_port);
  SerialPrint("MQTT - Declarando el Callback");
  MQTTClient.setCallback(MQTT_Callback);
  SerialPrint("MQTT - Setup done");
}
void MQTT_Reconnect()
{
  static int connectionAttempts = 0;
  SerialPrint("MQTT - Intentando Conexion...");
  SerialPrint("MQTT - " + MQTTClient.state());

  if (MQTTClient.connect(hostName, mqtt_user, mqtt_pass))
  {
    SerialPrint("MQTT - Conectado");

#ifdef Board_4OutRelay
    // Suscribir a los temas MQTT si se han configurado
    if (!Relay1_MQTT_Command.isEmpty())
    {
      MQTT_SubscribeToTopic(Relay1_MQTT_Command);
    }
    if (!Relay2_MQTT_Command.isEmpty())
    {
      MQTT_SubscribeToTopic(Relay2_MQTT_Command);
    }
    if (!Relay3_MQTT_Command.isEmpty())
    {
      MQTT_SubscribeToTopic(Relay3_MQTT_Command);
    }
    if (!Relay4_MQTT_Command.isEmpty())
    {
      MQTT_SubscribeToTopic(Relay4_MQTT_Command);
    }
#endif

    connectionAttempts = 0;
  }
  else
  {
    connectionAttempts++; // Incrementar el contador de intentos de conexión fallidos
    SerialPrint("MQTT - Fallo conexion");
    SerialPrint(MQTTClient.state());
    SerialPrint("MQTT - Intentando en 5 seg...");
    delay(5000);

    if (connectionAttempts >= 10) // Realizar un hard reset después de 10 intentos
    {
      SerialPrint("MQTT - Maximo de intentos alcanzado. Realizando hard reset...");
      delay(5000);
      ESP.restart(); // Realizar un reinicio completo (hard reset)
    }
  }
}
// Función auxiliar para suscribir a un tema MQTT de forma no bloqueante
void MQTT_SubscribeToTopic(String topic)
{
  if (topic != "")
  {
    SerialPrint("MQTT - Suscribiendo en " + topic + " ...");

    unsigned long startTime = millis();
    while (!MQTTClient.subscribe(topic.c_str()))
    {
      MQTTClient.loop();

      if (millis() - startTime > 5000)
      {
        SerialPrint("MQTT - Fallo suscripcion");
        // rebootCount++;
        // EEPROM.put(0, rebootCount);
        // EEPROM.commit();
        delay(5000);
        ESP.restart();
        while (true)
          ;
        break;
      }
    }
    SerialPrint("MQTT - Suscripcion OK");
  }
}
void MQTT_Callback(char *topic, byte *payload, unsigned int length)
{
  SerialPrint("MQTT - Message arrived: ");
  String mTopic = convertToString(topic, strlen(topic));
  String mPayload = convertToString(payload, sizeof(payload));
  SerialPrint(mTopic);
  SerialPrint(mPayload);
  SerialPrint();

#ifdef Board_4OutRelay
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
    lastMsg10seg = 0;
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
    lastMsg10seg = 0;
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
    lastMsg10seg = 0;
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
    lastMsg10seg = 0;
  }
#endif
}
String MQTT_Status()
{
  switch (MQTTClient.state())
  {
  case -4:
    return "MQTT_CONNECTION_TIMEOUT - the server didn't respond within the keepalive time";
    break;
  case -3:
    return "MQTT_CONNECTION_LOST - the network connection was broken";
    break;
  case -2:
    return "MQTT_CONNECT_FAILED - the network connection failed";
    break;
  case -1:
    return "MQTT_DISCONNECTED - the client is disconnected cleanly";
    break;
  case 0:
    return "MQTT_CONNECTED - the client is connected";
    break;
  case 1:
    return "MQTT_CONNECT_BAD_PROTOCOL - the server doesn't support the requested version of MQTT";
    break;
  case 2:
    return "MQTT_CONNECT_BAD_CLIENT_ID - the server rejected the client identifier";
    break;
  case 3:
    return "MQTT_CONNECT_UNAVAILABLE - the server was unable to accept the connection";
    break;
  case 4:
    return "MQTT_CONNECT_BAD_CREDENTIALS - the username/password were rejected";
    break;
  case 5:
    return "MQTT_CONNECT_UNAUTHORIZED - the client was not authorized to connect";
    break;
  default:
    return "";
    break;
  }
}

//**************************************************   Temperature   ***************************************
#if defined(Board_DHT22) || defined(Board_AHT10)
void TEMPERATURA_loop(float &temperature, float &humidity, float &hIndex, float &dPoint, float &AbsoluteH, byte &perception)
{
#if defined(Board_DHT22)
  TempAndHumidity val = dht.getTempAndHumidity();
  float t = val.temperature + Calibracion; // Obtener la temperatura en grados Celsius
  float h = val.humidity;                  // Obtener la humedad relativa en porcentaje
#endif
#if defined(Board_AHT10)
  // sensors_event_t hh, tt;
  // aht.getEvent(&hh, &tt);
  // float t = tt.temperature + Calibracion;
  // float h = hh.relative_humidity;

  float t = aht.readTemperature(true) + Calibracion;
  float h = aht.readHumidity(true);

  /* String payload = "{\"temperature\":" + String(t) + ", \"humidity\":" + String(h) + "}";
      char message[100];
      payload.toCharArray(message, 100);

      // Publish payload to MQTT
      MQTTClient.publish("Debug", message); */

  // MQTTClient.publish("Debug/temp", String(t, 2).c_str());
  // MQTTClient.publish("Debug/hum", String(h, 2).c_str());
  // MQTTClient.publish("Debug/status", String(status_AHT, 10).c_str());

#endif
  // Verificar si la lectura del sensor es válida
  if (!isnan(t) && !isnan(h))
  {
    temperature = t;
    humidity = h;
    hIndex = dht.computeHeatIndex(t, h);
    dPoint = dht.computeDewPoint(t, h);
    AbsoluteH = dht.computeAbsoluteHumidity(t, h);
    perception = dht.computePerception(t, h);

    SerialPrint("Temperatura: " + String(temperature) + " °C");
    SerialPrint("Humedad: " + String(humidity) + " %");
  }
  else
  {
    SerialPrint("Error al leer el sensor DHT22 o el AHT10");
  }
}
#endif

//**************************************************   Web Server   ****************************************
void WEBSERVER_Loop()
{
  WiFiClient client = WEB_Server.accept();

  if (client)
  {
    currentTime = millis();
    previousTime = currentTime;
    bool reset = false;
    SerialPrint("WebServer - New Client.");
    String currentLine = "";
    while (client.connected() && currentTime - previousTime <= timeoutTime)
    {
      currentTime = millis();
      if (client.available())
      {
        char c = client.read();
#ifdef debug
        Serial.write(c);
#endif
        header += c;
        if (c == '\n')
        {

          if (currentLine.length() == 0)
          {

            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();

#ifdef Board_4OutRelay
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
            else if (header.indexOf("GET /reset") >= 0)
            {
              reset = true;
            }
#endif
#if defined(Board_DHT22) || defined(Board_AHT10)
            if (header.indexOf("GET /reset") >= 0)
            {
              reset = true;
            }
#endif
            lastMsg10seg = 0;

            client.println("<!DOCTYPE html><html>");
            client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
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

            // client.println(".bomb {color: #ff4545;}");
            // client.println(".reset{margin-top: 40px;}");
            client.println(".foot{font-size: 12px;background-color: #f0f0f0;border-radius: 5px;}</style></head>");

            client.println("<body><div class=\"container\">");
            if (reset == false)
            {
              client.println("<h1 style=\"font-family: 'Helvetica Neue', Arial, sans-serif; font-weight: bold; text-align: center;\">" + String(hostName) + "<br>(" + WiFi.localIP().toString() + ")</h1>");
              client.println("<p  style=\"text-align: center;\"> Version: " + Version + "</p>");

#ifdef Board_4OutRelay
              if (Relay1Status == 0)
              {
                client.println("<p>Relay 1 estado: " + String(Relay1Status) + " &rarr; " + Relay1_Name + "</p>");
                client.println("<p><a href=\"/relay1/on\"><button class=\"button\">OFF</button></a></p>");
              }
              else
              {
                client.println("<p style="
                               "color:red;"
                               ">Relay 1 estado: " +
                               String(Relay1Status) + " &rarr; " + Relay1_Name + "</p>");
                client.println("<p><a href=\"/relay1/off\"><button class=\"button2\">ON</button></a></p>");
              }

              if (Relay2Status == 0)
              {
                client.println("<p>Relay 2 estado: " + String(Relay2Status) + " &rarr; " + Relay2_Name + "</p>");
                client.println("<p><a href=\"/relay2/on\"><button class=\"button\">OFF</button></a></p>");
              }
              else
              {
                client.println("<p style="
                               "color:red;"
                               ">Relay 2 estado: " +
                               String(Relay2Status) + " &rarr; " + Relay2_Name + "</p>");
                client.println("<p><a href=\"/relay2/off\"><button class=\"button2\">ON</button></a></p>");
              }

              if (Relay3Status == 0)
              {
                client.println("<p>Relay 3 estado: " + String(Relay3Status) + " &rarr; " + Relay3_Name + "</p>");
                client.println("<p><a href=\"/relay3/on\"><button class=\"button\">OFF</button></a></p>");
              }
              else
              {
                client.println("<p style="
                               "color:red;"
                               ">Relay 3 estado: " +
                               String(Relay3Status) + " &rarr; " + Relay3_Name + "</p>");
                client.println("<p><a href=\"/relay3/off\"><button class=\"button2\">ON</button></a></p>");
              }

              if (Relay4Status == 0)
              {
                client.println("<p>Relay 4 estado: " + String(Relay4Status) + " &rarr; " + Relay4_Name + "</p>");
                client.println("<p><a href=\"/relay4/on\"><button class=\"button\">OFF</button></a></p>");
              }
              else
              {
                client.println("<p style="
                               "color:red;"
                               ">Relay 4 estado: " +
                               String(Relay4Status) + " &rarr; " + Relay4_Name + "</p>");
                client.println("<p><a href=\"/relay4/off\"><button class=\"button2\">ON</button></a></p>");
              }
#endif
#if defined(Board_DHT22) || defined(Board_AHT10)
              client.println("<p>Temperatura: " + String(temperature) + " grados" + "</p>");
              client.println("<p>Humedad: " + String(humidity) + " %" + "</p>");
#endif
              client.println("<div class=\"foot\">");
              client.println("<p class=\"foot\">MQTT server status: " + MQTT_Status() + "</p>");

#ifdef Report_IP_DuckDNS
              client.println("<p class=\"foot\">DuckDNS Updated every 1 min: " + urlDuckDNS + "</p>");
#endif
#ifndef Report_IP_DuckDNS
              client.println("<p class=\"foot\">DuckDNS Updated disabled</p>");
#endif
#ifdef Report_HealthChecks
              client.println("<p class=\"foot\">HealthChecks Updated every 5 min: " + urlHealthChecks + "</p>");
#endif
#ifndef Report_HealthChecks
              client.println("<p class=\"foot\">HealthChecks Updated disabled</p>");
#endif
              client.println("</div>");
              client.println("<p><a href=\"/reset\"><button class=\"button3\">RESET</button></a></p>");
            }
            else
            {
              client.println("<script>");
              client.println("setTimeout(function(){");
              client.println("window.history.back();");
              client.println("}, 20000);");
              client.println("</script>");
              client.println("<p>Reseting in 5 sec... Reloading page in 20 sec</p>");
            }

            client.println("</body></html>");
            client.println();
            break;
          }
          else
          {
            currentLine = "";
          }
        }
        else if (c != '\r')
        {
          currentLine += c;
        }
      }
    }
    header = "";

    client.stop();
    SerialPrint("WebServer - Client disconnected.");
    SerialPrint("");

    if (reset == true)
    {
#ifdef Board_4OutRelay
      Serial.write(Relay1_OFF, sizeof(Relay1_OFF));
      delay(50);
      Serial.write(Relay2_OFF, sizeof(Relay2_OFF));
      delay(50);
      Serial.write(Relay3_OFF, sizeof(Relay3_OFF));
      delay(50);
      Serial.write(Relay4_OFF, sizeof(Relay4_OFF));
      delay(50);
#endif
      Serial.println(" ");
      Serial.println("Reset in 5 sec..");
      delay(5000);
      ESP.restart();
    }
  }
}

//**************************************************   Relay   **********************************************
#ifdef Board_4OutRelay
void RELAY_Loop()
{
  if (Relay1_Name != "")
  {
    if (Relay1Status == true)
    {
      Serial.write(Relay1_ON, sizeof(Relay1_ON));
      MQTTClient.publish(Relay1_MQTT_Status.c_str(), "ON");
      SerialPrint("Relay 1 -> 1");
    }
    else
    {
      Serial.write(Relay1_OFF, sizeof(Relay1_OFF));
      MQTTClient.publish(Relay1_MQTT_Status.c_str(), "OFF");
      SerialPrint("Relay 1 -> 0");
    }
  }
  delay(50);
  if (Relay2_Name != "")
  {
    if (Relay2Status == true)
    {
      Serial.write(Relay2_ON, sizeof(Relay2_ON));
      MQTTClient.publish(Relay2_MQTT_Status.c_str(), "ON");
      SerialPrint("Relay 2 -> 1");
    }
    else
    {
      Serial.write(Relay2_OFF, sizeof(Relay2_OFF));
      MQTTClient.publish(Relay2_MQTT_Status.c_str(), "OFF");
      SerialPrint("Relay 2 -> 0");
    }
  }
  delay(50);
  if (Relay3_Name != "")
  {
    if (Relay3Status == true)
    {
      Serial.write(Relay3_ON, sizeof(Relay3_ON));
      MQTTClient.publish(Relay3_MQTT_Status.c_str(), "ON");
      SerialPrint("Relay 3 -> 1");
    }
    else
    {
      Serial.write(Relay3_OFF, sizeof(Relay3_OFF));
      MQTTClient.publish(Relay3_MQTT_Status.c_str(), "OFF");
      SerialPrint("Relay 3 -> 0");
    }
  }
  delay(50);
  if (Relay4_Name != "")
  {
    if (Relay4Status == true)
    {
      Serial.write(Relay4_ON, sizeof(Relay4_ON));
      MQTTClient.publish(Relay4_MQTT_Status.c_str(), "ON");
      SerialPrint("Relay 4 -> 1");
    }
    else
    {
      Serial.write(Relay4_OFF, sizeof(Relay4_OFF));
      MQTTClient.publish(Relay4_MQTT_Status.c_str(), "OFF");
      SerialPrint("Relay 4 -> 0");
    }
  }
}
#endif

//**************************************************   Funciones   ******************************************
void HTTP_Get(String url)
{
  if ((WiFi.status() == WL_CONNECTED))
  {
    String urlRequest = url;
    WiFiClient client;
    HTTPClient http;

    SerialPrint("Iniciando cliente HTTP");

    if (http.begin(client, urlRequest))
    {
      SerialPrint(urlRequest);

      int httpCode = http.GET();

      if (httpCode > 0)
      {
        SerialPrint(httpCode);

        if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY)
        {
          String payload = http.getString();
          SerialPrint(payload);
        }
      }
      else
      {
        SerialPrint("[HTTP] Error on HTTP request");
        SerialPrint("[HTTP] GET... failed, error: %s\n" + http.errorToString(httpCode));
      }
      http.end();
    }
    else
    {
      SerialPrint("[HTTP] Unable to connect\n");
    }
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
void SerialPrint(int msg)
{
  int a = 0;
  a = a;
#ifdef debug
  Serial.println(msg);
#endif
}

//**************************************************   OTA   ***********************************************
void InitOTA()
{
  // Port defaults to 8266
  ArduinoOTA.setPort(8266);

  // Hostname defaults to esp8266-[ChipID]
  ArduinoOTA.setHostname(hostName);

  // No authentication by default
  // ArduinoOTA.setPassword("admin");

  // Password can be set with it's md5 value as well
  // MD5(admin) = 21232f297a57a5a743894a0e4a801fc3
  // ArduinoOTA.setPasswordHash("21232f297a57a5a743894a0e4a801fc3");

  ArduinoOTA.onStart([]()
                     {
  String type;
  if (ArduinoOTA.getCommand() == U_FLASH) {
    type = "sketch";
  } else { // U_SPIFFS
    type = "filesystem";
  }

  // NOTE: if updating SPIFFS this would be the place to unmount SPIFFS using SPIFFS.end()
  Serial.println("Start updating " + type); });

  ArduinoOTA.onEnd([]()
                   { Serial.println("\nEnd"); });

  ArduinoOTA.onProgress([](unsigned int progress, unsigned int total)
                        { Serial.printf("Progress: %u%%\r", (progress / (total / 100))); });

  ArduinoOTA.onError([](ota_error_t error)
                     {
  Serial.printf("Error[%u]: ", error);
  if (error == OTA_AUTH_ERROR) {
    Serial.println("Auth Failed");
  } else if (error == OTA_BEGIN_ERROR) {
    Serial.println("Begin Failed");
  } else if (error == OTA_CONNECT_ERROR) {
    Serial.println("Connect Failed");
  } else if (error == OTA_RECEIVE_ERROR) {
    Serial.println("Receive Failed");
  } else if (error == OTA_END_ERROR) {
    Serial.println("End Failed");
  } });

  ArduinoOTA.begin();
  Serial.println("");
  Serial.println("OTA iniciado");
}
