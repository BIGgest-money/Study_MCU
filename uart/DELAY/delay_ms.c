#include "delay_ms.h"
/*******************************************************************************
 *	@brief	延时函数 当ms=1时，延时1ms
 *	@param	无符号整型 0-65535
 *	@retval	无
*******************************************************************************/
void delay_ms(u16 ms)
{
	u16 i,j;
	for(i=ms;i>0;i--)
	{
		for(j=110;j>0;j--);
		
	}
}