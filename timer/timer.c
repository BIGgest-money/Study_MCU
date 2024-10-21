#include "regx52.h"
#include "delay.h"
sbit LED1=P2^0;
/*******************
*函数名  	：timer0_init
*函数功能	：定时器0中断配置函数，通过设置TH,TL即可确定定时时间 
*输入			：无
*输出			：无
********************/

void timer0_init()
{
	TMOD|=0x01;//选择为定时器0模式，工作方式1  低四位
	TH0=0xfc;//给定时器赋初值，定时1ms 高八位
	TL0=0x18;//低八位
	ET0=1;//打开定时器0中断允许
	EA=1;//打开总中断
	TR0=1;//打开定时器
	
	
}
void timer0() interrupt 1
	{
		static u16 i;//定义静态变量
		TH0=0xfc;//重新赋初始值
		TL0=0x18;
		i++;
		if(1000==i)
		{
			i=0;//将i清零
			LED1=!LED1;
			Delay_25us(800);
		}
		
	}