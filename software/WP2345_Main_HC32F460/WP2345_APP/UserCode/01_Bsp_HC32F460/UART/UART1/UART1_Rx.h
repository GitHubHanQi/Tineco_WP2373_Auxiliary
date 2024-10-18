#ifndef _UART1_Rx_H
#define _UART1_Rx_H

#include "includes.h"



#define UART1_RX_BUF_SIZE      (2048)
typedef struct
{
    uint8_t Buf[UART1_RX_BUF_SIZE];
    uint16_t Index_In;
    uint16_t Index_Out;
    uint16_t Water_Mark;
    //
    //uint16_t Test_Cnt;
} UART1_Rx_t;
extern UART1_Rx_t UART1_Rx;



void UART1_Rx_Byte_Analysis(uint8_t x);
void UART1_Rx_Task(void);


#endif
