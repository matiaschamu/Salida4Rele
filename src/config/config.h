#pragma once
#include <Arduino.h>

#define debug
extern const String Numero_Version;

//**************************************************   WIFI   ********************************************
#if defined(Board_4OutRelay_Emmanuel_Living) || defined(Board_4OutRelay_Emmanuel_Lavadero) || defined(Board_4OutRelay_Emmanuel_Living_ESP32)
extern const char *ssid;
extern const char *password;
#elif defined(Board_4OutRelay_Valencia_Living)
extern const char *ssid;
extern const char *password;
#else
extern const char *ssid;
extern const char *password;
#endif

//**************************************************   BOARDS   ********************************************

#ifdef Board_4OutRelay_Living
// Placa1
// #define Report_IP_DuckDNS
#define Report_HealthChecks
// #define NO_MQTT
extern const char *hostName;
extern const int webServerPort;
extern const String Relay1_Name;
extern const String Relay1_MQTT_Command;
extern const String Relay1_MQTT_Status;
extern const String Relay2_Name;
extern const String Relay2_MQTT_Command;
extern const String Relay2_MQTT_Status;
extern const String Relay3_Name;
extern const String Relay3_MQTT_Command;
extern const String Relay3_MQTT_Status;
extern const String Relay4_Name;
extern const String Relay4_MQTT_Command;
extern const String Relay4_MQTT_Status;
extern const String urlHealthChecks;
extern const String urlDuckDNS;
#endif

#ifdef Board_4OutRelay_Living2
// Placa2
// #define Report_IP_DuckDNS
#define Report_HealthChecks
// #define NO_MQTT
extern const char *hostName;
extern const int webServerPort;
extern const String Relay1_Name;
extern const String Relay1_MQTT_Command;
extern const String Relay1_MQTT_Status;
extern const String Relay2_Name;
extern const String Relay2_MQTT_Command;
extern const String Relay2_MQTT_Status;
extern const String Relay3_Name;
extern const String Relay3_MQTT_Command;
extern const String Relay3_MQTT_Status;
extern const String Relay4_Name;
extern const String Relay4_MQTT_Command;
extern const String Relay4_MQTT_Status;
extern const String urlHealthChecks;
extern const String urlDuckDNS;
#endif

#ifdef Board_4OutRelay_Galeria
// Placa3
// #define Report_IP_DuckDNS
#define Report_HealthChecks
// #define NO_MQTT
extern const char *hostName;
extern const int webServerPort;
extern const String Relay1_Name;
extern const String Relay1_MQTT_Command;
extern const String Relay1_MQTT_Status;
extern const String Relay2_Name;
extern const String Relay2_MQTT_Command;
extern const String Relay2_MQTT_Status;
extern const String Relay3_Name;
extern const String Relay3_MQTT_Command;
extern const String Relay3_MQTT_Status;
extern const String Relay4_Name;
extern const String Relay4_MQTT_Command;
extern const String Relay4_MQTT_Status;
extern const String urlHealthChecks;
extern const String urlDuckDNS;
#endif

#ifdef Board_4OutRelay_Garage
// Placa4
// #define Report_IP_DuckDNS
#define Report_HealthChecks
// #define NO_MQTT
extern const char *hostName;
extern const int webServerPort;
extern const String Relay1_Name;
extern const String Relay1_MQTT_Command;
extern const String Relay1_MQTT_Status;
extern const String Relay2_Name;
extern const String Relay2_MQTT_Command;
extern const String Relay2_MQTT_Status;
extern const String Relay3_Name;
extern const String Relay3_MQTT_Command;
extern const String Relay3_MQTT_Status;
extern const String Relay4_Name;
extern const String Relay4_MQTT_Command;
extern const String Relay4_MQTT_Status;
extern const String urlHealthChecks;
extern const String urlDuckDNS;
#endif

#ifdef Board_4OutRelay_Tablero
// Placa5
#define Report_IP_DuckDNS
#define Report_HealthChecks
// #define NO_MQTT
extern const char *hostName;
extern const int webServerPort;
extern const String Relay1_Name;
extern const String Relay1_MQTT_Command;
extern const String Relay1_MQTT_Status;
extern const String Relay2_Name;
extern const String Relay2_MQTT_Command;
extern const String Relay2_MQTT_Status;
extern const String Relay3_Name;
extern const String Relay3_MQTT_Command;
extern const String Relay3_MQTT_Status;
extern const String Relay4_Name;
extern const String Relay4_MQTT_Command;
extern const String Relay4_MQTT_Status;
extern const String urlHealthChecks;
extern const String urlDuckDNS;
#endif

