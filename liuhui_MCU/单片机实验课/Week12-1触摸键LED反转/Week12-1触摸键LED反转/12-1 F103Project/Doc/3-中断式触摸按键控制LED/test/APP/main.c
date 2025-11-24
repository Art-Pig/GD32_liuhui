#include "LED.h"
#include "KEY.h"
#include "DELAY.h"
#include "EXTI.h"

int main(){
	LED_Init();
	KEY_Init();
	EXTI_Init();
	
	while(1){
//		delay_ms(300);
		
		if(KEY_A_Pressed()){
			LED1_Toggle();
		}
	}
}
