#include "Config.h"
#include <Arduino.h>

const String versionNumber = "1.0.39";

//************************************************** MQTT
//********************************************
#if defined(BOARD_4OUT_RELAY_VALENCIA_LIVING)
const char *mqttServer = "https:www.acantilados-io.com";
#else
const char *mqttServer = "192.168.1.10";
#endif

const uint16_t mqttPort = 1883;
const char *mqttUser = "matias";
const char *mqttPass = "Mato19428426.";

//**************************************************   WIFI
//********************************************
#if defined(BOARD_4OUT_RELAY_EMMANUEL_LIVING) ||                               \
    defined(BOARD_4OUT_RELAY_EMMANUEL_LAVADERO) ||                             \
    defined(BOARD_4OUT_RELAY_EMMANUEL_LIVING_ESP32)
const char *ssid = "Camaras";
const char *password = "37615097";
#elif defined(BOARD_4OUT_RELAY_VALENCIA_LIVING)
const char *ssid = "PoneteWifi";
const char *password = "ratondemierda";
#else
const char *ssid = "Domotics";
const char *password = "Mato19428426";
#endif

//**************************************************   BOARDS
//********************************************
#ifdef BOARD_4OUT_RELAY_LIVING
// Placa1
// #define REPORT_IP_DUCKDNS
#define REPORT_HEALTH_CHECKS
// #define NO_MQTT
const char *hostName = "ESP_Living";
const int webServerPort = 80;
const String relay1Name = "Luz Living";
const String relay1MqttCommand = "Acantilados/Luz/Living/Comando";
const String relay1MqttStatus = "Acantilados/Luz/Living/Estado";
const String relay2Name = "Luz Frente";
const String relay2MqttCommand = "Acantilados/Luz/Frente/Comando";
const String relay2MqttStatus = "Acantilados/Luz/Frente/Estado";
const String relay3Name = "Luz Ventanal";
const String relay3MqttCommand = "Acantilados/Luz/Ventanal/Comando";
const String relay3MqttStatus = "Acantilados/Luz/Ventanal/Estado";
const String relay4Name = "Luz Arcada";
const String relay4MqttCommand = "Acantilados/Luz/Arcada/Comando";
const String relay4MqttStatus = "Acantilados/Luz/Arcada/Estado";
const String urlHealthChecks =
    "http://hc-ping.com/d5283654-660f-4c1a-b812-389f443233d9";
const String urlDuckDns = "http://www.duckdns.org/update/acantilados/"
                          "f4be5f35-a9c4-4837-b709-f38afbfaaabd";
#endif

#ifdef BOARD_4OUT_RELAY_LIVING2
// Placa2
// #define REPORT_IP_DUCKDNS
#define REPORT_HEALTH_CHECKS
// #define NO_MQTT
const char *hostName = "ESP_Living2";
const int webServerPort = 80;
const String relay1Name = "Luz PuertaEnt";
const String relay1MqttCommand = "Acantilados/Luz/PuertaEnt/Comando";
const String relay1MqttStatus = "Acantilados/Luz/PuertaEnt/Estado";
const String relay2Name = "Luz Entrada";
const String relay2MqttCommand = "Acantilados/Luz/Entrada/Comando";
const String relay2MqttStatus = "Acantilados/Luz/Entrada/Estado";
const String relay3Name = "Luz Habitacion";
const String relay3MqttCommand = "Acantilados/Luz/Habitacion/Comando";
const String relay3MqttStatus = "Acantilados/Luz/Habitacion/Estado";
const String relay4Name = "Luz CaraSur";
const String relay4MqttCommand = "Acantilados/Luz/CaraSur/Comando";
const String relay4MqttStatus = "Acantilados/Luz/CaraSur/Estado";
const String urlHealthChecks =
    "http://hc-ping.com/1774013e-4433-4ee4-8229-5449a16e7ca2";
