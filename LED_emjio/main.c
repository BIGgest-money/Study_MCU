#include "reg52.h"
#include "delay.h"
#include "hc595.h"
#define col_port P0
u8 row[]={0x00,0x18,0xA4,0x7C,0x24,0x7C,0xA4,0x18};
u8 col[]={0x7f,0xbf,0xdf,0xef,0xf7,0xfb,0xfd,0xfe};


void main()
{
	u8 i=0;
	while(1)
	{
		for(i=0;i<8;i++)
		{
			
			col_port=col[i];
			hc595_write_data(row[i]);
			delay(10);
			hc595_write_data(0x00);
			
		}
	}
	
}