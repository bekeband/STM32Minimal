
#ifndef __SD_SPI_H
#define __SD_SPI_H

/* Definitions and macros for SD card SPIcommunication.
 * Base the http://elm-chan.org/docs/mmc/mmc_e.html 
 
	define SD SPI commands  */

/*In idle state, the card accepts only CMD0, CMD1, ACMD41,CMD58 and CMD59.*/

#define GO_IDLE_STATE (0)	// 	0 R1	No	GO_IDLE_STATE	Software reset.
#define SEND_OP_COND	(1)	//	0 R1	No		Initiate initialization process.
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
 
#endif

