#ifndef _LED_H
#define _LED_H

#include "gd32f10x.h"
#include <stdio.h>

#define LED1_PIN    GPIO_PIN_0
#define LED2_PIN    GPIO_PIN_1

void LED_Init(void);

void LED1_On(void);
void LED1_Off(void);
void LED1_Toggle(void);

void LED2_On(void);
void LED2_Off(void);
void LED2_Toggle(void);

#endif
