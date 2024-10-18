#ifndef _TDS_H
#define _TDS_H

#include "includes.h"

typedef struct
{
	uint8_t TDS_status;
	uint16_t u16Campture;
	uint16_t u16CmpLast;
	uint16_t u16CamptureCnt;
	uint8_t Fre_Cnt;
	float Fre_Buff[20]; 
	float TDS_Fre;
	uint32_t TDS_Buff[10];
	uint16_t TDS_Val;
	uint16_t LastTDS_Val;
	uint16_t BeforeLastTDS_Val;
	uint8_t TDS_Cnt;
	uint16_t TDS_Timeout1;
	uint16_t TDS_Timeout2;
	uint16_t pitcount;
	uint8_t Error;
}TDS_t;

extern TDS_t SourceTDS;//Ô´Ë®
extern TDS_t PureTDS;//¾»Ë®

void PureTDS_Calculate(void);
void SourceTDS_Calculate(void);

void TDS_Task(void);






#endif