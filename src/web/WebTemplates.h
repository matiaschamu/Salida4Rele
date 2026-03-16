#pragma once
#include <Arduino.h>

/**
 * Plantillas HTML y Estilos CSS almacenados en Flash (PROGMEM)
 * para optimizar el uso de memoria RAM en el ESP8266.
 */

const char WEB_STYLE[] PROGMEM = R"=====(
<style>body{font-family: "Helvetica Neue", Arial, sans-serif; background-color: #f9f9f9; color: #333; margin: 0; padding: 0;}
.container{max-width: 600px; margin: 0 auto; padding: 20px; background-color: #fff; border-radius: 5px; box-shadow: 0px 0px 5px rgba(0,0,0,0.2);}
h1{font-size: 36px; margin-bottom: 20px; color: #007bff; background-color: #f0f0f0; padding: 10px 20px; border-radius: 5px;}
p{font-size: 18px;margin: 10px 0;color: #666;}
.button{width:100px; text-align: center; display: inline-block;background-color: #007bff;color: #fff;padding: 12px 24px;font-size: 18px;text-decoration: none;margin: 5px;cursor: pointer;border: none;outline: none;transition: background-color 0.3s ease;border-radius: 5px;}
.button:hover{background-color: #004a99;}
.button2{width:100px; text-align: center; display: inline-block;background-color: #4CAF50;color: #fff;padding: 12px 24px;font-size: 18px;text-decoration: none;margin: 5px;cursor: pointer;border: none;outline: none;transition: background-color 0.3s ease;border-radius: 5px;}
.button2:hover{background-color: #2f6a31;}
.button3{width:100px; text-align: center; display: inline-block;background-color: #FF0000;color: #fff;padding: 12px 24px;font-size: 18px;text-decoration: none;margin: 5px;cursor: pointer;border: none;outline: none;transition: background-color 0.3s ease;border-radius: 5px;}
.button3:hover{background-color: #990000;}
.foot{font-size: 12px;background-color: #f0f0f0;border-radius: 5px; padding: 10px;}
.foot p{margin: 0; padding: 3px;}
.stats-box{background-color: #f8f9fa; border-left: 4px solid #007bff; padding: 10px; margin: 10px 0; font-size: 14px;}
.stats-title{font-weight: bold; color: #333; margin-bottom: 5px;}
</style>
)=====";

const char WEB_HEADER_START[] PROGMEM = R"=====(
<!DOCTYPE html><html>
<head><meta name="viewport" content="width=device-width, initial-scale=1">
<link rel="icon" href="data:,">
)=====";

const char WEB_BODY_START[] PROGMEM = R"=====(
</head>
<body><div class="container">
)=====";

const char WEB_FOOTER[] PROGMEM = R"=====(
</body></html>
)=====";
