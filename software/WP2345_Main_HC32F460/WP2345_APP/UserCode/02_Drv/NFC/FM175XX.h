
#ifndef _FM175XX_H
#define _FM175XX_H
#include "hc32_common.h"


extern void FM175XX_HardReset(void);
extern unsigned char FM175XX_SoftReset(void);
extern void FM175XX_HPD(unsigned char mode);
extern unsigned char GetReg(unsigned char reg_address,unsigned char* reg_data);
extern unsigned char SetReg(unsigned char reg_address,unsigned char reg_data);
extern unsigned char ModifyReg(unsigned char reg_address,unsigned char mask,unsigned char set);
extern unsigned char SetCW(unsigned char mode);

void FM1755XX_Init(void);
#endif





