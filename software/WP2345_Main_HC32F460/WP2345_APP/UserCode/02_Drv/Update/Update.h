#ifndef _UPDATE_H
#define _UPDATE_H

#include "includes.h"




typedef struct 
{
	  char Project_String[16]; //项目名，字符串
    char Machine_String[16]; //部位，字符串
    char Mcu_String[16];     //MCU，字符串
	
    uint32_t Length;    // 0x20
    uint32_t Checksum;  // 0x24
    //
    uint32_t Pages;
    uint32_t Kilos;
	
	  uint8_t ret;        // 0有错误，1正确
} Update_Info_t;
extern Update_Info_t Update_Info;



uint8_t UpData_App1_Write(uint16_t Kilo, const uint8_t *pBuf, uint16_t Length);


#endif
