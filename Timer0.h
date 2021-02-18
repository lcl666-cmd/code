//Timer0 22.1184MHZ
#ifndef __TIMER0_H__
#define __TIMER0_H__
#include "STC8.h"

//初始化定时器0
void Timer0_Init(void);
//系统定时器中断里面执行的函数
void Timer0_SYS_APP_LOOP(void);
//添加一个函数到定时器中
unsigned char Timer_0_Add_Fun(unsigned int Time,void (*Fun)(void));

#endif