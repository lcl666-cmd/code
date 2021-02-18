#include "AT30TS75A.h"
#include "IIC.h"
#include "Timer0.h"
#include "Uart_1.h"

//抽象一下IIC接口
#define	AT30_Start 			IIC_Start
#define	AT30_SendData 	IIC_SendData
#define	AT30_RecvACK 		IIC_RecvACK
#define	AT30_RecvData 	IIC_RecvData
#define	AT30_SendACK 		IIC_SendACK
#define	AT30_SendNAK 		IIC_SendNAK
#define	AT30_Stop 			IIC_Stop

//IIC地址  加上读信息
#define	IIC_Addr	0X91

//读取AT30TS75A
char Read_AT30TS75A(void)
{
	int Temperature=0;
	
	//Send_Data1(0x66);
	
	AT30_Start();
	AT30_SendData(IIC_Addr);
	AT30_RecvACK();
	Temperature = AT30_RecvData();
	Temperature <<= 8;
	AT30_SendACK();
	Temperature += AT30_RecvData();
	AT30_SendNAK();
	AT30_Stop();
	
	Temperature /= 128;
	
	//四舍五入
	if(Temperature % 2)
	{
		Temperature = Temperature / 2 + 1;
	}
	else
	{
		Temperature /= 2;
	}
	
	Send_Data1(Temperature);
	
	return Temperature;
	
}

//





