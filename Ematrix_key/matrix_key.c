#include "reg52.h"
#include "delay.h"
//typedef unsigned char u8;
//typedef unsigned int u16;//对数据类型重定义
#define matrix_port P1//使用宏定义对
/***********
	*	@brief	矩阵键盘读取键值 行列式扫描 检测矩阵按键是否按下 按下返回对应键值
	*	@param	无
	*	@retval	key_value
************/ 
unsigned char Matrix_Key()
{
	unsigned char key_value=0;//变量用于存放返回键值的变量
	
	matrix_port=0xf7;//给第一列赋值0即P1_3=0，其余全为1
	if(matrix_port!=0xf7)//判断第一列是否有按键按下
	{
		Delay_25us(800);//延时20ms 按键消抖
		switch(matrix_port)//用第一列按键后的值来确认返回的键值
		{
			case 0x77:key_value=1;break;//P1_7=0此时按下的时第一列的第一行 S1 键值为1
			case 0xb7:key_value=5;break;
			case 0xd7:key_value=9;break;
			case 0xe7:key_value=13;break;
			
		}
		while(matrix_port!=0xf7);//检测松手
		Delay_25us(800);//延时20ms 松手消抖

	}
	
	matrix_port=0xfb;//给第二列赋值0其余全为1 即P1_2=0
	if(matrix_port!=0xfb)//判断第二列是否有按键按下
	{
		Delay_25us(800);//延时20ms 按键消抖
		switch(matrix_port)//用第一列按键后的值来确认返回的键值
		{
			case 0x7b:key_value=2;break;//P1_7=0此时按下的时第2列的第一行 S2 键值为2
			case 0xbb:key_value=6;break;
			case 0xdb:key_value=10;break;
			case 0xeb:key_value=14;break;
		}
	}
		while(matrix_port!=0xfb);//检测松手
		Delay_25us(800);//延时20ms 松手消抖
	
	
	matrix_port=0xfd;//给第3列赋值0其余全为1 即P1_1=0
	if(matrix_port!=0xfd)//判断第二列是否有按键按下
	{
		Delay_25us(800);//延时20ms 按键消抖
		switch(matrix_port)//用第一列按键后的值来确认返回的键值
		{
			case 0x7e:key_value=4;break;//P1_7=0此时按下的时第4列的第一行 S4键值为4
			case 0xbe:key_value=8;break;
			case 0xde:key_value=12;break;
			case 0xee:key_value=16;break;
		}
	}
		while(matrix_port!=0xfd);//检测松手
		Delay_25us(800);//延时20ms 松手消抖
	
	
		
	matrix_port=0xfe;//给第3列赋值0其余全为1 即P1_1=0
	if(matrix_port!=0xfe)//判断第二列是否有按键按下
	{
		Delay_25us(800);//延时20ms 按键消抖
		switch(matrix_port)//用第一列按键后的值来确认返回的键值
		{
			case 0x7e:key_value=4;break;//P1_7=0此时按下的时第4列的第一行 S4键值为4
			case 0xbe:key_value=8;break;
			case 0xde:key_value=12;break;
			case 0xee:key_value=16;break;
		}
	}
		while(matrix_port!=0xfe);//检测松手
		Delay_25us(800);//延时20ms 松手消抖
	
	
	return key_value;
	
}