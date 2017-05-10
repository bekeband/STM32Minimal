
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

/* ----------------- SD card I/O-s --------------------------------*/

#define SPI2_SIGNAL_PORT	GPIOB

#define SPI2_SIGNAL_PORT_CLK_ENABLE() __HAL_RCC_GPIOB_CLK_ENABLE()

#define SPI2_CLK_PIN	GPIO_PIN_13
#define SPI2_MOSI_PIN	GPIO_PIN_15
#define SPI2_MISO_PIN	GPIO_PIN_14

#define SD_CARD_CS_PORT	GPIOB
#define SD_CARD_CS_PORT_CLK_ENABLE() __HAL_RCC_GPIOB_CLK_ENABLE()

#define SD_CARD_CS_PIN	GPIO_PIN_11

#define SELECT_SD()	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, GPIO_PIN_RESET)
#define DESELECT_SD()	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, GPIO_PIN_SET)

/* ----------------------------------------------------------------*/

#endif