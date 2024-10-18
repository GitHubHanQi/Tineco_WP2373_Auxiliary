#ifndef _UART3_H
#define _UART3_H

#include "includes.h"


void UART3_Init(void);
void Uart3_IRQHandler_Tx(void);
void Uart3_IRQHandler_Rx(void);
void M4_Uart3_ErrorCallBack(void);

void UART3_Task(void);

#include "UART3_Tx.h"
#include "UART3_Rx.h"


#endif
