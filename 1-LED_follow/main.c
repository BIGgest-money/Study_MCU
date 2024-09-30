/***
 实现流水灯代码
***/

#include "reg52.h"
#include "delay.h"

#define LED_PORT P2 //定义led端口

void main()
{
	 u8 i,num;//i 控制循环次数 num 为了操作P2口  定义变量一定要放在最前面
	 LED_PORT=0X01;//给P2口赋值 1111 1110
	
	
	for(i=0;i<8;i++)// 八位 循环八次
	{
		num=LED_PORT++;//num接收P2取反后的值
		LED_PORT<<=1;//P2向左移一位
		Delay_25us(50000);
		
	}
}




