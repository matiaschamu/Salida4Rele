#define Numero_Version "1.0.13"
// Define for debug information
//  #define debug

//**************************************************   DEFINE   ********************************************

// Define if use ESP8266
#ifndef ESP8266
#define ESP8266
#endif

// Define if use ESP32
// #ifndef ESP32
//  #define ESP32
// #endif

#if defined(Board_4OutRelay_Living) || defined(Board_4OutRelay_Living2) || defined(Board_4OutRelay_Comedor) || defined(Board_4OutRelay_Garage) || defined(Board_4OutRelay_Tablero) || defined(Board_4OutRelay_1erPiso) || defined(Board_4OutRelay_Emmanuel_Living) || defined(Board_4OutRelay_Emmanuel_Lavadero)
#define Board_4OutRelay
#endif

#if defined(Board_Temp_Humedad_PB) || defined(Board_Temp_Humedad_Exterior)
#define Board_DHT22
#define DHT_PIN 3
#endif

#if defined(Board_Temp_Humedad_Galeria)
#define Board_AHT10
#endif

//**************************************************   LIBRERIAS   ******************************************

#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ArduinoOTA.h>
#ifdef ESP32
#include <WiFi.h>
#endif
#ifdef ESP8266
#include <ESP8266HTTPClient.h>
#endif
#include <PubSubClient.h>

#if defined(Board_DHT22)
#include <DHTesp.h>
#endif

#if defined(Board_AHT10)
#include <DHTesp.h>
#include <Adafruit_AHTX0.h>
#include <Wire.h>
#include <AHT10.h>
#endif

//**************************************************   DECLARACIONES   **************************************
void WIFI_Setup();
void InitOTA();
void MQTT_Setup();
void MQTT_Callback(char *, byte *, unsigned int);
void MQTT_Reconnect();
void MQTT_SubscribeToTopic(String);
String MQTT_Status();
void WEBSERVER_Loop();
void HTTP_Get(String);
void DuckDNS_Loop();
void HealthChecks_Loop();
void SerialPrint();
void SerialPrint(String);
void SerialPrint(char);
void SerialPrint(int);
String convertToString(char *, int);
String convertToString(byte *, int);

#ifdef Board_4OutRelay
void RELAY_Loop();
#endif

#if defined(Board_DHT22) || defined(Board_AHT10)
void TEMPERATURA_loop(float &temperature, float &humidity, float &hIndex, float &dPoint, float &AbsoluteH, byte &perception);
#endif


class DataAnalisis
{
    public:
    float value = 0, max = 0, min = 0, max1h = 0, min1h = 0, max6h = 0, min6h = 0, max12h = 0, min12h = 0 , trend1h=0 , trend6h=0, trend12h=0 ;
    String timeMax = "", timeMin = "";
    

    void SetValue(float value);
   
};
