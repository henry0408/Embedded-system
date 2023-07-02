
#include "fan.h"
	
void fan_init(void)
{
	GPIOSetDir(PORT0, 2, 1);	//�ȼ���1<<2
	GPIOSetValue(PORT0, 2, 1);
}

void fan_on(void)
{
	GPIOSetDir(PORT0, 2, 0);	//�ȼ���1<<2
}

void fan_off(void)
{
	GPIOSetValue(PORT0, 2, 1);
}
