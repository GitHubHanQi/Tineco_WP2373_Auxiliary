#ifndef _UART1_TX_H
#define _UART1_TX_H

#include "includes.h"



#define UART1_TX_BUF_SIZE      (2048)
typedef struct
{
    uint8_t Buf[UART1_TX_BUF_SIZE];
    uint16_t Index_In;
    uint16_t Index_Out;
    bool_t Is_Transmitting;
    uint16_t Water_Mark;
    //
    //uint16_t Test_Cnt;
} UART1_Tx_t;
extern UART1_Tx_t UART1_Tx;




void UART1_Tx_Task(void);
void UART1_Tx_Isr(void);

void UART1_PrintArray(const uint8_t *pBuf, uint16_t Len);
void UART1_PrintString(const char *pStr);


//////// Drv 使用
void Wifi_PrintArray(const uint8_t *pBuf, uint16_t Len);
void Wifi_PrintString(const char *pStr);

void UART1_Tx_Test(void);
// tEST 
extern  uint8_t UART1_Tx_Test_Cnt1 ;
#endif
