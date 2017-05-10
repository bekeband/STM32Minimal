
#ifndef __SD_SPI_H
#define __SD_SPI_H

/* Definitions and macros for SD card SPIcommunication.
 * SDCARD https://www.sdcard.org/downloads/pls/ 
 * Physical Layer Simplified Specification pdf */

/*7.3.1.3 Detailed Command Description 
 * The following table provides a detailed description of the SPI bus commands. 
 * The responses are defined in Section 7.3.2. Table 7-3 lists all SD Memory Card commands. 
 * A "yes" in the SPI mode column indicates that the command is supported in SPI mode. 
 * With these restrictions, the command class description in the CSD is still valid. 
 * If a command does not require an argument, the value of this field should be set to zero. 
 * The reserved commands are reserved in SD mode as well. The binary code of a command is 
 * defined by the mnemonic symbol. As an example, the content of the command index field 
 * is (binary) '000000' for CMD0 and '100111' for CMD39. The card shall ignore stuff bits 
 * and reserved bits in an argument.*/

#define GO_IDLE_STATE (0)	// 	[31:0] stuff bits R1	No	Resets the SD Memory Card

/* @brief SEND_OP_COND Sends host capacity support information and activates the card's 
 * initialization process. HCS is effective when card receives SEND_IF_COND command. Reserved 
 * bits shall be set to '0'. [31]Reserved bit [30]HCS [29:0]Reserved bits*/
#define SEND_OP_COND	(1)	//	 R1	

/* CMD8 9 Yes [31:12]Reserved SEND_IF_COND Sends SD Memory Card interface bits condition that 
 * includes host supply [11:8]supply voltage information and asks the voltage(VHS) accessed 
 * card whether card can [7:0]check pattern operate in supplied voltage range. Reserved bits 
 * shall be set to '0'. */
 
#define SEND_IF_COND (8)

#define APP_SEND_OP_COND (0x41) // *2 		R1	No		For only SDC. Initiate initialization process.
#define SEND_IF_COND (8)	//CMD8	*3			R7	No		For only SDC V2. Check voltage range.
#define SEND_CSD	(9)	//		CMD9	None(0)	R1	Yes		Read CSD register.
#define SEND_CID	(10)//		CMD10	None(0)	R1	Yes		Read CID register.
#define STOP_TRANSMISSION	(12)	// CMD12	None(0)	R1b	No		Stop to read data.
#define SET_BLOCKLEN (16)	CMD16	// Blocklength[31:0]	R1	No		Change R/W block size.
#define READ_SINGLE_BLOCK (17)	//CMD17	Address[31:0]	R1	Yes		Read a block.
#define READ_MULTIPLE_BLOCK (18)//CMD18	Address[31:0]	R1	Yes		Read multiple blocks.
#define SET_BLOCK_COUNT (23)	/* CMD23	Number of blocks[15:0]	R1	No		For only MMC. Define number of blocks to transfer
						with next multi-block read/write command.*/
#define SET_WR_BLOCK_ERASE_COUNT (23) /* ACMD23(*1)	Number of blocks[22:0]	R1	No		For only SDC. Define number of blocks to pre-erase
						with next multi-block write command.*/
#define WRITE_BLOCK (24) // CMD24	Address[31:0]	R1	Yes		Write a block.
#define WRITE_MULTIPLE_BLOCK (25) // CMD25	Address[31:0]	R1	Yes		Write multiple blocks.
#define APP_CMD (0x55) // CMD55(*1)	None(0)	R1	No		Leading command of ACMD<n> command.
#define READ_OCR (0x58) // CMD58	None(0)	R3	No		Read OCR. 
  
#define SD_DUMMY_BYTE	(0xFF) 
//* SDCARD https://www.sdcard.org/downloads/pls/ 
// * Physical Layer Simplified Specification pdf

/* @brief enumeration SD_SPI result states */

typedef enum {
	SD_SPI_OK = 0,
	SD_SPI_TIMEOUT = 1,
	SD_SPI_ERROR = -1
} SD_SPI_STATE;
 
void SD_SPI2_Init(); 
void SD_Card_SPI_Select(); 

/* @brief ResetCard() */
SD_SPI_STATE ResetCard();

/* Struct of command bits (all command are 40 bits) */
typedef union {
	uint32_t argw;
	struct {
			uint32_t res01: 1;
			uint32_t HCS: 1;
			uint32_t res02: 29;		
	};
}s_args;

/* 4.7.2 Command Format All commands have a fixed code length of 48 bits.
 * SDCARD https://www.sdcard.org/downloads/pls/ 
 * Physical Layer Simplified Specification pdf
*/

typedef union {
	struct __attribute__ ((__packed__)){
		uint8_t cind:	6;		// Command index
		uint8_t trm : 1;		// Transmission bit
		uint8_t start : 1;	// Start bit
		s_args args;				// Argument
		uint8_t end: 1;			// End bit		
		uint8_t crc7: 7;		// CRC7
	};
	uint8_t datas[6];
} s_command;

typedef union {
	struct __attribute__ ((__packed__)){
	uint8_t idle_state : 1; 	// in idle state
	uint8_t erase_res : 1; 	// erase reset
	uint8_t ill_comm_err : 1; 	// illegal command error
	uint8_t com_crc_err : 1; 	// com crc error
	uint8_t er_seq_err : 1; 	// erase sequence error
	uint8_t addr_err : 1; 	// address error
	uint8_t parm_err : 1;	// parameter error
	uint8_t : 1;
	};
	uint8_t b;		
} s_r1;

/* @brief Baud rate prescaler for configutration fhase, To the SD card SPI mode
 * must be at least 74 bits times keep high the data line. The max. SPI speed of 
 * 400 kHz,and this prescaler applies this SPI speed. 
 * */
#define CONFIG_BAUD_PRESCALER	256

/* @brief Th prescaler determine the data stream of SPI2 SD card channel. 
 * */
#define DATA_BAUD_PRESCALER		4
 
#endif

