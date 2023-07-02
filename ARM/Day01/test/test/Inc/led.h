#ifndef LED_H
#define LED_H

#include "LPC11xx.h"                    // Device header

void led_init(void);
void led_on(int n);
void led_off(int n);

#endif
