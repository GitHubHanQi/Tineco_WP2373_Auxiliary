#ifndef _S_FLASH_H
#define _S_FLASH_H

#include "includes.h"

#define FLASH_PAGE_SIZE             (0x200)                 // 512字节


//////// Flash 地址 ////////
//////// Boot
#define FLASH_BOOT_ADDR_START       (0)     // Sector 0~15
#define FLASH_BOOT_PAGES            (16)    // 共16页
#define FLASH_BOOT_SIZE             (FLASH_PAGE_SIZE * FLASH_BOOT_PAGES)    // 512 * 16 = 0x2000

#define FLASH_MARK_ADDR             (FLASH_BOOT_ADDR_START + FLASH_BOOT_SIZE - FLASH_PAGE_SIZE)  // 0x1E00 最后一页用于存标记
#define FLASH_MARK_WORD             (0x123455AA)

//////// App
#define FLASH_APP0_ADDR_START       (0x02000)   // Sector  16~261
#define FLASH_APP0_INFO_END       	(0x02100)   // Half sector


#define FLASH_APP1_ADDR_START      	(0x20C00)   // Sector 262~507
#define FLASH_APP1_INFO_END      	(0x20D00)   // Half sector

#define FLASH_APP_PAGES             (246)       // 共246页
#define FLASH_APP_SIZE              ((FLASH_PAGE_SIZE * FLASH_APP_PAGES))  

//#define FLASH_RUN_OFFSET            (256)
#define FLASH_RUN_ADDR              (FLASH_APP0_ADDR_START + FLASH_RUN_OFFSET)

#define OTA_SUCCESS_ADDR			((uint32_t)0x3F600)     // Sector507
#define PUMP_SET_ADDR				((uint32_t)0x3F800)     // Sector508

// Log
#define FLASH_LOG1_ADDR_START       ((uint32_t)0x3FA00)     // Sector509
#define FLASH_LOG0_ADDR_START       ((uint32_t)0x3FC00)     // Sector510

// Parameter
#define FLASH_PARAMETER_ADDR_START  ((uint32_t)0x3FE00)     // Sector511

//////// 函数地址 ////////
//#define FLASH_EraseWrite_ADDR_START ((uint32_t)0x02400)     // 擦写Flash函数的位置

#define HDSC_MAX_ADDRESS          0x40000

/************************ TEST *****************************/
// PanelLcd  flag  address
//#define PANEL_FLAG_ADDRESS        0x12800


/************************ TEST *****************************/


void Flash__Init(void);


void Flash__Unlock(void);
void Flash__Lock(void);


void Flash__ErasePage(uint32_t FlashAddr);

void Flash__WriteWord(uint32_t FlashAddr, uint32_t Data);
void Flash__WriteArray(uint32_t FlashAddr, const uint8_t *pBuf, uint16_t Length);

uint8_t Flash__ReadByte(uint32_t FlashAddr);
uint32_t Flash__ReadWord(uint32_t FlashAddr);
void Flash__ReadArray(uint32_t FlashAddr, uint8_t *pBuf, uint16_t Length);

//void FlashWriteByte(uint32_t u32Addr, uint8_t *txbuf, uint16_t len);

extern uint8_t Flash__Test_Buf0[];
extern uint8_t Flash__Test_Buf1[];
extern uint8_t Flash__Test_Buf2[];
void Flash__Test(void);


#endif
