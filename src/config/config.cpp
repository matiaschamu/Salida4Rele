#include "config.h"
#include <Arduino.h>

const String Numero_Version = "1.0.27";

//**************************************************   WIFI   ********************************************
#if defined(Board_4OutRelay_Emmanuel_Living) || defined(Board_4OutRelay_Emmanuel_Lavadero) || defined(Board_4OutRelay_Emmanuel_Living_ESP32)
const char *ssid = "Camaras";
const char *password = "37615097";
#elif defined(Board_4OutRelay_Valencia_Living)
const char *ssid = "PoneteWifi";
const char *password = "ratondemierda";
#else
const char *ssid = "Domotics";
const char *password = "Mato19428426";
#endif

//**************************************************   BOARDS   ********************************************
#ifdef Board_4OutRelay_Living
// Placa1
// #define Report_IP_DuckDNS
#define Report_HealthChecks
// #define NO_MQTT
const char *hostName = "ESP_Living";
const int webServerPort = 80;
const String Relay1_Name = "Luz Living";
const String Relay1_MQTT_Command = "Acantilados/Luz/Living/Comando";
const String Relay1_MQTT_Status = "Acantilados/Luz/Living/Estado";
const String Relay2_Name = "Luz Frente";
const String Relay2_MQTT_Command = "Acantilados/Luz/Frente/Comando";
const String Relay2_MQTT_Status = "Acantilados/Luz/Frente/Estado";
const String Relay3_Name = "Luz Ventanal";
const String Relay3_MQTT_Command = "Acantilados/Luz/Ventanal/Comando";
const String Relay3_MQTT_Status = "Acantilados/Luz/Ventanal/Estado";
const String Relay4_Name = "Luz Arcada";
const String Relay4_MQTT_Command = "Acantilados/Luz/Arcada/Comando";
const String Relay4_MQTT_Status = "Acantilados/Luz/Arcada/Estado";
const String urlHealthChecks = "http://hc-ping.com/d5283654-660f-4c1a-b812-389f443233d9";
const String urlDuckDNS = "http://www.duckdns.org/update/acantilados/f4be5f35-a9c4-4837-b709-f38afbfaaabd";
#endif

#ifdef Board_4OutRelay_Living2
// Placa2
// #define Report_IP_DuckDNS
#define Report_HealthChecks
// #define NO_MQTT
const char *hostName = "ESP_Living2";
const int webServerPort = 80;
const String Relay1_Name = "Luz PuertaEnt";
const String Relay1_MQTT_Command = "Acantilados/Luz/PuertaEnt/Comando";
const String Relay1_MQTT_Status = "Acantilados/Luz/PuertaEnt/Estado";
const String Relay2_Name = "Luz Entrada";
const String Relay2_MQTT_Command = "Acantilados/Luz/Entrada/Comando";
const String Relay2_MQTT_Status = "Acantilados/Luz/Entrada/Estado";
const String Relay3_Name = "Luz Habitacion";
const String Relay3_MQTT_Command = "Acantilados/Luz/Habitacion/Comando";
const String Relay3_MQTT_Status = "Acantilados/Luz/Habitacion/Estado";
const String Relay4_Name = "Luz CaraSur";
const String Relay4_MQTT_Command = "Acantilados/Luz/CaraSur/Comando";
const String Relay4_MQTT_Status = "Acantilados/Luz/CaraSur/Estado";
const String urlHealthChecks = "http://hc-ping.com/1774013e-4433-4ee4-8229-5449a16e7ca2";
const String urlDuckDNS = "http://www.duckdns.org/update/acantilados/f4be5f35-a9c4-4837-b709-f38afbfaaabd";
#endif

#ifdef Board_4OutRelay_Galeria
// Placa3
// #define Report_IP_DuckDNS
#define Report_HealthChecks
// #define NO_MQTT
const char *hostName = "ESP_Galeria";
const int webServerPort = 80;
const String Relay1_Name = "Luz Comedor";
const String Relay1_MQTT_Command = "Acantilados/Luz/Comedor/Comando";
const String Relay1_MQTT_Status = "Acantilados/Luz/Comedor/Estado";
const String Relay2_Name = "Luz Cocina";
const String Relay2_MQTT_Command = "Acantilados/Luz/Cocina/Comando";
const String Relay2_MQTT_Status = "Acantilados/Luz/Cocina/Estado";
const String Relay3_Name = "Luz Galeria";
const String Relay3_MQTT_Command = "Acantilados/Luz/Galeria/Comando";
const String Relay3_MQTT_Status = "Acantilados/Luz/Galeria/Estado";
const String Relay4_Name = "Luz Farolas";
const String Relay4_MQTT_Command = "Acantilados/Luz/Farolas/Comando";
const String Relay4_MQTT_Status = "Acantilados/Luz/Farolas/Estado";
const String urlHealthChecks = "http://hc-ping.com/4390036e-80a9-4fee-99cc-42f6201f6336";
const String urlDuckDNS = "http://www.duckdns.org/update/acantilados/f4be5f35-a9c4-4837-b709-f38afbfaaabd";
#endif

