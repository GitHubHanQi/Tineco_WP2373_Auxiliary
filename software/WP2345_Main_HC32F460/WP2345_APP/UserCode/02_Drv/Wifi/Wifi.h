#ifndef _WIFI_H
#define _WIFI_H

#include "includes.h"


#define WIFI_HALT_CHECK     // 检测死机，死机后复位




#define MMI_Name_MAX                (20)
#define MMI_RemoteClientID_MAX      (64)
#define MMI_ReqRespID_MAX           (4)



typedef enum
{
    WifiState_Reseting = 0,
    WifiState_WlanSsidCheck,
    WifiState_NoSsid,           // 4s
    WifiState_WlanSsidReady,    // 2s
    WifiState_WlanIotReady,     // 1s
    WifiState_Off,              // 低功耗时使用
} Wifi_State_t;



// WIFI 状态
#define GET_WIFI_STAT_ST_Unknow         (0)     // 初始状态，不用也没关系
#define GET_WIFI_STAT_ST_idle           ('i')
#define GET_WIFI_STAT_ST_smartConfig    ('s')
#define GET_WIFI_STAT_ST_connecting     ('c')
#define GET_WIFI_STAT_ST_connected      ('o')   // 表示已经连接到路由器
#define GET_WIFI_STAT_ST_ap             ('a')

// IOT 状态
#define GET_IOT_CONN_STATUS_CONN_DISCONN        (0)
#define GET_IOT_CONN_STATUS_CONN_CONNECTING     (1)
#define GET_IOT_CONN_STATUS_CONN_CONNECTED      (2) // 2用于比较




typedef struct 
{
    uint16_t Tick;
    Wifi_State_t State;
    bool_t IsReady;                 // 0不在位，1已就位
	
    //////// 死机检测
    uint16_t Halt_Check_Tick;       // 1ms累加，到达周期上限时清0并且发送查询帧。收到查询帧不处理，收到其他帧清0
    uint16_t Halt_Check_Cnt;        // 发送查询帧+1，收到任意帧清0。数值过大表示wifi死机
	
	  uint16_t Halt_Times;
	
    
    
    //////// MMI 参数
    char Ssid_Read[65];             // 路由器用户名 (没有网络配置即为 NULL)
    char Ssid_Write[20];            
    char Password_Write[20];        // 路由器密码

    char GetWIFIStat_st;            // WIFI 当前状态 ('i':idle, 's':smartConfig, 'c':connecting, 'o':connected, 'a':ap)
    uint8_t GetIOTConnStatus_conn;  // IOT 服务连接状态 (0：DISCONN 1：CONNECTING 2：CONNECTED) 数值
    char GetWKVer_ver[20];          // 固件版本
    char GetCredential_lb[30];      // 域名
    char GetCredential_did[40];     // 设备did


    //////// 配网
    bool_t Start_Pair_Flag;     // 配网标志


    //////// 重复输出控制数据
    uint16_t Repeat_Send_Tick;  // 累加到200ms的时候重复发送
    uint8_t Repeat_Send_Times;  // 需要重复发送的剩余次数

    //////// 调试
    uint8_t Display_Mode;       // 0)正常工作, 1)输出调试信息

    //////// Test
    //uint32_t Test_Cnt;
} Wifi_t;
extern Wifi_t Wifi;



void Wifi_En_Off(void);
void Wifi_En_On(void);


void Wifi_Reset(void);
void Wifi_On(void);


void WifiState_Goto_NoSsid(void);   // 复位后也要设置本指令，外部调用
// void WifiState_Goto_WlanSsidReady(void);
// void WifiState_Goto_WlanIotReady(void);
void WifiState_Goto_Off(void);

void Wifi_Task(void);



#include "Wifi_String.h"

#include "WifiTx.h"
#include "WifiTx_FP.h"
#include "WifiTx_FPb.h"
#include "WifiTx_FR.h"

#include "WifiRx.h"
#include "WifiRx_MMI_Analyize.h"
#include "WifiRx_FPq.h"
#include "WifiRx_FPqb.h"
#include "WifiRx_FPp.h"
#include "WifiRx_FPm.h"
#include "WifiRx_FR.h"

#include "Ble.h"

#endif
