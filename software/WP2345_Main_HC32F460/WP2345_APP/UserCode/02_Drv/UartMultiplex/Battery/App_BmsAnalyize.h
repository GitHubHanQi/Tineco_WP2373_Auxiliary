#ifndef _APP_BMS_ANALYIZE_H
#define _APP_BMS_ANALYIZE_H

#include "includes.h"

uint16_t StringCopy(volatile uint8_t *pStrTo, const uint8_t *pStrFrom);
bool_t StringIsDiff(const uint8_t *pStr1, const uint8_t *pStr2);
void Bms_Analyize(void);
bool_t StringIsNormalAscii(uint8_t ch);

#endif

