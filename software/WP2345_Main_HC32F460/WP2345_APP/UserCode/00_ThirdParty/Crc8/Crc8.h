#ifndef _CRC8_H
#define _CRC8_H

#include "includes.h"


extern const uint8_t Crc8_Table[];

uint8_t Crc8_Calc(uint8_t *pBuf, uint32_t Length);


#endif
