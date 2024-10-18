#ifndef _BOOTLOADER_H_
#define _BOOTLOADER_H_
#include "drv_flash.h"


typedef struct 
{
    //////// 从 Info 区获取的信息
    uint32_t Mark;
    uint32_t Length;        // 0x40
    uint32_t Checksum;      // 0x44
    //
    uint32_t Pages;

    //////// App1 计算出的数据
    uint32_t App1_Checksum;
} Update_Info_t;
extern Update_Info_t Update_Info;



void Boot(void);
void Boot_Get_Mark(void);
void Boot_Get_Info(void);
void Boot_Get_App1Checksum(void);
void Boot_CopyApp(void);
void Boot_EraseMark(void);

void JumpTo(uint32_t Addr);


#endif
