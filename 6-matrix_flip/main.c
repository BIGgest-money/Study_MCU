#include "reg52.h"
#include "matrix_flip.h"
#define SMG_PORT P0//数码管端口宏定义
unsigned char SMG_A_DP_code[17]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};//共阴0-f 段码

void main()
{
	unsigned char key=0;//用来接收矩阵按键函数的返回值的变量
	while(1)
	{
		key=matrix_flip();
		if(key!=0)//判断按键是否按下
		SMG_PORT=SMG_A_DP_code[key-1];//键值1-16 数码管显示0-f 下标对应数码管所显示的数字段码 键值-1
	}
}