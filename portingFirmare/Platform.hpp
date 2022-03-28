//
// Created by pcx on 3/23/2022.
//

#ifndef ARDPORTING_U_PLATFORM_HPP
#define ARDPORTING_U_PLATFORM_HPP

// todo: #include platform HAL, API, LL

#ifdef __cplusplus
#include <cstdint>
#include <iostream>
#else
#include <stdint.h>
#include <stdlib.h>
#endif




typedef uint16_t PF_pin_t; //! todo: Need to be changed
typedef uint32_t PF_port_t; //! todo: Need to be changed


struct PF_GPIO_T
{
public:
    PF_pin_t pin;
    PF_port_t port;

    PF_GPIO_T & operator =(const PF_GPIO_T& var) = default;
    bool operator !=(const PF_GPIO_T& var) const;
    bool operator ==(const PF_GPIO_T& var) const;
};


/* CONFIGURATION*/
#define _AVR_MICROCHIP_STUDIO_  0
#define _WIN64_CLION_GCC_ 1

#if _AVR_MICROCHIP_STUDIO_ == 1


#elif _WIN64_CLION_GCC_ == 1
/* WIN_GCC Portable Compiler*/
#include <iostream>
static inline void PF_NOP()
{
    std::cout << "NOP!!" << std::endl;
}
static inline void yield()
{
    std::cout << "yield Function!!" << std::endl;
}

#endif



/* BASIC BITWISE MACRO */
#define BIT_SET(a, b) ((a) |= (1UL << (b)))
#define BIT_CLEAR(a, b) ((a) &= ~(1UL << (b)))
#define BIT_TOGGLE(a, b) ((a) ^= (1UL << (b)))
#define BIT_READ(a, b) (!!((a) & (1UL << (b)))) // '!!' to make sure this returns 0 or 1
#define SET_BIT(a, b) ((a) |= (1UL << (b)))
#define CLEAR_BIT(a, b) ((a) &= ~(1UL << (b)))
#define TOGGLE_BIT(a, b) ((a) ^= (1UL << (b)))
#define READ_BIT(a, b) (!!((a) & (1UL << (b)))) // '!!' to make sure this returns 0 or 1
#define CLEAR_REG(REG) ((REG) = (0x0))
#define WRITE_REG(REG, VAL) ((REG) = (VAL))
#define READ_REG(REG) ((REG))
#define MODIFY_REG(REG, CLEARMASK, SETMASK) WRITE_REG((REG), (((READ_REG(REG)) & (~(CLEARMASK))) | (SETMASK)))
#define LOWBYTE(w) ((uint8_t) ((w) & 0xff))
#define HIGHBYTE(w) ((uint8_t) ((w) >> 8))
#define CONSTRAIN(amt,low,high) ((amt)<(low)?(low):((amt)>(high)?(high):(amt)))
#define READ_BIT_MASK(R,P,M) (((R)>>(P))&((M)))
#define WAIT_UNTIL(a) while(!(a))

#define UNUSED(X) (void)X   


//todo: modifying for platform
static inline void PF_delayUs(uintmax_t delayUsTime)
{
    std::cout << "Delay " << delayUsTime << " us" << std::endl;
}
static inline void PF_delayMs(uintmax_t delayMsTime)
{
    std::cout << "Delay " << delayMsTime << " Ms" << std::endl;
}
static inline void PF_delayCyc(uintmax_t delayCycTime)
{
    std::cout << "Delay " << delayCycTime << " Cyc" << std::endl;
}


static PF_GPIO_T PF_UNUSED_PIN {UINT8_MAX,UINT8_MAX}; // todo: Need to be changed from compatibility





#endif //ARDPORTING_U_PLATFORM_HPP