#ifdef Board_4OutRelay_Garage
// Placa4
// #define Report_IP_DuckDNS
#define Report_HealthChecks
// #define NO_MQTT
const char *hostName = "ESP_Garage";
const int webServerPort = 80;
const String Relay1_Name = "Luz Garage";
const String Relay1_MQTT_Command = "Acantilados/Luz/Garage/Comando";
const String Relay1_MQTT_Status = "Acantilados/Luz/Garage/Estado";
const String Relay2_Name = "Luz LateralGarage";
const String Relay2_MQTT_Command = "Acantilados/Luz/LateralGarage/Comando";
const String Relay2_MQTT_Status = "Acantilados/Luz/LateralGarage/Estado";
const String Relay3_Name = "Luz Servicio";
const String Relay3_MQTT_Command = "Acantilados/Luz/Servicio/Comando";
const String Relay3_MQTT_Status = "Acantilados/Luz/Servicio/Estado";
const String Relay4_Name = "Luz Lavadero";
const String Relay4_MQTT_Command = "Acantilados/Luz/Lavadero/Comando";
const String Relay4_MQTT_Status = "Acantilados/Luz/Lavadero/Estado";
const String urlHealthChecks = "http://hc-ping.com/74e92fc0-61bd-41ac-b751-be1c333c06af";
const String urlDuckDNS = "http://www.duckdns.org/update/acantilados/f4be5f35-a9c4-4837-b709-f38afbfaaabd";
#endif

#ifdef Board_4OutRelay_Tablero
// Placa5
#define Report_IP_DuckDNS
#define Report_HealthChecks
// #define NO_MQTT
const char *hostName = "ESP_Tablero";
const int webServerPort = 80;
const String Relay1_Name = "Bomba Agua";
const String Relay1_MQTT_Command = "Acantilados/Servicios/BombaAgua/Comando";
const String Relay1_MQTT_Status = "Acantilados/Servicios/BombaAgua/Estado";
const String Relay2_Name = "";
const String Relay2_MQTT_Command = "";
const String Relay2_MQTT_Status = "";
const String Relay3_Name = "";
const String Relay3_MQTT_Command = "";
const String Relay3_MQTT_Status = "";
const String Relay4_Name = "";
const String Relay4_MQTT_Command = "";
const String Relay4_MQTT_Status = "";
const String urlHealthChecks = "http://hc-ping.com/6b750dde-84ed-424a-b708-7c869b8c5253";
const String urlDuckDNS = "http://www.duckdns.org/update/acantilados/f4be5f35-a9c4-4837-b709-f38afbfaaabd";
#endif

#ifdef Board_4OutRelay_1erPiso
// Placa6
// #define Report_IP_DuckDNS
#define Report_HealthChecks
// #define NO_MQTT
const char *hostName = "ESP_1erPiso";
const int webServerPort = 80;
const String Relay1_Name = "Luz 1er Piso 1";
const String Relay1_MQTT_Command = "Acantilados/Luz/PlantaAlta/Comando";
const String Relay1_MQTT_Status = "Acantilados/Luz/PlantaAlta/Estado";
const String Relay2_Name = "Luz Reflector";
const String Relay2_MQTT_Command = "Acantilados/Luz/Reflector/Comando";
const String Relay2_MQTT_Status = "Acantilados/Luz/Reflector/Estado";
const String Relay3_Name = "Resistencia Termo";
const String Relay3_MQTT_Command = "Acantilados/Servicios/ResistenciaTermo/Comando";
const String Relay3_MQTT_Status = "Acantilados/Servicios/ResistenciaTermo/Estado";
const String Relay4_Name = "Luz 1er Piso 2";
const String Relay4_MQTT_Command = "Acantilados/Luz/PlantaAlta2/Comando";;
const String Relay4_MQTT_Status = "Acantilados/Luz/PlantaAlta2/Estado";
const String urlHealthChecks = "http://hc-ping.com/fa586267-0c9e-4b02-bd6d-7d2ac39cc7ed";
const String urlDuckDNS = "http://www.duckdns.org/update/acantilados/f4be5f35-a9c4-4837-b709-f38afbfaaabd";
#endif

