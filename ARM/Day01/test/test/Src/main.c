#include "main.h"


void SysTick_Handler(void)
{
	static int count = 0;
	count++;
	if(count == 500)
	{
		led_on(2);
	}
	else if(count == 1000)
	{
		led_off(2);
		count = 0;
	}
}


int main()
{
	uint8_t temp[2] = {0};
	uint8_t hum[2] = {0};
	char buf[40];
	
	SystemInit();
	SysTick_Config(48000);	//系统定时器
	
	//中断处理函数，定时时间一到，发送中断信号
	SPI_IOConfig(0);
	SPI_Init(0,8,2);
	OLED_Init_I();
	
	GPIOInit();
	led_init();
	fan_init();
	speaker_init();
	//speaker_set_rate(G2);
	
	OLED_DisStrLine(0, 0, "FAN ON ");

	speaker_on();
	fan_on();
	delay_ms(300);
	fan_off();
	speaker_off();
	delay_ms(40);
	OLED_DisStrLine(0, 0, "FAN OFF ");
	
	
	timer16_interrupt(5);
	while(1)
	{
		if( DHT11(temp,hum) )
		{
			sprintf(buf, "temp: %d.%d ℃ ", temp[0], temp[1]);
			OLED_DisStrLine(2, 0, (uint8_t *)buf);
			
			sprintf(buf, "hum: %d.%d ", hum[0], hum[1]);
			OLED_DisStrLine(3, 0, (uint8_t *)buf);
		}
		
		led_on(1);
		led_on(2);
		
		timer16_ms(1000);
		
		delay_ms(1000);
		led_off(1);
		led_off(2);
		
		delay_ms(1000);
	}
	
	return 0;
}
