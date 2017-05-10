

#include <stdint.h>
#include "spi.h"
#include "sd_spi.h"
#include "init.h"
#include "stm32f1xx_hal.h"

/*	
 * @brief SD card SPI handle. SPI2 channel.Load datas for SD card initialize 
 * process.
 */

static SPI_HandleTypeDef 	sd_spi2_handle = 
{.Instance = SPI2, 
.Init.BaudRatePrescaler  = SPI_BAUDRATEPRESCALER_256,
.Init.Direction          = SPI_DIRECTION_2LINES,
.Init.CLKPhase           = SPI_PHASE_2EDGE,
.Init.CLKPolarity        = SPI_POLARITY_HIGH,
.Init.CRCCalculation     = SPI_CRCCALCULATION_DISABLE,
.Init.CRCPolynomial      = 7,
.Init.DataSize           = SPI_DATASIZE_8BIT,
.Init.FirstBit           = SPI_FIRSTBIT_MSB,
.Init.NSS                = SPI_NSS_SOFT,
.Init.TIMode             = SPI_TIMODE_DISABLE,
.Init.Mode               = SPI_MODE_MASTER
};


/* @brief SD_Card_SPI_Select(): Select SD card SPI communication. To use must 
 * be initialize SPI with <400kHz baud rate.
 * Power ON or card insertion
After supply voltage reached 2.2 volts, wait for one millisecond at least. 
 * Set SPI clock rate between 100 kHz and 400 kHz. Set DI and CS high and apply 74 or 
 * more clock pulses to SCLK. The card will enter its native operating mode and go 
 * ready to accept native command. (http://elm-chan.org/docs/mmc/mmc_e.html)
*/

void SD_Card_SPI_Select()
{	uint16_t counter;
	/* deselect chip select line */
	DESELECT_SD();
	/* min. 74 clock bits write */
  for (counter = 0; counter <= 9; counter++)
  {
    SPI_WriteByte(SD_DUMMY_BYTE, sd_spi2_handle, 1000);
  }
}

/* @brief SD_SPI2_Init(): initialize SPI 2 signals for SD card reader, 
 * and set SPI channel, and initialize CS line for standard I/O. */

void SD_SPI2_Init()
{
  GPIO_InitTypeDef  gpioinitstruct = {0};

		/* Enable SPI2, and signal ports clock. */
	__HAL_RCC_SPI2_CLK_ENABLE();
	SPI2_SIGNAL_PORT_CLK_ENABLE();
	SD_CARD_CS_PORT_CLK_ENABLE();

  /* configure SPI2 SCK (GPIOB 13), and SPI2 MOSI (GPIOB 15)*/
	 
  gpioinitstruct.Pin        = SPI2_CLK_PIN | SPI2_MOSI_PIN;
  gpioinitstruct.Mode       = GPIO_MODE_AF_PP;
  gpioinitstruct.Pull       = GPIO_NOPULL;
  gpioinitstruct.Speed      = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(SPI2_SIGNAL_PORT, &gpioinitstruct);

	/* configure SD chip select line (GPIOB 11)*/

  gpioinitstruct.Pin        = SD_CARD_CS_PIN;
  gpioinitstruct.Mode       = GPIO_MODE_OUTPUT_PP;
  gpioinitstruct.Pull       = GPIO_NOPULL;
  gpioinitstruct.Speed      = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(SD_CARD_CS_PORT, &gpioinitstruct);

  /* Configure SPI MISO to input GPIOB 14 . 
	 * Note! The line must be configuring pull up mode, or pulling up physically 
	 * with resistor , because if there is not SD card, float the input line, 
	 * might cause disturbance input datas.   */
	 
  gpioinitstruct.Pin        = SPI2_MISO_PIN;
  gpioinitstruct.Mode       = GPIO_MODE_AF_INPUT;
  gpioinitstruct.Pull       = GPIO_PULLUP;
  gpioinitstruct.Speed      = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(SPI2_SIGNAL_PORT, &gpioinitstruct);

	SPI_Init(&sd_spi2_handle);

} 

/* SD_SPI_STATE SD_SPI_ReadExpectedByteWithinTimeOut(uint8_t* Value, SPI_HandleTypeDef 
 * handle, uint32_t TimeOut, uint8_t Expected)
 * @brief Reading from SD_SPI the expected byte. If expected data is come from SD_CARD 
 * within Timeout time, then will return with SD_SPI_OK with readed byte in Value for 
 * further uses. Else return with SD_SPI_TIMEOUT.*/

SD_SPI_STATE 
	SD_SPI_ReadExpectedByteWithinTimeOut(uint8_t* Value, SPI_HandleTypeDef handle, 
	uint32_t TimeOut, uint8_t Expected)
{ SD_SPI_STATE retval;
	do {
		SPI_ReadByte(Value, handle, 1000);
	} while (((*Value) != Expected) && (TimeOut--));
  return (*Value == Expected) ? SD_SPI_OK : SD_SPI_ERROR;
}

/* @brief ResetCard() Reset card with GO_IDLE_STATE.  */
SD_SPI_STATE ResetCard()
{ s_command command; s_r1 r1; uint32_t TimeOut = 3000; 
	SELECT_SD();
	command.start = 0;
	command.trm = 1;
	command.cind = GO_IDLE_STATE;
	command.args.argw = 0;	
	command.crc7 = 0x4A;
	command.end = 1;
	SPI_WriteBuf(&command, sizeof(command), sd_spi2_handle, 1000);
	return SD_SPI_ReadExpectedByteWithinTimeOut(&r1.b, sd_spi2_handle, 40000, 0x01);
}