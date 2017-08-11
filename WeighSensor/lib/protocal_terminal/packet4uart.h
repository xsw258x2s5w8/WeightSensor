
#ifndef PACKET4UART_H_
#define PACKET4UART_H_

#include "QT_cmd.h"
#include "queue.h"
#define	HD_HEAD	0
#define	HD_FROM	1
#define	HD_TO	2
#define	HD_TYPE	5
#define	TL_END	4


#define	COLLECT_1	1
#define	COLLECT_2	2

#define	NORMAL_1	3
#define	NORMAL_2	4
#define	NORMAL_3	5
#define	NORMAL_4	6
#define	NORMAL_5	7
#define	NORMAL_6	8
#define	NORMAL_7	9
#define	NORMAL_8	10

#define	NON_NORMAL_1	11
#define	NON_NORMAL_2	12
#define	NON_NORMAL_3	13
#define	NON_NORMAL_4	14

#define	HEAD	0x80
#define	TAIL		0x40
#define FROM     0
#define TO          1


typedef	struct CMD_NORMAL_DATA_1{
	unsigned char number;   	//传感器个数
	unsigned char type;      //传感器协议类型
	unsigned char config;    //采集数据的配置
	unsigned char temp;     	//备用
	unsigned int  password; 	//通讯密码
}CMD_NORMAL_DATA_1;


Convey_Data protocal_packet(int type,Start_System_Formal *start,
                                Set_Address_Sensor *set,
                            Encrypt_Sensor_Address *encript);


#endif
