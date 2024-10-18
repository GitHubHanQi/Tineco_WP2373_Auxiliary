/*
 * @Description:
 * @Author: hanqi.zhang
 * @Date: 2024-02-29 09:34:26
 * @LastEditors: hanqi.zhang
 * @LastEditTime: 2024-02-29 13:45:21
 */

#ifndef _COMM_TESTER_RX_BYTE_H
#define _COMM_TESTER_RX_BYTE_H

#include "includes.h"


#define COMM_TESTER_BUF_SIZE (1024 + 8)

#define COMM_TESTER_RX_FRAME_HEAD (0xF1)

typedef enum {
  CommRxState_Head,
  CommRxState_CmdH,
  CommRxState_CmdL,
  CommRxState_Len,
  CommRxState_Data,
  CommRxState_Checksum,
} CommTester_Rx_State_t;

typedef struct {
  CommTester_Rx_State_t State;
  uint32_t Tick;
  uint8_t Checksum;
  uint16_t Index;
  bool_t Flag;
  CommTester_Frame_t Frame;
  uint8_t Data[COMM_TESTER_BUF_SIZE];  // 数据域

  //////// Test
  uint32_t Test_Byte_Cnt;
  uint32_t Test_Frame_Cnt;
} CommTester_Rx_t;
extern CommTester_Rx_t CommTester_Rx;

void CommTester_Rx_Clear(void);
void CommTester_Rx_Task(void);
void CommTester_Rx_Byte_Analyize(uint8_t RxData);
uint8_t generate_crc8(uint8_t *buf, uint8_t Len);

#endif
