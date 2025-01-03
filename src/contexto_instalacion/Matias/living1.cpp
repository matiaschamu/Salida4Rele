#include "../IInstallationContext.h"

class Living1Context : public IInstallationContext {
public:
    std::string getWiFiName() const override {
        return "WiFi_Living";
    }
    std::string getIPAddress() const override {
        return "192.168.1.101";
    }
    std::string getMQTTCommandName() const override {
        return "luz_Living_mqtt_command";
    }
};