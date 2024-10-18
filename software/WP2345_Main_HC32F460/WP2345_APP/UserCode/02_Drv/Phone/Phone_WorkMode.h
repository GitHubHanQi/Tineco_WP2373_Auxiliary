#ifndef _PHONE_WORK_MODE_H
#define _PHONE_WORK_MODE_H




typedef enum
{
    PhoneWorkMode_Charge = 2,		//���
    PhoneWorkMode_SelfClean = 8,	//�����

    PhoneWorkMode_Clean = 3,		//�ŵ�
    PhoneWorkMode_CleanPause = 10,	//ֱ��ͣ��

    PhoneWorkMode_Idle = 1,			//����
    PhoneWorkMode_Halt = 0,			//ͣ��

    PhoneWorkMode_WifiPair = 7,		//����
    PhoneWorkMode_Demo = 4,			//��ʾ
    PhoneWorkMode_Tester = 5,		//���Ի�

    PhoneWorkMode_IapMcu = 9,  		//OTA MCU
    PhoneWorkMode_IapVoice = 11, 	//OTA voice

    PhoneWorkMode_Unknow = 0xFF
} Phone_WorkMode_t;



void Phone_AppState_Task(void);


#endif
