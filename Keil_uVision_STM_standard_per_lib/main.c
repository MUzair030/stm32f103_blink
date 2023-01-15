#include "GPIO_STM32F10x.h"

void temp_delay(uint32_t time);

int main(){
	
	GPIO_PortClock(GPIOB, true);
	GPIO_PinConfigure(GPIOB, 13, GPIO_OUT_PUSH_PULL, GPIO_MODE_OUT2MHZ);	
	
	while(1){
		GPIO_PinWrite (GPIOB, 13, 0);
		temp_delay(10000);
		GPIO_PinWrite (GPIOB, 13, 1);
		temp_delay(10000);
	}
	
}

void temp_delay(uint32_t time){
	while(time > 0){
		time--;
	}
}
