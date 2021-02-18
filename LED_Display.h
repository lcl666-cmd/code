//8-Segment-Display 8端数码管模块 显示数字
#ifndef __LED_Display_H__
#define __LED_Display_H__

#include<STC8.h>

void Show_Display(unsigned char *Num);

void Show_Num_Loop(void);

void Set_Num(int Num);

#endif







