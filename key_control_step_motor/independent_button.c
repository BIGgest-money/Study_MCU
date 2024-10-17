#include "regx52.h"
#include "delay.h"
#include "independent_button.h"
/****
函数功能：实现独立按键 当按键按下返回键值
****/

sbit KEY1=P3^1;
sbit KEY2=P3^0;
sbit KEY3=P3^2;
sbit KEY4=P3^3;


u8 key_scan(u8 mode)
{
	static u8 key=1;
	if(mode)key=1;//单次扫描：按下键只扫描一次 mode=0 连续扫描: 按下键连续扫描直到松开键
	if(key=1&&(KEY1==0||KEY2==0||KEY3==0||KEY4==0))//同时判断按键
	{
		Delay_25us(800);//按键消抖
		key=0;
		if(KEY1==0)//再次判断按键 
			return KEY1_VALUE;//按键返回相应键值
    else if(KEY2==0)
			return KEY2_VALUE;
		else if(KEY3==0)
			return KEY3_VALUE;
		else if(KEY4==0)
			return KEY4_VALUE;
		
	}
	else //if (KEY1==1&&KEY2==1&&KEY3==1&&KEY4==1)//松手或者没有按键按下 或处于单次扫描模式
	{
		key=1;
	}
		return KEY_VALUELESS;
}
