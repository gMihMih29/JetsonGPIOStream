#include <iostream>
#include <unistd.h>
#include "GPIOStreamIn.h"

using namespace JetsonGPIOStream;

GPIOStreamIn::GPIOStreamIn(ChannelType channel) {
    channel_ = channel;
}

std::vector<char> GPIOStreamIn::Read() const {
    int serialPort = open(channel_, O_RDWR | O_NOCTTY | O_NDELAY);
    if (serialPort == -1) {
        std::cerr << "Ошибка открытия порта" << std::endl;
        return std::vector<char>{};
    }

    struct termios tty;
    if (tcgetattr(serialPort, &tty) != 0) {
        std::cerr << "Ошибка получения атрибутов" << std::endl;
        return std::vector<char>{};
    }

    cfsetospeed(&tty, kBitRate); // Установите скорость передачи
    cfsetispeed(&tty, kBitRate);

    tty.c_cflag |= (CLOCAL | CREAD); // Включение чтения и локального соединения
    tty.c_cflag &= ~PARENB;          // Отключение проверки четности
    tty.c_cflag &= ~CSTOPB;          // Один стоп-бит
    tty.c_cflag &= ~CSIZE;
    tty.c_cflag |= CS8;              // 8 бит данных

    tcsetattr(serialPort, TCSANOW, &tty);

    std::vector<char> buffer(256);
    ssize_t bytesRead = read(serialPort, buffer.data(), buffer.size() * 8);
    if (bytesRead > 0) {
        std::cout << "Прочитано " << bytesRead << " байт: " << std::endl;
    } else {
        std::cerr << "Ошибка чтения" << std::endl;
    }

    close(serialPort);

    return buffer;
}

GPIOStreamIn::~GPIOStreamIn() {
    delete channel_;
}
