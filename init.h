
#ifndef __INIT_H
#define __INIT_H

/* Erro LED functions and constants ------------------------------------ */
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

/* ----------------- Error LED end --------------------------------*/

void SD_SPI2_Init();

/* @brief Baud rate prescaler for configutration fhase, To the SD card SPI mode
 * must be at least 74 bits times keep high the data line. The max. SPI speed of 
 * 400 kHz,and this prescaler applies this SPI speed. 
 * */
#define CONFIG_BAUD_PRESCALER	256

/* @brief Th prescaler determine the data stream of SPI2 SD card channel. 
 * */
#define DATA_BAUD_PRESCALER		4

/* ----------------------------------------------------------------*/

#endif