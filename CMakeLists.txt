cmake_minimum_required(VERSION 3.21)
project(Arduino_Porting_Stm32)

set(CMAKE_CXX_STANDARD 14)

include_directories(portingFirmare)
include_directories(portingFirmare/avr)

add_executable(Arduino_Porting_Stm32
        portingFirmare/avr/dtostrf.c
        portingFirmare/avr/dtostrf.h
        portingFirmare/avr/pgmspace.h
        portingFirmare/Arduino.cpp
        portingFirmare/Arduino.hpp
        portingFirmare/Binary.hpp
        portingFirmare/Platform.cpp
        portingFirmare/Platform.hpp
        Arduino_Porting_Stm32.cpp)
