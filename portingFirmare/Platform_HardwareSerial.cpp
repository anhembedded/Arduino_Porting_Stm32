
#include "Platform_HardwareSerial.h"

void Platform_HardwareSerial::begin(unsigned long baud)
{
    std::cout << "SetBaud Rate : " << baud << std::endl;
}

void Platform_HardwareSerial::end()
{
    std::cout << "END!!! " << std::endl;
}

int Platform_HardwareSerial::available(void)
{
    std::cout << "check available !!! " << std::endl;
    return 1;
}

int Platform_HardwareSerial::peek(void)
{
    std::cout << "Peek check !!! " << std::endl;
    return 1;
}

int Platform_HardwareSerial::read(void)
{
    int temp{};
    std::cout << "UART read 1 byte: " << std::endl;
    std::cin >> temp;
    return temp;
}

int Platform_HardwareSerial::availableForWrite(void)
{
    std::cout << "availableForWrite !!! " << std::endl;
    return 1;
}

void Platform_HardwareSerial::flush(void)
{
    std::cout << "flush !!! " << std::endl;
}

size_t Platform_HardwareSerial::write(uint8_t data)
{
    std::cout << data;
    return 1;
}
Platform_HardwareSerial Serial;