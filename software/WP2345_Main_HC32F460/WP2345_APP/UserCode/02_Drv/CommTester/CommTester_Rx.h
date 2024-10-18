#ifndef _COMM_TESTER_RX_H
#define _COMM_TESTER_RX_H

#include "includes.h"


// #define COMM_RX_FRAME_HEAD    (0xF1) // 调试用
// #define COMM_RX_FRAME_END     (0xF2)
#define COMM_RX_FRAME_HEAD      (0xF2)
#define COMM_RX_FRAME_END       (0xF1)

typedef enum
{
	CommRxState_Head,
	CommRxState_SendAddr,
	CommRxState_RecvAddr,
	CommRxState_CmdH,
	CommRxState_CmdL,
	CommRxState_Len,
	CommRxState_Data,
	CommRxState_Checksum,
	CommRxState_End,
} CommTester_Rx_State_t;


typedef struct 
{
    //////// 字节
    uint16_t Tick;
    CommTester_Rx_State_t State;
    uint8_t Checksum;
    uint8_t Index;

    //////// 帧
    CommTester_Frame_t Frame;   // 地址、指令、长度
    uint8_t Data[64 + 16];           // 数据域
    bool_t Flag;


    //////// Test
    uint32_t Byte_Cnt0;
    uint32_t Byte_Cnt1;
    uint32_t Frame_Cnt;
} CommTester_Rx_t;
extern CommTester_Rx_t CommTester_Rx;


void CommTester_Rx_Clear(void);
void CommTester_Rx_Task(void);
void CommTester_Rx_Byte_Analysis(uint8_t RxData);


#endif
