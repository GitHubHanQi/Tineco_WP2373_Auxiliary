#ifndef _MCU_H
#define _MCU_H

#include "includes.h"

#define MCU_CLK (48000000)  // 48MHz


#define MCU_UID_ADDR0   (0x00100E74)
#define MCU_UID_ADDR1   (MCU_UID_ADDR0 + 4)
#define MCU_UID_ADDR2   (MCU_UID_ADDR0 + 8)

#define IRQ_LEVEL       IrqLevel2
#define PWM_DUTY_MAX    (1000)





//////// Delay
#define USER_TICK_PERIOD	((uint8_t)(1))       // 1表示1ms
//
#define ELAPSE_10ms     (1u * 10           	/ USER_TICK_PERIOD)
#define ELAPSE_30ms     (1u * 30           	/ USER_TICK_PERIOD)
#define ELAPSE_50ms     (1u * 50            / USER_TICK_PERIOD)
#define ELAPSE_80ms     (1u * 80            / USER_TICK_PERIOD)
#define ELAPSE_100ms    (1u * 100          	/ USER_TICK_PERIOD)
#define ELAPSE_120ms    (1u * 120          	/ USER_TICK_PERIOD)
#define ELAPSE_150ms    (1u * 150          	/ USER_TICK_PERIOD)
#define ELAPSE_200ms    (1u * 200          	/ USER_TICK_PERIOD)
#define ELAPSE_500ms    (1u * 500          	/ USER_TICK_PERIOD)
//
#define ELAPSE_1s       (1000u * 1         	/ USER_TICK_PERIOD)
#define ELAPSE_2s       (1000u * 2         	/ USER_TICK_PERIOD)
#define ELAPSE_3s       (1000u * 3         	/ USER_TICK_PERIOD)
#define ELAPSE_5s       (1000u * 5         	/ USER_TICK_PERIOD)
#define ELAPSE_6s       (1000u * 6         	/ USER_TICK_PERIOD)
#define ELAPSE_10s      (1000u * 10        	/ USER_TICK_PERIOD)
#define ELAPSE_15s      (1000u * 15        	/ USER_TICK_PERIOD)
#define ELAPSE_20s      (1000u * 20        	/ USER_TICK_PERIOD)
#define ELAPSE_25s      (1000u * 25        	/ USER_TICK_PERIOD)
#define ELAPSE_30s      (1000u * 30			/ USER_TICK_PERIOD)
#define ELAPSE_70s      (1000u * 70			/ USER_TICK_PERIOD)
//
#define ELAPSE_1min     (1000u * 60 * 1    	/ USER_TICK_PERIOD)
#define ELAPSE_2min     (1000u * 60 * 2    	/ USER_TICK_PERIOD)
#define ELAPSE_5min     (1000u * 60 * 5    	/ USER_TICK_PERIOD)
#define ELAPSE_6min     (1000u * 60 * 6    	/ USER_TICK_PERIOD)
#define ELAPSE_10min    (1000u * 60 * 10   	/ USER_TICK_PERIOD)
#define ELAPSE_30min    (1000u * 60 * 30	/ USER_TICK_PERIOD)
//
#define ELAPSE_1h       (1000u * 60 * 60 * 1    / USER_TICK_PERIOD)
#define ELAPSE_5h       (1000u * 60 * 60 * 5    / USER_TICK_PERIOD)




typedef struct
{
    uint32_t Tick_ms;

    ///uint32_t HClkFreq;   // 内核时钟
    uint32_t PClkFreq_Hz;      // 外设时钟
    uint32_t PClkFreq_MHz;      // 外设时钟
    
} Mcu_t;
extern Mcu_t Mcu;

void Mcu_Init(void);


#endif
