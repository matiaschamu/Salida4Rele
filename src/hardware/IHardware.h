#include <string>
class IHardware {
public:
    virtual std::string getHardwareName() const = 0;        
    virtual ~IHardware() {}
};