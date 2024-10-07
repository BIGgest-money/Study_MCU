#include "reg52.h"
#include "delay.h"

// Y引脚定义
sbit LCD_EN = P2^7;
sbit LCD_RS = P2^6;//写命令0/写数据1
sbit LCD_RW = P2^5;//读1/写0
#define LCD_Dataport P0

//写命令
void LCD_write_cmd(u8 cmd)
{
	LCD_RS=0;//写命令
	LCD_RW=0;//写入
	LCD_Dataport=cmd;
	LCD_EN=1;//上升沿使数据有效
	Delay_25us(40);//延时1ms
	LCD_EN=0;//下降沿存入数据完成
	Delay_25us(40);
	
	
}
//写数据
void LCD_write_data(u8 dat)
{
	LCD_RS=1;//写数据
	LCD_RW=0;//写入
	LCD_Dataport=dat;
	LCD_EN=1;//上升沿使数据有效
	Delay_25us(40);//延时1ms
	LCD_EN=0;//下降沿存入数据完成
	Delay_25us(40);
	
}

//初始化
void LCD_init(void)
{
	LCD_write_cmd(0x38);//5*8点阵
	LCD_write_cmd(0x0c);//屏开 无光标
	LCD_write_cmd(0x06);//屏不移 光标右移
	LCD_write_cmd(0x01);//清屏 空白
}
//光标位置
void LCD_setcursor(u8 line,u8 column) //行 列
{
	if(line==1)
		LCD_write_cmd(0x80|(column-1));//列-1>行的地址
	else
		LCD_write_cmd(0x80|(column-1)+0x40);
	
	
}
//显示字符
void LCD_showchar(u8 line,u8 column,u8 Char)
{
	LCD_setcursor(line,column);
	LCD_write_data(Char);
}

//显示字符串
void LCD_showstr(u8 line,u8 column,u8* str)
{
	u8 i;
	LCD_setcursor(line,column);
	for(i=0;str[i]!='\0';i++)//遍历字符串
	{
		LCD_write_data(str[i]);
	}
	
}
u16 pow(u16 x,u16 y)//x的y次方 
{
	u8 i=0;
	u16 result=1;
	for(i=0;i<y;i++)
	{
		result*=x;
		
	}
	return result;
}

//显示数字 十进制
void LCD_shownum(u8 line,u8 column,u16 num,u8 length)//行 列 传入的十进制数字 长度
{
	u8 i;
	LCD_setcursor(line,column);
	for(i=length;i>0;i--)
	{
		LCD_write_data('0'+num/pow(10,i-1)%10);
	}
}
//显示有符号数字 
void LCD_signalnum(u8 line,u8 column,int num,u8 length)
{
	u8 i;
	u16 num1=0;//为了防止int num溢出 int可表示范围：-32768~32767
	LCD_setcursor(line,column);
	if(num>='0')
	{
		LCD_write_data('+');
		num1=num;
		
	}
	else
	{
		LCD_write_data('-');
		num1=-num;
	}
	for(i=length;i>0;i--)
	{
		LCD_write_data('0'+num/pow(10,i-1)%10);
	}
}

//显示16进制
void LCD_ShowHexNum(u8 line,u8 column,u16 num,u8 length)
{
	u8 i,num1;
	
	LCD_setcursor(line,column);
	for(i=length;i>0;i--)
	{
		num1=num/pow(16,i-1)%16;
		if(num1<10)
		LCD_write_data(num1+'0');
		else
		LCD_write_data('A'+num1-10);
	}
}
//显示二进制
void LCD_ShowBinNum(u8 line,u8 column,u16 num,u8 length)
{
	u8 i;
	LCD_setcursor(line,column);
	for(i=length;i>0;i--)
	{
		LCD_write_data('0'+num/pow(2,i-1)%2);
	}
}


	
