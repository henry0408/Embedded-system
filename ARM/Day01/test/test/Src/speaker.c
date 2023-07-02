#include "speaker.h"

//自定义中断函数
void timer16_interrupt(int s)
{
	LPC_SYSCON->SYSAHBCLKCTRL |= 1<<8;
	
	NVIC_EnableIRQ( TIMER_16_1_IRQn );
	
	LPC_TMR16B1->PR = SystemFrequency/1000 - 1;
	LPC_TMR16B1->MR0 = 1000*s;
	LPC_TMR16B1->MCR |= 1<<0 | 1<<2;
	
	NVIC_SetPriority( TIMER_16_1_IRQn, 2 );
	
	LPC_TMR16B1->TCR |= 1<<1;
	LPC_TMR16B1->TCR &= ~(1<<1);
	
	LPC_TMR16B1->TCR = 1;
}

void timer16_interrupt_start(void)
{
	LPC_TMR16B1->TCR |= 1<<1;
	LPC_TMR16B1->TCR &= ~(1<<1);
	
	LPC_TMR16B1->TCR = 1;
}

void TIMER16_1_IRQHandler(void)
{
	if(LPC_TMR16B1->IR & 1)
	{
		LPC_TMR16B1->IR |= 1;
	}
	speaker_on();
	timer16_ms(500);
	speaker_off();
}

//自定义毫秒延时函数：ms为多少毫秒
void timer16_ms(int ms)
{
	LPC_SYSCON->SYSAHBCLKCTRL |= 1<<7;
	LPC_TMR16B0->PR = SystemFrequency/1000-1;
	LPC_TMR16B0->MR0 = ms;
	LPC_TMR16B0->MCR |= 1<<2;
	LPC_TMR16B0->TCR |= 1<<1;
	LPC_TMR16B0->TCR &= ~(1<<1);
	
	LPC_TMR16B0->TCR = 1;
	while( LPC_TMR16B0->TCR & 1 );
}

void speaker_init(void)
{
	LPC_SYSCON->SYSAHBCLKCTRL |= 1<<10;
	LPC_IOCON->R_PIO1_1 &= ~7;
	LPC_IOCON->R_PIO1_1 |= 3;
	
	LPC_TMR32B1->PR = 99;
	LPC_TMR32B1->MR0 = 750;
	LPC_TMR32B1->MR1 = 1500;
	LPC_TMR32B1->PWMC |= 1<<0;
	LPC_TMR32B1->MCR |= 1<<4;
}

void speaker_on(void)
{
	LPC_TMR32B1->TCR = 1;
}

void speaker_off(void)
{
	LPC_TMR32B1->TCR = 0;
}

void speaker_set_rate(int val)
{
	LPC_TMR32B1->MR1 = 48000000/(LPC_TMR32B1->PR+1)/val;
	LPC_TMR32B1->MR0 = LPC_TMR32B1->MR1/2;
	
	LPC_TMR32B1->TCR |= 1<<1;
	LPC_TMR32B1->TCR = 0;
}

