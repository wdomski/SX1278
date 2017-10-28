# SX1278
STM32 HAL driver for LoRa SX1278 module

This is a driver for wireless LoRa module -- SX1278.

The initial work was based on DORJI.COM sample code and [SX1278_LoRa](https://github.com/realspinner/SX1278_LoRa).

# About the driver

The driver was written in **C**. It has a hardware abstraction layer for easy porting to others MCUs.
Also the hardware functions are defined as *__weak* so there is no need to change the driver files themselves.
The driver is using HAL to communicate between STM32 SPI periperal and LoRa module.

# Example

There is also an example available at [SX1278-example repository](https://github.com/wdomski/SX1278-example). 
The example project was prepared for STM32F1 MCU in SW4STM32.

# Final remarks

You can visit [my blog](http://blog.domski.pl) to read more about the SX1278 modules or my other projects.

