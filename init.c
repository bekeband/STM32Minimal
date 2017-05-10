
/* The board, and I/O, and port configuration etc... */

#include "init.h"
#include "stm32f1xx_hal.h"

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

