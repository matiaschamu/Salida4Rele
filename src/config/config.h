#pragma once
#include <Arduino.h>

//#define DEBUG
//#define NO_MQTT // Descomentar esta linea para deshabilitar MQTT totalmente y probar solo WiFi/Web

#if defined(BOARD_4OUT_RELAY_LIVING) || defined(BOARD_4OUT_RELAY_LIVING2) || defined(BOARD_4OUT_RELAY_GALERIA) || defined(BOARD_4OUT_RELAY_TABLERO) || defined(BOARD_4OUT_RELAY_GARAGE)  || defined(BOARD_4OUT_RELAY_1ERPISO) || defined(BOARD_4OUT_RELAY_EMMANUEL_LIVING) || defined(BOARD_4OUT_RELAY_EMMANUEL_LAVADERO) || defined(BOARD_4OUT_RELAY_VALENCIA_LIVING)
#define BOARD_4OUT_RELAY
#define ESP8266
#endif

#if defined(BOARD_TEMP_HUMEDAD_PB) || defined(BOARD_TEMP_HUMEDAD_EXTERIOR)
#define BOARD_DHT22
#define DHT_PIN 3
#define ESP8266
#endif

#if defined(BOARD_TEMP_HUMEDAD_GALERIA)
#define BOARD_AHT10
#define ESP8266
#endif

#if defined(BOARD_4OUT_RELAY_EMMANUEL_LIVING_ESP32)
#define BOARD_4OUT_RELAY
//#define ESP32
#endif

#if defined(BOARD_DHT22)
#include <DHTesp.h>
#endif

#if defined(BOARD_AHT10)
#include <DHTesp.h>
#include <Adafruit_AHTX0.h>
#include <Wire.h>
#include <AHT10.h>
#endif

//**************************************************   GENERAL   ******************************************

extern const String versionNumber;

//**************************************************   MQTT   ********************************************
extern const char *mqttServer;
extern const uint16_t mqttPort;
extern const char *mqttUser;
extern const char *mqttPass;

//**************************************************   WIFI   ********************************************
#if defined(BOARD_4OUT_RELAY_EMMANUEL_LIVING) || defined(BOARD_4OUT_RELAY_EMMANUEL_LAVADERO) || defined(BOARD_4OUT_RELAY_EMMANUEL_LIVING_ESP32)
extern const char *ssid;
extern const char *password;
#elif defined(BOARD_4OUT_RELAY_VALENCIA_LIVING)
extern const char *ssid;
extern const char *password;
#else
extern const char *ssid;
extern const char *password;
#endif

//**************************************************   BOARDS   ********************************************

#ifdef BOARD_4OUT_RELAY_LIVING
// Placa1
// #define REPORT_IP_DUCKDNS
#define REPORT_HEALTH_CHECKS
// #define NO_MQTT
extern const char *hostName;
extern const int webServerPort;
extern const String relay1Name;
extern const String relay1MqttCommand;
extern const String relay1MqttStatus;
extern const String relay2Name;
extern const String relay2MqttCommand;
extern const String relay2MqttStatus;
extern const String relay3Name;
extern const String relay3MqttCommand;
extern const String relay3MqttStatus;
extern const String relay4Name;
extern const String relay4MqttCommand;
extern const String relay4MqttStatus;
extern const String urlHealthChecks;
extern const String urlDuckDns;
#endif

#ifdef BOARD_4OUT_RELAY_LIVING2
// Placa2
// #define REPORT_IP_DUCKDNS
#define REPORT_HEALTH_CHECKS
// #define NO_MQTT
extern const char *hostName;
extern const int webServerPort;
extern const String relay1Name;
extern const String relay1MqttCommand;
extern const String relay1MqttStatus;
extern const String relay2Name;
extern const String relay2MqttCommand;
extern const String relay2MqttStatus;
extern const String relay3Name;
extern const String relay3MqttCommand;
extern const String relay3MqttStatus;
extern const String relay4Name;
extern const String relay4MqttCommand;
extern const String relay4MqttStatus;
extern const String urlHealthChecks;
extern const String urlDuckDns;
#endif

