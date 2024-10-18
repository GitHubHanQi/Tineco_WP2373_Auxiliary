#ifndef __DRV_FLASH_H_
#define __DRV_FLASH_H_
#include "hc32_ddl.h"

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



#define FLASH_PAGE_SIZE             ((uint32_t)0x2000)                 // 8K字节  


//////// Flash 地址 ////////
//////// Boot
#define FLASH_BOOT_ADDR_START       (0)     // Sector 0
#define FLASH_BOOT_PAGES            (2)    // 共2页
#define FLASH_BOOT_SIZE             (FLASH_PAGE_SIZE * FLASH_BOOT_PAGES)    // 2000 * 2 = 0x4000 FLASH_PAGE_SIZE * FLASH_BOOT_PAGES

#define FLASH_MARK_ADDR             (FLASH_BOOT_ADDR_START + FLASH_BOOT_SIZE - FLASH_PAGE_SIZE)  // 0x2000 - 0x3FFF 最后一页用于存标记
#define FLASH_MARK_WORD             (0x123455AA)

//////// App
#define FLASH_APP0_ADDR_START       ((uint32_t)0x04000)   // Sector  2
#define FLASH_APP0_INFO_END       	((uint32_t)0x06000)   // Sector  3 APP1 


#define FLASH_APP1_ADDR_START      	((uint32_t)0x1C000)   // Sector 22
#define FLASH_APP1_INFO_END      	  ((uint32_t)0x1E000)   // Sector 17 APP2



#define FLASH_APP_PAGES             (12)       // 共13页  
#define FLASH_APP_SIZE              ((uint32_t)FLASH_PAGE_SIZE * FLASH_APP_PAGES) // 96K

#define FLASH_RUN_OFFSET            (0x2000)
#define FLASH_RUN_ADDR              (FLASH_APP0_ADDR_START + FLASH_RUN_OFFSET) //FLASH_APP0_INFO_END

// Pump
#define PUMP_SET_ADDR       		    ((uint32_t)0x38000)     // Sector28

// Log
#define FLASH_LOG1_ADDR_START       ((uint32_t)0x3A000)     // Sector29
#define FLASH_LOG0_ADDR_START       ((uint32_t)0x3C000)     // Sector30

// Parameter
#define FLASH_PARAMETER_ADDR_START  ((uint32_t)0x3E000)     // Sector31






void Flash__Init(void);


void Flash__Unlock(void);
void Flash__Lock(void);


void Flash__ErasePage(uint32_t FlashAddr);

void Flash__WriteWord(uint32_t FlashAddr, uint32_t Data);
void Flash__WriteArray(uint32_t FlashAddr, const uint8_t *pBuf, uint16_t Length);

uint8_t Flash__ReadByte(uint32_t FlashAddr);
uint32_t Flash__ReadWord(uint32_t FlashAddr);
void Flash__ReadArray(uint32_t FlashAddr, uint8_t *pBuf, uint16_t Length);




//extern uint8_t Flash__Test_Buf0[];
//extern uint8_t Flash__Test_Buf1[];
//extern uint8_t Flash__Test_Buf2[];
void Flash__Test(void);


#endif
