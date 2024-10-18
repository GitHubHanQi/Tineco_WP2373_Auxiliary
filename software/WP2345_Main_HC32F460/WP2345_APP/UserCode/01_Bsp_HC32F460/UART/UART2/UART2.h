#ifndef _UART2_H
#define _UART2_H

#include "includes.h"

//////// UART2  Tester  M4_USART3
#define Tester_PORT				  PortB      
#define Tester_Tx_PIN				Pin15
#define Tester_Rx_PIN				Pin14

void UART2_Init(void);
void M4_Uart1_ErrorCallBack(void);

void Uart2_IRQHandler_Rx(void);
void Uart2_IRQHandler_Tx(void);


void UART2_Tx_Disable(void);
void UART2_Tx_Enable(void);
void UART2_Rx_Disable(void);
void UART2_Rx_Enable(void);

void UART2_Task(void);


#include "UART2_Tx.h"
#include "UART2_Rx.h"


#endif
