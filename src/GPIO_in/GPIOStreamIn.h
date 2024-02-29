#include <string>
#include <vector>
#include <fcntl.h>
#include <termios.h>
#include <unistd.h>

namespace JetsonGPIOStream {
class GPIOStreamIn {
    using ChannelType = const char*;
    const int kBitRate = B115200; // TODO

public:
    GPIOStreamIn() = delete;
    GPIOStreamIn(ChannelType channel);
    ~GPIOStreamIn();

    std::vector<char> Read() const;

private:
    ChannelType channel_;
};

}  // namespace JetsonGPIOStream
