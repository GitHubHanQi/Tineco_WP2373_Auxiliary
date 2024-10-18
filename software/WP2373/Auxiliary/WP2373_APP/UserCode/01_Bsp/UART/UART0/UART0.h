#ifndef _UART0_H
#define _UART0_H

#include "includes.h"

#include "UART0_Tx.h"
#include "UART0_Rx.h"

void Uart0_IRQHandler_Tx(void);
void UART0_Init(void);
void Uart0_IRQHandler_Rx(void);
void M4_Uart0_ErrorCallBack(void);
void UART0_Task(void);


#endif
