#include<IO.h>

//��ʼ�����е�IO��Ϊ��ͨIO
void Init_IO(void)
{
	P0M1=0;P0M0=0;P1M1=0;P1M0=0;
	P2M1=0;P2M0=0;P3M1=0;P3M0=0;
	P4M1=0;P4M0=0;P5M1=0;P5M0=0;//�ϵ��ʼ������IO��Ϊ��ͨIO
	
	LED1 = 0;LED2 = 0;LED3 = 0;
	LED4 = 0;Relay = 0;Key = 1;//�����˿���Ϊֻ���ģ���Ҫ����д��1.
	
}
//��ʱ����  ��������ʹ��
void Delay1ms(unsigned int a)	// 1ms @30.000MHz
{
	unsigned char i, j;
	unsigned int b=0;
	for(b=0;b<a;b++)
	{
		i = 29;
		j = 183;
		do
		{
			while (--j);
		}while (--i);
	}
}
//




