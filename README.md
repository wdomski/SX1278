# SX1278
STM32 HAL driver for LoRa SX1278 module

This is a driver for wireless LoRa module -- SX1278.

The initial work was based on DORJI.COM sample code and [SX1278_LoRa](https://github.com/realspinner/SX1278_LoRa).

# About the driver

The driver was written in **C**. It has a hardware abstraction layer for easy porting to others MCUs.
Also the hardware functions are defined as *__weak* so there is no need to change the driver files themselves.
The driver is using HAL to communicate between STM32 SPI peripheral and LoRa module.

# Example

There is also an example available at [SX1278-example repository](https://github.com/wdomski/SX1278-example). 
The example project was initially prepared for STM32F1 MCU in SW4STM32. 
Consult the *README* file in the above repository which development 
board is currently supported. 

# Documentation 

The driver is quite simple to use and now requires even lower entry 
level. After collecting some feedback from my blog readers I decided 
to include some more features including automatic frequency setting. 
Previously, it was done by manually calculating values which 
should be written to the LoRa module's registers. Now, the frequency 
can be set during initialization by passing an argument to the 
function.

Since the driver is rather small the documentation (at least the 
most common parts) will be included here.

## Hardware layer

The driver can be easily ported to a different platform with 
minimum effort. Only the hardware dependant functions ought to be 
modified. The hardware dependant parts can be find in 
**SX1278_hw.c** and **SX1278_hw.h**.

## Logic layer

# Final remarks

You can visit [my blog](http://blog.domski.pl) to read more about the SX1278 modules or my other projects.

