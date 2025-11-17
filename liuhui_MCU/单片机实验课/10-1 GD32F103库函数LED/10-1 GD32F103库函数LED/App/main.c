#include "LED.h"
#include "DELAY.h"
#include "systick.h"

int main(){
	LED_Init();
	systick_config();	
	while(1){
		LED_Open(LED2);
		LED_Close(LED3);
		delay_ms(5000);
		LED_Close(LED2);
		LED_Open(LED3);

		delay_1ms(5000);
	}
}
