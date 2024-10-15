#include "reg52.h"
#include "delay_ms.h"


sbit DC_motor=P1^0;
#define DC_MOTOR_RUN_TIME 6000

void main()
{
	DC_motor=1;
	delay_ms(DC_MOTOR_RUN_TIME);
	DC_motor=0;
	while(1)
	{
		
	}
}