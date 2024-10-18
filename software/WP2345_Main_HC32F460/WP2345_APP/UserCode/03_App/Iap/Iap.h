#ifndef _IAP_H
#define _IAP_H

#include "includes.h"


typedef struct
{
    uint32_t Tick;
} Iap_t;
extern Iap_t Iap;


void Iap_Start(void);
void Iap_Stop(void);
void Iap_Task(void);


#endif

