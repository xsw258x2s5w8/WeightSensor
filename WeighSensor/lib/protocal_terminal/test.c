
#include "QT_cmd.h"

Start_System_Formal start_system_formal; 
Set_Address_Sensor set_address_sensor;
Encrypt_Sensor_Address encrypt_sensor_address;

/* 8 normal*/
extern State_Inode          state_inode;
extern Protocal_Version     protocal_version;
extern Full_Weight_Sensor   full_weight_sensor;
extern Sensor_Angle         sensor_angle;
extern Sensor_Temperature   sensor_temperature;
extern Sensor_Humidity      sensor_humidity;
extern Sensor_Current       sensor_current;
extern Current_Sensor_ID    current_sensor_id;
/* 4 abnormal */
extern All_Link_Sensor_ID          all_link_sensor_id;
extern Group_Sensor_Address        group_sensor_address;
extern Group_Sensor_Info           group_sensor_info;
extern Encrypt_Sensor_Address_R    encrypt_sensor_address_r;
/* 2 Query merge int one*/
extern Config config;
/* store receive data */
extern unsigned int mutex;

#define WAIT while(mutex != 1) usleep(10 * 1000);
void printReceivedData(int cmd);

int main()
{
	int i,j;
	int ret;
	for(i = 0; i < 16; i++)
	 start_system_formal.type[i] = i;
	start_system_formal.config = 1;
	start_system_formal.temp[0] = 0;
	start_system_formal.temp[1] = 0;
	start_system_formal.temp[2] = 0;
	start_system_formal.passWord = 0x12345678;
	
	set_address_sensor.type = 1;
	set_address_sensor.number = 16;
	set_address_sensor.temp1 = 1;
	set_address_sensor.temp2 = 2;
	for(i=0;i<16;i++)
		set_address_sensor.ID[i]=i;

	for(i=0;i<16;i++)
		set_address_sensor.address[i]=i;
	
	encrypt_sensor_address.type = 1;
	encrypt_sensor_address.number = 16;
	encrypt_sensor_address.temp1 = 1;
	encrypt_sensor_address.temp2 = 2;
	encrypt_sensor_address.password = 0xffffffff;
	for(i=0;i<16;i++)
		encrypt_sensor_address.address[i]=i;
	
	QT_cmd_initial("123456","1","1");
	/**********************************/
	WAIT;
	mutex--;
	ret = QT_cmd_handle(QT_Config_All,NULL,NULL,NULL);
	WAIT;
	printReceivedData(1);
	/***********************************/
	WAIT;
	mutex--;
	QT_cmd_handle(QT_Current_State_All,NULL,NULL,NULL);
	WAIT;
	printReceivedData(2);
	/*********************************/
	WAIT;
	mutex--;
	QT_cmd_handle(QT_Isn_State_Normal,&start_system_formal,NULL,NULL);
	WAIT;
	printReceivedData(3);
	/************************************/
    WAIT;
	mutex--;
	QT_cmd_handle(QT_Measure_Protocal_Normal,&start_system_formal,NULL,NULL); 
    WAIT;
	printReceivedData(4); 
	/**************************************/
	WAIT;
	mutex--;
	QT_cmd_handle(QT_Full_Weight_Normal,&start_system_formal,NULL,NULL); 
	WAIT;
	printReceivedData(5); 
	/***************************************/
	WAIT;
	mutex--;
	QT_cmd_handle(QT_Angle_Normal,&start_system_formal,NULL,NULL); 
    WAIT;
	printReceivedData(6); 
	/***************************************/
	WAIT;
	mutex--;
	QT_cmd_handle(QT_Tempera_Normal,&start_system_formal,NULL,NULL); 
	WAIT;
	printReceivedData(7);
	/***************************************/
    WAIT;
	mutex--;
	QT_cmd_handle(QT_Humidity_Normal,&start_system_formal,NULL,NULL); 
	WAIT;
	printReceivedData(8);
	/*********************************************/
	WAIT; 
	mutex--;
	QT_cmd_handle(QT_Current_Normal,&start_system_formal,NULL,NULL); 
	WAIT;
	printReceivedData(9); 
	/************************************************/
	WAIT;
	mutex--;
	QT_cmd_handle(QT_ID_Normal,&start_system_formal,NULL,NULL); 
    WAIT;
	printReceivedData(10); 
	/************************************************/
	WAIT;
	mutex--;
	ret = QT_cmd_handle(QT_Connect_ID_Idle,NULL,NULL,NULL);
	WAIT;
	printReceivedData(11); 
	/************************************************/
	WAIT;
	mutex--;
	ret = QT_cmd_handle(QT_Set_Address_Idle,NULL,&set_address_sensor,NULL);
	WAIT;
	printReceivedData(12); 
	/***********************************************/
	WAIT;
	mutex--;
	ret = QT_cmd_handle(QT_Scan_Idle,NULL,NULL,NULL);
	WAIT;
	printReceivedData(13);
    /*************************************************/	
	WAIT;
	mutex--;
	ret = QT_cmd_handle(QT_Encode_Idle,NULL,NULL,&encrypt_sensor_address);
	WAIT;
	printReceivedData(14); 
	while(1);	
	return 0;
}

