#ifndef _UART1_H
#define _UART1_H

#include "includes.h"


void UART1_Init(void);
void UART1_Task(void);


#include "UART1_Tx.h"
#include "UART1_Rx.h"


#endif
