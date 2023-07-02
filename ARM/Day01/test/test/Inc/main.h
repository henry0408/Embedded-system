#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include "LPC11xx.h"                    // Device header

#include "led.h"
#include "fan.h"

#include "gpio.h"

#include "ssp.h"
#include "oled2864.h"

#include "tools.h"

#include "speaker.h"

int DHT11(uint8_t *temp, uint8_t *hump);

#endif
