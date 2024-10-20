/***
函数功能：外部中断初始化配置
***/
#include "reg52.h"
#include "delay.h"
sbit KEY3=P3^2;
sbit LED1=P2^0;

void exINT0_init()
{
	IT0=1;//下降沿触发
	EX0=1;//中断INT0使能
	EA=1;//总中断使能
	
}
/***
函数功能：中断函数
***/
void exINT0() interrupt 0
{
	Delay_25us(800);//延时20ms 按键消抖
	if(KEY3==0)//判断按键
	{
		LED1=!LED1;
		
	}
}