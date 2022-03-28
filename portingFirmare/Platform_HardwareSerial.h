#ifndef __PLATFORM_HARDWARESERIAL_H__
#define __PLATFORM_HARDWARESERIAL_H__


#include "Platform.hpp"
#include "HardwareSerial.h"

class Platform_HardwareSerial : public HardwareSerial
{
public:
    void begin(unsigned long baud) override;
    void end() override;
    int available(void) override;
    int peek(void) override;
    virtual int read(void) override;
    int availableForWrite(void) override;
    void flush(void) override;
    size_t write(uint8_t data) override;
};

extern Platform_HardwareSerial Serial; 
#endif // __PLATFORM_HARDWARESERIAL_H__