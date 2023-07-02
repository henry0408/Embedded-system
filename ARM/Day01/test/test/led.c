#include "led.h"

//led初始化
void led_init()
{
	LPC_GPIO3->DIR = LPC_GPIO3->DIR | (1<<0);
	LPC_GPIO3->DATA = LPC_GPIO3->DATA | (1<<0);	//初始灯灭
	
	LPC_GPIO3->DIR = LPC_GPIO3->DIR | (1<<1);
	LPC_GPIO3->DATA = LPC_GPIO3->DATA | (1<<1);
}

//开灯
void led_on(int n)
{
	if(n == 1)
	{
		LPC_GPIO3->DATA = LPC_GPIO3->DATA & ~(1<<0);
	}
	else if(n == 2)
	{
		LPC_GPIO3->DATA = LPC_GPIO3->DATA & ~(1<<1);
	}
}

//关灯
void led_off(int n)
{
	if(n == 1)
	{
		LPC_GPIO3->DATA = LPC_GPIO3->DATA | (1<<0);
	}
	else if(n == 2)
	{
		LPC_GPIO3->DATA = LPC_GPIO3->DATA | (1<<1);
	}
}
