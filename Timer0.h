//Timer0 22.1184MHZ
#ifndef __TIMER0_H__
#define __TIMER0_H__
#include "STC8.h"

//��ʼ����ʱ��0
void Timer0_Init(void);
//ϵͳ��ʱ���ж�����ִ�еĺ���
void Timer0_SYS_APP_LOOP(void);
//���һ����������ʱ����
unsigned char Timer_0_Add_Fun(unsigned int Time,void (*Fun)(void));

#endif