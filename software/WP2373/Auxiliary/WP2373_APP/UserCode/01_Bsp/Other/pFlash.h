#ifndef _PFLASH_H
#define _PFLASH_H

#include "includes.h"

#define HDSC_MAX_ADDRESS          0x40000

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



extern void FlashWriteByte(uint32_t u32Addr, uint8_t* txbuf, uint16_t len);
extern void FlashSectorErase(uint32_t Sector_Addr);



#endif
