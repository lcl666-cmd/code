//内部时钟  22.1184MHZ  
#include "STC8.h"
#include "intrins.h"
#include "Uart_1.h"
#include "Timer0.h"
#include "IIC.h"
#include "ADC.h"
sbit  BEEF=P3^4;
sbit  LED= P3^5;
sbit  BT = P1^4;
sbit  YW = P4^4;
sbit  CO = P1^5;
sbit  key1=P1^6;
sbit  key2=P1^7;

void main(void)
{
	P0M1=0;P0M0=0;P1M1=0;P1M0=0;
	P2M1=0;P2M0=0;P3M1=0;P3M0=0;
	P4M1=0;P4M0=0;P5M1=0;P5M0=0;//上电初始化所有IO口为普通IO
	
	P2M1=0;P2M0=0XFF;
	
	
	Init_Uart1();//初始化串口1，115200bps
	Timer0_Init();//简单任务调度定时器初始化
	Init_IIC();
	EA = 1;//打开单片机全局中断
	wifi_protocol_init();
	
	
	while(1)
	{  
		wifi_uart_service();
		Timer0_SYS_APP_LOOP();//运行简单任务调度
		
		
	}
	
}