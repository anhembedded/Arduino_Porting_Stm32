/*
  TwoWire.cpp - TWI/I2C library for Wiring & Arduino
  Copyright (c) 2006 Nicholas Zambetti.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

  Modified 2012 by Todd Krein (todd@krein.org) to implement repeated starts
*/

extern "C" {
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
}

#include "Wire.h"

// Distinguish master from slave.
// 0x01 is a reserved value, and thus cannot be used by slave devices
static const uint8_t MASTER_ADDRESS = 0x01;

// Constructors ////////////////////////////////////////////////////////////////



// Public Methods //////////////////////////////////////////////////////////////

void TwoWire::end(void)
{
 
}

void TwoWire::setClock(uint32_t frequency)
{
 
}



uint8_t TwoWire::requestFrom(uint8_t address, uint8_t quantity, uint8_t sendStop)
{
    return 1;
}

uint8_t TwoWire::requestFrom(uint8_t address, size_t quantity, bool sendStop)
{
  return requestFrom((uint8_t)address, (uint8_t)quantity, (uint8_t)sendStop);
}

uint8_t TwoWire::requestFrom(uint8_t address, uint8_t quantity)
{
  return requestFrom((uint8_t)address, (uint8_t)quantity, (uint8_t)true);
}

uint8_t TwoWire::requestFrom(int address, int quantity)
{
  return requestFrom((uint8_t)address, (uint8_t)quantity, (uint8_t)true);
}

uint8_t TwoWire::requestFrom(int address, int quantity, int sendStop)
{
  return requestFrom((uint8_t)address, (uint8_t)quantity, (uint8_t)sendStop);
}

void TwoWire::beginTransmission(uint8_t address)
{

}

void TwoWire::beginTransmission(int address)
{
  beginTransmission((uint8_t)address);
}

//
//  Originally, 'endTransmission' was an f(void) function.
//  It has been modified to take one parameter indicating
//  whether or not a STOP should be performed on the bus.
//  Calling endTransmission(false) allows a sketch to
//  perform a repeated start.
//
//  WARNING: Nothing in the library keeps track of whether
//  the bus tenure has been properly ended with a STOP. It
//  is very possible to leave the bus in a hung state if
//  no call to endTransmission(true) is made. Some I2C
//  devices will behave oddly if they do not see a STOP.
//

//  This provides backwards compatibility with the original
//  definition, and expected behaviour, of endTransmission
//
uint8_t TwoWire::endTransmission(void)
{
    return 1;
}

// must be called in:
// slave tx event callback
// or after beginTransmission(address)
size_t TwoWire::write(uint8_t data)
{

    return 1;
}

/**
  * @brief  This function must be called in slave Tx event callback or after
  *         beginTransmission() and before endTransmission().
  * @param  pdata: pointer to the buffer data
  * @param  quantity: number of bytes to write
  * @retval number of bytes ready to write.
  */
size_t TwoWire::write(const uint8_t *data, size_t quantity)
{
 
  return 1;
}

// must be called in:
// slave rx event callback
// or after requestFrom(address, numBytes)
int TwoWire::available(void)
{
    return 1;
}

// must be called in:
// slave rx event callback
// or after requestFrom(address, numBytes)
int TwoWire::read(void)
{
  int value = -1;

  return value;
}

// must be called in:
// slave rx event callback
// or after requestFrom(address, numBytes)
int TwoWire::peek(void)
{
  int value = -1;


  return value;
}

void TwoWire::flush(void)
{

}


// sets function called on slave write
void TwoWire::onReceive(void (*function)(int))
{
  
}

// sets function called on slave read
void TwoWire::onRequest(void (*function)(void))
{
  
}




// Preinstantiate Objects //////////////////////////////////////////////////////


