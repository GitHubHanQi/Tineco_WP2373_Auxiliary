#ifndef _COMM_TESTER_RX_BYTE_H
#define _COMM_TESTER_RX_BYTE_H

#include "includes.h"



#define COMM_TESTER_BUF_SIZE        (1024 + 8)


#define COMM_TESTER_RX_FRAME_HEAD   (0xF1)


typedef enum
{
	CommRxState_Head,
	CommRxState_CmdH,
	CommRxState_CmdL,
	CommRxState_Len,
	CommRxState_Data,
	CommRxState_Checksum,
} CommTester_Rx_State_t;


typedef enum
{
	TDS_Head,
	TDS_Len,
	TDS_Type,
	TDS_keep,
	TDS_Val1H,
	TDS_Val1L,
	TDS_Val2H,
	TDS_Val2L,
	TDS_Tem,
	TDS_CRC,
	TDS_END
} TDS_Rx_State_t;

typedef struct 
{
    //////// 字节
    uint32_t Tick;
    CommTester_Rx_State_t State;
    uint8_t Checksum;
    uint16_t Index;

    //////// 帧
    bool_t Flag;
    CommTester_Frame_t Frame;
    uint8_t Data[COMM_TESTER_BUF_SIZE]; // 数据域


    //////// Test
    uint32_t Test_Byte_Cnt;
    uint32_t Test_Frame_Cnt;
} CommTester_Rx_t;
extern CommTester_Rx_t CommTester_Rx;
extern CommTester_Rx_t BLE_CommTester_Rx;

void CommTester_Rx_Clear(void);
void CommTester_Rx_Task(void);
void CommTester_Rx_Byte_Analyize(uint8_t RxData);
void TDS_Rx_Byte_Analyize(uint8_t RxData);
uint8_t generate_crc8( uint8_t *buf, uint8_t Len );
void BLE_CommTester_Rx_Clear(void);
int tester_protocol_parse(uint8_t RxData);
#endif
