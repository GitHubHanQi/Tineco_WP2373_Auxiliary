/*
 * @Description: 将龙头信息重新打包发送给主机
 * @Author: hanqi.zhang
 * @Date: 2023-12-14 10:35:47
 * @LastEditors: hanqi.zhang
 * @LastEditTime: 2023-12-14 10:39:00
 */

#ifndef _AUXILIARYHOST_TX_H
#define _AUXILIARYHOST_TX_H

#include "includes.h"

#define AUXILIARYHOST_TX_DATA_LEN (12)
#define AUXILIARYHOST_TX_ALLLENGTHS (16)

typedef struct {
  uint16_t Tick_ms;
  uint16_t Len;
  uint16_t Index;
  uint8_t Checksum;
  uint8_t TxBuf[AUXILIARYHOST_TX_ALLLENGTHS];
  uint8_t Tx_Flag;

} AuxiliaryHost_Tx_t;
extern AuxiliaryHost_Tx_t AuxiliaryHost_Tx;

typedef struct {
  uint16_t Tick_ms;
  uint16_t Len;
  uint16_t Index;
  uint8_t Checksum;
  uint8_t TxBuf[100];
	uint8_t CachBuf[100];
  uint8_t Tx_Flag;
	uint32_t SendVersionCnt;
	
} AuxiliaryHost_GetVersion_Tx_t;
extern AuxiliaryHost_GetVersion_Tx_t AuxiliaryHost_GetVersion_Tx;

typedef struct {
  uint16_t Tick_ms;
  uint16_t Len;
  uint16_t Index;
  uint8_t Checksum;
  uint8_t TxBuf[512];
  uint8_t Tx_Flag;
	uint32_t SendPlantSeedCnt;
}AuxiliaryHost_PlantSeed_Tx_t;
extern AuxiliaryHost_PlantSeed_Tx_t AuxiliaryHost_PlantSeed_Tx;

void AuxiliaryHost_Tx_Frame(void);
void AuxiliaryHost_Tx_Task(void);


void AuxiliaryHost_GetVersion_Tx_Task(void);

//上报埋点


void AuxiliaryHost_PlantSeed_Tx_Frame(uint8_t *CJSON_Data);
#endif