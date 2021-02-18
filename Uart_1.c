//���Դ���0����USBת����ֱ������   115200 22.1184MHZ
//������ַ��WWW.JIXIN.PRO
#include "Uart_1.h"
bit busy1=0;//COM1�õ��ķ���æ��־
/*******�жϳ�����̳��� ʾ�� UART1******************************************/
void INT_Uart1(void) interrupt 4
{
	if(RI)//��ն��жϱ�־λ
	{
		RI = 0;
		SBUF = SBUF;//�ѽ��յ�������ֱ�ӷ��ͳ�ȥ
		if(SBUF == 0XFA)//�յ� 0XFA ����Ƭ����λ����д��
			IAP_CONTR = 0x60;
	}
	if(TI)//��շ����жϱ�־λ
	{
		TI = 0;
		busy1 = 0;
	}
}
// ����: ���ڳ�ʼ������.
void Init_Uart1(void)
{
	SCON = 0x50;//
	AUXR |= 0x40;//��ʱ��1��1T
	AUXR &= 0xFE;
	TMOD &= 0x0F;	
	TL1 = 0xD0;		//
	TH1 = 0XFF;//����������		115200 22.1184MHZ
	ET1 = 0;
	TR1 = 1;
	ES = 1;//����COM1���п��ж�
	//PS = 1;//COM1������ȼ��ж�		
}
//COM1����һ���ֽ�
void Send_Data1(unsigned char dat)
{
	busy1 = 1;//����һ������֮ǰ����æ��־λΪ1
	SBUF = dat;//���ڿ�ʼ��������
	
	while(busy1);//�ȴ�һ�����ݷ�����ϡ��ڷ��ͽ����ж����棬������æ��־λ
	busy1 = 1;
	
}
//COM1����һ���ַ���
void Send_Str1(unsigned char *s)
{
	do
		Send_Data1(*s++);
	while(*s);
}
//��ʱ����  ��������ʹ��
void Delay1ms(unsigned int a)	// 1ms @30.000MHz
{
	unsigned char i, j;
	unsigned int b=0;
	for(b=0;b<a;b++)
	{
		i = 30;
		j = 43;
		do
		{
			while (--j);
		} while (--i);
	}
}