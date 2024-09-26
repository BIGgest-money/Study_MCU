
#include "lcd1602.h"
#include "Delay.h"
//延迟函数
//void Delay(unsigned int xms)		//@11.0592MHz
//{
//	unsigned char i, j;
//  while(xms--)
//	{
//		_nop_();
//		i = 2;
//		j = 199;
//		do
//		{
//			while (--j);
//		} while (--i);
//	}
//}






//lcd1602

void lcd1602_write_cmd(unsigned char bin)//写入函数 写命令
{
	P2_6=0;//写命令
	P2_5=0;//写入
	P2_7=0;//使能低电平 
	P0=bin;//准备数据 在是使能上升沿时开始存入数据 
	Delay(1);//延时1ms  要求是ns所以1ms时间足够
	P2_7=1;//下降沿时数据传入完成
	Delay(1);
  P2_7=0;
	
	
	
}	
void lcd1602_write_dat(unsigned char bin)//写入函数 写数据
{
	P2_6=1;//写数据
	P2_5=0;//写入
	P2_7=0;//使能低电平 
	P0=bin;//准备数据 在是使能上升沿时开始存入数据 
	Delay(1);//延时1ms  要求是ns所以1ms时间足够
	P2_7=1;//下降沿时数据传入完成
	Delay(1);
	P2_7=0;
}



void lcd1602_init(void)//初始化
{
	//功能设定指令
	lcd1602_write_cmd(0x38);//5*7点阵 显示2行 8位
	//显示开关控制指令
	lcd1602_write_cmd(0x0c);//显示开 无光标
	//进入模式设置
	lcd1602_write_cmd(0x06);//显示屏不移动 光标右移
	//清除数据
	lcd1602_write_cmd(0x01);//空白
	
	
}


void lcd1602_show_str(unsigned char x,unsigned char y,unsigned char*str)//设置坐标显示函数
{
	unsigned char i=0;
	//x:0-15  显示16个  x表示从第几个开始显示
	//y:0-1   两行
	if(x>16||y>1)return;
	if(y<1)//第一行
	{
		while(*str!='\0')
		{
			if(i<16-x)//一行只能显示16个
				lcd1602_write_cmd(0x80+x+i);//写入地址命令
			else
				lcd1602_write_cmd(0x80+0x40+i-16);
			lcd1602_write_dat(*str);//写入数据
			i++;
			str++;
		}
	}
		else  //第二行
		{
			while(*str!='\0')
		 {
			if(i<16-x)//一行只能显示16个
				lcd1602_write_cmd(0x80+0x40+x+i);//写入地址命令
			else
				lcd1602_write_cmd(0x80+i-16);
			lcd1602_write_dat(*str);
			i++;
			str++;
		 }
		}
			
	}
void lcd1602_clear(void)
{
	lcd1602_write_cmd(0x01);
}




