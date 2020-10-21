/**
 * Author Wojciech Domski <Wojciech.Domski@gmail.com>
 * www: www.Domski.pl
 *
 * Hardware layer for SX1278 LoRa module
 */

#include "SX1278_hw.h"
#include <string.h>

#include "gpio.h"
#include "spi.h"

__weak void SX1278_hw_init(SX1278_hw_t *hw) {
	SX1278_hw_SetNSS(hw, 1);
	HAL_GPIO_WritePin(hw->reset.port, hw->reset.pin, GPIO_PIN_SET);
}

__weak void SX1278_hw_SetNSS(SX1278_hw_t *hw, int value) {
	HAL_GPIO_WritePin(hw->nss.port, hw->nss.pin,
			(value == 1) ? GPIO_PIN_SET : GPIO_PIN_RESET);
}

__weak void SX1278_hw_Reset(SX1278_hw_t *hw) {
	SX1278_hw_SetNSS(hw, 1);
	HAL_GPIO_WritePin(hw->reset.port, hw->reset.pin, GPIO_PIN_RESET);

	SX1278_hw_DelayMs(1);

	HAL_GPIO_WritePin(hw->reset.port, hw->reset.pin, GPIO_PIN_SET);

	SX1278_hw_DelayMs(100);
}

__weak void SX1278_hw_SPICommand(SX1278_hw_t *hw, uint8_t cmd) {
	SX1278_hw_SetNSS(hw, 0);
	HAL_SPI_Transmit(hw->spi, &cmd, 1, 1000);
	while (HAL_SPI_GetState(hw->spi) != HAL_SPI_STATE_READY)
		;
}

__weak uint8_t SX1278_hw_SPIReadByte(SX1278_hw_t *hw) {
	uint8_t txByte = 0x00;
	uint8_t rxByte = 0x00;

	SX1278_hw_SetNSS(hw, 0);
	HAL_SPI_TransmitReceive(hw->spi, &txByte, &rxByte, 1, 1000);
	while (HAL_SPI_GetState(hw->spi) != HAL_SPI_STATE_READY)
		;
	return rxByte;
}

__weak void SX1278_hw_DelayMs(uint32_t msec) {
	HAL_Delay(msec);
}

__weak int SX1278_hw_GetDIO0(SX1278_hw_t *hw) {
	return (HAL_GPIO_ReadPin(hw->dio0.port, hw->dio0.pin) == GPIO_PIN_SET);
}

