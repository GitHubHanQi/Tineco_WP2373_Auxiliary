#ifndef _UART3_Rx_H
#define _UART3_Rx_H

#include "includes.h"



#define UART3_RX_BUF_SIZE      (2048)
typedef struct
{
    uint8_t Buf[UART3_RX_BUF_SIZE];
    uint16_t Index_In;
    uint16_t Index_Out;
    //bool_t Is_Transmitting;
    uint16_t Water_Mark;
    //
    uint16_t Test_Cnt;
} UART3_Rx_t;
extern UART3_Rx_t UART3_Rx;



void UART3_Rx_Byte_Analysis(uint8_t x);
void UART3_Rx_Task(void);


#endif
