#include "Platform_Wire.hpp"




Platform_Wire::Platform_Wire()
{
    std::cout << "I2C hardware had been initialize" << std::endl;
}

void Platform_Wire::end(void)
{
    std::cout << "I2C hardware had been END" << std::endl;

}

void Platform_Wire::setClock(uint32_t frequency)
{
    std::cout << "<setClock> : " << frequency << std::endl;
}
void Platform_Wire::begin()
{
    std::cout << "I2C Begin" << std::endl;
}




void Platform_Wire::beginTransmission(uint8_t address)
{
    std::cout << "<beginTransmission> (address) " << static_cast<uint16_t>(address) << std::endl;
}

uint8_t Platform_Wire::endTransmission(void)
{
    std::cout << "<endTransmission>" << std::endl;

    return 1;
}

size_t Platform_Wire::write(uint8_t data)
{
    std::cout << "<write> (data)  " << static_cast<uint16_t>(data) ;
    return 1;
}

// must be called in:
// slave rx event callback
// or after requestFrom(address, numBytes)
int Platform_Wire::available(void)
{
    std::cout << "<available>"  << std::endl;
    return 1;
}

// must be called in:
// slave rx event callback
// or after requestFrom(address, numBytes)
int Platform_Wire::read(void)
{
    int value = -1;

    std::cout << "<read> nothing for read" << std::endl;
    //return value: 
    return 1;
}

void Platform_Wire::onReceive(void(*)(int), uint8_t)
{
    
}

void Platform_Wire::onRequest(void(*)(void))
{
}

// link: https://www.arduino.cc/en/Reference/WireRequestFrom
uint8_t Platform_Wire::requestFrom(uint8_t address, uint8_t quantity, uint8_t sendStop)
{

    std::cout << "<requestFrom> <adress> <quantity> <sendStop>: "
        << address << " | "
        << quantity << " | "
        << sendStop << " | "
        << std::endl;
    //Return: byte: the number of bytes returned from the slave device
    return 1;
}

Platform_Wire Wire;