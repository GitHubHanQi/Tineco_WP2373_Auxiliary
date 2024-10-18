#ifndef _UART0_H
#define _UART0_H

#include "includes.h"


void UART0_Init(void);
void UART0_Task(void);

#include "UART0_Tx.h"
#include "UART0_Rx.h"


#endif
