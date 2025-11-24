#include "LED.h"


void LED_Init(){
	rcu_periph_clock_enable(RCU_GPIOB);
	
	gpio_init(GPIOB, GPIO_MODE_OUT_PP, GPIO_OSPEED_50MHZ, LED1_PIN|LED2_PIN|LED0_PIN|LED9_PIN);
	gpio_bit_reset(GPIOB, LED1_PIN|LED2_PIN);
}

// 点亮LED1
void LED1_On(void){
	gpio_bit_set(GPIOB, LED1_PIN);
}

// 熄灭LED1
void LED1_Off(void){
	gpio_bit_reset(GPIOB, LED1_PIN);
}

// 反转LED1 点亮或熄灭的状态
void LED1_Toggle(void){
	gpio_bit_write(GPIOB, LED1_PIN, (bit_status)!gpio_output_bit_get(GPIOB,LED1_PIN));
}

void LED0_Toggle(void){
	gpio_bit_write(GPIOB, LED0_PIN, (bit_status)!gpio_output_bit_get(GPIOB,LED0_PIN));
}
// 点亮LED2
void LED2_On(void){
	gpio_bit_set(GPIOB, LED2_PIN);
}

// 熄灭LED2
void LED2_Off(void){
	gpio_bit_reset(GPIOB, LED2_PIN);
}

// 反转LED2 点亮或熄灭的状态
void LED2_Toggle(void){
	gpio_bit_write(GPIOB, LED2_PIN, (bit_status)!gpio_output_bit_get(GPIOB,LED2_PIN));
}
