#ifndef _PANEL_LCD_TX_H
#define _PANEL_LCD_TX_H

#include "includes.h"

#define PanelWiFi0Voice0      0x00      // 都关
#define PanelWiFi1Voice0	  0x01		// WIFI开 声音关
#define PanelWiFi2Voice0	  0x02		// WIFI闪 声音关

#define PanelWiFi0Voice1	  0x04		// WIFI关 声音开
#define PanelWiFi1Voice1	  0x05		// WIFI开 声音开
#define PanelWiFi2Voice1	  0x06		// WIFI闪 声音开


void SendGuiFrame(void);

extern uint8_t PanelLedMode;
extern uint8_t PanelWorkMode;
extern uint8_t PanelWifiVoice;

// 屏幕亮度
extern  uint8_t PanelLcdLight;
// 屏幕运行时间
extern uint8_t PanelLcdTime ; // 0--100
extern uint8_t PanelSelfCleanDuty; // 0-100

#endif
