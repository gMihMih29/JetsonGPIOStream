#include <JetsonGPIO.h>
#include <vector>

namespace JetsonGPIOStream {
class GPIOStreamOut {
    using ChannelType = int;
public:
    GPIOStreamOut() = delete;
    GPIOStreamOut(ChannelType channel);
    ~GPIOStreamOut();

    bool Write(std::vector<unsigned char> data);
private:
};

}  // namespace JetsonGPIOStream
