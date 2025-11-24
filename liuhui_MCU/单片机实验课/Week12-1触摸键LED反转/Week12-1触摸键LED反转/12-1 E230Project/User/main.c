#include "gd32e23x.h"
#include "systick.h"
#include <stdio.h>
#include "main.h"
#include "usart.h"


/* 定义key的引脚 */
#define BSP_KEY_RCU      	RCU_GPIOA
#define BSP_KEY_PORT    	GPIOA
#define BSP_KEY_PIN      	GPIO_PIN_1
#define BSP_KEY_EXTI_LINE   EXTI_1 			// 中断线
#define BSP_KEY_EXTI_IRQn   EXTI0_1_IRQn  	// 中断类型
#define BSP_KEY_EXTI_PORT_SOURCE   EXTI_SOURCE_GPIOA
#define BSP_KEY_EXTI_PIN_SOURCE    EXTI_SOURCE_PIN1


void led(void)
{
	rcu_periph_clock_enable(RCU_GPIOC);
	gpio_mode_set(GPIOC, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO_PIN_13);
	gpio_output_options_set(GPIOC, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_13);
	
	gpio_bit_reset(GPIOC, GPIO_PIN_13);
}


void EXTI0_1_IRQHandler(void)
{
	if(exti_interrupt_flag_get(BSP_KEY_EXTI_LINE) == SET)  // 中断标志位为1，按键按下            
	{                    
		if(gpio_input_bit_get(BSP_KEY_PORT,BSP_KEY_PIN) == SET) // 按键按下                    
		{                        
			/* 执行功能 */                        
			printf("key press!\r\n");                        
			gpio_bit_toggle(GPIOC, GPIO_PIN_13); // led电平状态翻转                    
		}
		else
		{                                                                                      
			// 按键释放                         
			printf("key release!\r\n");                    
		}    
		exti_interrupt_flag_clear(BSP_KEY_EXTI_LINE); // 清中断标志位            
	}
}



int main(void)
{
	systick_config();	//	初始化滴答定时器
	usart_init(); 		// 初始化串口0，波特率：115200
		
		/* 开启时钟 */
	rcu_periph_clock_enable(BSP_KEY_RCU);
	rcu_periph_clock_enable(RCU_CFGCMP);  // 系统配置时钟
	led();
		/* 配置为输入模式 下拉模式 */    
	gpio_mode_set(BSP_KEY_PORT, GPIO_MODE_INPUT, GPIO_PUPD_PULLDOWN, BSP_KEY_PIN);	// 按键默认状态是低电平，配置为下拉
	nvic_irq_enable(BSP_KEY_EXTI_IRQn, 1);    // 设置中断优先级
	
		/* 配置外部中断线的映射，将外部中断线与具体的 GPIO 引脚进行关联。 */
	syscfg_exti_line_config(BSP_KEY_EXTI_PORT_SOURCE, BSP_KEY_EXTI_PIN_SOURCE); 
		/* 初始化中断线配置为中断模式，上升沿和下降沿均触发。 */
	exti_init(BSP_KEY_EXTI_LINE, EXTI_INTERRUPT, EXTI_TRIG_BOTH);
	
		/* 使能中断 */
	exti_interrupt_enable(BSP_KEY_EXTI_LINE);
	
	while(1)
	{
	}
}
