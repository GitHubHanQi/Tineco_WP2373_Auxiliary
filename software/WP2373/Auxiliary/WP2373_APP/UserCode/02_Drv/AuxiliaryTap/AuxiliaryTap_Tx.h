/*
 * @Description: 将主机信息重新打包发给龙头
 * @Author: hanqi.zhang
 * @Date: 2023-12-14 10:35:47
 * @LastEditors: hanqi.zhang
 * @LastEditTime: 2023-12-14 14:38:58
 */
#ifndef _AUXILIARYTAP_TX_H
#define _AUXILIARYTAP_TX_H

#include "includes.h"


#define AUXILIARYTAP_TX_DATA_LEN (0x13)
#define AUXILIARYTAP_TX_DATA_ALLLENGTHS (0x17) 



typedef struct
{
    uint16_t Tick_ms;
    uint16_t Len;
    uint16_t Index;
    uint8_t  Checksum;
    uint8_t  TxBuf[AUXILIARYTAP_TX_DATA_ALLLENGTHS];
    uint8_t  Tx_Flag;       
       
}AuxiliaryTap_Tx_t;
extern AuxiliaryTap_Tx_t AuxiliaryTap_Tx;


void AuxiliaryTap_Tx_Frame(void);
void AuxiliaryTap_Tx_Task(void);

#endif