#ifndef _UPDATE_OTA_VOICE_H
#define _UPDATE_OTA_VOICE_H

#include "includes.h"



typedef enum
{
    OtaVoiceState_Stop,
    ////OtaVoiceState_Start,
    OtaVoiceState_Check,
    OtaVoiceState_Write,
    OtaVoiceState_Copy,
} UpdataOtaVoice_State_t;

typedef struct
{
    UpdataOtaVoice_State_t State;
    uint8_t Flag;
    uint32_t Tick;
    //
    uint32_t Test_Cnt;
	uint32_t TimeOut_1ms;
} UpdataOtaVoice_t;
extern UpdataOtaVoice_t UpdataOtaVoice;



void UpdataOtaVoice_Start(void);
void UpdataOtaVoice_Stop(void);
void UpdataOtaVoice_Task(void);

void UpDataOtaVoice_Write(void);


#endif
