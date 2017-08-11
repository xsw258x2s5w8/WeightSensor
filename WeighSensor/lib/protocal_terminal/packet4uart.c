
#include	"QT_cmd.h"
#include	"packet4uart.h"
#include    "CRC.h"

int Start_System_Formal_To_Array(unsigned char *array,Start_System_Formal *p)
{
    memcpy(array,p,sizeof(Start_System_Formal));
    return sizeof(Start_System_Formal);
}
int Set_Address_Sensor_To_Array(unsigned char *array,Set_Address_Sensor *p)
{
    memcpy(array,p,sizeof(Set_Address_Sensor));
	return sizeof(Set_Address_Sensor);
}
int Encrypt_Sensor_Address_To_Array(char* array,Encrypt_Sensor_Address *p)
{
	memcpy(array,p,sizeof(Encrypt_Sensor_Address));
	return sizeof(Encrypt_Sensor_Address);
}
static int id = 0;

Convey_Data protocal_packet(int type,Start_System_Formal *start,
                   Set_Address_Sensor *set,
                   Encrypt_Sensor_Address *encript)
{
	Convey_Data	sda;
	unsigned char array[maxByte];
	int len,i,j = 0;
	uint codeCRC;
	sda.head = HEAD;
	
	sda.id = id++;
	sda.id &= 0x7F;
	sda.from = FROM;
	sda.to = TO;
	sda.type = type;
    sda.tail = TAIL;
    switch (type)
    {
    case QT_Normal_Open_Input:
        sda.len = Start_System_Formal_To_Array(sda.data,start);
        break;
    case QT_Set_Address_Idle:
        sda.len = Set_Address_Sensor_To_Array(sda.data,set);
        break;
    case QT_Encode_Idle:
        sda.len = Encrypt_Sensor_Address_To_Array(sda.data,encript);
        break;
    default:
        sda.len = 0;
    }
	array[j++] = sda.id;
	array[j++] = sda.from;
	array[j++] = sda.to;
	memcpy(array + j,&sda.len,2);
	j = j + 2;
	array[j++] = sda.type;
	for(i = 0; i < sda.len; i++)
	{
		array[j++] = sda.data[i];
	}
	sda.CRC = CRC32Software(array,j);
	/*printf("Send Data:\n");
	printf("HEAD: %x\n", sda.head);
	printf("ID: %x\n", sda.id);
	printf("FROM: %x\n", sda.from);
	printf("TO: %x\n",sda.to);
	printf("LEN: %x\n", sda.len);
	printf("TYPE: %x\n", sda.type);
	printf("DATA: ");
	for (i = 0; i < sda.len; i++)
	{
		printf("%x ", sda.data[i]);
	}
	printf("\n");
	printf("CRC: %8x\n", sda.CRC);
	printf("TAIL: %x\n", sda.tail);*/
    return sda;
}
