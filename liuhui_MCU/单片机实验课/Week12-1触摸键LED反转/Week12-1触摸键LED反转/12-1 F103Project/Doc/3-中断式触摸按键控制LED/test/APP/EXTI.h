#ifndef _EXTI_H
#define _EXTI_H

#include "gd32f10x.h"
#include <stdio.h>


void EXTI_Init(void);

void EXTI1_IRQHandler(void);
void EXTI2_IRQHandler(void);
void EXTI3_IRQHandler(void);

#endif
