#ifndef _MIFARE_H_
#define _MIFARE_H_
#define KEY_A_AUTH 0
#define KEY_B_AUTH 1

extern unsigned char SECTOR,BLOCK,BLOCK_NUM;
extern unsigned char BLOCK_VAULE[4];
extern unsigned char INCREMENT_VALUE[4];
extern unsigned char DECREMENT_VALUE[4];
extern unsigned char BLOCK_DATA[16];
extern unsigned char KEY_A[16][6];
extern unsigned char KEY_B[16][6];
extern void Mifare_Clear_Crypto(void);
extern unsigned char Mifare_Transfer(unsigned char block_num);
extern unsigned char Mifare_Restore(unsigned char block_num);
extern unsigned char Mifare_Blockset(unsigned char block_num,unsigned char *data_buff);
extern unsigned char Mifare_Blockinc(unsigned char block_num,unsigned char *data_buff);
extern unsigned char Mifare_Blockdec(unsigned char block_num,unsigned char *data_buff);
extern unsigned char Mifare_Blockwrite(unsigned char block_num,unsigned char *data_buff);
extern unsigned char Mifare_Blockread(unsigned char block_num,unsigned char *data_buff);
extern unsigned char Mifare_Auth(unsigned char mode,unsigned char sector,unsigned char *mifare_key,unsigned char *card_uid);
#endif
