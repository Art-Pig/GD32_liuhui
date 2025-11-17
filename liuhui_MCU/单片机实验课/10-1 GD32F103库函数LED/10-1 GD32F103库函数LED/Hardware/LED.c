#include "LED.h"

/*
功能：控制LED的GPIO口的初始化
*/
void LED_Init(){
	rcu_periph_clock_enable(RCU_GPIOB);		//使能GPIOB外设时钟
	
	gpio_init(GPIOB, GPIO_MODE_OUT_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_0 | GPIO_PIN_1|GPIO_PIN_9);
	gpio_bit_reset(GPIOB, GPIO_PIN_0 | GPIO_PIN_1);
	
	rcu_periph_clock_enable(RCU_GPIOC);		//使能GPIOC外设时钟
	gpio_init(GPIOC, GPIO_MODE_OUT_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_13);
	gpio_bit_reset(GPIOC, GPIO_PIN_13);
}

void LED_Open(unsigned char LED_Number){
	switch(LED_Number){
		
		case LED0:
			gpio_bit_set(GPIOC, GPIO_PIN_13);
			break;
		
		case LED1:
			gpio_bit_set(GPIOB, GPIO_PIN_0);
			break;
		case LED2:
			gpio_bit_set(GPIOB, GPIO_PIN_0);
		  break;
		case LED3:
			gpio_bit_set(GPIOB, GPIO_PIN_9);
		  break;
//		case LED2:
////			gpio_bit_set(GPIOB, GPIO_PIN_1);
//			gpio_bit_write(GPIOB, GPIO_PIN_1, SET);
//			break;
		default:
			break;
	}
}

void LED_Close(unsigned char LED_Number){
	switch(LED_Number){
		
		
			case LED0:
			gpio_bit_reset(GPIOC, GPIO_PIN_13);
			break;
			
		case LED1:
//			gpio_bit_reset(GPIOB, GPIO_PIN_0);
			gpio_bit_write(GPIOB, GPIO_PIN_0, RESET);
			break;
		case LED2:
			gpio_bit_reset(GPIOB, GPIO_PIN_0);
		  break;
		case LED3:
			gpio_bit_reset(GPIOB, GPIO_PIN_9);
		  break;		
		
//		case LED2:
//			gpio_bit_reset(GPIOB, GPIO_PIN_1);
//			break;
		default:
			break;
	}
}
