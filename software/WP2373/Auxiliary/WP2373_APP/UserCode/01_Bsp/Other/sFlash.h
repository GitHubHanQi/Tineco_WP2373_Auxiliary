#ifndef _S_FLASH_H
#define _S_FLASH_H

#include "includes.h"

#define FLASH_PAGE_SIZE             (0x2000)                 // 8K字节

#define HC32_OK			(0)
#define HC32_ERROR		(1)
#define HC32_TIMEOUT	(2)
#define HC32_INVALID	(3)


#define HC32_FLASH_SIZE             (0x40000u)	
#define HC32_FLASH_END_ADDR         (0x3FFFFu)      //HC32_FLASH_SIZE - 1
#define HC32_EFM_KEY1                            (0x0123ul)
#define HC32_EFM_KEY2                            (0x3210ul)

#define HC32_EFM_LOCK                            (0x00000000u)
#define HC32_EFM_UNLOCK                          (0x00000001u)


#define HC32_FLASH_TIMEOUT_INIT     (0xFFFFFFu)
#define HC32_FLASH_TIMEOUT_PGM      (0xFFFFFFu)
#define HC32_FLASH_TIMEOUT_ERASE    (0xFFFFFFu)
#define HC32_FLASH_LOCK_ALL         (0u)
#define HC32_FLASH_UNLOCK_ALL       (0xFFFFFFFFu)

//////// Flash 地址 ////////
//////// Boot
#define FLASH_BOOT_ADDR_START       (0)     // Sector 0
#define FLASH_BOOT_PAGES            (2)    // 共2页
#define FLASH_BOOT_SIZE             (FLASH_PAGE_SIZE * FLASH_BOOT_PAGES)    // 2000 * 2 = 0x4000

#define FLASH_MARK_ADDR             (FLASH_BOOT_ADDR_START + FLASH_BOOT_SIZE - FLASH_PAGE_SIZE)  // 0x3FFF 最后一页用于存标记
#define FLASH_MARK_WORD             (0x123455AA)

//////// App
#define FLASH_APP0_ADDR_START       (0x04000)   // Sector  2
#define FLASH_APP0_INFO_END       	(0x06000)   // Sector  3 APP1 



#define FLASH_APP1_ADDR_START      	(0x1C000)   // Sector 
#define FLASH_APP1_INFO_END      	  (0x1E000)   // Sector  APP2

#define FLASH_APP_PAGES             (12)       // 共13页  0x18000
#define FLASH_APP_SIZE              ((FLASH_PAGE_SIZE * FLASH_APP_PAGES))  

#define FLASH_RUN_OFFSET            (0x2000)
#define FLASH_RUN_ADDR              (FLASH_APP0_ADDR_START + FLASH_RUN_OFFSET)

// Env
#define FLASH_ENV_ADDR_START       ((uint32_t)0x34000)     // 

// Log
#define FLASH_LOG1_ADDR_START       ((uint32_t)0x3A000)     // Sector29
#define FLASH_LOG0_ADDR_START       ((uint32_t)0x3C000)     // Sector30

// Parameter   SN
#define FLASH_PARAMETER_ADDR_START  ((uint32_t)0x3E000)     // Sector31



//////// 函数地址 ////////
#define HDSC_MAX_ADDRESS          0x40000

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
