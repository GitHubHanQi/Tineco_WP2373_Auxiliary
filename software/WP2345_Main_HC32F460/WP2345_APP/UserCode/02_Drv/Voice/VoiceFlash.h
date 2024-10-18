#ifndef _VOICE_FLASH_H
#define _VOICE_FLASH_H

#include "includes.h"



typedef struct 
{
    uint32_t Tick;
    //uint8_t Id;
    //char Project[16];

    enum
    {
        VoiceFlashState_Start,
        VoiceFlashState_Read,
        VoiceFlashState_Check,
        VoiceFlashState_Idle,   // SPIø’œ–£¨ø…“‘≤•∑≈”Ô“Ù
    } State;

} VoiceFlash_t;
extern VoiceFlash_t VoiceFlash;


void VoiceFlash_Task(void);


#endif

