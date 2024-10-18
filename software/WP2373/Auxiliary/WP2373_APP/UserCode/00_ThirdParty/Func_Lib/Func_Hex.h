#ifndef _FUN_HEX_H
#define _FUN_HEX_H

#include "includes.h"


bool_t TypeConvert_Hex1_to_U8(uint8_t *pToByte, uint8_t FromByte);
uint8_t TypeConvert_Hex2_to_U8(const char *pHex2);
void TypeConvert_ArrayHex2_to_ArrayU8(uint8_t *pToU8, const char *pFromHex2, uint16_t len);


uint16_t TypeConvert_ArrayU8_to_ArrayHex2(uint8_t *pToArrayHex2, const uint8_t *pFromArrayU8, uint16_t LenFromArrayU8);


void Uint32_To_Hex(uint32_t num, char *hex);
void Uint64_To_Hex(uint64_t num, char *hex);

#endif
