/*
 * Copyright (c) 2010 by Cristian Maglie <c.maglie@arduino.cc>
 * Copyright (c) 2014 by Paul Stoffregen <paul@pjrc.com> (Transaction API)
 * SPI Master library for arduino.
 *
 * This file is free software; you can redistribute it and/or modify
 * it under the terms of either the GNU General Public License version 2
 * or the GNU Lesser General Public License version 2.1, both as
 * published by the Free Software Foundation.
 */

#ifndef _SPI_H_INCLUDED
#define _SPI_H_INCLUDED

#include "Arduino.hpp"
#include <stdio.h>
extern "C" {
#include "utility/spi_com.h"
#include <SPI/SPI.h>
}

// SPI_HAS_TRANSACTION means SPI has
//   - beginTransaction()
//   - endTransaction()
//   - usingInterrupt()
//   - SPISetting(clock, bitOrder, dataMode)
#define SPI_HAS_TRANSACTION 1

// Compatibility with sketches designed for AVR @ 16 MHz could not
// be ensured as SPI frequency depends of system clock configuration.
// user have to use appropriate divider for the SPI clock
// This function should not be used in new project.
// Use SPISettings with SPI.beginTransaction() to configure SPI parameters.
#define SPI_CLOCK_DIV2   2
#define SPI_CLOCK_DIV4   4
#define SPI_CLOCK_DIV8   8
#define SPI_CLOCK_DIV16  16
#define SPI_CLOCK_DIV32  32
#define SPI_CLOCK_DIV64  64
#define SPI_CLOCK_DIV128 128

// SPI mode parameters for SPISettings
#define SPI_MODE0 0x00
#define SPI_MODE1 0x01
#define SPI_MODE2 0x02
#define SPI_MODE3 0x03

#define SPI_TRANSMITRECEIVE 0x0
#define SPI_TRANSMITONLY 0x1

// Transfer mode
enum SPITransferMode {
  SPI_CONTINUE, /* Transfer not finished: CS pin kept active */
  SPI_LAST      /* Transfer ended: CS pin released */
};

// Indicates the user controls himself the CS pin outside of the spi class
#define CS_PIN_CONTROLLED_BY_USER  NUM_DIGITAL_PINS

// Indicates there is no configuration selected
#define NO_CONFIG   ((int16_t)(-1))

// Defines a default timeout delay in milliseconds for the SPI transfer
#ifndef SPI_TRANSFER_TIMEOUT
  #define SPI_TRANSFER_TIMEOUT 1000
#endif

/*
 * Defines the number of settings saved per SPI instance. Must be in range 1 to 254.
 * Can be redefined in variant.h
 */
#ifndef NB_SPI_SETTINGS
  #define NB_SPI_SETTINGS 4
#endif



class SPIClass {
protected:
    PF_GPIO_T cspin;
  public:
    SPIClass();
    SPIClass(PF_GPIO_T cspin);


    void begin(PF_GPIO_T cspin);
    void end(void);

    /* This function should be used to configure the SPI instance in case you
     * don't use default parameters.
     * You can attach another CS pin to the SPI instance and each CS pin can be
     * attach with specific SPI settings.
     */
    void beginTransaction(PF_GPIO_T cspin);
    void endTransaction(PF_GPIO_T cspin);
    void endTransaction(void)
    {
      endTransaction(cspin);
    }

    /* Transfer functions: must be called after initialization of the SPI
     * instance with begin() or beginTransaction().
     * You can specify the CS pin to use.
     */
    byte transfer(PF_GPIO_T cspin, uint8_t _data, SPITransferMode _mode = SPI_LAST);
    uint16_t transfer16(PF_GPIO_T cspin, uint16_t _data, SPITransferMode _mode = SPI_LAST);
    void transfer(PF_GPIO_T cspin, void *_buf, size_t _count, SPITransferMode _mode = SPI_LAST);
    void transfer(byte cspin, void *_bufout, void *_bufin, size_t _count, SPITransferMode _mode = SPI_LAST);

    // Transfer functions when user controls himself the CS pin.
    byte transfer(uint8_t _data, SPITransferMode _mode = SPI_LAST)
    {
      return transfer(cspin, _data, _mode);
    }

    uint16_t transfer16(uint16_t _data, SPITransferMode _mode = SPI_LAST)
    {
      return transfer16(cspin, _data, _mode);
    }

    void transfer(void *_buf, size_t _count, SPITransferMode _mode = SPI_LAST)
    {
      transfer(cspin, _buf, _count, _mode);
    }

    void transfer(void *_bufout, void *_bufin, size_t _count, SPITransferMode _mode = SPI_LAST)
    {
      transfer(cspin, _bufout, _bufin, _count, _mode);
    }

    /* These methods are deprecated and kept for compatibility.
     * Use SPISettings with SPI.beginTransaction() to configure SPI parameters.
     */
    void setBitOrder(PF_GPIO_T cspin, BitOrder);
    void setBitOrder(BitOrder _order)
    {
      setBitOrder(cspin, _order);
    }

    void setDataMode(PF_GPIO_T cspin, uint8_t);
    void setDataMode(uint8_t _mode)
    {
      setDataMode(cspin, _mode);
    }

    void setClockDivider(PF_GPIO_T cspin, uint8_t);
    void setClockDivider(uint8_t _div)
    {
      setClockDivider(cspin, _div);
    }

    // Not implemented functions. Kept for backward compatibility.
    void usingInterrupt(uint8_t interruptNumber);
    void attachInterrupt(void);
    void detachInterrupt(void);

  private:
    /* Contains various spiSettings for the same spi instance. Each spi spiSettings
    is associated to a CS pin. */




    // spi instance

    typedef enum {
      GET_IDX = 0,
      ADD_NEW_PIN = 1
    } pin_option_t;

    void RemovePin(uint8_t _pin)
    {
     
    }

    void RemoveAllPin(void)
    {
      
    }
};

extern SPIClass SPI;

#endif
