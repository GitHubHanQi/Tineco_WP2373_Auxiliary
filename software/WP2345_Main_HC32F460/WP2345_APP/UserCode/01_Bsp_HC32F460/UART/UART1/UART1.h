#ifndef _UART1_H
#define _UART1_H

#include "includes.h"

extern uint8_t NFC_RX;
extern uint8_t NFC_RXEnd;

void Uart1_IRQHandler(void);
void M4_Uart2_ErrorCallBack(void);
void Uart1_IRQHandler_Tx(void);
void Uart1_IRQHandler_Rx(void);

void UART1_Init(void);
void UART1_Task(void);


#include "UART1_Tx.h"
#include "UART1_Rx.h"


#endif
