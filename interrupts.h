

#ifndef __INTERRUPTS_H
#define __INTERRUPTS_H


/* MACRO for LED ON-OFF functions */
#define IND_LED_ON()		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_RESET)
#define IND_LED_OFF()		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_SET)

#define IND_LED_TOGGLE()		HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13)

/* Gap for two blinking cycle for error indicate. */
#define BLINK_GAP 4
/* blink number for no error (1). */
#define NO_ERROR					1
#define NMI_NUMBER				2
#define HardFault_NUMBER 	3
#define MemManage_NUMBER	4
#define BusFault_NUMBER		5
#define UsageFault_NUMBER	6

/*Error blink cycle time in millisecondsd.*/
#define ERR_CT	100

/* I/O init for error LED. */
void Init_ErrLED();

#endif