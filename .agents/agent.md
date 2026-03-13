---
name: Salida4Rele Project Agent
description: Agente para gestionar estándares de código y compilación del proyecto de relés IoT
version: 1.0.0
rules:
  - comentarios
  - estandarizacion
  - compilacion
---

# Salida4Rele Project Agent

Agente de desarrollo para el proyecto **Salida4Rele** - Sistema IoT de control de relés distribuidos con sensores de temperatura y humedad.

## Reglas Activas

### 1. Comentarios de Funciones
**Trigger:** `always_on`

Siempre que se crea una función, agregar en la parte superior antes de la definición un comentario que detalle:
- Resumen de lo que hace la función
- Descripción de cada parámetro
- Tipo de retorno (si aplica)

**Ejemplo:**
```cpp
// Obtiene el estado actual de la línea MQTT
// Parameters:
//   - topic: tópico MQTT a consultar
//   - payload: contenido del mensaje
void handleMQTT(String topic, String payload)
{
  // ...
}
```

### 2. Estandarización de Código
**Trigger:** `always_on`

#### Estructura de Llaves
- Corchetes de apertura y cierre alineados
- Corchete de cierre en línea nueva

#### Nomenclatura
| Tipo | Estilo | Ejemplo |
|------|--------|---------|
| Funciones | camelCase | `handleMQTTMessage()` |
| Variables | camelCase | `relayPin`, `sensorValue` |
| Constantes/Macros | SCREAMING_SNAKE_CASE | `BOARD_4OUT_RELAY_LIVING` |
| Archivos/Includes | PascalCase | `Config.h`, `Utils.h` |
| Variables Locales | _camelCase (con prefijo _) | `_tempValue`, `_counter` |

#### Tabulación
- Directivas del preprocesador deben estar tabuladas igual que las instrucciones adyacentes
- Mantener coherencia visual en toda la estructura de código

#### Nombres de Archivos
- Revisar y estandarizar todos los nombres para formato profesional
- Seguir convención PascalCase para archivos de código

**Ejemplo correcto:**
```cpp
#include "Config.h"
#include "Utils.h"

#define BOARD_4OUT_RELAY_LIVING

void setupRelays()
{
  int _relayCount = 4;
  // ...
}
```

### 3. Revisión de Compilación
**Trigger:** `always_on`

Antes de proponer cualquier cambio de código:
1. Verificar que el código compile correctamente
2. No introducir errores de compilación
3. Validar que todas las dependencias estén disponibles
4. Revisar compatibilidad con la plataforma destino (ESP8266/ESP32)

## Configuración de Plataformas

### Plataformas Soportadas
- **ESP8266** (esp01_1m): Múltiples nodos con relés de 4 salidas
- **ESP32** (esp32dev): Nodos avanzados con soporte extendido

### Dispositivos Configurados
- Living Room (192.168.1.11)
- Living Room 2 (192.168.1.12)
- Galería (192.168.1.13)
- Garaje (192.168.1.14)
- Tablero (192.168.1.15)
- 1er Piso (192.168.1.16)
- Sensor Temp/Humedad PB (192.168.1.17)
- Sensor Temp/Humedad Galería (192.168.1.18)
- Sensor Temp/Humedad Exterior (192.168.1.19)
- Emmanuel Living (192.168.1.62)
- Emmanuel Lavadero (192.168.1.63)
- Valencia Living (192.168.251.10)
- Emmanuel Living ESP32 (192.168.1.62)

## Dependencias Comunes

```
knolleary/PubSubClient@^2.8
beegee-tokyo/DHT sensor library for ESPx@^1.18
adafruit/Adafruit AHTX0@^2.0.3
enjoyneering/AHT10@^1.1.0
fbiego/ESP32Time@^2.0.0
```

## Checklist para Cambios de Código

- [ ] ¿El código sigue las reglas de nomenclatura?
- [ ] ¿Las funciones tienen comentarios descriptivos?
- [ ] ¿Las llaves están correctamente alineadas?
- [ ] ¿El código compila sin errores?
- [ ] ¿Se utilizan prefijos _ en variables locales?
- [ ] ¿Los nombres de archivos están en PascalCase?
- [ ] ¿Las constantes están en SCREAMING_SNAKE_CASE?
