#ifndef _PANEL_LCD_TEST_H
#define _PANEL_LCD_TEST_H

#include "includes.h"


extern uint8_t GuiTxBuf_Bms[];
extern uint16_t GuiTxBuf_Bms_Len;


void Panel_Encode(uint8_t *pBuf, uint16_t *pLen);



#endif
