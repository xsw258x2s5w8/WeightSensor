
#include "Base64.h"
#include "CRC.h"
#include "uart.h"
#include "queue.h"
#include "packet4uart.h"
#include <pthread.h>
#include <string.h>

#define SLEEP usleep(10*1000)
unsigned int mutex = 1;

/* 8 normal*/
State_Inode          state_inode;
Protocal_Version     protocal_version;
Full_Weight_Sensor   full_weight_sensor;
Sensor_Angle         sensor_angle;
Sensor_Temperature   sensor_temperature;
Sensor_Humidity      sensor_humidity;
Sensor_Current       sensor_current;
Current_Sensor_ID    current_sensor_id;
/* 4 abnormal */
All_Link_Sensor_ID          all_link_sensor_id;
Group_Sensor_Address        group_sensor_address;
Group_Sensor_Info           group_sensor_info;
Encrypt_Sensor_Address_R    encrypt_sensor_address_r;
/* 2 Query merge int one*/
Config config;
/* store receive data */
Queue *queue_uart;

pthread_t UartRecvThrId;
int UARTID;
Init_Data id;
INT8U array[maxByte];
int length;// packed data length

//id.flag = NONINIT;

void Uart_Recv(void * arg);

void QT_cmd_initial(char*passwd,unsigned char config,unsigned char flag)
{
	int err;

	if( id.flag == INIT)
		return;

	/*global variable from user*/
	memcpy(id.passwd,passwd,strlen(passwd)>128?128:strlen(passwd));
	id.config	= config;
	id.flag		= flag;

	if( id.flag == UPDATE)
		return;

	/*device operation, data structure and thread initial*/
	UARTID = uartInit("/dev/ttyUSB0");
	queue_uart = InitQueue();
	err = pthread_create(&UartRecvThrId,NULL,Uart_Recv,NULL);
	if(err != 0)
	{
		printf("cannot create thread serial port RX:%s\n",strerror(err));
		return ;
	}
	/* initialize sensor arg,such as number,id*/

}

/*
* Name:			Interface-4-QT
* Descritption: Handle each command
* Input:		Argument from QT,(type,argument)
*/
int    QT_cmd_handle(int QT_cmd,
                   Start_System_Formal *start,
                   Set_Address_Sensor *set,
                   Encrypt_Sensor_Address *encript)
{
	int try = 10;
	QNode data_return;

   	/*send start state query mode or send start config state mode*/

	int type = cmd_type(QT_cmd);

    if( type == STATE_QUERY || type == CONFIG_STATE_QUERY || type == NON_NORMAL_COLLECT)
	{
        /* step 1 */
		//printf("Step 1:\n");
		uart_tx( QT_cmd,start,set,encript );
		while( IsEmptyQueue(queue_uart) && try--)
		{// wait for 100 ms
			SLEEP;
		}
		if(try < 0)
		{
			printf("com is too slow to collect any data\n");
			return -1;
		}
		//printf("Step 2:\n");

		data_return = DeQueue( queue_uart );
		/* step 2 */
        uart_rx(data_return->data,QT_cmd);
	}

   	/*send start normal collect mode*/
	else if( type == NORMAL_COLLECT	)
	{
	    /* step 1 */
		//printf("step1:\n");
		uart_tx(QT_Normal_Open_Input,start,set,encript);
		SLEEP;
        /* step 2 */
		//printf("step2:\n");
        uart_tx( QT_cmd,start,set,encript );
		while( IsEmptyQueue(queue_uart) && try--)
		{
			SLEEP;
		}
		//if(IsEmptyQueue(queue_uart))
		//	printf("Don't Receive Any Dada\n");
		if(try < 0)
		{
			printf("com is too slow to collect any data\n");
			return -1;
		}
		data_return = DeQueue( queue_uart );
		//printf("Step3:\n");
		uart_rx(data_return->data,QT_cmd );

        /* step 4 */
		//printf("Step4:\n");
		uart_tx( QT_Cmd_Close,start,set,encript);
	}

   	/* unknown mode*/
	else
	{
	}

	return 1;
}

