//
// Created by Anh.Embedded on 3/22/2022. 
// 0965062996
// Anh.Embedded@gmail.com
//

#ifndef ARDPORTING_U_ARDUINO_HPP
#define ARDPORTING_U_ARDUINO_HPP

#include "Platform.hpp"
#include "Binary.hpp"
#include "avr/pgmspace.h"
#include "avr/dtostrf.h"
#include <cstdint>


#define HIGH 0x1
#define LOW  0x0

#define INPUT 0x0
#define OUTPUT 0x1
#define INPUT_PULLUP 0x2
/* STM32 extension */
#define INPUT_FLOATING      INPUT
#define INPUT_PULLDOWN      0x3
#define INPUT_ANALOG        0x4
#define OUTPUT_OPEN_DRAIN   0x5

#define PI 3.1415926535897932384626433832795
#define HALF_PI 1.5707963267948966192313216916398
#define TWO_PI 6.283185307179586476925286766559
#define DEG_TO_RAD 0.017453292519943295769236907684886
#define RAD_TO_DEG 57.295779513082320876798154814105
#define EULER 2.718281828459045235360287471352

#define SERIAL  0x0
#define DISPLAY 0x1

enum BitOrder {
  LSBFIRST = 0,
  MSBFIRST = 1
};

#define LSBFIRST 0
#define MSBFIRST 1

#define LOW     0x0
#define HIGH    0x1
#define CHANGE 1
#define FALLING 2
#define RISING 3

#define INTERNAL 3
#define DEFAULT 1
#define EXTERNAL 0



#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#ifdef abs
#undef abs
#endif
#define constrain(amt,low,high) ((amt)<(low)?(low):((amt)>(high)?(high):(amt)))
#define round(x)     ((x)>=0?(long)((x)+0.5):(long)((x)-0.5))
#define radians(deg) ((deg)*DEG_TO_RAD)
#define degrees(rad) ((rad)*RAD_TO_DEG)
#define sq(x) ((x)*(x))

#define interrupts() PL_enableGlobalInterrupt()
#define noInterrupts() PL_disableGlobalInterrupt()

#define clockCyclesPerMicrosecond()
#define clockCyclesToMicroseconds(a)
#define microsecondsToClockCycles(a)

#define lowByte(w) ((uint8_t) ((w) & 0xff))
#define highByte(w) ((uint8_t) ((w) >> 8))


#ifndef  bitRead
#define bitRead(value, bit) (((value) >> (bit)) & 0x01)
#endif

#ifndef  bitSet
#define bitSet(value, bit) ((value) |= (1UL << (bit)))
#endif

#ifndef  bitClear
#define bitClear(value, bit) ((value) &= ~(1UL << (bit)))
#endif

#ifndef  bitToggle
#define bitToggle(value, bit) ((value) ^= (1UL << (bit)))
#endif

#ifndef  bitWrite
#define bitWrite(value, bit, bitvalue) ((bitvalue) ? bitSet(value, bit) : bitClear(value, bit))
#endif

#ifndef NOP
#define NOP() // todo: implement NOP function
#endif




typedef unsigned int word;

#ifndef  bit
#define bit(b) (1UL << (b))
#endif

typedef bool boolean;
typedef uint8_t byte;
//macro added for compatibility
#ifndef _BV
  #define _BV(bit) (1 << (bit))
#endif
#ifndef cbi
  #define cbi(reg, bitmask) *reg &= ~bitmask
#endif
#ifndef sbi
  #define sbi(reg, bitmask) *reg |= bitmask
#endif


class Arduino {

public:

    virtual void pinMode(PF_GPIO_T pin, uint8_t mode);
    virtual  void digitalWrite(PF_GPIO_T pin, uint8_t val);
    virtual int digitalRead(PF_GPIO_T pin);

    virtual int analogRead(uint8_t pin);
    virtual void analogReference(uint8_t mode);
    virtual void analogWrite(uint8_t pin, int val);


    virtual unsigned long millis(void);
    virtual unsigned long micros(void);

    virtual void delay(unsigned long ms);
    virtual void delayMicroseconds(unsigned int us);


    virtual unsigned long pulseIn(PF_GPIO_T pin, uint8_t state, unsigned long timeout);
    virtual unsigned long pulseInLong(PF_GPIO_T pin, uint8_t state, unsigned long timeout);

    virtual void shiftOut(PF_GPIO_T dataPin, PF_GPIO_T clockPin, uint8_t bitOrder, uint8_t val);
    virtual uint8_t shiftIn(PF_GPIO_T dataPin, PF_GPIO_T clockPin, uint8_t bitOrder);

};


#endif //ARDPORTING_U_ARDUINO_HPP
