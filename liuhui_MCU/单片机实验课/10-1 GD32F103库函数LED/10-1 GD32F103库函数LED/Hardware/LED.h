#ifndef _LED_H
#define _LED_H

#include "gd32f10x.h"
#include <stdio.h>

#define LED0 0
#define LED1 1
#define LED2 2
#define LED3 3



void LED_Init(void);

void LED_Open(unsigned char LED_Number);
void LED_Close(unsigned char LED_Number);

#endif
