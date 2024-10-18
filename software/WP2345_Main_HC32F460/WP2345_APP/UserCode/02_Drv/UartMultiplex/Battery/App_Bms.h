#ifndef _APP_BMS_H
#define _APP_BMS_H

#include "includes.h"


#ifdef BMS_TEST_FOR_COMM_ERROR
    #define BMS_COMM_ERROR_CNT_MAX      (1)
#else
    #define BMS_COMM_ERROR_CNT_MAX      (16)
#endif


#define ADDR_TOOL	(0xE0)	// 本机地址
#define ADDR_BMS	(0x01)	// 电池包地址
#define ADDR_TESTER (0x0A)  // 测试机转接板地址




//////// 请求帧
extern const uint8_t BmsRequest_Version[];
extern const uint8_t BmsRequest_Id[];

extern const uint8_t BmsRequest_Voltage[];
extern const uint8_t BmsRequest_CurTemp[];
extern const uint8_t BmsRequest_Capacity[];

extern const uint8_t BmsRequest_UcpOff[];
//extern const uint8_t BmsRequest_UcpOn[];
extern const uint8_t BmsRequest_PowerOff[];
extern const uint8_t BmsRequest_Charge[];
extern const uint8_t BmsRequest_Discharge[];
extern uint8_t BmsRequest_Vaccum[];

extern volatile uint8_t BmsTx_Buf[];





extern volatile uint16_t BmsUartRx_Tick;


//extern volatile uint8_t Battery.Percent;
//extern volatile uint8_t Battery.SelfState;



extern volatile uint8_t Bms_CommErrorCnt;
extern volatile bool_t Bms_CommErrorState;
void Bms_CommErrorClear(void);
void Bms_CommErrorAdd(void);

void Bms_Task(void);


#endif

