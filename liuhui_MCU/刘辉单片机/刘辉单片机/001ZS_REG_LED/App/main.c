#include "bsp_led.h"
#include "gd32f10x.h"
//#include "gd32f103c_start.h"
#include "systick.h"

int main(){
systick_config();	
//	LED_Init();
	while(1){

		led_gpio_config();

//	delay_1ms(1000);
//	led_gpio_unconfig();

//	delay_1ms(1000);
	}
}