void printReceivedData(int cmd)
{
	/* 8 normal */
		int j;
		/*while(queue_uart->size > 0)
			usleep(10 * 1000);
		usleep(100 * 1000);*/
		printf("*******************************************Recevived Data***************************************************\n");

	switch(cmd)
	{
		case QT_Isn_State_Normal:
			printf("state = %x\n",state_inode.state);
			printf("temp1 = %x\n",state_inode.temp1); 
			printf("temp2 = %x\n",state_inode.temp2); 
			printf("temp3 = %x\n",state_inode.temp3);
		    for(j = 0; j < 	16; j++)
			{
				printf("Cell%disn:%f\n",j,state_inode.CellState[j].isn);
				printf("Cell%dState0:%x\n",j,state_inode.CellState[j].state0);
				printf("Cell%dState1:%x\n",j,state_inode.CellState[j].state1);
			    printf("Cell%dtemp4:%x\n",j,state_inode.CellState[j].temp4);
				printf("Cell%dtemp5:%x\n",j,state_inode.CellState[j].temp5);	
			}
            break;
        case QT_Measure_Protocal_Normal:
			printf("C_type		 = %x\n",protocal_version.C_type);
			printf("C_ext_type	 = %x\n",protocal_version.C_ext_type); 			
			printf("E_type = %x\n",protocal_version.E_type); 
			printf("E_ext_type = %x\n",protocal_version.E_ext_type); 
			printf("K_type = %x\n",protocal_version.K_type); 
			printf("K_ext_type = %x\n",protocal_version.K_ext_type); 
			printf("CAN_type = %x\n",protocal_version.CAN_type); 
			printf("CAN_ext_type = %x\n",protocal_version.CAN_ext_type); 
            break;
        case QT_Full_Weight_Normal:
            printf("state = %x\n",full_weight_sensor.state);
            printf("temp1 = %x\n",full_weight_sensor.temp1);
            printf("temp2 = %x\n",full_weight_sensor.temp2);
            printf("temp3 = %x\n",full_weight_sensor.temp3);
		   	for(j = 0; j < 16; j++)
			{
				printf("CellState%d = %x\n",j,full_weight_sensor.CellState[j]);
			}
            for(j = 0; j < 16; j++)
            {
				printf("FullWeight%d = %x\n",j,full_weight_sensor.fullWeight[j]);
			}
            break;
        case QT_Angle_Normal:
            printf("state = %x\n",sensor_angle.state);
            printf("temp1 = %x\n",sensor_angle.temp1);
			printf("temp2 = %x\n",sensor_angle.temp2);  
			printf("temp3 = %x\n",sensor_angle.temp3);
            for(j = 0; j < 16; j++)
			{
				printf("cornerXstate%d = %x\n",j,sensor_angle.cornerXState[j]);
			}
            for(j = 0; j < 16; j++)
            {
				printf("cornerXData%d = %x\n",j,sensor_angle.cornerXDate[j]);
            }
			for(j = 0; j < 16; j++)	
			{
				printf("cornerYstate%d = %x\n",j,sensor_angle.cornerYState[j]);
			}
			for(j = 0; j < 16; j++)
			{
				printf("cornerYData%d = %x\n",j,sensor_angle.cornerYDate[j]);								
			}
            break;
        case QT_Tempera_Normal:
            printf("state = %x\n",sensor_temperature.state);
            printf("temp1 = %x\n",sensor_temperature.temp1);
			printf("temp2 = %x\n",sensor_temperature.temp2);
			printf("temp3 = %x\n",sensor_temperature.temp3);
            for(j = 0; j < 16; j++)
               printf("temperateState%d = %x\n",j,sensor_temperature.temperatureState[j]);
            for(j = 0; j < 16; j++)
            {
				printf("temperateData%d = %x\n",j,sensor_temperature.temperatureData[j]);
            }
            break;
        case QT_Humidity_Normal:
            printf("state = %x\n",sensor_humidity.state);
            printf("temp1 = %x\n",sensor_humidity.temp1);
			printf("temp2 = %x\n",sensor_humidity.temp2);
			printf("temp3 = %x\n",sensor_humidity.temp3);
            for(j = 0; j < 16; j++)
				printf("humioityState%d = %x\n",j,sensor_humidity.humidityState[j]);
            for(j = 0; j < 16; j++)
            {
				printf("humidityData%d = %x\n",j,sensor_humidity.humidityData[j]);
            }
            break;
        case QT_Current_Normal:
            printf("state = %x\n",sensor_current.state);
			printf("temp1 = %x\n",sensor_current.temp1);
			printf("temp2 = %x\n",sensor_current.temp2); 
			printf("temp3 = %x\n",sensor_current.temp3); 
            for(j = 0; j < 16; j++)
                printf("currentState%d = %x\n",j,sensor_current.currentState[j]);
            for(j = 0; j < 16; j++)
            {
				printf("currentData%d = %x\n",j,sensor_current.currentData[j]);
            }
            break;
        case QT_ID_Normal:
			printf("state = %x\n",current_sensor_id.state);
			printf("temp1 = %x\n",current_sensor_id.temp1);
            printf("temp2 = %x\n",current_sensor_id.temp2);
			printf("temp3 = %x\n",current_sensor_id.temp3);
            for(j = 0; j < 16; j++)
				printf("CellState%d = %x\n",j,current_sensor_id.CellState[j]);
            for(j = 0; j < 16; j++)
                printf("IDData%d = %x\n",j,current_sensor_id.IDData[j]);

            break;
        /* 4 abnormal */

        case QT_Connect_ID_Idle:
            printf("state = %x\n",all_link_sensor_id.state);
			printf("type = %x\n",all_link_sensor_id.type);
			printf("number = %x\n",all_link_sensor_id.number);
			printf("temp1 = %x\n",all_link_sensor_id.temp1);
            for(j = 0; j < 16; j++)
            {
				printf("IDData%d = %x\n",j,all_link_sensor_id.IDData[j]);
            }
            break;
        case QT_Set_Address_Idle:
			printf("number = %x\n",group_sensor_address.number);
			printf("temp1 = %x\n",group_sensor_address.temp1);
			printf("temp2 = %x\n",group_sensor_address.temp2);
			printf("temp3 = %x\n",group_sensor_address.temp3);
            for(j = 0; j < 16; j++)
            {
                printf("address%d = %x\n",j,group_sensor_address.state[j]);
            }
            break;
        case QT_Scan_Idle:
            for(j = 0; j < 16; j++)
            {
               printf("State%d = %x\n",j,group_sensor_info.State[j]);
            }
            for(j = 0; j < 16; j++)
            {
				printf("IDData%d = %x\n",j,group_sensor_info.IDData[j]);
            }
            break;
        case QT_Encode_Idle:
			printf("number = %x\n",encrypt_sensor_address_r.number);
			printf("temp1 = %x\n",encrypt_sensor_address_r.temp1);
			printf("temp2 = %x\n",encrypt_sensor_address_r.temp2); 
			printf("temp3 = %x\n",encrypt_sensor_address_r.temp3); 
            for(j = 0 ; j < 16; j++)
            {
				printf("State%d = %x\n",j,encrypt_sensor_address_r.State[j]);
            }
            break;
        /* 2 */
        case QT_Config_All:                                                                                                                                                                            
			printf("state = %x\n",config.state);
			printf("temp1 = %x\n",config.temp1);
			printf("temp2 = %x\n",config.temp2);  
			printf("temp3 = %x\n",config.temp3);
			break;
        case QT_Current_State_All:
			printf("state = %x\n",config.state);
			printf("temp1 = %x\n",config.temp1);
			printf("temp2 = %x\n",config.temp2);  
			printf("temp3 = %x\n",config.temp3);
            break;
            default:
                break;

	}
	printf("*************************************************Received Completed*********************************************************\n");
}
