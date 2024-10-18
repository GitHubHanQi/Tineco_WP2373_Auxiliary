#ifndef _PANELANALYZE_H
#define _PANELANALYZE_H

#include "includes.h"


extern volatile uint16_t Level1_Choose;       // 左槽档位
extern volatile uint16_t Level2_Choose;       // 右槽档位
extern volatile uint8_t Mode_Choose;          // 模式选择
extern volatile uint8_t Start_Flag;           // 烘烤使能
extern volatile uint8_t Bread_State;          // 面包状态
extern volatile uint8_t Slot_Selection;       // 槽位选择
extern volatile uint8_t LeftProgress_Value;   // 左槽烘烤程度
extern volatile uint8_t RightProgress_Value;  // 右槽烘烤程度
extern volatile uint8_t LeftProgress_ShowValue;   // 左槽烘烤程度 显示
extern volatile uint8_t RightProgress_ShowValue;  // 右槽烘烤程度 显示
extern volatile uint8_t Slot_State;           // 积屑槽状态
extern volatile uint8_t Touch_Flag;           // 触摸标志
extern volatile uint8_t Shutdown_Flag;        // 关机标志
extern volatile uint16_t Monitor_Count;       // 监听指令计数
extern volatile uint16_t Error_Value;         // 故障
extern volatile char Panel_Version[10];       // 屏幕版本号
extern volatile uint8_t Turnoff_Flag;          // 关机标志


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