const String urlDuckDns = "http://www.duckdns.org/update/acantilados/"
                          "f4be5f35-a9c4-4837-b709-f38afbfaaabd";
#endif

#ifdef BOARD_4OUT_RELAY_GALERIA
// Placa3
// #define REPORT_IP_DUCKDNS
#define REPORT_HEALTH_CHECKS
// #define NO_MQTT
const char *hostName = "ESP_Galeria";
const int webServerPort = 80;
const String relay1Name = "Luz Comedor";
const String relay1MqttCommand = "Acantilados/Luz/Comedor/Comando";
const String relay1MqttStatus = "Acantilados/Luz/Comedor/Estado";
const String relay2Name = "Luz Cocina";
const String relay2MqttCommand = "Acantilados/Luz/Cocina/Comando";
const String relay2MqttStatus = "Acantilados/Luz/Cocina/Estado";
const String relay3Name = "Luz Galeria";
const String relay3MqttCommand = "Acantilados/Luz/Galeria/Comando";
const String relay3MqttStatus = "Acantilados/Luz/Galeria/Estado";
const String relay4Name = "Luz Farolas";
const String relay4MqttCommand = "Acantilados/Luz/Farolas/Comando";
const String relay4MqttStatus = "Acantilados/Luz/Farolas/Estado";
const String urlHealthChecks =
    "http://hc-ping.com/4390036e-80a9-4fee-99cc-42f6201f6336";
const String urlDuckDns = "http://www.duckdns.org/update/acantilados/"
                          "f4be5f35-a9c4-4837-b709-f38afbfaaabd";
#endif

#ifdef BOARD_4OUT_RELAY_GARAGE
// Placa4
// #define REPORT_IP_DUCKDNS
#define REPORT_HEALTH_CHECKS
// #define NO_MQTT
const char *hostName = "ESP_Garage";
const int webServerPort = 80;
const String relay1Name = "Luz Garage";
const String relay1MqttCommand = "Acantilados/Luz/Garage/Comando";
const String relay1MqttStatus = "Acantilados/Luz/Garage/Estado";
const String relay2Name = "Luz LateralGarage";
const String relay2MqttCommand = "Acantilados/Luz/LateralGarage/Comando";
const String relay2MqttStatus = "Acantilados/Luz/LateralGarage/Estado";
const String relay3Name = "Luz Servicio";
const String relay3MqttCommand = "Acantilados/Luz/Servicio/Comando";
const String relay3MqttStatus = "Acantilados/Luz/Servicio/Estado";
const String relay4Name = "Luz Lavadero";
const String relay4MqttCommand = "Acantilados/Luz/Lavadero/Comando";
const String relay4MqttStatus = "Acantilados/Luz/Lavadero/Estado";
const String urlHealthChecks =
    "http://hc-ping.com/74e92fc0-61bd-41ac-b751-be1c333c06af";
const String urlDuckDns = "http://www.duckdns.org/update/acantilados/"
                          "f4be5f35-a9c4-4837-b709-f38afbfaaabd";
#endif

#ifdef BOARD_4OUT_RELAY_TABLERO
// Placa5
#define REPORT_IP_DUCKDNS
#define REPORT_HEALTH_CHECKS
// #define NO_MQTT
const char *hostName = "ESP_Tablero";
const int webServerPort = 80;
const String relay1Name = "Bomba Agua";
const String relay1MqttCommand = "Acantilados/Servicios/BombaAgua/Comando";
const String relay1MqttStatus = "Acantilados/Servicios/BombaAgua/Estado";
const String relay2Name = "";
const String relay2MqttCommand = "";
const String relay2MqttStatus = "";
const String relay3Name = "";
const String relay3MqttCommand = "";
const String relay3MqttStatus = "";
const String relay4Name = "";
const String relay4MqttCommand = "";
const String relay4MqttStatus = "";
const String urlHealthChecks =
    "http://hc-ping.com/6b750dde-84ed-424a-b708-7c869b8c5253";
