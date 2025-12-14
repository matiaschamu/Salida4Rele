#pragma once
#include <Arduino.h>

//#define debug

#if defined(Board_4OutRelay_Living) || defined(Board_4OutRelay_Living2) || defined(Board_4OutRelay_Galeria) || defined(Board_4OutRelay_Tablero) || defined(Board_4OutRelay_Garage)  || defined(Board_4OutRelay_1erPiso) || defined(Board_4OutRelay_Emmanuel_Living) || defined(Board_4OutRelay_Emmanuel_Lavadero) || defined(Board_4OutRelay_Valencia_Living)
#define Board_4OutRelay
#define ESP8266
#endif

#if defined(Board_Temp_Humedad_PB) || defined(Board_Temp_Humedad_Exterior)
#define Board_DHT22
#define DHT_PIN 3
#define ESP8266
#endif

#if defined(Board_Temp_Humedad_Galeria)
#define Board_AHT10
#define ESP8266
#endif

#if defined(Board_4OutRelay_Emmanuel_Living_ESP32)
#define Board_4OutRelay
//#define ESP32
#endif

#if defined(Board_DHT22)
#include <DHTesp.h>
#endif

#if defined(Board_AHT10)
#include <DHTesp.h>
#include <Adafruit_AHTX0.h>
#include <Wire.h>
#include <AHT10.h>
#endif

//**************************************************   GENERAL   ******************************************

extern const String Numero_Version;

//**************************************************   MQTT   ********************************************
extern const char *mqtt_server;
extern const uint16_t mqtt_port;
extern const char *mqtt_user;
extern const char *mqtt_pass;

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
extern const char *hostName;
extern const int webServerPort;
extern const float Calibracion;
extern const String Temperatura_MQTT_Status;
extern const String Humedad_MQTT_Status;
extern const String SensacionTermica_MQTT_Status;
extern const String PuntoRocio_MQTT_Status;
extern const String HumedadAbsoluta_MQTT_Status;
extern const String Percepcion_MQTT_Status;
extern const String urlHealthChecks;
extern const String urlDuckDNS;
#endif

#ifdef Board_Temp_Humedad_Galeria
// Placa8
// #define Report_IP_DuckDNS
#define Report_HealthChecks
// #define NO_MQTT
extern const char *hostName;
extern const int webServerPort;
extern const float Calibracion;
extern const String Temperatura_MQTT_Status;
extern const String Humedad_MQTT_Status;
extern const String SensacionTermica_MQTT_Status;
extern const String PuntoRocio_MQTT_Status;
extern const String HumedadAbsoluta_MQTT_Status;
extern const String Percepcion_MQTT_Status;
extern const String urlHealthChecks;
extern const String urlDuckDNS;
#endif

#ifdef Board_Temp_Humedad_Exterior
// Placa9
// #define Report_IP_DuckDNS
#define Report_HealthChecks
// #define NO_MQTT
extern const char *hostName;
extern const int webServerPort;
extern const float Calibracion;
extern const String Temperatura_MQTT_Status;
extern const String Humedad_MQTT_Status;
extern const String SensacionTermica_MQTT_Status;
extern const String PuntoRocio_MQTT_Status;
extern const String HumedadAbsoluta_MQTT_Status;
extern const String Percepcion_MQTT_Status;
extern const String urlHealthChecks;
extern const String urlDuckDNS;
#endif

#ifdef Board_4OutRelay_Emmanuel_Living
// Placa1
// #define Report_IP_DuckDNS
// #define Report_HealthChecks
#define NO_MQTT
extern const char *hostName;
extern const int webServerPort;
extern const  String Relay1_Name;
extern const  String Relay1_MQTT_Command;
extern const  String Relay1_MQTT_Status;
extern const  String Relay2_Name;
extern const  String Relay2_MQTT_Command;
extern const  String Relay2_MQTT_Status;
extern const  String Relay3_Name;
extern const  String Relay3_MQTT_Command;
extern const  String Relay3_MQTT_Status;
extern const  String Relay4_Name;
extern const  String Relay4_MQTT_Command;
extern const  String Relay4_MQTT_Status;
extern const  String urlHealthChecks;
extern const  String urlDuckDNS;
#endif

#ifdef Board_4OutRelay_Emmanuel_Lavadero
// Placa2
#define Report_IP_DuckDNS
// #define Report_HealthChecks
#define NO_MQTT
extern const char *hostName;
extern const int webServerPort;
extern const  String Relay1_Name;
extern const  String Relay1_MQTT_Command;
extern const  String Relay1_MQTT_Status;
extern const  String Relay2_Name;
extern const  String Relay2_MQTT_Command;
extern const  String Relay2_MQTT_Status;
extern const  String Relay3_Name;
extern const  String Relay3_MQTT_Command;
extern const  String Relay3_MQTT_Status;
extern const  String Relay4_Name;
extern const  String Relay4_MQTT_Command;
extern const  String Relay4_MQTT_Status;
extern const  String urlHealthChecks;
extern const  String urlDuckDNS;
#endif

#ifdef Board_4OutRelay_Valencia_Living
// Placa1
#define Report_IP_DuckDNS
// #define Report_HealthChecks
#define NO_MQTT
extern const char *hostName;
extern const int webServerPort;
extern const  String Relay1_Name;
extern const  String Relay1_MQTT_Command;
extern const  String Relay1_MQTT_Status;
extern const  String Relay2_Name;
extern const  String Relay2_MQTT_Command;
extern const  String Relay2_MQTT_Status;
extern const  String Relay3_Name;
extern const  String Relay3_MQTT_Command;
extern const  String Relay3_MQTT_Status;
extern const  String Relay4_Name;
extern const  String Relay4_MQTT_Command;
extern const  String Relay4_MQTT_Status;
extern const  String urlHealthChecks;
extern const  String urlDuckDNS;
#endif

#ifdef Board_4OutRelay_Emmanuel_Living_ESP32
// Placa1
// #define Report_IP_DuckDNS
#define Report_HealthChecks
#define NO_MQTT
extern const char *hostName;
extern const int webServerPort;
extern const  String Relay1_Name;
extern const  String Relay1_MQTT_Command;
extern const  String Relay1_MQTT_Status;
extern const  String Relay2_Name;
extern const  String Relay2_MQTT_Command;
extern const  String Relay2_MQTT_Status;
extern const  String Relay3_Name;
extern const  String Relay3_MQTT_Command;
extern const  String Relay3_MQTT_Status;
extern const  String Relay4_Name;
extern const  String Relay4_MQTT_Command;
extern const  String Relay4_MQTT_Status;
extern const  String urlHealthChecks;
extern const  String urlDuckDNS;
#endif