#ifndef _WT588_TX_BIT_H
#define _WT588_TX_BIT_H

#include "includes.h"



typedef enum
{
    WT588_TxBitState_Idle,
    WT588_TxBitState_Start,   // 5ms

    WT588_TxBitState_D8,
    WT588_TxBitState_C8,
    WT588_TxBitState_D9,
    WT588_TxBitState_C9,
    WT588_TxBitState_D10,
    WT588_TxBitState_C10,
    WT588_TxBitState_D11,
    WT588_TxBitState_C11,
    WT588_TxBitState_D12,
    WT588_TxBitState_C12,
    WT588_TxBitState_D13,
    WT588_TxBitState_C13,
    WT588_TxBitState_D14,
    WT588_TxBitState_C14,
    WT588_TxBitState_D15,
    WT588_TxBitState_C15,

    WT588_TxBitState_DMid,
    WT588_TxBitState_CMid,

    WT588_TxBitState_D0,
    WT588_TxBitState_C0,
    WT588_TxBitState_D1,
    WT588_TxBitState_C1,
    WT588_TxBitState_D2,
    WT588_TxBitState_C2,
    WT588_TxBitState_D3,
    WT588_TxBitState_C3,
    WT588_TxBitState_D4,
    WT588_TxBitState_C4,
    WT588_TxBitState_D5,
    WT588_TxBitState_C5,
    WT588_TxBitState_D6,
    WT588_TxBitState_C6,
    WT588_TxBitState_D7,
    WT588_TxBitState_C7,

    WT588_TxBitState_Stop,    // 10ms
} WT588_TxBit_State_t;



void WT588_TxBit_GotoStart(void);
void WT588_TxBit_Task(void);



#endif

