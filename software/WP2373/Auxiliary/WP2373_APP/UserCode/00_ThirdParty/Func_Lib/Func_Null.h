#ifndef _FUN_NULL_H
#define _FUN_NULL_H

#include "includes.h"


void Function_Null_Void(void);
void Function_Null_U16(uint16_t x);


uint16_t U16_Add_One(uint16_t Num);
uint32_t U32_Add_One(uint32_t Num);

uint16_t U16_Add(uint16_t Num, uint16_t Step, uint16_t Max);
uint16_t U16_Sub(uint16_t Num, uint16_t Step, uint16_t Min);

uint32_t U32_Add(uint32_t Num, uint32_t Step, uint32_t Max);
uint32_t U32_Sub(uint32_t Num, uint32_t Step, uint32_t Min);

uint64_t U64_Add(uint64_t Num, uint64_t Step, uint64_t Max);
uint64_t U64_Sub(uint64_t Num, uint64_t Step, uint64_t Min);


#endif
