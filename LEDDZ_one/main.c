#include "reg52.h"
#include "hc595.h"
#define LEDDZ_COL_PORT P0 //对点阵列的端口P0宏定义
void main()
{
	LEDDZ_COL_PORT=0x7f;
	while(1)
	{
		hc595_write_data(0x80);
	}
}