#ifdef BOARD_4OUT_RELAY_GALERIA
// Placa3
// #define REPORT_IP_DUCKDNS
#define REPORT_HEALTH_CHECKS
// #define NO_MQTT
extern const char *hostName;
extern const int webServerPort;
extern const String relay1Name;
extern const String relay1MqttCommand;
extern const String relay1MqttStatus;
extern const String relay2Name;
extern const String relay2MqttCommand;
extern const String relay2MqttStatus;
extern const String relay3Name;
extern const String relay3MqttCommand;
extern const String relay3MqttStatus;
extern const String relay4Name;
extern const String relay4MqttCommand;
extern const String relay4MqttStatus;
extern const String urlHealthChecks;
extern const String urlDuckDns;
#endif

#ifdef BOARD_4OUT_RELAY_GARAGE
// Placa4
// #define REPORT_IP_DUCKDNS
#define REPORT_HEALTH_CHECKS
// #define NO_MQTT
extern const char *hostName;
extern const int webServerPort;
extern const String relay1Name;
extern const String relay1MqttCommand;
extern const String relay1MqttStatus;
extern const String relay2Name;
extern const String relay2MqttCommand;
extern const String relay2MqttStatus;
extern const String relay3Name;
extern const String relay3MqttCommand;
extern const String relay3MqttStatus;
extern const String relay4Name;
extern const String relay4MqttCommand;
extern const String relay4MqttStatus;
extern const String urlHealthChecks;
extern const String urlDuckDns;
#endif

#ifdef BOARD_4OUT_RELAY_TABLERO
// Placa5
#define REPORT_IP_DUCKDNS
#define REPORT_HEALTH_CHECKS
// #define NO_MQTT
extern const char *hostName;
extern const int webServerPort;
extern const String relay1Name;
extern const String relay1MqttCommand;
extern const String relay1MqttStatus;
extern const String relay2Name;
extern const String relay2MqttCommand;
extern const String relay2MqttStatus;
extern const String relay3Name;
extern const String relay3MqttCommand;
extern const String relay3MqttStatus;
extern const String relay4Name;
extern const String relay4MqttCommand;
extern const String relay4MqttStatus;
extern const String urlHealthChecks;
extern const String urlDuckDns;
#endif

#ifdef BOARD_4OUT_RELAY_1ERPISO
// Placa6
// #define REPORT_IP_DUCKDNS
#define REPORT_HEALTH_CHECKS
// #define NO_MQTT
extern const char *hostName;
extern const int webServerPort;
extern const String relay1Name;
extern const String relay1MqttCommand;
extern const String relay1MqttStatus;
extern const String relay2Name;
extern const String relay2MqttCommand;
extern const String relay2MqttStatus;
extern const String relay3Name;
extern const String relay3MqttCommand;
extern const String relay3MqttStatus;
extern const String relay4Name;
extern const String relay4MqttCommand;
extern const String relay4MqttStatus;
extern const String urlHealthChecks;
extern const String urlDuckDns;
#endif

#ifdef BOARD_TEMP_HUMEDAD_PB
// Placa7
// #define REPORT_IP_DUCKDNS
#define REPORT_HEALTH_CHECKS
// #define NO_MQTT
extern const char *hostName;
extern const int webServerPort;
extern const float calibrationOffset;
extern const String temperatureMqttStatus;
extern const String humidityMqttStatus;
extern const String heatIndexMqttStatus;
extern const String dewPointMqttStatus;
extern const String absoluteHumidityMqttStatus;
extern const String perceptionMqttStatus;
extern const String urlHealthChecks;
extern const String urlDuckDns;
#endif

#ifdef BOARD_TEMP_HUMEDAD_GALERIA
// Placa8
// #define REPORT_IP_DUCKDNS
#define REPORT_HEALTH_CHECKS
// #define NO_MQTT
extern const char *hostName;
extern const int webServerPort;
extern const float calibrationOffset;
extern const String temperatureMqttStatus;
extern const String humidityMqttStatus;
extern const String heatIndexMqttStatus;
extern const String dewPointMqttStatus;
extern const String absoluteHumidityMqttStatus;
extern const String perceptionMqttStatus;
extern const String urlHealthChecks;
extern const String urlDuckDns;
#endif

