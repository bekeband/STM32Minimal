

#include "spi.h"


/* @brief Handle for SPI general error.  
 * @TODO What we are to do?   
 * */

void SPI_Error()
{
	
}

/* @brief SPI_Init(SPI channel) Initialize on the got parameter SPI channel */

void SPI_Init(SPI_HandleTypeDef* SPI_Chan)
{
	HAL_SPI_DeInit(SPI_Chan);
  if (HAL_SPI_Init(SPI_Chan) != HAL_OK)
  {
    /* Should not occur */
    while(1) {};
  }
}

/**
  * @brief SPI_WriteByte Write a byte to SPI handle port.
  * @param Value the byte to written, TimeOut the timeout value to write. 
  * @retval None
  */
void SPI_WriteByte(uint8_t Value, SPI_HandleTypeDef handle, uint32_t TimeOut)
{
  HAL_StatusTypeDef status = HAL_OK;

  status = HAL_SPI_Transmit(&handle, (uint8_t*) &Value, 1, TimeOut);

  /* Check the communication status */
  if(status != HAL_OK)
  {
    /* Execute user timeout callback */
    SPI_Error(handle);
  }
}

/**
  * @brief SPI_WriteBuf Write buffer bytes to the selected SPI port.
  * @param Value the pointer for buffer, size: size of buffer in bytes 
	* TimeOut the timeout value to write. 
  * @retval None
  */

void SPI_WriteBuf(void* Value, uint16_t size, SPI_HandleTypeDef handle, uint32_t TimeOut)
{
  HAL_StatusTypeDef status = HAL_OK;

  status = HAL_SPI_Transmit(&handle, (uint8_t*) Value, size, TimeOut);

  /* Check the communication status */
  if(status != HAL_OK)
  {
    /* Execute user timeout callback */
    SPI_Error(handle);
  }
}

/**
  * @brief SPI_ReadByte Read a byte from SPI port designated by handle.
  * @param Value the byte to read, TimeOut the timeout value to read. 
  * @retval None
  */
void SPI_ReadByte(uint8_t* Value, SPI_HandleTypeDef handle, uint32_t TimeOut)
{
  HAL_StatusTypeDef status = HAL_OK;

  status = HAL_SPI_Receive(&handle, (uint8_t*) Value, 1, TimeOut);

  /* Check the communication status */
  if(status != HAL_OK)
  {
    /* Execute user timeout callback */
    SPI_Error(handle);
  }
}
