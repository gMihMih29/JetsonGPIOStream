#include <JetsonGPIO.h>
#include <vector>

namespace JetsonGPIOStream {
class GPIOStreamOut {
    using ChannelType = int;
public:
    GPIOStreamOut() = delete;
    GPIOStreamOut(ChannelType channel);
    ~GPIOStreamOut();

    void Write(const std::vector<unsigned char>& data);
private:
    ChannelType channel_;
};

}  // namespace JetsonGPIOStream
