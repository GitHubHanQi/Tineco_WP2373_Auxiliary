#ifndef _UART0_Rx_H
#define _UART0_Rx_H

#include "includes.h"

#define UART0_RX_BUF_SIZE      (2058)
typedef struct
{
    uint8_t Buf[UART0_RX_BUF_SIZE];
    uint16_t Index_In;
    uint16_t Index_Out;
    uint16_t Water_Mark;
    uint16_t Test_Cnt;
} UART0_Rx_t;
extern UART0_Rx_t UART0_Rx;

void UART0_Rx_Byte_Analysis(uint8_t x);
void UART0_Rx_Task();


#endif
