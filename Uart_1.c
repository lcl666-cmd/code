//测试串口0，与USB转串口直接连接   115200 22.1184MHZ
//作者网址：WWW.JIXIN.PRO
#include "Uart_1.h"
bit busy1=0;//COM1用到的发送忙标志
/*******中断程序，最短程序 示范 UART1******************************************/
void INT_Uart1(void) interrupt 4
{
	if(RI)//清空读中断标志位
	{
		RI = 0;
		SBUF = SBUF;//把接收到的数据直接发送出去
		if(SBUF == 0XFA)//收到 0XFA ，单片机复位到烧写区
			IAP_CONTR = 0x60;
	}
	if(TI)//清空发送中断标志位
	{
		TI = 0;
		busy1 = 0;
	}
}
// 描述: 串口初始化程序.
void Init_Uart1(void)
{
	SCON = 0x50;//
	AUXR |= 0x40;//定时器1，1T
	AUXR &= 0xFE;
	TMOD &= 0x0F;	
	TL1 = 0xD0;		//
	TH1 = 0XFF;//波特率设置		115200 22.1184MHZ
	ET1 = 0;
	TR1 = 1;
	ES = 1;//允许COM1串行口中断
	//PS = 1;//COM1最高优先级中断		
}
//COM1发送一个字节
void Send_Data1(unsigned char dat)
{
	busy1 = 1;//发送一个数据之前先让忙标志位为1
	SBUF = dat;//串口开始发送数据
	
	while(busy1);//等待一个数据发送完毕。在发送结束中断里面，清零了忙标志位
	busy1 = 1;
	
}
//COM1发送一个字符串
void Send_Str1(unsigned char *s)
{
	do
		Send_Data1(*s++);
	while(*s);
}
//延时函数  主函数中使用
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