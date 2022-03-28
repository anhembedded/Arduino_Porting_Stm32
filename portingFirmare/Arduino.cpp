//
// Created by pcx on 3/22/2022.
//

#include "Arduino.hpp"

void Arduino::pinMode(PF_GPIO_T pin, uint8_t mode)
{
	std::cout << "<PinMode>" << std::endl;
}

void Arduino::digitalWrite(PF_GPIO_T pin, uint8_t val)
{
}

int Arduino::digitalRead(PF_GPIO_T pin)
{
	return 0;
}

int Arduino::analogRead(uint8_t pin)
{
	return 0;
}

void Arduino::analogReference(uint8_t mode)
{
}

void Arduino::analogWrite(uint8_t pin, int val)
{
}

unsigned long Arduino::millis(void)
{
	return 0;
}

unsigned long Arduino::micros(void)
{
	return 0;
}

void Arduino::delay(unsigned long ms)
{
}

void Arduino::delayMicroseconds(unsigned int us)
{
}

unsigned long Arduino::pulseIn(PF_GPIO_T pin, uint8_t state, unsigned long timeout)
{
	return 0;
}

unsigned long Arduino::pulseInLong(PF_GPIO_T pin, uint8_t state, unsigned long timeout)
{
	return 0;
}

void Arduino::shiftOut(PF_GPIO_T dataPin, PF_GPIO_T clockPin, uint8_t bitOrder, uint8_t val)
{
}

uint8_t Arduino::shiftIn(PF_GPIO_T dataPin, PF_GPIO_T clockPin, uint8_t bitOrder)
{
	return uint8_t();
}
