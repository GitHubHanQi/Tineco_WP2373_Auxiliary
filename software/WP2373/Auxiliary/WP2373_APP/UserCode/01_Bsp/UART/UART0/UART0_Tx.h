#ifndef _UART0_TX_H
#define _UART0_TX_H

#include "includes.h"


#define UART0_TX_BUF_SIZE      (1024)
typedef struct
{
    uint8_t Buf[UART0_TX_BUF_SIZE];
    uint16_t Index_In;
    uint16_t Index_Out;
    bool_t Is_Transmitting;
    uint16_t Water_Mark;
    //
    uint16_t Test_Cnt;
} UART0_Tx_t;
extern UART0_Tx_t UART0_Tx;

void UART0_Tx_Isr(void);
void UART0_Printc(uint8_t x);
void UART0_Tx_Task(void);
void UART0_PrintArray(const uint8_t *pBuf, uint16_t Len);
void AuxiliaryHost_Transmit(uint8_t *pBuf, uint16_t Len);





#endif