#ifdef BOARD_TEMP_HUMEDAD_EXTERIOR
// Placa9
// #define REPORT_IP_DUCKDNS
#define REPORT_HEALTH_CHECKS
// #define NO_MQTT
extern const char *hostName;
extern const int webServerPort;
extern const float calibrationOffset;
extern const String temperatureMqttStatus;
extern const String humidityMqttStatus;
extern const String heatIndexMqttStatus;
extern const String dewPointMqttStatus;
extern const String absoluteHumidityMqttStatus;
extern const String perceptionMqttStatus;
extern const String urlHealthChecks;
extern const String urlDuckDns;
#endif

#ifdef BOARD_4OUT_RELAY_EMMANUEL_LIVING
// Placa1
// #define REPORT_IP_DUCKDNS
// #define REPORT_HEALTH_CHECKS
#define NO_MQTT
extern const char *hostName;
extern const int webServerPort;
extern const  String relay1Name;
extern const  String relay1MqttCommand;
extern const  String relay1MqttStatus;
extern const  String relay2Name;
extern const  String relay2MqttCommand;
extern const  String relay2MqttStatus;
extern const  String relay3Name;
extern const  String relay3MqttCommand;
extern const  String relay3MqttStatus;
extern const  String relay4Name;
extern const  String relay4MqttCommand;
extern const  String relay4MqttStatus;
extern const  String urlHealthChecks;
extern const  String urlDuckDns;
#endif

#ifdef BOARD_4OUT_RELAY_EMMANUEL_LAVADERO
// Placa2
#define REPORT_IP_DUCKDNS
// #define REPORT_HEALTH_CHECKS
#define NO_MQTT
extern const char *hostName;
extern const int webServerPort;
extern const  String relay1Name;
extern const  String relay1MqttCommand;
extern const  String relay1MqttStatus;
extern const  String relay2Name;
extern const  String relay2MqttCommand;
extern const  String relay2MqttStatus;
extern const  String relay3Name;
extern const  String relay3MqttCommand;
extern const  String relay3MqttStatus;
extern const  String relay4Name;
extern const  String relay4MqttCommand;
extern const  String relay4MqttStatus;
extern const  String urlHealthChecks;
extern const  String urlDuckDns;
#endif

#ifdef BOARD_4OUT_RELAY_VALENCIA_LIVING
// Placa1
#define REPORT_IP_DUCKDNS
// #define REPORT_HEALTH_CHECKS
#define NO_MQTT
extern const char *hostName;
extern const int webServerPort;
extern const  String relay1Name;
extern const  String relay1MqttCommand;
extern const  String relay1MqttStatus;
extern const  String relay2Name;
extern const  String relay2MqttCommand;
extern const  String relay2MqttStatus;
extern const  String relay3Name;
extern const  String relay3MqttCommand;
extern const  String relay3MqttStatus;
extern const  String relay4Name;
extern const  String relay4MqttCommand;
extern const  String relay4MqttStatus;
extern const  String urlHealthChecks;
extern const  String urlDuckDns;
#endif

#ifdef BOARD_4OUT_RELAY_EMMANUEL_LIVING_ESP32
// Placa1
// #define REPORT_IP_DUCKDNS
#define REPORT_HEALTH_CHECKS
#define NO_MQTT
extern const char *hostName;
extern const int webServerPort;
extern const  String relay1Name;
extern const  String relay1MqttCommand;
extern const  String relay1MqttStatus;
extern const  String relay2Name;
extern const  String relay2MqttCommand;
extern const  String relay2MqttStatus;
extern const  String relay3Name;
extern const  String relay3MqttCommand;
extern const  String relay3MqttStatus;
extern const  String relay4Name;
extern const  String relay4MqttCommand;
extern const  String relay4MqttStatus;
extern const  String urlHealthChecks;
extern const  String urlDuckDns;
#endif

