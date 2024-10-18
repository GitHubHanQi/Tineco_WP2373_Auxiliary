#ifndef _S_SPI_H
#define _S_SPI_H

#include "includes.h"

#define SPI_UNIT                        (M4_SPI3)
#define SPI_UNIT_CLOCK                  (PWC_FCG1_PERIPH_SPI3)

void sSPI_Init(void);
void sSPI_DeInit(void);

uint8_t SPI_WriteReadByte(uint8_t TxData);

void SPI_WriteArray(const uint8_t *pBuf, uint16_t Length);
void SPI_ReadArray(uint8_t *pBuf, uint16_t Length);
void SPI_Busy_Wait(void);
void SPI_CS_Enable(void);
void SPI_CS_Disable(void);

void SPI_Test(void);



#endif
