

/* The indicator LED connect to C port 13-th PIN */

#include "stm32f1xx_hal.h"
#include "interrupts.h"
#include "init.h"
#include "sd_spi.h"

/**
 System Clock, and osc configuration for 8000000 Hz Minimal STM 32 board.
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



int main()
{
	/* Enable the DIVZERO exception. */
  SCB->CCR |= SCB_CCR_DIV_0_TRP;
	HAL_Init();
	SystemClock_Config();
	
	Init_ErrLED();
	
	SD_SPI2_Init(); // Initialize SPI2 for SD card. 

/* Main program loop. */
	while (1)
	{	
		
		if (GetSDCardCheckFlag())
		{

			SD_Card_SPI_Select();
			if (ResetCard() == SD_SPI_OK)
			{	
				ForceErrorNumber(4);
				GetSDCardFeatures();
			} else
			{
				ForceErrorNumber(2);				
			}
				
			ClearSDCardCheckFlag();
		}
	}		
	
	return 0;
	}