#ifdef Board_Temp_Humedad_PB
// Placa7
// #define Report_IP_DuckDNS
#define Report_HealthChecks
// #define NO_MQTT
const char *hostName = "ESP_TemperaturaPB";
const int webServerPort = 80;
const float Calibracion = 0;
const String Temperatura_MQTT_Status = "Acantilados/Servicios/Meteorologia/Interior/Living/Temperatura";
const String Humedad_MQTT_Status = "Acantilados/Servicios/Meteorologia/Interior/Living/Humedad";
const String SensacionTermica_MQTT_Status = "Acantilados/Servicios/Meteorologia/Interior/Living/SensacionTermica";
const String PuntoRocio_MQTT_Status = "Acantilados/Servicios/Meteorologia/Interior/Living/PuntoRocio";
const String HumedadAbsoluta_MQTT_Status = "Acantilados/Servicios/Meteorologia/Interior/Living/HumedadAbsoluta";
const String Percepcion_MQTT_Status = "Acantilados/Servicios/Meteorologia/Interior/Living/PercepcionTermica";
const String urlHealthChecks = "http://hc-ping.com/78ac3681-519e-4fc8-8aef-e975f8781420";
const String urlDuckDNS = "http://www.duckdns.org/update/acantilados/f4be5f35-a9c4-4837-b709-f38afbfaaabd";
#endif

#ifdef Board_Temp_Humedad_Galeria
// Placa8
// #define Report_IP_DuckDNS
#define Report_HealthChecks
// #define NO_MQTT
const char *hostName = "ESP_TemperaturaGaleria";
const int webServerPort = 80;
const float Calibracion = 0;
const String Temperatura_MQTT_Status = "Acantilados/Servicios/Meteorologia/Exterior/Galeria/Temperatura";
const String Humedad_MQTT_Status = "Acantilados/Servicios/Meteorologia/Exterior/Galeria/Humedad";
const String SensacionTermica_MQTT_Status = "Acantilados/Servicios/Meteorologia/Exterior/Galeria/SensacionTermica";
const String PuntoRocio_MQTT_Status = "Acantilados/Servicios/Meteorologia/Exterior/Galeria/PuntoRocio";
const String HumedadAbsoluta_MQTT_Status = "Acantilados/Servicios/Meteorologia/Exterior/Galeria/HumedadAbsoluta";
const String Percepcion_MQTT_Status = "Acantilados/Servicios/Meteorologia/Exterior/Galeria/PercepcionTermica";
const String urlHealthChecks = "http://hc-ping.com/9f3794ff-3052-4eea-8739-2d4b01a3c7ce";
const String urlDuckDNS = "http://www.duckdns.org/update/acantilados/f4be5f35-a9c4-4837-b709-f38afbfaaabd";
#endif

#ifdef Board_Temp_Humedad_Exterior
// Placa9
// #define Report_IP_DuckDNS
#define Report_HealthChecks
// #define NO_MQTT
const char *hostName = "ESP_TemperaturaExterior";
const int webServerPort = 80;
const float Calibracion = 0;
const String Temperatura_MQTT_Status = "Acantilados/Servicios/Meteorologia/Exterior/Parque/TemperaturaExterior";
const String Humedad_MQTT_Status = "Acantilados/Servicios/Meteorologia/Exterior/Parque/HumedadExterior";
const String SensacionTermica_MQTT_Status = "Acantilados/Servicios/Meteorologia/Exterior/Parque/SensacionTermica";
const String PuntoRocio_MQTT_Status = "Acantilados/Servicios/Meteorologia/Exterior/Parque/PuntoRocio";
const String HumedadAbsoluta_MQTT_Status = "Acantilados/Servicios/Meteorologia/Exterior/Parque/HumedadAbsoluta";
const String Percepcion_MQTT_Status = "Acantilados/Servicios/Meteorologia/Exterior/Parque/PercepcionTermica";
const String urlHealthChecks = "http://hc-ping.com/a0f6e21c-b127-410d-8851-b6182a344b69";
const String urlDuckDNS = "http://www.duckdns.org/update/acantilados/f4be5f35-a9c4-4837-b709-f38afbfaaabd";
#endif

#ifdef Board_4OutRelay_Emmanuel_Living
// Placa1
// #define Report_IP_DuckDNS
// #define Report_HealthChecks
#define NO_MQTT
const char *hostName = "Living";
const int webServerPort = 8083;
const String Relay1_Name = "Luz Living";
const String Relay1_MQTT_Command = "CasaEmma/Luz/Living/Comando";
const String Relay1_MQTT_Status = "CasaEmma/Luz/Living/Estado";
const String Relay2_Name = "Luz Dormitorio";
const String Relay2_MQTT_Command = "CasaEmma/Luz/Dormitorio/Comando";
const String Relay2_MQTT_Status = "CasaEmma/Luz/Dormitorio/Estado";
const String Relay3_Name = "Luz Dorm Superior";
const String Relay3_MQTT_Command = "CasaEmma/Luz/Superior/Comando";
const String Relay3_MQTT_Status = "CasaEmma/Luz/Superior/Estado";
const String Relay4_Name = "Luz Garage";
const String Relay4_MQTT_Command = "CasaEmma/Luz/Garage/Comando";
const String Relay4_MQTT_Status = "CasaEmma/Luz/Garage/Estado";
const String urlHealthChecks = "";
const String urlDuckDNS = "http://www.duckdns.org/update/casaemmadebo/f4be5f35-a9c4-4837-b709-f38afbfaaabd";
#endif

