#include "GPIO_in/GPIOStreamIn.h"

int main() {
    JetsonGPIOStream::GPIOStreamIn g;
    g.SayHello();
    return 0;
}