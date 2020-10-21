/**
 * Author Wojciech Domski <Wojciech.Domski@gmail.com>
 * www: www.Domski.pl
 *
 * Hardware layer for SX1278 LoRa module
 */

#ifndef __SX1278_HW_HEADER
#define __SX1278_HW_HEADER

#include <stdint.h>

typedef struct {
	int pin;
	void *port;
} SX1278_hw_dio_t;

typedef struct {
	SX1278_hw_dio_t reset;
	SX1278_hw_dio_t dio0;
	SX1278_hw_dio_t nss;
	void *spi;
} SX1278_hw_t;

/**
 * \brief Initialize hardware layer
 *
 * Clears NSS and resets LoRa module.
 *
 * \param[in]   hw 		Pointer to hardware structure
 */
void SX1278_hw_init(SX1278_hw_t *hw);

/**
 * \brief Control NSS
 *
 * Clears and sets NSS according to passed value.
 *
 * \param[in]   hw 		Pointer to hardware structure.
 * \param[in]   value   1 sets NSS high, other value sets NSS low.
 */
void SX1278_hw_SetNSS(SX1278_hw_t *hw, int value);

/**
 * \brief Resets LoRa module
 *
 * Resets LoRa module.
 *
 * \param[in]   hw 		Pointer to hardware structure
 */
void SX1278_hw_Reset(SX1278_hw_t *hw);

/**
 * \brief Send command via SPI.
 *
 * Send single byte via SPI interface.
 *
 * \param[in]   hw 		Pointer to hardware structure
 * \param[in]   cmd		Command
 */
void SX1278_hw_SPICommand(SX1278_hw_t *hw, uint8_t cmd);

/**
 * \brief Reads data via SPI
 *
 * Reads data via SPI interface.
 *
 * \param[in]   hw 		Pointer to hardware structure
 *
 * \return				Read value
 */
uint8_t SX1278_hw_SPIReadByte(SX1278_hw_t *hw);

/**
 * \brief ms delay
 *
 * Milisecond delay.
 *
 * \param[in]   msec 		Number of milliseconds to wait
 */
void SX1278_hw_DelayMs(uint32_t msec);

/**
 * \brief Reads DIO0 state
 *
 * Reads LoRa DIO0 state using GPIO.
 *
 * \param[in]   hw 		Pointer to hardware structure
 *
 * \return				0 if DIO0 low, 1 if DIO high
 */
int SX1278_hw_GetDIO0(SX1278_hw_t *hw);

#endif

