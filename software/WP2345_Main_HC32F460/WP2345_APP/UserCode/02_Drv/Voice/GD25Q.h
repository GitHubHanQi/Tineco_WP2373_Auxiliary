#ifndef _GD25Q_H
#define _GD25Q_H

#include "includes.h"




// GD25Q 指令表
#define W25X_WriteEnable        (0x06)
#define W25X_WriteDisable 0x04
#define W25X_ReadStatusReg      (0x05)
#define W25X_WriteStatusReg 0x01
#define W25X_ReadData           (0x03)
#define W25X_FastReadData 0x0B
#define W25X_FastReadDual 0x3B
#define W25X_PageProgram        (0x02)
#define W25X_Block64Erase       (0xD8)
#define W25X_SectorErase        (0x20)
#define W25X_ChipErase 0xC7
#define W25X_PowerDown 0xB9
#define W25X_ReleasePowerDown   (0xAB)
#define W25X_DeviceID 0xAB
#define W25X_ManufactDeviceID   (0x90)
#define W25X_JedecDeviceID 0x9F

//#define sFLASH_ID 0XEF4017
#define W25X_DUMMY_BYTE         (0xFF)



//////// 地址
// Flash 参数
#define SPI_FLASH_START_ADDR        (0x00000000)
#define SPI_FLASH_BYTE_SIZE         (0x00400000)                // 4MB

#define SPI_FLASH_PAGE_SIZE         (0x100)                     // 256B          // 一次写入的最大字节
#define SPI_FLASH_PAGE_AMOUNT       (SPI_FLASH_BYTE_SIZE /SPI_FLASH_PAGE_SIZE)       // 总共 4096页

#define SPI_FLASH_SECTOR_SIZE       (0x1000)                    // 4KB, 16页    // 一次擦除的大小
#define SPI_FLASH_SECTOR_AMOUNT     (SPI_FLASH_BYTE_SIZE /SPI_FLASH_SECTOR_SIZE)     // 总共 256扇区

// #define SPI_FLASH_BLOCK_32KB_SIZE   (0x8000)                    // 32KB，128页，8扇区
// #define SPI_FLASH_BLOCK_32KB_AMOUNT (SPI_FLASH_BYTE_SIZE /SPI_FLASH_BLOCK_32KB_SIZE) // 总共 32k块

#define SPI_FLASH_BLOCK_64KB_SIZE   (0x10000)                   // 64KB
#define SPI_FLASH_BLOCK_64KB_AMOUNT (SPI_FLASH_BYTE_SIZE /SPI_FLASH_BLOCK_64KB_SIZE) // 总共 16块



//////// Front区
#define VOICE_FRONT_START_ADDR      (SPI_FLASH_START_ADDR)     
#define VOICE_FRONT_BYTE_SIZE       (SPI_FLASH_BYTE_SIZE /2)    
#define VOICE_FRONT_PAGE_AMOUNT     (VOICE_FRONT_BYTE_SIZE /SPI_FLASH_PAGE_SIZE)
#define VOICE_FRONT_SECTOR_AMOUNT   (VOICE_FRONT_BYTE_SIZE /SPI_FLASH_SECTOR_SIZE)

//////// Back区
#define VOICE_BACK_START_ADDR       (VOICE_FRONT_START_ADDR + VOICE_FRONT_BYTE_SIZE)    // 0x08 0000
#define VOICE_BACK_BYTE_SIZE        (VOICE_FRONT_BYTE_SIZE)
#define VOICE_BACK_PAGE_AMOUNT      (VOICE_BACK_BYTE_SIZE /SPI_FLASH_PAGE_SIZE)
#define VOICE_BACK_SECTOR_AMOUNT    (VOICE_BACK_BYTE_SIZE /SPI_FLASH_SECTOR_SIZE)

#define VOICE_BACK_WRITE_FLAG_ADDR  (SPI_FLASH_BYTE_SIZE - SPI_FLASH_SECTOR_SIZE)       // 0x0F F000


#define VOICE_BACK_WRITE_FLAG_BYTE  (0x5A)




void GD25Q_Read_ReleasePowerDownAndReadDeviceID(uint8_t *pDeviceId);
bool_t GD25Q_DeviceID_IsError(uint8_t DeviceId);

void FlashSpi_WriteEnable(void);
void FlashSpi_WaitForWriteEnd(void);
void FlashSpi_EraseSector(uint32_t Addr);
void FlashSpi_EraseBlock64KB(uint32_t Addr);
void FlashSpi_WritePage(const uint8_t* pBuf, uint32_t ToAddr, uint16_t Length);
void FlashSpi_ReadArray(uint8_t *pBuf, uint32_t FromAddr, uint16_t Length);

void GD25Q_Test(void);



#endif

