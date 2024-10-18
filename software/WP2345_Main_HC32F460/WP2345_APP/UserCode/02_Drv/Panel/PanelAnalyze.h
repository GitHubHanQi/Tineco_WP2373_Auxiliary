#ifndef _PANELANALYZE_H
#define _PANELANALYZE_H

#include "includes.h"


extern volatile uint16_t Level1_Choose;       // ��۵�λ
extern volatile uint16_t Level2_Choose;       // �Ҳ۵�λ
extern volatile uint8_t Mode_Choose;          // ģʽѡ��
extern volatile uint8_t Start_Flag;           // �濾ʹ��
extern volatile uint8_t Bread_State;          // ���״̬
extern volatile uint8_t Slot_Selection;       // ��λѡ��
extern volatile uint8_t LeftProgress_Value;   // ��ۺ濾�̶�
extern volatile uint8_t RightProgress_Value;  // �Ҳۺ濾�̶�
extern volatile uint8_t LeftProgress_ShowValue;   // ��ۺ濾�̶� ��ʾ
extern volatile uint8_t RightProgress_ShowValue;  // �Ҳۺ濾�̶� ��ʾ
extern volatile uint8_t Slot_State;           // ��м��״̬
extern volatile uint8_t Touch_Flag;           // ������־
extern volatile uint8_t Shutdown_Flag;        // �ػ���־
extern volatile uint16_t Monitor_Count;       // ����ָ�����
extern volatile uint16_t Error_Value;         // ����
extern volatile char Panel_Version[10];       // ��Ļ�汾��
extern volatile uint8_t Turnoff_Flag;          // �ػ���־


void Crc8_AddCalc(uint8_t *crc, uint8_t m);

void HexStrToByte(const char *source, unsigned char *dest, int sourceLen);
void ByteToHexStr(const unsigned char *source, char *dest, int sourceLen);

void Panel_Analyze(void);
void Panel_To_Bt(void);
void Bt_To_Panel(void);
void Error_Upload(void);
void BtStatus_Upload(void);
void Panel_debug(const char *pStr);
void Panel_stateUpdate(const char *pStr, uint32_t input);
void AppState_Upload(void);
void Shutdown_Signal(void);
void LeftHeatProgress_Upload(void);
void RightHeatProgress_Upload(void);
void SlotState_Upload(void);
void Monitor_Panel(void);
void Version_Panel(void);
void Panel_Reset(void);
void TurnOn_Signal(void);


#endif


