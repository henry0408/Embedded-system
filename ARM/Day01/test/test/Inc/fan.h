#ifndef FAN_H
#define FAN_H

#include "LPC11xx.h"
#include "gpio.h"

void fan_init(void);
void fan_on(void);
void fan_off(void);

#endif