/*
 * Name:		uart_tx
 * Description: uart send for user
 *
 * */
void uart_tx(int type,Start_System_Formal *start,
                   Set_Address_Sensor *set,
                   Encrypt_Sensor_Address *encript)
{
	Convey_Data sda;
	sda = protocal_packet( type,start,set,encript);
	length = ConveydataToArray(array,&sda);

	//encryt(p);
	//Base64Encode(p);
	//CRC(p);
	//printf("%d\n",length);
	Uart_Send(array,length);
}
/*
* Name:
* Descritption: return state according to command
* Input:
*/
int cmd_type(int cmd)
{
    if(cmd == QT_Config_All)
        return STATE_QUERY;
    if(cmd == QT_Current_State_All)
        return CONFIG_STATE_QUERY;
    if(cmd == QT_Connect_ID_Idle || cmd == QT_Set_Address_Idle || cmd == QT_Scan_Idle || cmd == QT_Encode_Idle)
        return NON_NORMAL_COLLECT;
    if(cmd == QT_Isn_State_Normal || cmd == QT_Measure_Protocal_Normal || cmd == QT_Full_Weight_Normal || cmd == QT_Angle_Normal
       || cmd == QT_Tempera_Normal || cmd == QT_Humidity_Normal || cmd == QT_Current_Normal || cmd == QT_ID_Normal)
        return NORMAL_COLLECT;
	return 0;
}

/*
 * Name:		uart_rx
 * Description: uart send for user
 * transalte received data into data structure
 * */
void uart_rx(Convey_Data* q,int cmd)
{
    switch (cmd)
    {
        /* 8 normal */
        case QT_Isn_State_Normal:
			memcpy(&state_inode,q->data,sizeof(State_Inode));
            break;
        case QT_Measure_Protocal_Normal:
			memcpy(&protocal_version,q->data,sizeof(Protocal_Version));
            break;
        case QT_Full_Weight_Normal:
			memcpy(&full_weight_sensor,q->data,sizeof(Full_Weight_Sensor));
			break;
        case QT_Angle_Normal:
			memcpy(&sensor_angle,q->data,sizeof(Sensor_Angle));
            break;
        case QT_Tempera_Normal:
			memcpy(&sensor_temperature,q->data,sizeof(Sensor_Temperature));
            break;
        case QT_Humidity_Normal:
			memcpy(&sensor_humidity,q->data,sizeof(Sensor_Humidity));
            break;
        case QT_Current_Normal:
			memcpy(&sensor_current,q->data,sizeof(Sensor_Current));
            break;
        case QT_ID_Normal:
			memcpy(&current_sensor_id,q->data,sizeof(Current_Sensor_ID));
            break;
        /* 4 abnormal */

        case QT_Connect_ID_Idle:
			memcpy(&all_link_sensor_id,q->data,sizeof(All_Link_Sensor_ID));	
            break;
        case QT_Set_Address_Idle:
			memcpy(&group_sensor_address,q->data,sizeof(Group_Sensor_Address));
            break;
        case QT_Scan_Idle:
			memcpy(&group_sensor_info,q->data,sizeof(Group_Sensor_Info));
            break;
        case QT_Encode_Idle:
            memcpy(&encrypt_sensor_address_r,q->data,sizeof(Encrypt_Sensor_Address_R));
            break;
        /* 2 */
        case QT_Config_All:
			memcpy(&config,q->data,sizeof(Config)); 
			break;
        case QT_Current_State_All:
			memcpy(&config,q->data,sizeof(Config));
            break;
            default:
                break;
    }
	mutex++;
}
/*
 * Name:
 * Description: uart send at low level
 *
 * */
