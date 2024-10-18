#ifndef _APP_BMS_UARTTX_H
#define _APP_BMS_UARTTX_H

#include "includes.h"



#define BMS_TX_REPEAT_TIMES     (5)

extern volatile bool_t BmsTx_Flag;
extern volatile const uint8_t *Bms_TxFrame;
extern volatile uint8_t Bms_TxCnt;

extern volatile uint8_t Bms_TxBuf[30];

#define BMS_LOOP_BIT_VACUUM		(BIT7)  // 无刷电机控制
#define BMS_LOOP_BIT_Change		(BIT6)
#define BMS_LOOP_BIT_Capacity   (BIT5)
#define BMS_LOOP_BIT_Version    (BIT4)  //
#define BMS_LOOP_BIT_Id         (BIT3)
#define BMS_LOOP_BIT_UcpOff     (BIT2)
#define BMS_LOOP_BIT_CurTemp    (BIT1)
#define BMS_LOOP_BIT_Voltage    (BIT0)
#define BMS_LOOP_BITS           (0xFF)  // 包含以上所有

#define BMS_CHARGE   			1
#define BMS_DISCHARGE      		2

extern volatile uint8_t BmsLoop_Content;
extern volatile uint8_t BmsLoop_State;
extern volatile uint8_t Bms_State;
void BmsLoop_Reset(void);




void Bms_PrintFrame(const uint8_t Buf[]);
void BmsTx_Task(void);

void Bms_LowLevel_Transmit(uint8_t *pbuf, uint16_t len);


#endif

