#include "Utils.h"
#ifdef ESP8266
#include <ESP8266WiFi.h>
#else
#include <WiFi.h>
#endif

/**
 * Inicializa la EEPROM con el tamaño necesario para el contador de reinicios.
 * Debe llamarse en setup() antes de usar getResetCount() o incrementResetCount().
 */
void initEeprom()
{
    EEPROM.begin(EEPROM_SIZE);
}

/**
 * Lee el contador de reinicios almacenado en EEPROM.
 * @return Número de reinicios acumulados (uint32_t).
 */
uint32_t getResetCount()
{
    uint32_t _count = 0;
    EEPROM.get(EEPROM_RESET_COUNT_ADDR, _count);
    return _count;
}

/**
 * Incrementa en 1 el contador de reinicios y lo persiste en EEPROM.
 */
void incrementResetCount()
{
    uint32_t _count = getResetCount();
    _count++;
    EEPROM.put(EEPROM_RESET_COUNT_ADDR, _count);
    EEPROM.commit();
}

static uint64_t _totalUptimeMs = 0;
static uint32_t _lastMillis = 0;

/**
 * Actualiza el contador interno de uptime para manejar desbordamientos de millis().
 */
void refreshUptime() 
{
    uint32_t _currentMillis = millis();
    if (_currentMillis < _lastMillis) 
    {
        // Ocurrió un desbordamiento (rollover)
        _totalUptimeMs += (0xFFFFFFFF - _lastMillis) + _currentMillis + 1;
    } 
    else 
    {
        _totalUptimeMs += (_currentMillis - _lastMillis);
    }
    _lastMillis = _currentMillis;
}

/**
 * Retorna el tiempo de actividad de la placa formateado.
 * @return String con formato "Xd Xh Xm Xs".
 */
String getUptime() 
{
    uint64_t _nowMs = _totalUptimeMs;
    uint32_t _totalSeconds = _nowMs / 1000;
    
    uint32_t _days = _totalSeconds / 86400;
    uint32_t _hours = (_totalSeconds % 86400) / 3600;
    uint32_t _minutes = (_totalSeconds % 3600) / 60;
    uint32_t _seconds = _totalSeconds % 60;

    String _uptime = "";
    if (_days > 0) _uptime += String(_days) + "d ";
    if (_hours > 0 || _days > 0) _uptime += String(_hours) + "h ";
    if (_minutes > 0 || _hours > 0 || _days > 0) _uptime += String(_minutes) + "m ";
    _uptime += String(_seconds) + "s";

    return _uptime;
}

static String _cachedCustomReason = "";

/**
 * Retorna el motivo del último reinicio de la placa.
 * @return String con el motivo descriptivo.
 */
String getResetReason() 
{
    #ifdef ESP8266
        return ESP.getResetReason() + _cachedCustomReason;
    #elif defined(ESP32) || defined(ARDUINO_ARCH_ESP32)
        esp_reset_reason_t _reason = esp_reset_reason();
        String _baseReason = "";
        switch (_reason) 
        {
            case ESP_RST_POWERON:  _baseReason = "Vcc (Power-on)"; break;
            case ESP_RST_EXT:      _baseReason = "External Pin"; break;
            case ESP_RST_SW:       _baseReason = "Software Reset"; break;
            case ESP_RST_PANIC:    _baseReason = "Software Crash (Exception)"; break;
            case ESP_RST_INT_WDT:  _baseReason = "Watchdog (Interrupt)"; break;
            case ESP_RST_TASK_WDT: _baseReason = "Watchdog (Task)"; break;
            case ESP_RST_WDT:      _baseReason = "Watchdog (Other)"; break;
            case ESP_RST_DEEPSLEEP:_baseReason = "Deep Sleep Wakeup"; break;
            case ESP_RST_BROWNOUT: _baseReason = "Brownout (Voltage drop)"; break;
            case ESP_RST_SDIO:     _baseReason = "SDIO Reset"; break;
            default:               _baseReason = "Unknown (" + String(_reason) + ")"; break;
        }
        return _baseReason + _cachedCustomReason;
    #else
        return "Unknown Architecture" + _cachedCustomReason;
    #endif
}

/**
 * Retorna la dirección MAC de la placa para identificación.
 * @return String con la MAC Address.
 */
String getBoardId() 
{
    return WiFi.macAddress();
}

/**
 * Guarda un código de motivo de reinicio personalizado en EEPROM.
 * @param _code Código del motivo (1: WiFi Failure, 2: MQTT Failure, 3: Web Restart, 4: Ping Timeout Router).
 */
void setCustomResetReason(uint8_t _code) 
{
    EEPROM.write(EEPROM_CUSTOM_RESET_ADDR, _code);
    EEPROM.commit();
}

/**
 * Carga el motivo de reinicio personalizado desde EEPROM a memoria y lo limpia.
 */
void loadCustomResetReason() 
{
    uint8_t _code = EEPROM.read(EEPROM_CUSTOM_RESET_ADDR);
    
    if (_code == 1) _cachedCustomReason = " [Software: WiFi Failure]";
    else if (_code == 2) _cachedCustomReason = " [Software: MQTT Failure]";
    else if (_code == 3) _cachedCustomReason = " [Software: Web Restart]";
    else if (_code == 4) _cachedCustomReason = " [Software: Ping Timeout - Router 192.168.1.1]";
    else _cachedCustomReason = "";

    if (_code != 0) 
    {
        EEPROM.write(EEPROM_CUSTOM_RESET_ADDR, 0);
        EEPROM.commit();
    }
}

/**
 * Resetea el contador de reinicios acumulados a cero en la EEPROM.
 */
void resetResetCount() 
{
    uint32_t _count = 0;
    EEPROM.put(EEPROM_RESET_COUNT_ADDR, _count);
    EEPROM.commit();
}

/**
 * Obtiene el nivel de señal WiFi en formato texto (Excelente, Buena, etc.).
 * @param _rssi Valor del RSSI recibido.
 * @return String descriptivo del nivel.
 */
String getRSSILevel(int32_t _rssi) 
{
    if (_rssi >= -50) return "Excelente";
    if (_rssi >= -60) return "Buena";
    if (_rssi >= -70) return "Aceptable";
    if (_rssi >= -80) return "Debil";
    if (_rssi >= -85) return "Muy Debil";
    return "Inestable";
}

/**
 * Obtiene el color asociado al nivel de señal WiFi para la interfaz web.
 * @param _rssi Valor del RSSI recibido.
 * @return String con el código hexadecimal del color.
 */
String getRSSIColor(int32_t _rssi) 
{
    if (_rssi >= -50) return "#00f230"; // Verde brillante
    if (_rssi >= -60) return "#2ecc71"; // Verde
    if (_rssi >= -70) return "#f1c40f"; // Amarillo
    if (_rssi >= -80) return "#e67e22"; // Naranja
    if (_rssi >= -85) return "#e74c3c"; // Rojo
    return "#922b21"; // Rojo oscuro
}
