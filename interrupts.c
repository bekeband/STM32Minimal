

/*
 * Interrupts.c interrupt handlers, and exceptions procedures.
 * */

#include <stdint.h>
#include "init.h"
#include "stm32f1xx_hal.h"

/* We must be defined the SysTick handler, because the HAL library does not 
 * define 'standard' Systick handler, so the Systick interrupt procedure goes 
 * to infinity cycle.  
 * */
/* Cycles in msec. */
static uint16_t blink_number = 0;
/* Error number value for error output to indicator LED. */
static uint16_t error_number = NO_ERROR;

/* @brief SysTick_Handler(void) The systick everi 1 msec handler. This procedure
 * threatments the error_number state LED blinking as well. */

void SysTick_Handler(void)
{
  HAL_IncTick();
	/* Simple cycle for error display on indicator LED. */
	if (!(HAL_GetTick() % ERR_CT))
	{
		blink_number++;
		if (blink_number <= (error_number * 2))
			IND_LED_TOGGLE();
		if (blink_number >= ((error_number * 2) + BLINK_GAP))
			blink_number = 0;
	}
}

/* NMI handler, and fault exceptions. We do not call default handler, (infiniti loop) 
 * we indicate the error and we hope, that will all right turn. */ 

void NMI_Handler(void)
{
	error_number = NMI_NUMBER;
}

void HardFault_Handler(void)
{
	/* div by zero ?? */
	if (SCB->CFSR & SCB_CFSR_DIVBYZERO)
	{
		error_number = HardFault_NUMBER;
		/* Let fast clear the div zero trap !! The blink remain, but the program 
		 * runing continue. */
		SCB->CCR &= ~SCB_CCR_DIV_0_TRP;
	} else
	{	/* else Reset (for example...) */
		SCB->AIRCR |= SCB_AIRCR_SYSRESETREQ_Msk;
	}
}

void MemManage_Handler(void)
{
	error_number = MemManage_NUMBER;
}

void BusFault_Handler(void)
{
	error_number = BusFault_NUMBER;
}

void UsageFault_Handler(void)
{
	error_number = UsageFault_NUMBER;
}
