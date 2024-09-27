#include "reg52.h"
#include "matrix_key.h"
#define SMG_PORT P0//数码管端口宏定义
unsigned char SMG_A_DP_code[17]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};//共阴0-f
//用数组存储 0-f段码
void main()
{
	while(1)
	{
		unsigned char key=0;
		key=Matrix_Key();
		if(key!=0)//判断是否按键 如果不判断 循环太快导致看不到键值变化
		{
			SMG_PORT=SMG_A_DP_code[key-1];//得到的键值减一换算成数组下表对应0-f段码
		}
	}
}