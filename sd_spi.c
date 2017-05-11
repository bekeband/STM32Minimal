

#include <stdint.h>
#include "spi.h"
#include "sd_spi.h"
#include "init.h"
#include "stm32f1xx_hal.h"

/* CRC table for CRC7 procedure 
 * Thanks for https://www.pololu.com/docs/0J1?section=5.f
 * */
#if defined (SD_CRC7)
	uint8_t CRCPoly = 0x89;  // the value of our CRC-7 polynomial
	uint8_t CRCTable[256];
#endif

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
	/* Generate the CRC7 chacksum table. */
#if defined (SD_CRC7)
	GenerateCRCTable(); 
#endif
	
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

/* SD_SPI_STATE SD_SPI_WaitValidResponse(s_r1* R1, SPI_HandleTypeDef 
 * handle, uint32_t TimeOut)
 * @brief Wait for valid response byte, or over time. Valid response byte with
 * most significant bit is 0. */

SD_SPI_STATE SD_SPI_WaitValidResponse(s_r1* R1, SPI_HandleTypeDef handle, uint32_t TimeOut)
{
	do {
		SPI_ReadByte((uint8_t*)R1, handle, 1000);
	} while ((R1->m_0) && (TimeOut--));
  return (!R1->m_0) ? SD_SPI_OK : SD_SPI_ERROR;
}

/* @brief SendSDCommand(uint8_t index, uint32_t args) 
 * @params: index command index, args: argumentums 
 * Simple command procedure */

void SendSDCommand(uint8_t index, s_args args)
{ s_command command;
	command.start = 0;
	command.trm = 1;
	command.cind = index;
	command.args = args;	
#if defined (SD_CRC7)
	command.crc7 = getCRCVal(command.datas, 5);
#endif
	command.end = 1;
	SPI_WriteBuf(&command, sizeof(command), sd_spi2_handle, SD_SPI2_TIMEOUT);
}

/* @brief ResetCard() Reset card with GO_IDLE_STATE.  */
SD_SPI_STATE ResetCard()
{ s_command command; s_r1 r1; SD_SPI_STATE retval;
	SELECT_SD();
	command.start = 0;
	command.trm = 1;
	command.cind = GO_IDLE_STATE;
	command.args.argw = 0;	
#if defined (SD_CRC7)
	command.crc7 = getCRCVal(command.datas, 5);
#else
	/* CRC7 preset value for CMD0 command. */
	command.crc7 = 0x4A;
#endif
	command.end = 1;
	SPI_WriteBuf(&command, sizeof(command), sd_spi2_handle, SD_SPI2_TIMEOUT);
	retval = SD_SPI_WaitValidResponse(&r1, sd_spi2_handle, SD_RESET_CARD_TIMEOUT);
	DESELECT_SD();
	return retval;
}

/*  Part_1_Physical_Layer_Simplified_Specification_Ver6.00.pdf 
 * 	Figure 7-2 : SPI Mode Initialization Flow
 * */

SD_INIT_RES GetSDCardFeatures()
{	s_command command; s_args args; s_r1 r1; SD_TYPE sd_type = VER_NONE; s_args resp;
	args.chk_pattern = PATT_8BIT; 
	args.VHS = VHS_27_36V;
	args.res08 = 0;
	SELECT_SD();
	/* Try CMD 8 response*/
	SendSDCommand(SEND_IF_COND, args);

	if (SD_SPI_WaitValidResponse(&r1, sd_spi2_handle, SD_RESET_CARD_TIMEOUT) 
				== SD_SPI_OK)
	{	
	
	if (r1.b == 0x01)	// Idle state return?
	{	/* All right get return datas */ 
		
		SPI_ReadBuf((uint8_t*)&resp.argw, sizeof(resp), sd_spi2_handle, 1000);
		
		if ((args.chk_pattern == PATT_8BIT) && (args.VHS == VHS_27_36V))
		{
			// Check pattern OK, and voltage OK.
		} else
		{
			return SD_ERR;
		}
	} else
	{
		if ((r1.ill_comm_err) && (r1.idle_state))	// Illegal Command?
		{ /* Ver1.X SD Memory Card or Not SD Memory Card */
			sd_type = VER1X;
		} else
		{ /* @TODO May take further consequence, and return with. */
			return SD_ERR;
		}
	}
	} else
	{	// not valid respunse...
		return SD_ERR;
	}
	
	
	
	/*	Here, if VER1X, or not */

 
	
//	retval = SD_SPI_ReadExpectedByteWithinTimeOut(&r1.b, sd_spi2_handle, SD_RESET_CARD_TIMEOUT, 0x01);
		
	
	DESELECT_SD();
	
}

/* ------------------- CRC7 procedures --------------------------*/
/* @TODO The table maybe to write the flash memory. Or maybe calculate on-line, 
 * not with table... */
/* Based on https://www.pololu.com/docs/0J1?section=5.f */

#if defined (SD_CRC7)

void GenerateCRCTable()
{
	int i, j;
 
	// generate a table value for all 256 possible byte values
	for (i = 0; i < 256; i++)
	{
		CRCTable[i] = (i & 0x80) ? i ^ CRCPoly : i;
		for (j = 1; j < 8; j++)
			{
				CRCTable[i] <<= 1;
				if (CRCTable[i] & 0x80) CRCTable[i] ^= CRCPoly;
			}
	}
}

// adds a message byte to the current CRC-7 to get a the new CRC-7
uint8_t CRCAdd(uint8_t CRC_VAL, uint8_t message_byte)
{
	return CRCTable[(CRC_VAL << 1) ^ message_byte];
}

// returns the CRC-7 for a message of "length" bytes
uint8_t getCRCVal(uint8_t message[], int length)
{
	int i;
	uint8_t CRC_VAL = 0;
 
	for (i = 0; i < length; i++)
		CRC_VAL = CRCAdd(CRC_VAL, message[i]);
 
  return CRC_VAL;
}

#endif