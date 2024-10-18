#ifndef _WIFI_PAIR_H
#define _WIFI_PAIR_H

#include "includes.h"



typedef enum
{
    WifiPairState_Stop,                 //
    WifiPairState_Start,                // 等待时机发送
    WifiPairState_FactoryResetSend,     // 发送请求
    WifiPairState_FactoryResetReceive,  // 等待响应
    WifiPairState_Pairing,              // 配网中
    WifiPairState_Paired,               // 已成功
	  WifiPairState_Fail,					// 失败
} WifiPair_State_t;


typedef struct 
{
    uint32_t Tick;              // 故障用的计时
    uint32_t Tick_ms;           // 配网界面5分钟，配网成功界面1分钟使用的计时
    WifiPair_State_t State;
    bool_t FactoryReset_Flag;   // 请求时置1，响应后置0。持续不响应，反复请求
} WifiPair_t;
extern WifiPair_t WifiPair;




void WifiPair_Start(void);
void WifiPair_Stop(void);

void WifiPair_Task(void);


#endif

