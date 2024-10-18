#ifndef _MUSIC_H
#define _MUSIC_H

#include "includes.h"


#define BUZ_CTRL_PORT           PortA
#define BUZ_CTRL_PIN            Pin06

#define BUZ_ENABLE()		PORT_SetBits(BUZ_CTRL_PORT, BUZ_CTRL_PIN)  
#define BUZ_DISABLE()		PORT_ResetBits(BUZ_CTRL_PORT, BUZ_CTRL_PIN) 

/*******************************************************/
typedef enum
{
	MusicReset          = 0x00,
  MusicPlay			      = 0x01,
  MusicWait         	= 0x02,  
	MusicStop           = 0x03,  	
} Music_Mode_t;

typedef struct
{
	uint32_t				  	   Running;
	Music_Mode_t				   State;
	Music_Mode_t			   	   Last_State;
	uint32_t 					   MusicPlayFre;
	uint32_t 					   MusicPlayTime;
	uint32_t 					   MusicWaitTime;
	uint32_t 					   MusicPlayNum;
	uint32_t 					   MusicPlayAllNum;
	uint32_t 					   MusicRunTime;
	uint32_t 					   MusicType;
}Music_State_t;

extern Music_State_t 	Music;
void Music_Task(void);
void Set_Music(uint32_t musictype);
void Set_MusicPar(uint32_t musictype,uint32_t playnum);
void Music_Play(uint32_t Frequent);
void Music_Wait(void);
void Music_Stop(void);
#endif

