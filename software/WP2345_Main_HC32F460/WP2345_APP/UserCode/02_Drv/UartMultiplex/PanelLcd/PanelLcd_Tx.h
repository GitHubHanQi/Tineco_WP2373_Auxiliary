#ifndef _PANEL_LCD_TX_H
#define _PANEL_LCD_TX_H

#include "includes.h"

#define PanelWiFi0Voice0      0x00      // ����
#define PanelWiFi1Voice0	  0x01		// WIFI�� ������
#define PanelWiFi2Voice0	  0x02		// WIFI�� ������

#define PanelWiFi0Voice1	  0x04		// WIFI�� ������
#define PanelWiFi1Voice1	  0x05		// WIFI�� ������
#define PanelWiFi2Voice1	  0x06		// WIFI�� ������


void SendGuiFrame(void);

extern uint8_t PanelLedMode;
extern uint8_t PanelWorkMode;
extern uint8_t PanelWifiVoice;

// ��Ļ����
extern  uint8_t PanelLcdLight;
// ��Ļ����ʱ��
extern uint8_t PanelLcdTime ; // 0--100
extern uint8_t PanelSelfCleanDuty; // 0-100

#endif
