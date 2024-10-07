//unsigned char SMG_A_DP_code[17]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};//共阴0-f
#include "delay.h"//延迟函数
#include "MatrixKey.h"
#include "regx52.h"

u8 matrix_key(void)
{
	
	//按列扫描
	u8 key_value=0;//按下的键值 
	
	P1=0xff;//给p1口高电平
	P1_3=0;//第一列按键
	if(P1_7==0)//判断第一列第一行按键
	{
		Delay_25us(800);//延迟20ms 按键消抖
		while(P1_7==0);//检测松手
		Delay_25us(800);//松手消抖
		key_value=1;
		
		
	}
	if(P1_6==0)//判断第一列第2行按键
	{
		Delay_25us(800);//延迟20ms 按键消抖
		while(P1_6==0);//检测松手
		Delay_25us(800);//松手消抖
		key_value=5;
		
	}
	if(P1_5==0)//判断第一列第3行按键
	{
		Delay_25us(800);//延迟20ms 按键消抖
		while(P1_5==0);//检测松手
		Delay_25us(800);//松手消抖
		key_value=9;
		
	}
	if(P1_4==0)//判断第一列第4行按键
	{
		Delay_25us(800);//延迟20ms 按键消抖
		while(P1_4==0);//检测松手
		Delay_25us(800);//松手消抖
		key_value=13;
		
	}
	
	
	P1=0xff;//给p1口高电平
	P1_2=0;//第2列按键
	if(P1_7==0)//判断第2列第1行按键
	{
		Delay_25us(800);//延迟20ms 按键消抖
		while(P1_7==0);//检测松手
		Delay_25us(800);//松手消抖
		key_value=2;
		
	}
	if(P1_6==0)//判断第2列第2行按键
	{
		Delay_25us(800);//延迟20ms 按键消抖
		while(P1_6==0);//检测松手
		Delay_25us(800);//松手消抖
		key_value=6;
		
	}
	if(P1_5==0)//判断第2列第3行按键
	{
		Delay_25us(800);//延迟20ms 按键消抖
		while(P1_5==0);//检测松手
		Delay_25us(800);//松手消抖
		key_value=10;
		
	}
	if(P1_4==0)//判断第2列第4行按键
	{
		Delay_25us(800);//延迟20ms 按键消抖
		while(P1_4==0);//检测松手
		Delay_25us(800);//松手消抖
		key_value=14;
		
	}
	
	
	
	P1=0xff;//给p1口高电平
	P1_1=0;//第3列按键
	if(P1_7==0)//判断第3列第1行按键
	{
		Delay_25us(800);//延迟20ms 按键消抖
		while(P1_7==0);//检测松手
		Delay_25us(800);//松手消抖
		key_value=3;
		
	}
	if(P1_6==0)//判断第3列第2行按键
	{
		Delay_25us(800);//延迟20ms 按键消抖
		while(P1_6==0);//检测松手
		Delay_25us(800);//松手消抖
		key_value=7;
		
	}
	if(P1_5==0)//判断第3列第3行按键
	{
		Delay_25us(800);//延迟20ms 按键消抖
		while(P1_5==0);//检测松手
		Delay_25us(800);//松手消抖
		key_value=11;
		
	}
	if(P1_4==0)//判断第3列第4行按键
	{
		Delay_25us(800);//延迟20ms 按键消抖
		while(P1_4==0);//检测松手
		Delay_25us(800);//松手消抖
		key_value=15;
		
	}
	
	
	P1=0xff;//给p1口高电平
	P1_0=0;//第3列按键
	if(P1_7==0)//判断第4列第1行按键
	{
		Delay_25us(800);//延迟20ms 按键消抖
		while(P1_7==0);//检测松手
		Delay_25us(800);//松手消抖
		key_value=4;
		
	}
	if(P1_6==0)//判断第4列第2行按键
	{
		Delay_25us(800);//延迟20ms 按键消抖
		while(P1_6==0);//检测松手
		Delay_25us(800);//松手消抖
		key_value=8;
		
	}
	if(P1_5==0)//判断第4列第3行按键
	{
		Delay_25us(800);//延迟20ms 按键消抖
		while(P1_5==0);//检测松手
		Delay_25us(800);//松手消抖
		key_value=12;
		
	}
	if(P1_4==0)//判断第4列第4行按键
	{
		Delay_25us(800);//延迟20ms 按键消抖
		while(P1_4==0);//检测松手
		Delay_25us(800);//松手消抖
		key_value=16;
		
	}
	
	return key_value;
	
	
	
}