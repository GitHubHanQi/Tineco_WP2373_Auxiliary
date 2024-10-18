#ifndef _READERAPI_H_
#define _READERAPI_H_


static const unsigned char RF_CMD_REQA = 0x26;
static const unsigned char RF_CMD_WUPA	= 0x52;
static const unsigned char RF_CMD_ANTICOL = 0x93;
static const unsigned char RF_CMD_SELECT = 0x93;
static const unsigned char RF_CMD_ANTICOL2 = 0x95;
static const unsigned char RF_CMD_SELECT2 = 0x95;
static const unsigned char RF_CMD_HLTA = 0x50;
static const unsigned char RF_CMD_PWDAUTH = 0x1B;

//�����������
#define MODWIDTH_106 0x26 //106KbpsΪ0x26
#define MODWIDTH_212 0x13 //212kbpsΪ0x13
#define MODWIDTH_424 0x09 //424kbpsΪ0x09
#define MODWIDTH_848 0x04 //848kbpsΪ0x04
//���ղ�������
//TYPE A
#define RXGAIN_A		4		//���÷�Χ0~7
#define GSNON_A			15			//���÷�Χ0~15
#define GSP_A 			31			//���÷�Χ0~63
#define COLLLEVEL_A 4	//���÷�Χ0~7
#define MINLEVEL_A  5	//���÷�Χ0~15
//TYPE B
#define RXGAIN_B		6		//���÷�Χ0~7
#define GSNON_B			15			//���÷�Χ0~15
#define MODGSNON_B 	6 	//���÷�Χ0~15
#define GSP_B 			31			//���÷�Χ0~63
#define MODGSP_B 		10		//���÷�Χ0~63
#define MINLEVEL_B  4	//���÷�Χ0~15




#define RXWAIT 		4		//���÷�Χ0~63
#define UARTSEL 	2		//Ĭ������Ϊ2  ���÷�Χ0~3 0:�̶��͵�ƽ 1:TIN�����ź� 2:�ڲ������ź� 3:TIN�����ź�

struct picc_b_struct
{
unsigned char ATQB[12];
unsigned char	PUPI[4];
unsigned char	APPLICATION_DATA[4];
unsigned char	PROTOCOL_INF[3];
unsigned char ATTRIB[10];
unsigned char UID[8];	
};

extern struct picc_b_struct PICC_B; 

struct picc_a_struct
{
unsigned char ATQA[2];
unsigned char UID[7];
unsigned char BCC;
unsigned char SAK;
unsigned char CK1;
unsigned char CK2;	
};

extern struct picc_a_struct PICC_A; 

#define FM175XX_SUCCESS				0x00
#define FM175XX_RESET_ERR			0xF1
#define FM175XX_PARAM_ERR 		0xF2	//�����������
#define FM175XX_TIMER_ERR			0xF3	//���ճ�ʱ
#define FM175XX_COMM_ERR			0xF4	//ͨ�Ŵ���
#define FM175XX_COLL_ERR			0xF5	//��ͻ����
#define FM175XX_FIFO_ERR			0xF6	//FIFO����
#define FM175XX_CRC_ERR				0xF7
#define FM175XX_PARITY_ERR		0xF8
#define FM175XX_PROTOCOL_ERR	0xF9

#define FM175XX_AUTH_ERR	0xE1


#define FM175XX_RATS_ERR 	0xD1
#define FM175XX_PPS_ERR 	0xD2
#define FM175XX_PCB_ERR 	0xD3

typedef struct
{
	unsigned char Cmd;                 	// �������
	unsigned char SendCRCEnable;
	unsigned char ReceiveCRCEnable;
	unsigned char nBitsToSend;					//׼�����͵�λ��	
	unsigned char nBytesToSend;        	//׼�����͵��ֽ���
	unsigned char nBitsToReceive;					//׼�����յ�λ��	
	unsigned char nBytesToReceive;			//׼�����յ��ֽ���	
	unsigned char nBytesReceived;      	// �ѽ��յ��ֽ���
	unsigned char nBitsReceived;       	// �ѽ��յ�λ��
	unsigned char *pSendBuf;						//�������ݻ�����
	unsigned char *pReceiveBuf;					//�������ݻ�����
	unsigned char CollPos;             	// ��ײλ��
	unsigned char Error;								// ����״̬
	unsigned char Timeout;							//��ʱʱ��
} command_struct;


extern unsigned  char FM175XX_Initial_ReaderA(void);
extern void FM175XX_Initial_ReaderB(void);
extern unsigned char ReaderA_Halt(void);
extern unsigned char ReaderA_Request(void);
extern unsigned char ReaderA_Wakeup(void);

extern unsigned char ReaderA_AntiColl(void);
extern unsigned char ReaderA_Select(void);
extern unsigned char ReaderA_AntiColl2(void);
extern unsigned char ReaderA_Select2(void);
extern unsigned char ReaderA_CardActivate(void);
extern unsigned char ReaderA_GETVERSION(void);
extern unsigned char ReaderA_PWD_AUTH(void);
unsigned char ReaderA_Read(unsigned char addr);
unsigned char ReaderA_Write(unsigned char addr,unsigned char dat[4]);

extern unsigned char ReaderB_Request(void);
extern unsigned char ReaderB_Wakeup(void);
extern unsigned char ReaderB_Attrib(void);
extern unsigned char ReaderB_GetUID(void);
extern unsigned char FM175XX_Polling(unsigned char *polling_card);
#endif

