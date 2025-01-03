#include "../IHardware.h"

class Rele4 : public IHardware {
public:

    std::string getHardwareName() const override {
        return "RelayBoard"; // El nombre del hardware
    }
    
};
