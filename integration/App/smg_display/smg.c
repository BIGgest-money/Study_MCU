#include "smg.h"
u8 SMG_port_code[17]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};

void gsmg_display(u8 pos,u8 num[])
{
	u8 i=0;
	u8  pos_temp=pos;
	for(i=pos_temp;i<=8;i++)
	{
		switch(pos_temp)
		{
			
			case 1:HCC=1;HCB=1;HCA=1;break;
			case 2:HCC=1;HCB=1;HCA=0;break;
			case 3:HCC=1;HCB=0;HCA=1;break;
			case 4:HCC=1;HCB=0;HCA=0;break;
			case 5:HCC=0;HCB=1;HCA=1;break;
			case 6:HCC=0;HCB=1;HCA=0;break;
			case 7:HCC=0;HCB=0;HCA=1;break;
			case 8:HCC=0;HCB=0;HCA=0;break;
		}
		SMG_PORT=SMG_port_code[num[pos_temp-pos]];
		delay_10us(100);
		SMG_PORT=0x00;
	}
	
}
//void main()
//{
//	while(1)
//	{
//		gsmg_code (2,5);
//		gsmg_code (3,2);
//		gsmg_code (4,0);
//		gsmg_code (6,5);
//		gsmg_code (7,2);
//		gsmg_code (8,0);
//	}
//	
//}