#ifndef _UART2_H
#define _UART2_H

#include "includes.h"


void UART2_Init(void);

void UART2_Tx_Disable(void);
void UART2_Tx_Enable(void);
void UART2_Rx_Disable(void);
void UART2_Rx_Enable(void);

void UART2_Task(void);


#include "UART2_Tx.h"
#include "UART2_Rx.h"


#endif
