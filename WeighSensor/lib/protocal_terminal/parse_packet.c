#include "sys.h"
#include "delay.h"

/**
* 数据包解析的实现
* 数据包格式：head + from + to + len + type + data + CRC + end
* Demo功能: 将data解析出来，提取所需数据
*/

/*
*2017年7月17日：接收到data部分还需要改，多字节数据的处理
*2017年7月18日：recv_len-5=data字节数
*              u8 data_len = recv_len - 5; //数据字节长度
*                    
*/

//判断状态
#define state_nomal      1  //常规状态下
#define state_abnomal    0  //非常规状态

#define send_head  0x80  //帧头 1个字节
#define send_from  0x01  //源地址 1个字节
#define send_to    0x02  //目的地址 1个字节
#define send_len   0x06  //长度     2个字节（包括帧头帧尾）
#define send_type     
#define send_data  0x2a  //假设数据 1个字节
#define send_CRC        //校验位
#define send_end   0x40  //帧尾 1个字节    



u8 state_system;   //系统状态
u8 recv_data;  //用于接收数据
u8 recv_state;   //用于记录接收进度
u8 recv_num;   //用于记录接收到的数据包长度
u8 recv_len;   //用于存放接收到的数据包长度 recv_len = send_len
u8 recv_flag;  //用于标志，表示一个数据包接收到


struct Get_TemperatureSensor{
            u8  state;  //0：数据正常  1：数据正在初始化  2：未启动常规采集功能
            u8  temp1;
            u8  temp2;
            u8  temp3;  //备用 
            u8  temperatureState[16];//传感器温度状态  0：硬件不支持  1：损坏  2：工作正常  3：通讯出错
            s16 temperatureData[16]; //传感器的温度值   数值/10
}tempera;


int main(){
	while(1)
	{
		//接收到数据后，
		uart_rx(  );
		base64Decode(  ); //解码

		if(state_system) //处于常规状态下
		{
			recv_state = 0;
			recv_num = 0;

			if(recv_state == 0)  //接收到帧头，第一个字节
			{
				if(recv_data == send_head)
				{
					recv_state ++; //1,读取第二个
					recv_num ++;
				}
				else
				{
					recv_len = 0; //复位
				}
			}

			if(recv_state == 1)  //接收到源地址，第二个字节
			{
				if(recv_data == send_from)
				{
					recv_state ++; //2，读取第三个
					recv_num ++;
				}
				else
				{
					recv_state = 0; //复位
				}
			}

			if(recv_state == 2)  //接收到目的地址，第三个字节
			{
				if(recv_data == send_to)
				{
					recv_state ++;//3,读取第四个
					recv_num ++;
				}
				else
				{
					recv_state = 0; //复位
				}
			}

			if(recv_state == 3 || recv_state == 4)  //接收到长度，第四个字节
			{
				if(recv_data == send_len)
				{
					recv_len = send_len;
					recv_state ++;//3,读取第五个
					recv_num ++;
				}
				else
				{
					recv_state = 0; //复位
				}
			}

			if(recv_state == 5)  //接收到类型type，第六个字节
			{
				if(recv_data == send_type)
				{
					recv_len = send_len;
					recv_state ++;//3,读取第五个
					recv_num ++;
					switch(recv_data)
					{
						//case 0:...;
						//case 1:...;
						//...
					}

				}
				else
				{
					recv_state = 0; //复位
				}
			}

			if(recv_state == 4)  //接收到数据（1个字节），第五个字节
			{
				if(recv_data == send_data)
				{
					recv_state ++;//4,读取第六个
					recv_num ++;
				}
				else
				{
					recv_state = 0; //复位
				}
			}

			if(recv_state == 5)  //接收到帧尾，第六个字节
			{
                                    if(recv_data == send_end)
                                    {
                                               // recv_state ++;//
                                                recv_flag = 0xaa;//接收到帧尾，置标志位，则数据包接收完整
                                                recv_num ++;
                                    }
                                     else
                                    {
                                                recv_state = 0; //复位
                                    }
                        }
            }
            
            else   //非常规状态下
            {
                        recv_data = 2; //未启动常规采集功能
            }
}
}