void Uart_Send(char* array,int length)
{
	/*int i;
	for(i = 0; i < length; i++)
	{
		printf("%02x ",array[i]);
	}	
	printf("\n");*/
	write( UARTID,array,length);
}

/*
 * Name:
 * Description: uart receive at low level
 *
 * */
void Uart_Recv(void * arg)
{
	fd_set	fs_read;
	int		flag=0;
	int tmp;
	int		i,j,k,num,m,len1,len2,plus;
	struct	timeval timeout = {1,0};
	unsigned char temp[maxByte];
	unsigned char array[maxByte];
	unsigned char base[maxByte];
	unsigned char debase[maxByte];

	while(1)
	{
		FD_ZERO(&fs_read);
		FD_SET(UARTID,&fs_read);
		//printf("fs_read = %x\n",fs_read);
		timeout.tv_sec = 3;
		timeout.tv_usec = 0;
		tmp = select(UARTID+1,&fs_read,NULL,NULL,&timeout);
		if(tmp  < 0)
		{
			perror("select");
			continue;
		}
		else
		{
			if( FD_ISSET(UARTID,&fs_read) )
			{
				while((num = read(UARTID,temp,maxByte)) > 0)
				{
					for(i = 0;i<num;i++)
					{
						//printf("received Data %x \n",temp[i]);
						if(temp[i] == HEAD && flag == 0)
						{
							array[0] = temp[i];
							j = 1 ;
							flag = 1;
							continue;
						}
						else if(flag == 1)
						{
							//printf("Recevied Data:%d\n",j);
						    base[j - 1] = temp[i];
							array[j] = temp[i];
							if( temp[i] == TAIL )
							{
								//printf("Recevied Data:%d\n",j);
								flag = 0;
                                /* find number of decoded byte */
                                len1 = j - 1;
                                plus = len1 % 4;
                                if(plus == 0)
                                {
                                    num = len1 / 4 * 3;
                                    len2 = len1;
                                }
                                else
                                {
                                    num = len1 / 4 * 3 + plus-1;
                                    len2 = len1 / 4 * 4 + 4;
                                }
                                len1 = base64Decode(base,len2);
                                for(k = 0; k < num; k++)
                                {
                                    array[k+1] = base[k];
                                }
                                array[k+1] = TAIL;
								//printf("Decoded Length : %d\n",k + 1);
								/*for(m = 0; m <= k + 1; m++)
								{
									printf("%2x ",array[m]);
								}
								printf("\n");*/
								/*while(queue_uart->size != 0)
								{
									FLAG = 0;;
								}*/
								EnQueuebyArray(queue_uart,array);
								memset(array,0,maxByte);
								break;
							}
							j++;
						}
					}
					memset(temp,0,maxByte);
				}
			}
		}
	}
	return NULL;
}
/* convert struct into array */
int ConveydataToArray(INT8U* array,Convey_Data *p)
{
    unsigned char temp[maxByte];
    unsigned char temp1[maxByte];

    int i = 0,j,len1;
    int len = p->len;
    temp[i++] = p->id;
    temp[i++] = p->from;
    temp[i++] = p->to;
	memcpy(temp + i,&(p->len),2);
	i = i + 2;
	temp[i++] = p->type;
    for(j = 0; j < len; j++)
        temp[i++] = p->data[j];
	memcpy(temp + i,&(p->CRC),4);
    i = i + 4;
	/*for(j = 0 ; j < i; j++)
	{
		printf("%2x ",temp[j]);
	}
	printf("\n");
	*/
	unsigned char * t = base64Encode(temp,i);
    memcpy(temp1,t,maxByte);
	if(i%3== 0)
		len1 = i / 3 * 4;
	else
		len1 = i / 3 * 4 + 1 + i % 3;
    array[0] = p->head;
    for(j = 0; j < len1; j++)
    {
        array[1+j] = temp1[j];
    }
    array[1+j] = p->tail;
	return 2+j;
}
