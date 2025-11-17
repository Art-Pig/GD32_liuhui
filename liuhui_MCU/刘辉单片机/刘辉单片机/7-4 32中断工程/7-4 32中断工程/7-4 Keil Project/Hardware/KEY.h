#ifndef _KEY_H
#define _KEy_H

#include "gd32f10x.h"
#include <stdio.h>

#define KEY_A_PIN    GPIO_PIN_0
//#define KEY_B_PIN    GPIO_PIN_1

void KEY_Init(void);

bool KEY_A_Pressed(void);
//bool KEY_B_Pressed(void);

#endif
