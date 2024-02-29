#include "GPIO_in/GPIOStreamIn.h"

#include <JetsonGPIO.h>

int main() {
    JetsonGPIOStream::GPIOStreamIn g;
    g.SayHello();
    GPIO::setmode(GPIO::BOARD);
    return 0;
}