#include <string>
class IInstallationContext {
public:
    virtual std::string getWiFiName() const = 0;        // Nombre de la red Wi-Fi
    virtual std::string getIPAddress() const = 0;       // Dirección IP
    virtual std::string getMQTTCommandName() const = 0; // Nombre del comando MQTT
    virtual ~IInstallationContext() {}
};