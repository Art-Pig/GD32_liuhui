#include "EXTI.h"
#include "LED.h"

// 外部中断的初始化函数
void EXTI_Init(void){
	// 使能复用时钟
	rcu_periph_clock_enable(RCU_AF);
	
	// 使能中断，并设置中断优先级
	nvic_irq_enable(EXTI1_IRQn, 2U, 2U);
	nvic_irq_enable(EXTI2_IRQn, 2U, 2U);
	nvic_irq_enable(EXTI3_IRQn, 2U, 2U);
	
	// 初始化EXTI线，并设置中断触发方式
	exti_init(EXTI_1, EXTI_INTERRUPT, EXTI_TRIG_FALLING);
	exti_init(EXTI_2, EXTI_INTERRUPT, EXTI_TRIG_RISING);
	exti_init(EXTI_3, EXTI_INTERRUPT, EXTI_TRIG_BOTH);
	
	// 清除中断发生的标志
	exti_interrupt_flag_clear(EXTI_1);
	exti_interrupt_flag_clear(EXTI_2);
	exti_interrupt_flag_clear(EXTI_3);

	// 选择中断源
	gpio_exti_source_select(GPIO_PORT_SOURCE_GPIOA, GPIO_PIN_SOURCE_1);
	gpio_exti_source_select(GPIO_PORT_SOURCE_GPIOA, GPIO_PIN_SOURCE_2);
	gpio_exti_source_select(GPIO_PORT_SOURCE_GPIOA, GPIO_PIN_SOURCE_3);
}

// EXTI1（按键B）过来的中断的服务函数
void EXTI1_IRQHandler(void){
	LED1_Toggle();
	exti_interrupt_flag_clear(EXTI_1);
}

// EXTI2（按键C）过来的中断的服务函数
void EXTI2_IRQHandler(void){
	LED2_Toggle();
	exti_interrupt_flag_clear(EXTI_2);
}

// EXTI3（按键D）过来的中断的服务函数
void EXTI3_IRQHandler(void){
	LED2_Toggle();
	exti_interrupt_flag_clear(EXTI_3);
}
