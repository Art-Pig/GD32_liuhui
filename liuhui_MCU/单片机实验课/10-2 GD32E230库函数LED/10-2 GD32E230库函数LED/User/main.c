#include "gd32e23x.h"
#include "systick.h"
#include <stdio.h>
#include "main.h"


int main(void)
{
	systick_config();	//	初始化滴答定时器
	
	rcu_periph_clock_enable(RCU_GPIOC);
	
	gpio_mode_set(GPIOC, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO_PIN_13);
	
	gpio_output_options_set(GPIOC, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_13);
	
	gpio_bit_set(GPIOC, GPIO_PIN_13);
	
	//组2成员学号尾数09，点亮PB0，PB9，首先初始化
	gpio_mode_set(GPIOB, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO_PIN_0|GPIO_PIN_9);

	
	while(1)
	{
		
		delay_1ms(5000);
		//gpio_bit_set(GPIOC, GPIO_PIN_13);
		gpio_bit_set(GPIOB, GPIO_PIN_0);//高电平
		delay_1ms(5000);
		//gpio_bit_reset(GPIOC, GPIO_PIN_13);
		gpio_bit_set(GPIOB, GPIO_PIN_9);//低电平		
	}
}
