#ifndef _BLE_H
#define _BLE_H

#include "includes.h"


typedef struct 
{
    uint32_t Tick;
} Ble_t;
extern Ble_t Ble;


void Ble_Task(void);


#endif
