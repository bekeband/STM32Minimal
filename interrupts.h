

#ifndef __INTERRUPTS_H
#define __INTERRUPTS_H

/* Check the sd card timer flag */
uint16_t SD_CARD_CHECK_FLAG;

 /* @brief SD_CARD_CHECK_INTERVAL The intelvel in milliseconds thet SD CARD check
  * inserting. Because the card detect input is not connected, we asking recently
	* intervals the SD card existing, with trying SPI mode, and idle state.  
  * If not defined we must solution anymore way to detect SD card! (For example
	* detect input from SD card connector.) */
#define SD_CARD_CHECK_INTERVAL	2000

#if defined SD_CARD_CHECK_INTERVAL

/* @brief Force error number from outside. Purpose of test and debug. */
void ForceErrorNumber(uint16_t enumb);

/* @brief GetSDCardCheckFlag() return the timer flag for SD card check */

inline static uint16_t GetSDCardCheckFlag(){ return SD_CARD_CHECK_FLAG;}

/* @brief ClearSDCardChackFlag() clear the timer flag for SD card check. */
inline static void ClearSDCardCheckFlag(){ SD_CARD_CHECK_FLAG = 0; }
#endif

#endif