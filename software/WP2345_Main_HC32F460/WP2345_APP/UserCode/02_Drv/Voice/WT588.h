#ifndef _WT588_H
#define _WT588_H

#include "includes.h"



#include "WT588_TxBit.h"
#include "WT588_TxData.h"
#include "WT588_Busy.h"
#include "WT588_Group.h"
#include "WT588_Normalize.h"



typedef struct 
{
    uint32_t Tick;
    enum
    {
        WT588State_Start,
        WT588State_Init,
        WT588State_Run,
    } State;

    //uint8_t Mute;   // 0正常播放，1静音
    //uint8_t Volume; // 0~7
    bool_t Volume_Flag; // 0音量未初始化，1音量已初始化。语音芯片重启后，需要重新初始化


    //////// Bit
    uint16_t TxBit_Tick;
    WT588_TxBit_State_t TxBit_State;
    uint16_t TxBit_Pos;
    uint16_t TxBit_Data;                // 正在输出bit和播放中的数据

    //////// Data
    uint16_t Tx_Buf[WT588_TX_SIZE];
    uint16_t Tx_Len;                // 缓冲区剩余语句长度


    //////// Busy
    uint8_t Comm_Busy;              // 通信完成后，等待语音播放
    uint16_t CommBusy_DelayTick;    // 通信结束后的延时
    uint8_t Pin_Busy;               // 端口
    uint8_t Voice_Busy;             // Pin_Busy 或 Comm_Busy。 表示语音播放中，不应该被打断
    uint8_t Speaker_Busy;           // Voice_Busy， 或 Bit不是Idle， 或Buf有数据。电机功率应该降低
    //
    uint8_t DeepPowerDown_Flag;     // 1s之后休眠
    uint32_t DeepPowerDown_Tick;


    //////// Error
    uint32_t Error_Tick;
    uint8_t Error;  // 0正常，1)Busy故障
} WT588_t;
extern WT588_t WT588;



void WT588_Task(void);

void WT588_Voice_Open(void);
void WT588_Voice_Close(void);
void WT588_Voice_Shift(void);









#endif

