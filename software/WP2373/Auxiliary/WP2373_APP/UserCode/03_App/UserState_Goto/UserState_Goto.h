#ifndef _USER_STATE_GOTO_H
#define _USER_STATE_GOTO_H

#include "includes.h"

void UserState_GotoInit(void); 
void UserState_GotoTester(void);  // ���Ի�
void UserState_GotoProgram(void); // ��¼
void UserState_GotoProgramOTA(void); // OTA
void UserState_GotoNormalWork(void);
void UserState_GotoHostStrongRinse(void);
void UserState_GotoProductionTest(void);

void UserState_GotoAuxiliaryFlushing(void);
void UserState_HostBoilingPointLearning(void);


#endif

