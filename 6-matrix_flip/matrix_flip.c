#include "delay.h"
#include "reg52.h"
#define matrix_port P1//使用宏定义矩阵按键控制口
/*******************************************************************************
 *	@brief	矩阵按键线翻转函数 使用线翻转扫描法，检测矩阵按键是否按下 ，按下返回对应键值
 *	@param	无
 *	@retval	key_value
*******************************************************************************/
unsigned char matrix_flip(void)
{
	
	static unsigned char key_value=0;
	//为了测试列而赋值
	matrix_port=0x0f;//所有行赋值为0 所有列赋值为1
	if(matrix_port!=0x0f)//判断是否按下
	{
		Delay_25us(800);//延时20ms 消抖
		if(matrix_port!=0x0f)
		{
			//测试列
			matrix_port=0x0f;//测试行时会对变量重新赋值，所以这里再次重新赋值
			switch(matrix_port)
			{
				case 0x07:key_value=1;break;//第一列
				case 0x0b:key_value=2;break;
				case 0x0d:key_value=3;break;
				case 0x0e:key_value=4;break;
			}
			//测试行
			matrix_port=0xf0;
			switch(matrix_port)
			{
				case 0x70:key_value=key_value;break;//第一行
				case 0xb0:key_value=key_value+4;break;
				case 0xd0:key_value=key_value+8;break;
				case 0xe0:key_value=key_value+12;break;
				
			}
			while(matrix_port!=0xf0);//检测松手
		}
		
	}
	return key_value;
}