
#ifndef QT_CMD_H_
#define QT_CMD_H_

#include "queue.h"
#include "datastruct.c"

#define		NONINIT	0
#define		INIT	1
#define		UPDATE	2

#define	STATE_QUERY			1
#define	CONFIG_STATE_QUERY	2
#define	NON_NORMAL_COLLECT	3
#define	NORMAL_COLLECT		4
/* STATE_QUERY */
#define 	QT_Config_All					0x01
#define		QT_Current_State_All			0x02
/* 8������  */
#define 	QT_Isn_State_Normal				0x03
#define		QT_Measure_Protocal_Normal		0x04
#define 	QT_Full_Weight_Normal			0x05
#define		QT_Angle_Normal					0x06
#define		QT_Tempera_Normal				0x07
#define		QT_Humidity_Normal				0x08
#define 	QT_Current_Normal				0x09
#define		QT_ID_Normal					0x0a
/* 4���ǳ��� */
#define 	QT_Connect_ID_Idle				0x0b
#define		QT_Set_Address_Idle				0x0c
#define 	QT_Scan_Idle					0x0d
#define  	QT_Encode_Idle					0x0e
/* ��ʼ���� */
#define		QT_Normal_Open_Input			0x0f
/* �ָ����� */
#define		QT_Fac_Config_Open				0x10
/* �ر� */
#define     QT_Cmd_Close                    0x11
#define maxByte 256
#define numSensor 16


typedef struct Convey_Data{
	INT8U   head;
	INT8U   id;
	INT8U   from;
	INT8U   to;
	INT16S  len;
	INT8U   type;
	INT8U   data[maxByte];
	INT32U  CRC;
	INT8U   tail;
}Convey_Data;

typedef struct Sensor_Protocal{
    unsigned char     C_type;
    unsigned char     C_ext_type;
    unsigned char     E_type;
    unsigned char     E_ext_type;
    unsigned char     K_type;
    unsigned char     K_ext_type;
    unsigned char     CAN_type;
    unsigned char     CAN_ext_type;
}Sensor_Protocal;

//1�����������ɼ�
typedef struct Start_System_Formal{
	INT8U	type[numSensor];
	INT8U	config;
	INT8U	temp[3];
	INT32U	passWord;	
}Start_System_Formal;

//2������ID�����ַ�����ô�������ַ
//����
typedef struct Set_Address_Sensor{
            INT8U  type;   //������Э������
            INT8U  number; //����������
            INT8U  temp1;  //����
            INT8U  temp2;  //����
            INT32U ID[numSensor];//��������ID��
            INT8U  address[numSensor];//��������ַ �ɵ�ַ
}Set_Address_Sensor;

//3������ַ����
 //����
 typedef struct Encrypt_Sensor_Address{
	        INT8U     type  ; //������Э������   0����  1��C�� 2��E�� 3:K�� 4��CAN��
	        INT8U     number;   //����������
	        INT8U     temp1;    //����
	        INT8U     temp2;    //����
            INT32U    password; //ͨѶ����
	        INT8U     address[numSensor]; //��������ַ
}Encrypt_Sensor_Address;

typedef struct Init_Data{
	char passwd[128];
	unsigned char config;
	unsigned char flag;
}Init_Data;

int ConveydataToArray(INT8U* array,Convey_Data *p);
void QT_cmd_initial(char *passwd,unsigned char config,unsigned char flag);
/* 14 interface for QT */
int	QT_cmd_handle(int cmd,
                   Start_System_Formal *start,
                   Set_Address_Sensor *set,
                   Encrypt_Sensor_Address *encript);

#endif
