#ifndef _PHONE_WORK_MODE_H
#define _PHONE_WORK_MODE_H




typedef enum
{
    PhoneWorkMode_Charge = 2,		//充电
    PhoneWorkMode_SelfClean = 8,	//自清洁

    PhoneWorkMode_Clean = 3,		//放电
    PhoneWorkMode_CleanPause = 10,	//直立停机

    PhoneWorkMode_Idle = 1,			//待机
    PhoneWorkMode_Halt = 0,			//停机

    PhoneWorkMode_WifiPair = 7,		//配网
    PhoneWorkMode_Demo = 4,			//演示
    PhoneWorkMode_Tester = 5,		//测试机

    PhoneWorkMode_IapMcu = 9,  		//OTA MCU
    PhoneWorkMode_IapVoice = 11, 	//OTA voice

    PhoneWorkMode_Unknow = 0xFF
} Phone_WorkMode_t;



void Phone_AppState_Task(void);


#endif