#ifdef Board_4OutRelay_Emmanuel_Lavadero
// Placa2
#define Report_IP_DuckDNS
// #define Report_HealthChecks
#define NO_MQTT
const char *hostName = "Lavadero";
const int webServerPort = 8084;
const String Relay1_Name = "Luz Cocina";
const String Relay1_MQTT_Command = "CasaEmma/Luz/Cocina/Comando";
const String Relay1_MQTT_Status = "CasaEmma/Luz/Cocina/Estado";
const String Relay2_Name = "Luz Lavadero";
const String Relay2_MQTT_Command = "CasaEmma/Luz/Lavadero/Comando";
const String Relay2_MQTT_Status = "CasaEmma/Luz/Lavadero/Estado";
const String Relay3_Name = "Luz Farolas";
const String Relay3_MQTT_Command = "CasaEmma/Luz/Farola/Comando";
const String Relay3_MQTT_Status = "CasaEmma/Luz/Farola/Estado";
const String Relay4_Name = "Bomba Agua";
const String Relay4_MQTT_Command = "CasaEmma/Servicios/BombaAgua/Comando";
const String Relay4_MQTT_Status = "CasaEmma/Servicios/BombaAgua/Estado";
const String urlHealthChecks = "";
const String urlDuckDNS = "http://www.duckdns.org/update/casaemmadebo/f4be5f35-a9c4-4837-b709-f38afbfaaabd";
#endif

#ifdef Board_4OutRelay_Valencia_Living
// Placa1
#define Report_IP_DuckDNS
// #define Report_HealthChecks
#define NO_MQTT
const char *hostName = "Living";
const int webServerPort = 80;
const String Relay1_Name = "Luz Living";
const String Relay1_MQTT_Command = "CasaValencia/Luz/Living/Comando";
const String Relay1_MQTT_Status = "CasaValencia/Luz/Living/Estado";
const String Relay2_Name = "Luz Frente";
const String Relay2_MQTT_Command = "CasaValencia/Luz/Frente/Comando";
const String Relay2_MQTT_Status = "CasaValencia/Luz/Frente/Estado";
const String Relay3_Name = "Luz Habitacion";
const String Relay3_MQTT_Command = "CasaValencia/Luz/Habitacion/Comando";
const String Relay3_MQTT_Status = "CasaValencia/Luz/Habitacion/Estado";
const String Relay4_Name = "Bomba Agua";
const String Relay4_MQTT_Command = "CasaValencia/Servicios/BombaAgua/Comando";
const String Relay4_MQTT_Status = "CasaValencia/Servicios/BombaAgua/Estado";
const String urlHealthChecks = "";
const String urlDuckDNS = "http://www.duckdns.org/update/valencia/f4be5f35-a9c4-4837-b709-f38afbfaaabd";
#endif

#ifdef Board_4OutRelay_Emmanuel_Living_ESP32
// Placa1
// #define Report_IP_DuckDNS
#define Report_HealthChecks
#define NO_MQTT
const char *hostName = "Living";
const int webServerPort = 8083;
const String Relay1_Name = "Luz Living";
const String Relay1_MQTT_Command = "CasaEmma/Luz/Living/Comando";
const String Relay1_MQTT_Status = "CasaEmma/Luz/Living/Estado";
const String Relay2_Name = "Luz Dormitorio";
const String Relay2_MQTT_Command = "CasaEmma/Luz/Dormitorio/Comando";
const String Relay2_MQTT_Status = "CasaEmma/Luz/Dormitorio/Estado";
const String Relay3_Name = "Luz Dorm Superior";
const String Relay3_MQTT_Command = "CasaEmma/Luz/Superior/Comando";
const String Relay3_MQTT_Status = "CasaEmma/Luz/Superior/Estado";
const String Relay4_Name = "Luz Garage";
const String Relay4_MQTT_Command = "CasaEmma/Luz/Garage/Comando";
const String Relay4_MQTT_Status = "CasaEmma/Luz/Garage/Estado";
const String urlHealthChecks = "http://hc-ping.com/4c523442-29aa-45bb-b8e4-a4217981e400";
const String urlDuckDNS = "http://www.duckdns.org/update/casaemmadebo2/f4be5f35-a9c4-4837-b709-f38afbfaaabd";
#endif