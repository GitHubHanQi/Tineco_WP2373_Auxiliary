#ifndef _NFC_H
#define _NFC_H


#include "UserMain.h"

#define NFC_NPD_Port PortB
#define NFC_NPD_Pin  Pin03

#define NFC__TX_Port PortD
#define NFC__TX_Pin  Pin02
#define NFC__SCL_Port PortD
#define NFC__SCL_Pin  Pin02

#define NFC__RX_Port PortC
#define NFC__RX_Pin  Pin12
#define NFC__SDA_Port PortC
#define NFC__SDA_Pin  Pin12


extern uint8_t NTC_TIG_Flag;


int Thread_NFC_Init(void);
void TYPE_A_EVENT(void);
void TYPE_B_EVENT(void);
void NFC_HardReset();











#endif
