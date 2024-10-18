#ifndef _PFLASH_H
#define _PFLASH_H

#include "includes.h"

#define HDSC_MAX_ADDRESS          0x40000
// PanelLcd  flag  address
#define PANEL_FLAG_ADDRESS        0x8CC0
#define PANEL_FLAG_SECTION        ".ARM.__at_0x00008CC0"

// Voice  flag  address  
#define VOICE_FLAG_ADDRESS        0xD000
#define VOICE_FLAG_SECTION        ".ARM.__at_0x0000D000"

// Voice  flag  address  
#define TEST_ADDRESS        0xE000
#define TEST_SECTION        ".ARM.__at_0x0000E000" 

extern void FlashWriteByte(uint32_t u32Addr, uint8_t* txbuf, uint16_t len);
extern void FlashSectorErase(uint32_t Sector_Addr);

extern const char pFlashLcdFlag[];
extern const char  gFlashVoiceFlag[];

#endif
