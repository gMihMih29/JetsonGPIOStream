#include "GPIOStreamOut.h"

using namespace JetsonGPIOStream;

GPIOStreamOut::GPIOStreamOut(ChannelType channel) {
    channel_ = channel;
    GPIO::setup(channel_, GPIO::OUT);
}

GPIOStreamOut::~GPIOStreamOut() {
    GPIO::cleanup(channel_);
}

void GPIOStreamOut::Write(const std::vector<unsigned char>& data) {
    for (size_t i = 0; i < data.size(); ++i) {
        for (int j = 7; j >= 0; --j) {
            if ((data[i] >> j) % 2) {
                GPIO::output(channel_, GPIO::LOW);
            } else {
                GPIO::output(channel_, GPIO::HIGH);
            }
        } 
    }
}
