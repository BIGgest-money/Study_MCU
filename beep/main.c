#include "regx52.h"
#include "delay.h"

sbit BEEP=P2^5;


/***
蜂鸣器响一段时间就关闭
***/
void main()
{
	u16 i=3000;//控制蜂鸣器响时间
	while(1)
	{
		while(i--)
		{
//			BEEP=!BEEP;//上电默认高电平 取非后 变低电平 一直循环就有长时间的脉冲存在
//			Delay_25us(20);//延时0.5ms 周期就是1ms  频率1khz
			BEEP=0;
			Delay_25us(5);
			BEEP=1;
			Delay_25us(35);//改变声音大小
			
		}
		i = 0;
		
	}
}