#ifndef _VOICE_H
#define _VOICE_H

#include "includes.h"



typedef struct
{
    //////// 存储器数据
    //uint8_t DeviceId;   // 不用

    //////// Info
    bool_t Info_IsReady;
    uint8_t Id;
    uint8_t Project_GetCnt;
    uint8_t Project_IsReady;
    char Project[16];

    //char Version[16];


    uint32_t DataSize;
    uint32_t DataChecksum;
    uint32_t Voice_AmountOf_256B;
    uint32_t Voice_AmountOf_4KB;
} Voice_t;
extern Voice_t Voice;


void Voice_Task(void);
void Voice_Test(void);


#include "GD25Q.h"
#include "WT588.h"
#include "VoiceFlash.h"
#include "VoiceCheck.h"
#include "Voice_Set.h"
#include "Voice_Once.h"



#endif

