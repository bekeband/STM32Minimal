
/* The board, and I/O, and port configuration etc... */

#include "init.h"
#include "stm32f1xx_hal.h"


/*
 * SD card SPI handle. SPI2 channel.
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


/* @brief  Indicator LED port configuration.
 * The indicatorLED is PC port 13-th pin.*/
void InitIndicatorLED()
{
  GPIO_InitTypeDef  gpioinitstruct = {0};
	/* C port clock enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();

  /* configure LED port GPI/O */
  gpioinitstruct.Pin        = GPIO_PIN_13;
  gpioinitstruct.Mode       = GPIO_MODE_OUTPUT_PP;
  gpioinitstruct.Speed      = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(GPIOC, &gpioinitstruct);
  IND_LED_OFF();
}
/* Initialize the error LED */
void Init_ErrLED()
{
	InitIndicatorLED();
}

/* @brief SPI_Init(SPI channel) Initialize on the got parameter SPI channel
		
 * */

void SPI_Init(SPI_HandleTypeDef* SPI_Chan)
{
	HAL_SPI_DeInit(SPI_Chan);
  if (HAL_SPI_Init(SPI_Chan) != HAL_OK)
  {
    /* Should not occur */
    while(1) {};
  }
}

/* @brief SD_SPI2_Init(): initialize SPI 2 signals for SD card reader, 
 * and set SPI channel, and initialize CS line for standard I/O. */

void SD_SPI2_Init()
{
  GPIO_InitTypeDef  gpioinitstruct = {0};

		/* ENable SPI2 clock, and GPIOB port clock */
	__HAL_RCC_SPI2_CLK_ENABLE();
	__HAL_RCC_GPIOB_CLK_ENABLE();
	
  /* configure SPI2 SCK (GPIOB 13), and SPI2 MOSI (GPIOB 15), and SD card 
	 * chip select line (GPIOB 11)*/
  gpioinitstruct.Pin        = GPIO_PIN_13 | GPIO_PIN_15 | GPIO_PIN_11;
  gpioinitstruct.Mode       = GPIO_MODE_AF_PP;
  gpioinitstruct.Pull       = GPIO_NOPULL;
  gpioinitstruct.Speed      = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(GPIOB, &gpioinitstruct);

  /* Configure SPI MISO to input GPIOB 14 . Note! The line must be configuring 
	 * pullup mode, because if there aren't SD card, float the input line, 
	 * might cause disturbance input datas.   */
  gpioinitstruct.Pin        = GPIO_PIN_14;
  gpioinitstruct.Mode       = GPIO_MODE_AF_INPUT;
  gpioinitstruct.Pull       = GPIO_PULLUP;
  gpioinitstruct.Speed      = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(GPIOB, &gpioinitstruct);

	
	
	
}