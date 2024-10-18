/*
 * @Description: 
 * @Author: hanqi.zhang
 * @Date: 2023-12-29 08:44:18
 * @LastEditors: hanqi.zhang
 * @LastEditTime: 2024-01-02 18:42:31
 */

#ifndef _OTA_H
#define _OTA_H
#include "includes.h"


typedef enum{
	OTARxStep_Head = 0,
	OTARxStep_SendAddress,
	OTARxStep_ReceiveAddress,
	OTARxStep_Function,
	OTARxStep_Command,
	OTARxStep_LenH,
	OTARxStep_LenL,
	OTARxStep_Data,
	OTARxStep_CheckSum,
	OTARxStep_End,
}OTARxStep_t;

typedef struct
{
	uint8_t RxBuf[1300];
	OTARxStep_t RxStep;
	uint16_t    RxCnt;
	uint16_t	RxDataLen;
	uint8_t		RxCheckSum;
	uint32_t  FrameAllNum;
	uint32_t	FrameNum;
	uint8_t		Type;
	uint8_t 	TxBuf[1300];
	uint32_t	Display100mscnt;
	uint32_t  OTATimeOutCount;
	uint8_t   OTACompleteFlag;
	uint32_t  OTACompleteCount;
	uint8_t   Function;
	uint8_t   Command;
	uint32_t  DocumentCheckSum;
	uint8_t   CheckSumErrorFlag;
	uint32_t  FileSize;
	uint32_t  OneFrameEnd;
}OTA_T;
extern OTA_T OTA;

void OTARxFiFo_Handler(uint8_t input);
void OTA_Analyze_bin(void);
void OTA_OTAResetDelay_Task(void);
void OTACommResetTask(void);





#endif