#ifdef Board_4OutRelay_1erPiso
// Placa6
// #define Report_IP_DuckDNS
#define Report_HealthChecks
// #define NO_MQTT
extern const char *hostName;
extern const int webServerPort;
extern const String Relay1_Name;
extern const String Relay1_MQTT_Command;
extern const String Relay1_MQTT_Status;
extern const String Relay2_Name;
extern const String Relay2_MQTT_Command;
extern const String Relay2_MQTT_Status;
extern const String Relay3_Name;
extern const String Relay3_MQTT_Command;
extern const String Relay3_MQTT_Status;
extern const String Relay4_Name;
extern const String Relay4_MQTT_Command;
extern const String Relay4_MQTT_Status;
extern const String urlHealthChecks;
extern const String urlDuckDNS;
#endif

#ifdef Board_Temp_Humedad_PB
// Placa7
// #define Report_IP_DuckDNS
#define Report_HealthChecks
// #define NO_MQTT
const char *hostName = "ESP_TemperaturaPB";
const int webServerPort = 80;
float Calibracion = 0;
String Temperatura_MQTT_Status = "Acantilados/Servicios/Meteorologia/Interior/Living/Temperatura";
String Humedad_MQTT_Status = "Acantilados/Servicios/Meteorologia/Interior/Living/Humedad";
String SensacionTermica_MQTT_Status = "Acantilados/Servicios/Meteorologia/Interior/Living/SensacionTermica";
String PuntoRocio_MQTT_Status = "Acantilados/Servicios/Meteorologia/Interior/Living/PuntoRocio";
String HumedadAbsoluta_MQTT_Status = "Acantilados/Servicios/Meteorologia/Interior/Living/HumedadAbsoluta";
String Percepcion_MQTT_Status = "Acantilados/Servicios/Meteorologia/Interior/Living/PercepcionTermica";
String urlHealthChecks = "http://hc-ping.com/78ac3681-519e-4fc8-8aef-e975f8781420";
String urlDuckDNS = "http://www.duckdns.org/update/acantilados/f4be5f35-a9c4-4837-b709-f38afbfaaabd";
#endif

#ifdef Board_Temp_Humedad_Galeria
// Placa8
// #define Report_IP_DuckDNS
#define Report_HealthChecks
// #define NO_MQTT
const char *hostName = "ESP_TemperaturaGaleria";
const int webServerPort = 80;
float Calibracion = 0;
String Temperatura_MQTT_Status = "Acantilados/Servicios/Meteorologia/Exterior/Galeria/Temperatura";
String Humedad_MQTT_Status = "Acantilados/Servicios/Meteorologia/Exterior/Galeria/Humedad";
String SensacionTermica_MQTT_Status = "Acantilados/Servicios/Meteorologia/Exterior/Galeria/SensacionTermica";
String PuntoRocio_MQTT_Status = "Acantilados/Servicios/Meteorologia/Exterior/Galeria/PuntoRocio";
String HumedadAbsoluta_MQTT_Status = "Acantilados/Servicios/Meteorologia/Exterior/Galeria/HumedadAbsoluta";
String Percepcion_MQTT_Status = "Acantilados/Servicios/Meteorologia/Exterior/Galeria/PercepcionTermica";
String urlHealthChecks = "http://hc-ping.com/9f3794ff-3052-4eea-8739-2d4b01a3c7ce";
String urlDuckDNS = "http://www.duckdns.org/update/acantilados/f4be5f35-a9c4-4837-b709-f38afbfaaabd";
#endif

#ifdef Board_Temp_Humedad_Exterior
// Placa9
// #define Report_IP_DuckDNS
#define Report_HealthChecks
// #define NO_MQTT
const char *hostName = "ESP_TemperaturaExterior";
const int webServerPort = 80;
float Calibracion = 0;
String Temperatura_MQTT_Status = "Acantilados/Servicios/Meteorologia/Exterior/Parque/TemperaturaExterior";
String Humedad_MQTT_Status = "Acantilados/Servicios/Meteorologia/Exterior/Parque/HumedadExterior";
String SensacionTermica_MQTT_Status = "Acantilados/Servicios/Meteorologia/Exterior/Parque/SensacionTermica";
String PuntoRocio_MQTT_Status = "Acantilados/Servicios/Meteorologia/Exterior/Parque/PuntoRocio";
String HumedadAbsoluta_MQTT_Status = "Acantilados/Servicios/Meteorologia/Exterior/Parque/HumedadAbsoluta";
String Percepcion_MQTT_Status = "Acantilados/Servicios/Meteorologia/Exterior/Parque/PercepcionTermica";
String urlHealthChecks = "http://hc-ping.com/a0f6e21c-b127-410d-8851-b6182a344b69";
String urlDuckDNS = "http://www.duckdns.org/update/acantilados/f4be5f35-a9c4-4837-b709-f38afbfaaabd";
#endif

