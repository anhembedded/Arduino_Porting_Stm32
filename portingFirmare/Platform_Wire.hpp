#pragma once

#include "Wire/Wire.h"

class Platform_Wire : public TwoWire
{
public:
    Platform_Wire();
    void end(void) override;

    void setClock(uint32_t frequency) override;

    void begin() override;

    uint8_t requestFrom(uint8_t address, uint8_t quantity, uint8_t sendStop) override;

    void beginTransmission(uint8_t address) override;

    uint8_t endTransmission(void) override;

    size_t write(uint8_t data) override;

    int available(void) override;

    int read(void) override;


     void onReceive(void (*)(int), uint8_t);
     void onRequest(void (*)(void));


};


extern Platform_Wire Wire;
