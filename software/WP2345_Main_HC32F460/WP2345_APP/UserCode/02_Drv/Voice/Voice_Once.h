#ifndef _VOICE_ONCE_H
#define _VOICE_ONCE_H

#include "includes.h"


typedef struct 
{
    bool_t Discharge20;
    bool_t Discharge10;
    //
    bool_t TankSewageFull;
    bool_t TankClearEmpty;
} Voice_Once_t;
extern Voice_Once_t Voice_Once;


void Voice_Clear(void);
void Voice_LowBattery(void);


#endif