#ifdef Board_4OutRelay_Emmanuel_Living
// Placa1
// #define Report_IP_DuckDNS
// #define Report_HealthChecks
#define NO_MQTT
const char *hostName = "Living";
const int webServerPort = 8083;
String Relay1_Name = "Luz Living";
String Relay1_MQTT_Command = "CasaEmma/Luz/Living/Comando";
String Relay1_MQTT_Status = "CasaEmma/Luz/Living/Estado";
String Relay2_Name = "Luz Dormitorio";
String Relay2_MQTT_Command = "CasaEmma/Luz/Dormitorio/Comando";
String Relay2_MQTT_Status = "CasaEmma/Luz/Dormitorio/Estado";
String Relay3_Name = "Luz Dorm Superior";
String Relay3_MQTT_Command = "CasaEmma/Luz/Superior/Comando";
String Relay3_MQTT_Status = "CasaEmma/Luz/Superior/Estado";
String Relay4_Name = "Luz Garage";
String Relay4_MQTT_Command = "CasaEmma/Luz/Garage/Comando";
String Relay4_MQTT_Status = "CasaEmma/Luz/Garage/Estado";
String urlHealthChecks = "";
String urlDuckDNS = "http://www.duckdns.org/update/casaemmadebo/f4be5f35-a9c4-4837-b709-f38afbfaaabd";
#endif

#ifdef Board_4OutRelay_Emmanuel_Lavadero
// Placa2
#define Report_IP_DuckDNS
// #define Report_HealthChecks
#define NO_MQTT
const char *hostName = "Lavadero";
const int webServerPort = 8084;
String Relay1_Name = "Luz Cocina";
String Relay1_MQTT_Command = "CasaEmma/Luz/Cocina/Comando";
String Relay1_MQTT_Status = "CasaEmma/Luz/Cocina/Estado";
String Relay2_Name = "Luz Lavadero";
String Relay2_MQTT_Command = "CasaEmma/Luz/Lavadero/Comando";
String Relay2_MQTT_Status = "CasaEmma/Luz/Lavadero/Estado";
String Relay3_Name = "Luz Farolas";
String Relay3_MQTT_Command = "CasaEmma/Luz/Farola/Comando";
String Relay3_MQTT_Status = "CasaEmma/Luz/Farola/Estado";
String Relay4_Name = "Bomba Agua";
String Relay4_MQTT_Command = "CasaEmma/Servicios/BombaAgua/Comando";
String Relay4_MQTT_Status = "CasaEmma/Servicios/BombaAgua/Estado";
String urlHealthChecks = "";
String urlDuckDNS = "http://www.duckdns.org/update/casaemmadebo/f4be5f35-a9c4-4837-b709-f38afbfaaabd";
#endif

#ifdef Board_4OutRelay_Valencia_Living
// Placa1
#define Report_IP_DuckDNS
// #define Report_HealthChecks
#define NO_MQTT
const char *hostName = "Living";
const int webServerPort = 80;
String Relay1_Name = "Luz Living";
String Relay1_MQTT_Command = "CasaValencia/Luz/Living/Comando";
String Relay1_MQTT_Status = "CasaValencia/Luz/Living/Estado";
String Relay2_Name = "Luz Frente";
String Relay2_MQTT_Command = "CasaValencia/Luz/Frente/Comando";
String Relay2_MQTT_Status = "CasaValencia/Luz/Frente/Estado";
String Relay3_Name = "Luz Habitacion";
String Relay3_MQTT_Command = "CasaValencia/Luz/Habitacion/Comando";
String Relay3_MQTT_Status = "CasaValencia/Luz/Habitacion/Estado";
String Relay4_Name = "Bomba Agua";
String Relay4_MQTT_Command = "CasaValencia/Servicios/BombaAgua/Comando";
String Relay4_MQTT_Status = "CasaValencia/Servicios/BombaAgua/Estado";
String urlHealthChecks = "";
String urlDuckDNS = "http://www.duckdns.org/update/valencia/f4be5f35-a9c4-4837-b709-f38afbfaaabd";
#endif

#ifdef Board_4OutRelay_Emmanuel_Living_ESP32
// Placa1
// #define Report_IP_DuckDNS
#define Report_HealthChecks
#define NO_MQTT
const char *hostName = "Living";
const int webServerPort = 8083;
String Relay1_Name = "Luz Living";
String Relay1_MQTT_Command = "CasaEmma/Luz/Living/Comando";
String Relay1_MQTT_Status = "CasaEmma/Luz/Living/Estado";
String Relay2_Name = "Luz Dormitorio";
String Relay2_MQTT_Command = "CasaEmma/Luz/Dormitorio/Comando";
String Relay2_MQTT_Status = "CasaEmma/Luz/Dormitorio/Estado";
String Relay3_Name = "Luz Dorm Superior";
String Relay3_MQTT_Command = "CasaEmma/Luz/Superior/Comando";
String Relay3_MQTT_Status = "CasaEmma/Luz/Superior/Estado";
String Relay4_Name = "Luz Garage";
String Relay4_MQTT_Command = "CasaEmma/Luz/Garage/Comando";
String Relay4_MQTT_Status = "CasaEmma/Luz/Garage/Estado";
String urlHealthChecks = "http://hc-ping.com/4c523442-29aa-45bb-b8e4-a4217981e400";
String urlDuckDNS = "http://www.duckdns.org/update/casaemmadebo2/f4be5f35-a9c4-4837-b709-f38afbfaaabd";
#endif