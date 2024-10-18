#ifndef _APP_BMS_RX_H
#define _APP_BMS_RX_H

#include "includes.h"



typedef enum
{
	BmsUartRxState_Header,
	BmsUartRxState_Reqaddr,
	BmsUartRxState_Rspaddr,
	BmsUartRxState_Func,
	BmsUartRxState_Cmd,
	BmsUartRxState_Len,
	BmsUartRxState_Data,
	BmsUartRxState_Checksum,
	BmsUartRxState_End
} enum_BmsUartRx_State_t;
extern volatile enum_BmsUartRx_State_t BmsUartRx_State;

#define BMS_RX_BUF_SIZE			(5+16 + 8 + 10)
extern uint8_t BmsRx_Buf[];
extern volatile uint8_t BmsUartRx_Index;
extern volatile uint8_t BmsUartRx_Len;
extern volatile uint8_t BmsUartRx_Checksum;

extern volatile uint8_t BmsRx_Len;  
extern volatile _Bool Flag_Bms_ReceiveEnd;

void BmsUartRx_Clear(void);
void BmsRx_ISR(uint8_t UartRx_Data);

void BmsRx_Check(void);


#endif

