#include <Arduino.h>
//**************************************************   BOARDS   ********************************************

#ifdef Board_4OutRelay_Living
// Placa1
// #define Report_IP_DuckDNS
#define Report_HealthChecks
// #define NO_MQTT
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
String urlHealthChecks = "http://hc-ping.com/d5283654-660f-4c1a-b812-389f443233d9";
String urlDuckDNS = "http://www.duckdns.org/update/acantilados/f4be5f35-a9c4-4837-b709-f38afbfaaabd";
#endif

#ifdef Board_4OutRelay_Living2
// Placa2
// #define Report_IP_DuckDNS
#define Report_HealthChecks
// #define NO_MQTT
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
String urlHealthChecks = "http://hc-ping.com/1774013e-4433-4ee4-8229-5449a16e7ca2";
String urlDuckDNS = "http://www.duckdns.org/update/acantilados/f4be5f35-a9c4-4837-b709-f38afbfaaabd";
#endif

#ifdef Board_4OutRelay_Galeria
// Placa3
// #define Report_IP_DuckDNS
#define Report_HealthChecks
// #define NO_MQTT
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
String urlHealthChecks = "http://hc-ping.com/4390036e-80a9-4fee-99cc-42f6201f6336";
String urlDuckDNS = "http://www.duckdns.org/update/acantilados/f4be5f35-a9c4-4837-b709-f38afbfaaabd";
#endif

#ifdef Board_4OutRelay_Garage
// Placa4
// #define Report_IP_DuckDNS
#define Report_HealthChecks
// #define NO_MQTT
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
String urlHealthChecks = "http://hc-ping.com/74e92fc0-61bd-41ac-b751-be1c333c06af";
String urlDuckDNS = "http://www.duckdns.org/update/acantilados/f4be5f35-a9c4-4837-b709-f38afbfaaabd";
#endif

#ifdef Board_4OutRelay_Tablero
// Placa5
#define Report_IP_DuckDNS
#define Report_HealthChecks
// #define NO_MQTT
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
String urlHealthChecks = "http://hc-ping.com/6b750dde-84ed-424a-b708-7c869b8c5253";
String urlDuckDNS = "http://www.duckdns.org/update/acantilados/f4be5f35-a9c4-4837-b709-f38afbfaaabd";
#endif

#ifdef Board_4OutRelay_1erPiso
// Placa6
// #define Report_IP_DuckDNS
#define Report_HealthChecks
// #define NO_MQTT
const char *hostName = "ESP_1erPiso";
const int webServerPort = 80;
String Relay1_Name = "Luz 1er Piso 1";
String Relay1_MQTT_Command = "Acantilados/Luz/PlantaAlta/Comando";
String Relay1_MQTT_Status = "Acantilados/Luz/PlantaAlta/Estado";
String Relay2_Name = "Luz Reflector";
String Relay2_MQTT_Command = "Acantilados/Luz/Reflector/Comando";
String Relay2_MQTT_Status = "Acantilados/Luz/Reflector/Estado";
String Relay3_Name = "Resistencia Termo";
String Relay3_MQTT_Command = "Acantilados/Servicios/ResistenciaTermo/Comando";
String Relay3_MQTT_Status = "Acantilados/Servicios/ResistenciaTermo/Estado";
String Relay4_Name = "Luz 1er Piso 2";
String Relay4_MQTT_Command = "Acantilados/Luz/PlantaAlta2/Comando";;
String Relay4_MQTT_Status = "Acantilados/Luz/PlantaAlta2/Estado";
String urlHealthChecks = "http://hc-ping.com/fa586267-0c9e-4b02-bd6d-7d2ac39cc7ed";
String urlDuckDNS = "http://www.duckdns.org/update/acantilados/f4be5f35-a9c4-4837-b709-f38afbfaaabd";
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