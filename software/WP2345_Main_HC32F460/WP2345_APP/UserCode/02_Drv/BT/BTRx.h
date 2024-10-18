#ifndef _BTRX_H
#define _BTRX_H

#include "includes.h"

#define COMM_BT_RX_HEAD1    (0xF1)
#define COMM_BT_RX_HEAD2    (0xF2)
#define COMM_PANEL_RX_FUNC     (0xCC)
#define COMM_PANEL_RX_END     (0x7E)

#define COMM_BT_RX_SIZE    (100)



typedef enum
{
	BTRxState_Head,
	BTRxState_CC,
	BTRxState_Len,
	BTRxState_Data,
	BTRxState_End,
} BTRx_State_t;




typedef struct 
{
    uint16_t Tick;
    uint8_t Buf1[COMM_BT_RX_SIZE];
		uint8_t Buf2[COMM_BT_RX_SIZE];
    BTRx_State_t State;
    uint8_t Checksum;
    uint16_t Len;
    uint16_t Index;
    //
    bool_t FrameFlag;   // 接收到一帧的标志
} BTRx_t;
extern BTRx_t BTRx;

void BTRx_Task(void);
void BTRx_Analyize(void);
void BTRx_Byte_Analyize(uint8_t RxData);




typedef struct
{
    uint32_t   Weigh1;
    uint32_t   Weigh2;
    uint32_t   Weigh3; 	
    uint32_t   W1;
    uint32_t   W2;
    uint32_t   W3; 
    uint32_t   WR; 
    uint32_t   Water; 
} prinflogo_struct_t;


void  Printflogo(prinflogo_struct_t logodata);
void  Printflogo8(prinflogo_struct_t logodata);

void BTTx_Task(void);
#endif

