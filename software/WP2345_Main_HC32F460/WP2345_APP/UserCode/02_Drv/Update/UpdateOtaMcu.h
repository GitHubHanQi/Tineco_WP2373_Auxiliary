#ifndef _UPDATE_OTA_MCU_H
#define _UPDATE_OTA_MCU_H

#include "includes.h"


typedef struct
{
    uint32_t Tick;
    uint8_t Finish_Flag;    // ��������
    uint8_t Voice_Flag;     // ��������

} UpdataOtaMcu_t;
extern UpdataOtaMcu_t UpdataOtaMcu;

void UpdataOtaMcu_Task(void);
void UpdataOtaMcu_FrameAnalyize(void);
void UpDataOtaMCU_App1Write(void);

#endif