const String urlDuckDns = "http://www.duckdns.org/update/acantilados/"
                          "f4be5f35-a9c4-4837-b709-f38afbfaaabd";
#endif

#ifdef BOARD_4OUT_RELAY_1ERPISO
// Placa6
// #define REPORT_IP_DUCKDNS
#define REPORT_HEALTH_CHECKS
// #define NO_MQTT
const char *hostName = "ESP_1erPiso";
const int webServerPort = 80;
const String relay1Name = "Luz 1er Piso 1";
const String relay1MqttCommand = "Acantilados/Luz/PlantaAlta/Comando";
const String relay1MqttStatus = "Acantilados/Luz/PlantaAlta/Estado";
const String relay2Name = "Luz Reflector";
const String relay2MqttCommand = "Acantilados/Luz/Reflector/Comando";
const String relay2MqttStatus = "Acantilados/Luz/Reflector/Estado";
const String relay3Name = "Resistencia Termo";
const String relay3MqttCommand =
    "Acantilados/Servicios/ResistenciaTermo/Comando";
const String relay3MqttStatus = "Acantilados/Servicios/ResistenciaTermo/Estado";
const String relay4Name = "Luz 1er Piso 2";
const String relay4MqttCommand = "Acantilados/Luz/PlantaAlta2/Comando";
;
const String relay4MqttStatus = "Acantilados/Luz/PlantaAlta2/Estado";
const String urlHealthChecks =
    "http://hc-ping.com/fa586267-0c9e-4b02-bd6d-7d2ac39cc7ed";
const String urlDuckDns = "http://www.duckdns.org/update/acantilados/"
                          "f4be5f35-a9c4-4837-b709-f38afbfaaabd";
#endif

#ifdef BOARD_TEMP_HUMEDAD_PB
// Placa7
// #define REPORT_IP_DUCKDNS
#define REPORT_HEALTH_CHECKS
// #define NO_MQTT
const char *hostName = "ESP_TemperaturaPB";
const int webServerPort = 80;
const float calibrationOffset = 0;
const String temperatureMqttStatus =
    "Acantilados/Servicios/Meteorologia/Interior/Living/Temperatura";
const String humidityMqttStatus =
    "Acantilados/Servicios/Meteorologia/Interior/Living/Humedad";
const String heatIndexMqttStatus =
    "Acantilados/Servicios/Meteorologia/Interior/Living/SensacionTermica";
const String dewPointMqttStatus =
    "Acantilados/Servicios/Meteorologia/Interior/Living/PuntoRocio";
const String absoluteHumidityMqttStatus =
    "Acantilados/Servicios/Meteorologia/Interior/Living/HumedadAbsoluta";
const String perceptionMqttStatus =
    "Acantilados/Servicios/Meteorologia/Interior/Living/PercepcionTermica";
const String urlHealthChecks =
    "http://hc-ping.com/78ac3681-519e-4fc8-8aef-e975f8781420";
const String urlDuckDns = "http://www.duckdns.org/update/acantilados/"
                          "f4be5f35-a9c4-4837-b709-f38afbfaaabd";
#endif

#ifdef BOARD_TEMP_HUMEDAD_GALERIA
// Placa8
// #define REPORT_IP_DUCKDNS
#define REPORT_HEALTH_CHECKS
// #define NO_MQTT
const char *hostName = "ESP_TemperaturaGaleria";
const int webServerPort = 80;
const float calibrationOffset = 0;
const String temperatureMqttStatus =
    "Acantilados/Servicios/Meteorologia/Exterior/Galeria/Temperatura";
const String humidityMqttStatus =
    "Acantilados/Servicios/Meteorologia/Exterior/Galeria/Humedad";
const String heatIndexMqttStatus =
    "Acantilados/Servicios/Meteorologia/Exterior/Galeria/SensacionTermica";
