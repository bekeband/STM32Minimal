

/* The indicator LED connect to C port 13-th PIN */

#include "stm32f1xx_hal.h"
/* MACRO for LED ON-OFF functions */
#define IND_LED_ON()		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_RESET)
#define IND_LED_OFF()		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_SET)

/* We must be defined the SysTick handler, because the HAL library does not 
 * define 'standard' Systick handler, so the Systick interrupt procedure goes 
 * to infinity cycle.  
 * */
 
void SysTick_Handler(void)
{
  HAL_IncTick();
}

/**
  * @brief  System Clock Configuration
  *         The system Clock is configured as follow : 
  *            System Clock source            = PLL (HSE)
  *            SYSCLK(Hz)                     = 72000000
  *            HCLK(Hz)                       = 72000000
  *            AHB Prescaler                  = 1
  *            APB1 Prescaler                 = 2
  *            APB2 Prescaler                 = 1
  *            HSE Frequency(Hz)              = 8000000
  *            HSE PREDIV1                    = 1
  *            PLLMUL                         = 9
  *            Flash Latency(WS)              = 2
  * @param  None
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_ClkInitTypeDef clkinitstruct = {0};
  RCC_OscInitTypeDef oscinitstruct = {0};
  
  /* Enable HSE Oscillator and activate PLL with HSE as source */
  oscinitstruct.OscillatorType  = RCC_OSCILLATORTYPE_HSE;
  oscinitstruct.HSEState        = RCC_HSE_ON;
  oscinitstruct.HSEPredivValue  = RCC_HSE_PREDIV_DIV1;
  oscinitstruct.PLL.PLLState    = RCC_PLL_ON;
  oscinitstruct.PLL.PLLSource   = RCC_PLLSOURCE_HSE;
  oscinitstruct.PLL.PLLMUL      = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&oscinitstruct)!= HAL_OK)
  {
    /* Initialization Error */
    while(1);
  }

  /* Select PLL as system clock source and configure the HCLK, PCLK1 and PCLK2 
     clocks dividers */
  clkinitstruct.ClockType = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2);
  clkinitstruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  clkinitstruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  clkinitstruct.APB2CLKDivider = RCC_HCLK_DIV1;
  clkinitstruct.APB1CLKDivider = RCC_HCLK_DIV2;  
  if (HAL_RCC_ClockConfig(&clkinitstruct, FLASH_LATENCY_2)!= HAL_OK)
  {
    /* Initialization Error */
    while(1);
  }
}

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

int main()
{
	HAL_Init();
	SystemClock_Config();
	InitIndicatorLED();
	while (1)
	{	/* Blinking LED */
		IND_LED_ON();
		/*First LED on. If on the LED we are sure that program reached this point. */
		HAL_Delay(500);
		/* 50 percent duty cycle LED lighting. If we took any mistake of clock, we 
		wiil seen any half-light cindering or something else. */
		IND_LED_OFF();
		HAL_Delay(500);
	}		
	
	return 0;
}