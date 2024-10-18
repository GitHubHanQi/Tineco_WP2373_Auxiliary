#ifndef _UART2_Rx_H
#define _UART2_Rx_H

#include "includes.h"


// //#define UART2_RX_BUF_SIZE      (16)
// #define UART2_RX_BUF_SIZE      (1024 + 16)

// typedef struct
// {
//     uint8_t Buf[UART2_RX_BUF_SIZE];
//     uint16_t Index_In;
//     uint16_t Index_Out;
//     uint16_t Water_Mark;
//     //
//     //uint16_t Test_Cnt;
// } UART2_Rx_t;
// extern UART2_Rx_t UART2_Rx;


void UART2_Rx_Byte_Analyize(uint8_t RxByte);


#endif
