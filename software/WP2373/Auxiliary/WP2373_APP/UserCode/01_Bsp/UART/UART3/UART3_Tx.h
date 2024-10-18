#ifndef _UART3_TX_H
#define _UART3_TX_H

#include "includes.h"



#define UART3_TX_BUF_SIZE      (2048)
typedef struct
{
    uint8_t Buf[UART3_TX_BUF_SIZE];
    uint16_t Index_In;
    uint16_t Index_Out;
    bool_t Is_Transmitting;
    uint16_t Water_Mark;
    //
    uint16_t Test_Cnt;
} UART3_Tx_t;
extern UART3_Tx_t UART3_Tx;




void UART3_Tx_Task(void);
void UART3_Tx_Isr(void);
void UART3_PrintArray(const uint8_t *pBuf, uint16_t Len);
void Wifi_Transmit(const uint8_t *pBuf, uint16_t Len);




#endif
