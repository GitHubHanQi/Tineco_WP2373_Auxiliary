#ifndef _VOICE_SET_H
#define _VOICE_SET_H

#include "includes.h"



#define VOICE_VOLUME_MIN    (1)
#define VOICE_VOLUME_MAX    (5)


void Voice_Mute_Set(uint8_t Mute);
void Voice_Level_Set(uint8_t Level, uint8_t IsSave);
void Voice_Select_Set(uint8_t Select);


#endif
