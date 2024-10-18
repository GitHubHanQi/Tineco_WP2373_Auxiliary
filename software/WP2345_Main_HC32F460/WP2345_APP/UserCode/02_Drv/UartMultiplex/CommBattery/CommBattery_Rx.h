#ifndef _COMM_BATTERY_RX_H
#define _COMM_BATTERY_RX_H

#include "includes.h"



#define COMM_BATTERY_RX_HEAD    (0xF2)
#define COMM_BATTERY_RX_END     (0xF1)
#define COMM_BATTERY_RX_SIZE    (100)

typedef enum
{
	CommBatteryRxState_Head,
	CommBatteryRxState_AddrSend,
	CommBatteryRxState_AddrReceive,
	CommBatteryRxState_Cmd0,
	CommBatteryRxState_Cmd1,
	CommBatteryRxState_Len,
	CommBatteryRxState_Data,
	CommBatteryRxState_Checksum,
	CommBatteryRxState_End,
} CommBattery_Rx_State_t;




typedef struct 
{
    uint16_t Tick;
    uint8_t Buf[COMM_BATTERY_RX_SIZE];
    CommBattery_Rx_State_t State;
    uint8_t Checksum;
    uint16_t DataLen;
    uint16_t Index;
    //
    uint32_t Test_Byte_Cnt;
    uint32_t Test_Frame_Cnt;

    //
    uint16_t oIndex;
} CommBattery_Rx_t;
extern CommBattery_Rx_t CommBattery_Rx;

void CommBattery_Rx_Task(void);
void CommBattery_Rx_Byte_Analysis(uint8_t RxData);





#endif
