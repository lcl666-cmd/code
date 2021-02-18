//Timer0    22.1184MHZ

#include "Timer0.h"
#include "Uart_1.h"

#define	FOSC	22118400
#define	Timer_0_List_Count	20

struct 
{
	unsigned char Flag[Timer_0_List_Count];
	void (*Fun_Point_List[Timer_0_List_Count])(void);
	unsigned int Counter[Timer_0_List_Count];
	unsigned int Timer[Timer_0_List_Count];
}Timer0_Struct;
unsigned char Timer0_Handler_Flag=0;
//��ʼ����ʱ��0
void Timer0_Init(void)
{
	unsigned char i=0;
	
	for(i=0;i<Timer_0_List_Count;i++)
	{
		Timer0_Struct.Flag[i] = 0;
		Timer0_Struct.Counter[i] = 0;
	}
	
	AUXR |= 0x80;//��ʱ��ʱ��1Tģʽ
	TMOD &= 0xF0;//���ö�ʱ��ģʽ
  TL0 = 0x9A;//���ö�ʱ��ֵ
	TH0 = 0xA9;//���ö�ʱ��ֵ
	TF0 = 0;//���TF0��־
  TR0 = 1;//������ʱ��
  ET0 = 1;//ʹ�ܶ�ʱ���ж�
	
}
//ϵͳ��ʱ���ж�����ִ�еĺ���
void Timer0_SYS_APP_LOOP(void)
{
	unsigned char i=0;
	if(Timer0_Handler_Flag == 0)
		return;
	Timer0_Handler_Flag = 0;
	for(i=0;i<Timer_0_List_Count;i++)
	{
		if(Timer0_Struct.Flag[i])
		{
			Timer0_Struct.Counter[i] ++ ;
			if(Timer0_Struct.Counter[i] > Timer0_Struct.Timer[i])
			{
				Timer0_Struct.Counter[i] = 0;
				Timer0_Struct.Fun_Point_List[i]();
			}
		}
	}
}
//���һ����������ʱ����
unsigned char Timer_0_Add_Fun(unsigned int Time,void (*Fun)(void))
{
	unsigned char i=0;
	for(i=0;i<Timer_0_List_Count;i++)
	{
		if(Timer0_Struct.Flag[i] == 0)
		{
			Timer0_Struct.Flag[i] = 1;
			Timer0_Struct.Counter[i] = 0;
			Timer0_Struct.Fun_Point_List[i] = Fun;
			Timer0_Struct.Timer[i] = Time-1;
			return 1;
		}
	}
	return 0;
}
//IRQ4�����ӵ��˶�ʱ��0.
void Timer0_Interrupt(void) interrupt 1
{
	Timer0_Handler_Flag = 1;
}

//

//


