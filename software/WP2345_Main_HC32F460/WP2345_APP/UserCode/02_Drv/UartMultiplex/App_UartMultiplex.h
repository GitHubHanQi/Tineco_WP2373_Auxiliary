#ifndef _APP_UART_MULTIPLEX_H
#define _APP_UART_MULTIPLEX_H

#include "includes.h"



typedef enum
{
    UartMultiplexState_CheckBmsType,        // 检测版本
    UartMultiplexState_CheckBmsCapacity,    // 检测电量
    UartMultiplexState_Bms,
    UartMultiplexState_Panel
} UartMultiplex_State_t;
extern volatile UartMultiplex_State_t UartMultiplex_State;
extern volatile uint16_t UartMultiplex_Tick;


void UartMultiplex_Task(void);



#endif

