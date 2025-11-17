#include "KEY.h"
#include "DELAY.h"

void KEY_Init(void){
	rcu_periph_clock_enable(RCU_GPIOA);
	
//	gpio_init(GPIOA, GPIO_MODE_IPU, GPIO_OSPEED_50MHZ, KEY_A_PIN|KEY_B_PIN);
	gpio_init(GPIOA, GPIO_MODE_IPU, GPIO_OSPEED_50MHZ, KEY_A_PIN);
}

/*
功能：判断按键A是否被按下（加了软件消抖）
返回：如果按下返回TRUE；否则返回FALSE
*/
bool KEY_A_Pressed(void){
	if(gpio_input_bit_get(GPIOA, KEY_A_PIN)==RESET){
		
		// 软件消抖
		delay_ms(15);
		if(gpio_input_bit_get(GPIOA, KEY_A_PIN)==RESET){
			while(gpio_input_bit_get(GPIOA, KEY_A_PIN)==RESET);
			return TRUE;
		}
	}
	
	return FALSE;
}

/*
功能：判断按键B是否被按下（没加软件消抖）
返回：如果按下返回TRUE；否则返回FALSE
*/
//bool KEY_B_Pressed(void){
//	if(gpio_input_bit_get(GPIOA, KEY_B_PIN)==RESET){
//		return TRUE;
//	}
//	return FALSE;
//}
