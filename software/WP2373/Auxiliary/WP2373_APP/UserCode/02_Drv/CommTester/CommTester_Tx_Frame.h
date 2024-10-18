#ifndef _COMM_TESTER_TX_FRAME_H
#define _COMM_TESTER_TX_FRAME_H

#include "includes.h"
#include "CommTester.h"


typedef struct
{
    uint8_t Buf[256];
    uint16_t Index;
    uint8_t Checksum;
    uint16_t Len;
} CommTester_TxFrame_t;



extern CommTester_TxFrame_t CommTester_TxFrame;
void CommTester_Tx_Frame(const CommTester_Frame_t *pFrame, const uint8_t *pData);


#endif
