/*
 * @Description: 
 * @Author: hanqi.zhang
 * @Date: 2024-02-29 09:34:26
 * @LastEditors: hanqi.zhang
 * @LastEditTime: 2024-02-29 13:44:20
 */
#ifndef _COMM_TESTER_H
#define _COMM_TESTER_H

#include "includes.h"

//#include <ctype.h>
////#include <stdlib.h>
//#include <stdint.h>


#define ADDR_TOOL       (0xE0)  // 本机地址
#define ADDR_BMS        (0x01)  // 电池包地址
#define ADDR_TESTER     (0x0A)  // 测试机转接板地址

typedef struct
{
    uint8_t CmdH;
    uint8_t CmdL;
    uint16_t Len;    // 0xFF 表示数据长度为1024
} CommTester_Frame_t;


#define TESTER_RX_WIFI_WKVer            (BIT0)   // 模块版本
#define TESTER_RX_WIFI_Credential       (BIT1)   // 模块帐号信息，激活信息
#define TESTER_RX_WIFI_SetWifiCfg       (BIT2)   // 
#define TESTER_RX_WIFI_FactoryReset     (BIT3)   // 
#define TESTER_RX_WIFI_CheckSsid        (BIT4)   // 
typedef struct 
{
    uint8_t Tx_Flag;                 // 测试机请求处理完成。发送完成置0，准备发送时置1，发送故障置2
    uint8_t Tx_Source;              //0测试机 1 BLE
    uint8_t SetWifiCfg_Rx_Flag;      // 设置联网的中间键，连到路由器时置1
} Comm_Tester_t;
extern Comm_Tester_t Comm_Tester;


void CommTester_Task(void);





#endif
