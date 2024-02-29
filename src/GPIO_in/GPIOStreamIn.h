#include <string>
#include <vector>
#include <fcntl.h>
#include <termios.h>
#include <unistd.h>

namespace JetsonGPIOStream {
class GPIOStreamIn {
    using ChannelType = std::string;
    const int kBitRate = B115200; // TODO

public:
    GPIOStreamIn() = delete;
    CPIOStreamIn(cosnt std::string& channel);

    std::vector<char> Read() const;

private:
    ChannelType channel_;
};

}  // namespace JetsonGPIOStream
