
#ifndef __IO_H__
#define __IO_H__

#include<STC15W.h>


#define LED1  P20
#define LED2  P21
#define LED3  P22
#define LED4  P23
#define Relay	P13
#define Key		P37


//��ʼ�����е�IO��Ϊ��ͨIO
void Init_IO(void);
//��ʱ����  ��������ʹ��
void Delay1ms(unsigned int a);	// 1ms 


#endif