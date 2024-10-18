#ifndef _IIC_H
#define _IIC_H

#include "includes.h"

/* Define I2C unit used for the example */
#define I2C_UNIT                        (M4_I2C1)

/* Define port and pin for SDA and SCL */
#define I2C1_SCL_PORT                    (PortC)
#define I2C1_SCL_PIN                     (Pin04)
#define I2C1_SDA_PORT                    (PortC)
#define I2C1_SDA_PIN                     (Pin05)
#define I2C1_GPIO_SCL_FUNC               (Func_I2c1_Scl)
#define I2C1_GPIO_SDA_FUNC               (Func_I2c1_Sda)

#define I2C_FCG_USE                     (PWC_FCG1_PERIPH_I2C1)


/* Define E2PROM device address */
#define E2_ADDRESS                      (0x50u)
/* 24c256 page length */
#define E2_PAGE_LEN                     (32u)
#define E2_MEM_ADR_LEN                  (2u)
/* Define test address for read and write */
#define DATA_TEST_ADDR                  (0x0000u)


typedef struct
{
    en_port_t SCL_PORT;
    en_pin_t  SCL_PIN;

    en_port_t SDA_PORT;
    en_pin_t  SDA_PIN;

} sI2C_TypeDef;


#define sI2C_SCL_H(sI2C)    PORT_SetBits(  sI2C->SCL_PORT, sI2C->SCL_PIN)
#define sI2C_SCL_L(sI2C)    PORT_ResetBits(sI2C->SCL_PORT, sI2C->SCL_PIN)

#define sI2C_SDA_H(sI2C)    PORT_SetBits(  sI2C->SDA_PORT, sI2C->SDA_PIN)
#define sI2C_SDA_L(sI2C)    PORT_ResetBits(sI2C->SDA_PORT, sI2C->SDA_PIN)

#define sI2C_SCL_GET(sI2C)  PORT_GetBit(sI2C->SCL_PORT, sI2C->SCL_PIN)
#define sI2C_SDA_GET(sI2C)  PORT_GetBit(sI2C->SDA_PORT, sI2C->SDA_PIN)

#define PIN_OUT 0
#define PIN_IN  1

void IIC_Init(void);
void At24cxx_Test(void);
void AT24C02_TEST(void);






























#endif
