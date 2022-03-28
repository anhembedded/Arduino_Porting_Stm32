/*
  HardwareSerial.cpp - Hardware serial library for Wiring
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

  Modified 23 November 2006 by David A. Mellis
  Modified 28 September 2010 by Mark Sproul
  Modified 14 August 2012 by Alarus
  Modified 3 December 2013 by Matthijs Kooijman
*/

#include <stdio.h>
#include "Arduino.hpp"
#include "HardwareSerial.h"

// Constructors ////////////////////////////////////////////////////////////////



void HardwareSerial::begin(unsigned long baud, byte config)
{
}

HardwareSerial::HardwareSerial()
{
}




void HardwareSerial::init()
{

}



// Actual interrupt handlers //////////////////////////////////////////////////////////////
//todo: interrupt
//void HardwareSerial::_rx_complete_irq(serial_t *obj)
//{
//
//}

// Actual interrupt handlers //////////////////////////////////////////////////

//int HardwareSerial::_tx_complete_irq(serial_t *obj)
//{
//
//  
//}

// Public Methods //////////////////////////////////////////////////////////////

void HardwareSerial::end()
{
  // wait for transmission of outgoing data
  flush();

 //uart_deinit(&_serial);

  // clear any received data
  
}

int HardwareSerial::available(void)
{
    //Number of byte a
 // return ((unsigned int)(SERIAL_RX_BUFFER_SIZE + _serial.rx_head - _serial.rx_tail)) % SERIAL_RX_BUFFER_SIZE;
    return 0;
}

int HardwareSerial::peek(void)
{
 
   /* return -1;

    return _serial.rx_buff[_serial.rx_tail];*/
    return 0;
  
}

int HardwareSerial::read(void)
{
  
  //// if the head isn't ahead of the tail, we don't have any characters
  //
  //  return -1;
  //
  //  return c;
    return 0;
}

int HardwareSerial::availableForWrite(void)
{
    return 0;
}

void HardwareSerial::flush()
{
  // If we have never written a byte, no need to flush. This special
  // case is needed since there is no way to force the TXC (transmit
  // complete) bit to 1 during initialization
 
 
    // nop, the interrupt handler will free up space for us
  
  // If we get here, nothing is queued anymore (DRIE is disabled) and
  // the hardware finished tranmission (TXC is set).
}


void HardwareSerial::setHalfDuplex(void)
{
}

bool HardwareSerial::isHalfDuplex(void) const
{
    return false;
}

void HardwareSerial::enableHalfDuplexRx(void)
{
  
}


