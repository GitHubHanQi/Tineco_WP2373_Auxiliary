#ifndef _APP_DATALOG_H
#define _APP_DATALOG_H

#include "includes.h"

//typedef struct
//{
//    uint32_t                 Header;

//    uint32_t                 Number;

//    uint32_t                 DischargeSecondTotal;

//    uint32_t                 DustNumTotal;

////  uint32_t                 SecondTotal_SelfClean;      //�ۼ�ʱ�䣬�������

////  uint32_t                 DustSecondTotal_SelfClean;      //ǿ�����ۼ�ʱ�䣬�������

//    uint32_t                 DischargeSecond;

//    uint32_t                 DischargeTimes;

//    uint32_t                 SelfCleanTimes;                //��������

//    uint32_t                 SelfCleanSecondTotal;          //������ۼ�ʱ��

//    uint32_t                 SelfCleanDustHSecondTotal;         //����������ۼ�ʱ��

//    uint32_t                 SelfCleanDustLSecondTotal;         //����������ۼ�ʱ��

//    uint32_t                 SelfCleanDustHSecond;          //���������ʱ��

//    uint32_t                 SelfCleanDustLSecond;          //���������ʱ��

//    uint32_t                 ButtonWifiCnt;

//    uint32_t                 MuteState;

//    uint32_t                 SelfCleanRemindState;

//    uint32_t                 SensorState;
//    //uint32_t                 WifiDisable;
//    uint32_t                 MusicOTABreak;

//    uint32_t                 BrushAbradeTimes;

//    uint32_t                 VoiceSelect;

//    uint32_t                 VoiceLevel;

//    uint32_t                 Checksum;
//} Datalog_TypeDef;

//extern Datalog_TypeDef Datalog_Data;

//#define DATALOG_DischargeSecondTotal    (*(uint32_t *)(Datalog_Buf + 0))    //[0:3]
//#define DATALOG_DustNumTotal            (*(uint64_t *)(Datalog_Buf + 4))    //[4:11]
//#define DATALOG_DischargeSecond         (*(uint32_t *)(Datalog_Buf + 12))    //[12:15]

//#define DATALOG_DustNumTotal_L          (DATALOG_DustNumTotal & 0xFFFFFFFF)
//#define DATALOG_DustNumTotal_H          ((DATALOG_DustNumTotal >> 32) & 0xFFFFFFFF)



//#define DATALOG_SIZE    (16)
//extern volatile uint8_t Datalog_Buf[];







extern volatile uint32_t Datalog_Discharge_Tick_ms;
extern volatile bool_t Datalog_IsSaved;


//void Datalog_Save(void);
//void Datalog_Read(void);
//void Datalog_Clear(void);


#endif

