#include "sys.h"
#include "delay.h"

/**
* ���ݰ�������ʵ��
* ���ݰ���ʽ��head + from + to + len + type + data + CRC + end
* Demo����: ��data������������ȡ��������
*/

/*
*2017��7��17�գ����յ�data���ֻ���Ҫ�ģ����ֽ����ݵĴ���
*2017��7��18�գ�recv_len-5=data�ֽ���
*              u8 data_len = recv_len - 5; //�����ֽڳ���
*                    
*/

//�ж�״̬
#define state_nomal      1  //����״̬��
#define state_abnomal    0  //�ǳ���״̬

#define send_head  0x80  //֡ͷ 1���ֽ�
#define send_from  0x01  //Դ��ַ 1���ֽ�
#define send_to    0x02  //Ŀ�ĵ�ַ 1���ֽ�
#define send_len   0x06  //����     2���ֽڣ�����֡ͷ֡β��
#define send_type     
#define send_data  0x2a  //�������� 1���ֽ�
#define send_CRC        //У��λ
#define send_end   0x40  //֡β 1���ֽ�    



u8 state_system;   //ϵͳ״̬
u8 recv_data;  //���ڽ�������
u8 recv_state;   //���ڼ�¼���ս���
u8 recv_num;   //���ڼ�¼���յ������ݰ�����
u8 recv_len;   //���ڴ�Ž��յ������ݰ����� recv_len = send_len
u8 recv_flag;  //���ڱ�־����ʾһ�����ݰ����յ�


struct Get_TemperatureSensor{
            u8  state;  //0����������  1���������ڳ�ʼ��  2��δ��������ɼ�����
            u8  temp1;
            u8  temp2;
            u8  temp3;  //���� 
            u8  temperatureState[16];//�������¶�״̬  0��Ӳ����֧��  1����  2����������  3��ͨѶ����
            s16 temperatureData[16]; //���������¶�ֵ   ��ֵ/10
}tempera;


int main(){
	while(1)
	{
		//���յ����ݺ�
		uart_rx(  );
		base64Decode(  ); //����

		if(state_system) //���ڳ���״̬��
		{
			recv_state = 0;
			recv_num = 0;

			if(recv_state == 0)  //���յ�֡ͷ����һ���ֽ�
			{
				if(recv_data == send_head)
				{
					recv_state ++; //1,��ȡ�ڶ���
					recv_num ++;
				}
				else
				{
					recv_len = 0; //��λ
				}
			}

			if(recv_state == 1)  //���յ�Դ��ַ���ڶ����ֽ�
			{
				if(recv_data == send_from)
				{
					recv_state ++; //2����ȡ������
					recv_num ++;
				}
				else
				{
					recv_state = 0; //��λ
				}
			}

			if(recv_state == 2)  //���յ�Ŀ�ĵ�ַ���������ֽ�
			{
				if(recv_data == send_to)
				{
					recv_state ++;//3,��ȡ���ĸ�
					recv_num ++;
				}
				else
				{
					recv_state = 0; //��λ
				}
			}

			if(recv_state == 3 || recv_state == 4)  //���յ����ȣ����ĸ��ֽ�
			{
				if(recv_data == send_len)
				{
					recv_len = send_len;
					recv_state ++;//3,��ȡ�����
					recv_num ++;
				}
				else
				{
					recv_state = 0; //��λ
				}
			}

			if(recv_state == 5)  //���յ�����type���������ֽ�
			{
				if(recv_data == send_type)
				{
					recv_len = send_len;
					recv_state ++;//3,��ȡ�����
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
					recv_state = 0; //��λ
				}
			}

			if(recv_state == 4)  //���յ����ݣ�1���ֽڣ���������ֽ�
			{
				if(recv_data == send_data)
				{
					recv_state ++;//4,��ȡ������
					recv_num ++;
				}
				else
				{
					recv_state = 0; //��λ
				}
			}

			if(recv_state == 5)  //���յ�֡β���������ֽ�
			{
                                    if(recv_data == send_end)
                                    {
                                               // recv_state ++;//
                                                recv_flag = 0xaa;//���յ�֡β���ñ�־λ�������ݰ���������
                                                recv_num ++;
                                    }
                                     else
                                    {
                                                recv_state = 0; //��λ
                                    }
                        }
            }
            
            else   //�ǳ���״̬��
            {
                        recv_data = 2; //δ��������ɼ�����
            }
}
}
