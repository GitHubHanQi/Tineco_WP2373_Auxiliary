#ifndef _UART2_H
#define _UART2_H

#include "includes.h"
#include "UART2_Tx.h"
#include "UART2_Rx.h"




void UART2_Init(void);
void M4_Uart2_ErrorCallBack(void);

void Uart2_IRQHandler_Rx(void);
void Uart2_IRQHandler_Tx(void);


void UART2_Task(void);



#endif