const String dewPointMqttStatus =
    "Acantilados/Servicios/Meteorologia/Exterior/Galeria/PuntoRocio";
const String absoluteHumidityMqttStatus =
    "Acantilados/Servicios/Meteorologia/Exterior/Galeria/HumedadAbsoluta";
const String perceptionMqttStatus =
    "Acantilados/Servicios/Meteorologia/Exterior/Galeria/PercepcionTermica";
const String urlHealthChecks =
    "http://hc-ping.com/9f3794ff-3052-4eea-8739-2d4b01a3c7ce";
const String urlDuckDns = "http://www.duckdns.org/update/acantilados/"
                          "f4be5f35-a9c4-4837-b709-f38afbfaaabd";
#endif

#ifdef BOARD_TEMP_HUMEDAD_EXTERIOR
// Placa9
// #define REPORT_IP_DUCKDNS
#define REPORT_HEALTH_CHECKS
// #define NO_MQTT
const char *hostName = "ESP_TemperaturaExterior";
const int webServerPort = 80;
const float calibrationOffset = 0;
const String temperatureMqttStatus =
    "Acantilados/Servicios/Meteorologia/Exterior/Parque/TemperaturaExterior";
const String humidityMqttStatus =
    "Acantilados/Servicios/Meteorologia/Exterior/Parque/HumedadExterior";
const String heatIndexMqttStatus =
    "Acantilados/Servicios/Meteorologia/Exterior/Parque/SensacionTermica";
const String dewPointMqttStatus =
    "Acantilados/Servicios/Meteorologia/Exterior/Parque/PuntoRocio";
const String absoluteHumidityMqttStatus =
    "Acantilados/Servicios/Meteorologia/Exterior/Parque/HumedadAbsoluta";
const String perceptionMqttStatus =
    "Acantilados/Servicios/Meteorologia/Exterior/Parque/PercepcionTermica";
const String urlHealthChecks =
    "http://hc-ping.com/a0f6e21c-b127-410d-8851-b6182a344b69";
const String urlDuckDns = "http://www.duckdns.org/update/acantilados/"
                          "f4be5f35-a9c4-4837-b709-f38afbfaaabd";
#endif

#ifdef BOARD_4OUT_RELAY_EMMANUEL_LIVING
// Placa1
// #define REPORT_IP_DUCKDNS
// #define REPORT_HEALTH_CHECKS
#define NO_MQTT
const char *hostName = "Living";
const int webServerPort = 8083;
const String relay1Name = "Luz Living";
const String relay1MqttCommand = "CasaEmma/Luz/Living/Comando";
const String relay1MqttStatus = "CasaEmma/Luz/Living/Estado";
const String relay2Name = "Luz Dormitorio";
const String relay2MqttCommand = "CasaEmma/Luz/Dormitorio/Comando";
const String relay2MqttStatus = "CasaEmma/Luz/Dormitorio/Estado";
const String relay3Name = "Luz Dorm Superior";
const String relay3MqttCommand = "CasaEmma/Luz/Superior/Comando";
const String relay3MqttStatus = "CasaEmma/Luz/Superior/Estado";
const String relay4Name = "Luz Garage";
const String relay4MqttCommand = "CasaEmma/Luz/Garage/Comando";
const String relay4MqttStatus = "CasaEmma/Luz/Garage/Estado";
const String urlHealthChecks = "";
const String urlDuckDns = "http://www.duckdns.org/update/casaemmadebo/"
                          "f4be5f35-a9c4-4837-b709-f38afbfaaabd";
#endif

