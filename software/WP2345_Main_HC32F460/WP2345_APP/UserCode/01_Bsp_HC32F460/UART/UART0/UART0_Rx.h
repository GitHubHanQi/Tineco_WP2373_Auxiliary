#ifndef _UART0_Rx_H
#define _UART0_Rx_H

#include "includes.h"



#define UART0_RX_BUF_SIZE      (20)
typedef struct
{
    uint8_t Buf[UART0_RX_BUF_SIZE];
    uint16_t RxCount;
	  uint8_t FrameHeader;
    uint8_t OverFlag;

} UART0_Rx_t;

extern UART0_Rx_t UART0_Rx;

extern uint8_t FrameNum;//֡��
extern uint8_t FaucetReplyFlag;//��ͷ������

void UART0_Rx_Byte_Analysis(uint8_t x);
void UART0_Rx_Task(void);
extern uint8_t CheckSum(uint8_t *buf ,uint16_t len);

#endif
