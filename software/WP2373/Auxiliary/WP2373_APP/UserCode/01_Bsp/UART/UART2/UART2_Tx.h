#ifndef _UART2_TX_H
#define _UART2_TX_H

#include "includes.h"



#define UART2_TX_BUF_SIZE      (256)
typedef struct
{
    uint8_t Buf[UART2_TX_BUF_SIZE];
    uint16_t Index_In;
    uint16_t Index_Out;
    bool_t Is_Transmitting;
    uint16_t Water_Mark;
    //
    //uint16_t Test_Cnt;
} UART2_Tx_t;
extern UART2_Tx_t UART2_Tx;




void UART2_Tx_Task(void);
void UART2_Tx_Isr(void);
void UART2_PrintArray(const uint8_t *pBuf, uint16_t Len);
void UART2_PrintString(const char *pStr);

void UART2_Tx_Test(void);

void AuxiliaryTap_Transmit(uint8_t *pBuf, uint16_t Len);


#endif
