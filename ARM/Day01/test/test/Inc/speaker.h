#ifndef SPEAKER_H
#define SPEAKER_H

#include "LPC11xx.h"

// 定义低音音名（数值单位：Hz）  
#define C1 262 // c1
#define D1 294 // d1 
#define E1 330 // e1 
#define F1 349 // f1
#define G1 392 // g1 
#define A1 440 // a1  
#define B1 494 // b1 

// 定义中音音名
#define C2 523 // c2  
#define D2 587 // d2 
#define E2 659 // e2  
#define F2 698 // f2
#define G2 784 // g2  
#define A2 880 // a2  
#define B2 988 // b2 

// 定义高音音名 
#define C3 1047 // c3 
#define D3 1175 // d3 
#define E3 1319 // e3  
#define F3 1397 // f3  
#define G3 1568 // g3  
#define A3 1760 // a3  
#define B3 1976 // b3   

/* 全音符时长（单位：ms） */
#define T   3600

typedef struct 
{
	int note;  //音符
	int meter; //节拍 间隔时间
}music_t;

void timer16_ms(int ms);
void speaker_init(void);
void speaker_on(void);
void speaker_off(void);
void speaker_set_rate(int val);

void timer16_interrupt(int s);
void timer16_interrupt_start(void);
void TIMER16_1_IRQHandler(void);

#endif
