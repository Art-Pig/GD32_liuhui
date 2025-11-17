#ifndef _bsp_led_h
#define _bsp_led_h

#include "systick.h"
#include "gd32f10x.h"

#define BSP_RCU_BASE (unsigned int) 0x40021000
//P118 GD32F10x User Manual
#define BSP_RCU_AHB2EN *(unsigned int*) (BSP_RCU_BASE + 0x18)
//P133 GD32F10x User Manual
#define BSP_GPIOC_BASE (unsigned int) 0x40011000
//P166  GD32F10x User Manual
#define BSP_GPIOC_CTL0 *(unsigned int*) (BSP_GPIOC_BASE + 0x00)
#define BSP_GPIOC_CTL1 *(unsigned int*) (BSP_GPIOC_BASE + 0x04)
//P168 GD32F10x User Manual
#define BSP_GPIOC_OCTL *(unsigned int*)(BSP_GPIOC_BASE + 0x0C)
//P170 GD32F10x User Manual
#define BSP_GPIOC_BOP *(unsigned int*) (BSP_GPIOC_BASE + 0x10)
//P171 GD32F10x User Manual


#define BSP_GPIOA_BASE (unsigned int) 0x40010800
//P166 GD32F10x User Manual
#define BSP_GPIOA_CTL0 *(unsigned int*) (BSP_GPIOA_BASE + 0x00)
#define BSP_GPIOA_CTL1 *(unsigned int*) (BSP_GPIOA_BASE + 0x04)
#define BSP_GPIOA_OCTL *(unsigned int*)(BSP_GPIOA_BASE + 0x0C)
#define BSP_GPIOA_BOP *(unsigned int*) (BSP_GPIOA_BASE + 0x10)

void led_gpio_config(void);
void led_gpio_unconfig(void);
#endif
