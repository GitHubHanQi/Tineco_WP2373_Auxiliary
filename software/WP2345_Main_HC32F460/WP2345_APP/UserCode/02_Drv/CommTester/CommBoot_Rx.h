#ifndef _COMM_BOOT_RX_H
#define _COMM_BOOT_RX_H

#include "includes.h"



typedef enum
{
	IAP_UartRx_State_Header,    // 0xAA
	IAP_UartRx_State_Number,    // 0x00
	IAP_UartRx_State_Length,    // 0x01
	IAP_UartRx_State_Command,   // 0x0D
	IAP_UartRx_State_CRCH,      // 0xD1
	IAP_UartRx_State_CRCL,      // 0xAD
} IAP_UartRx_State_t;



typedef struct 
{
    uint16_t Tick;
    IAP_UartRx_State_t State;

    //////// Test
    uint32_t Byte_Cnt0;
    uint32_t Byte_Cnt1;
} CommBoot_Rx_t;
extern CommBoot_Rx_t CommBoot_Rx;



void CommBoot_Rx_Task(void);
void CommBoot_Rx_Clear(void);
void CommBoot_Rx_Byte_Analysis(uint8_t RxData);

#endif
