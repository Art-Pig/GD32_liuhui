#include "bsp_led.h"




/*配置GPIO输出*/
void led_gpio_config(void)
	
{

	/*开启GPIO端口C时钟*/
BSP_RCU_AHB2EN |= 0x00000010;	
	
//BSP_RCU_AHB2EN |=(1<<4);
//P133 GD32F10x User Manual
//RCU基地址+AHB2偏移地址所在寄存器第4位写1 PCEN	
	
	
/*配置GPIO 端口PC13输出模式与频率*/
BSP_GPIOC_CTL1 |= 0x00300000;
BSP_GPIOC_CTL1 &= 0xFF3FFFFF;
	
//P168 GD32F10x User Manual
/*配置GPIO PC13 0011(3)：GPIO output with push-pull推挽输出(00)，50MHz(11)*/
/*端口控制寄存器1 GPIOx_CTL1 x=A..G
地址偏移：0x04
复位值：0x4444 4444*/
	
	

/*配置GPIO PC13输出低电平(1101)*/
BSP_GPIOC_OCTL &= 0xDFFF;
	
//P170 GD32F10x User Manual
/*Address offset: 0x0C
Reset value: 0x0000 0000*/
//	输出控制寄存器 OCTL13=0（15-12位1101为D）
//BSP_GPIOC_BOP  &= 0x00000000;	
//BSP_GPIOC_BOP  |= 0x20000000;		
//	


///*开启GPIO端口A时钟 
//RCU基地址+AHB2偏移地址所在寄存器第2位写1 PAEN
//	//P133 GD32F10x User Manual
//*/
//BSP_RCU_AHB2EN |= 0x00000004;	
////BSP_RCU_AHB2EN |=(1<<2);
//	
//BSP_GPIOA_CTL0 |= 0x00000030;
//BSP_GPIOA_CTL0 &= 0xFFFFFF3F;
//////	/*配置GPIO PA0 (3) 0011：AFIO */
///*端口控制寄存器 0 GPIOx_CTL0 x=A..G
//地址偏移：0x00
//复位值：0x4444 4444*/
}

void led_gpio_unconfig(void)
	
{
/*打开GPIO端口时钟 
RCU基地址+AHB2偏移地址
*/
BSP_RCU_AHB2EN &= 0x00000010;	


/*配置GPIOC PC口模式0100(4): Floating input*/
BSP_GPIOC_CTL1 |= 0x44444444;
BSP_GPIOC_CTL1 &= 0x44444444;
	
//BSP_GPIOA_CTL0 |= 0x44444444;
//BSP_GPIOA_CTL0 &= 0x44444444;
/////*配置GPIO输出1*/	
//BSP_GPIOC_BOP  &= 0x0000000;	
//BSP_GPIOC_BOP  |= 0x00002000;	
//////	BSP_GPIOC_OCTL |= 0x02000000;
}
