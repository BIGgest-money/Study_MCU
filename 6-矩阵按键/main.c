#include <REGX52.H>

#include "MatrixKey.h"
#include "lcd1602.h"
//unsigned char SMG_A_DP_code[17]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};//共阴0-f

unsigned char key=0;
void main()
{
	lcd1602_init();//对lcd初始化
	lcd1602_show_str(0,0,"you deserve it!");
	while(1)
	{
		key=matrix_key();
		if(key)
		{
			
			lcd1602_show_str(1,1,"key");//第二行显示键值
		}
		
	}
}
