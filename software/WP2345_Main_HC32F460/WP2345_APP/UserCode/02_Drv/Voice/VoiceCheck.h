#ifndef _VOICE_CHECK_H
#define _VOICE_CHECK_H

#include "includes.h"



#define SPI_BUF_SIZE    (16)

#define VOICE_PROJECT_ADDR      (0x00)
#define VOICE_PROJECT_LEN       (10)

#define VOICE_CHECK_0x76_ADDR   (0x76)
#define VOICE_CHECK_0x76_VALUE  (0x01)  // 0x00»ò0x01

#define VOICE_CHECK_0x80_ADDR   (0x80)
#define VOICE_CHECK_0x80_VALUE  (0x00)  // 0x00


void Voice_Read_Project(void);
void Voice_Check_Error(uint32_t Addr, uint8_t Data);


#endif
