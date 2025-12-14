#pragma once

// Define for debug information


//**************************************************   DEFINE   ********************************************

// Define if use ESP8266
//#ifndef ESP8266
//#define ESP8266
//#endif

// Define if use ESP32
//#ifndef ESP32
//#define ESP32
//#endif



//**************************************************   LIBRERIAS   ******************************************

#include <Arduino.h>

#include <ArduinoOTA.h>
#ifdef ESP32
#include <WiFi.h>
#include <HTTPClient.h>
#endif
#ifdef ESP8266
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#endif
#include <PubSubClient.h>



//**************************************************   DECLARACIONES   **************************************
extern bool mqttEnabled;

//#if !defined(NO_MQTT)
//void MQTT_Setup();
//void MQTT_Callback(char *, byte *, unsigned int);
//void MQTT_Reconnect();
//void MQTT_SubscribeToTopic(String);
//String MQTT_Status();
//#endif
//void WEBSERVER_Loop();
void HTTP_Get(String);
void DuckDNS_Loop();
void HealthChecks_Loop();


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