#ifdef BOARD_4OUT_RELAY_EMMANUEL_LAVADERO
// Placa2
#define REPORT_IP_DUCKDNS
// #define REPORT_HEALTH_CHECKS
#define NO_MQTT
const char *hostName = "Lavadero";
const int webServerPort = 8084;
const String relay1Name = "Luz Cocina";
const String relay1MqttCommand = "CasaEmma/Luz/Cocina/Comando";
const String relay1MqttStatus = "CasaEmma/Luz/Cocina/Estado";
const String relay2Name = "Luz Lavadero";
const String relay2MqttCommand = "CasaEmma/Luz/Lavadero/Comando";
const String relay2MqttStatus = "CasaEmma/Luz/Lavadero/Estado";
const String relay3Name = "Luz Farolas";
const String relay3MqttCommand = "CasaEmma/Luz/Farola/Comando";
const String relay3MqttStatus = "CasaEmma/Luz/Farola/Estado";
const String relay4Name = "Bomba Agua";
const String relay4MqttCommand = "CasaEmma/Servicios/BombaAgua/Comando";
const String relay4MqttStatus = "CasaEmma/Servicios/BombaAgua/Estado";
const String urlHealthChecks = "";
const String urlDuckDns = "http://www.duckdns.org/update/casaemmadebo/"
                          "f4be5f35-a9c4-4837-b709-f38afbfaaabd";
#endif

#ifdef BOARD_4OUT_RELAY_VALENCIA_LIVING
// Placa1
#define REPORT_IP_DUCKDNS
// #define REPORT_HEALTH_CHECKS
#define NO_MQTT
const char *hostName = "Living";
const int webServerPort = 80;
const String relay1Name = "Luz Living";
const String relay1MqttCommand = "CasaValencia/Luz/Living/Comando";
const String relay1MqttStatus = "CasaValencia/Luz/Living/Estado";
const String relay2Name = "Luz Frente";
const String relay2MqttCommand = "CasaValencia/Luz/Frente/Comando";
const String relay2MqttStatus = "CasaValencia/Luz/Frente/Estado";
const String relay3Name = "Luz Habitacion";
const String relay3MqttCommand = "CasaValencia/Luz/Habitacion/Comando";
const String relay3MqttStatus = "CasaValencia/Luz/Habitacion/Estado";
const String relay4Name = "Bomba Agua";
const String relay4MqttCommand = "CasaValencia/Servicios/BombaAgua/Comando";
const String relay4MqttStatus = "CasaValencia/Servicios/BombaAgua/Estado";
const String urlHealthChecks = "";
const String urlDuckDns = "http://www.duckdns.org/update/valencia/"
                          "f4be5f35-a9c4-4837-b709-f38afbfaaabd";
#endif

#ifdef BOARD_4OUT_RELAY_EMMANUEL_LIVING_ESP32
// Placa1
// #define REPORT_IP_DUCKDNS
#define REPORT_HEALTH_CHECKS
#define NO_MQTT
const char *hostName = "Living";
const int webServerPort = 8083;
const String relay1Name = "Luz Living";
const String relay1MqttCommand = "CasaEmma/Luz/Living/Comando";
const String relay1MqttStatus = "CasaEmma/Luz/Living/Estado";
const String relay2Name = "Luz Dormitorio";
const String relay2MqttCommand = "CasaEmma/Luz/Dormitorio/Comando";
const String relay2MqttStatus = "CasaEmma/Luz/Dormitorio/Estado";
const String relay3Name = "Luz Dorm Superior";
const String relay3MqttCommand = "CasaEmma/Luz/Superior/Comando";
const String relay3MqttStatus = "CasaEmma/Luz/Superior/Estado";
const String relay4Name = "Luz Garage";
const String relay4MqttCommand = "CasaEmma/Luz/Garage/Comando";
const String relay4MqttStatus = "CasaEmma/Luz/Garage/Estado";
const String urlHealthChecks =
    "http://hc-ping.com/4c523442-29aa-45bb-b8e4-a4217981e400";
const String urlDuckDns = "http://www.duckdns.org/update/casaemmadebo2/"
                          "f4be5f35-a9c4-4837-b709-f38afbfaaabd";
#endif
