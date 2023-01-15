#include "stm32f10x.h"

void delay_f(int itteration){
	volatile int i,j; 
	for (i=0; i<itteration; i++){
		j++;
	}
}


int main(){
	// GPIO Clock for PORTC
	RCC ->APB2ENR |= (1<<4); 
	RCC ->APB2ENR |= (1<<2); 

	// Mode Reg
	GPIOC ->CRH |= ( (1<<20) | (1<<21) );
	// OSpeed Reg + OType Reg
	GPIOC ->CRH &= ~( (1<<22) | (1<<23) );
	
	GPIOA ->CRL |= ( (1<<0) | (1<<1) );
	GPIOA ->CRL &= ~( (1<<2) | (1<<3) );
	
  GPIOA ->CRL |= ( (1<<4) | (1<<5) );
	GPIOA ->CRL &= ~( (1<<6) | (1<<7) );
	
  GPIOA ->CRL |= ( (1<<8) | (1<<9) );
	GPIOA ->CRL &= ~( (1<<10) | (1<<11) );
	
	while(1){

		GPIOC ->BSRR |= (1<<13);
  	delay_f(500000);
		GPIOC ->BSRR |= (1<<(13+16));
		delay_f(500000);
		
for(int i=0; i<2; i++){		
		GPIOA ->BSRR |= (1<<0);
  	delay_f(500000);
		GPIOA ->BSRR |= (1<<(16));
		delay_f(500000);
		
		GPIOA ->BSRR |= (1<<1);
  	delay_f(500000);
		GPIOA ->BSRR |= (1<<(1+16));
		delay_f(500000);
		
		GPIOA ->BSRR |= (1<<2);
  	delay_f(500000);
		GPIOA ->BSRR |= (1<<(2+16));
		delay_f(500000);
}
		delay_f(15000000);
	}	
}



/*
#include "stm32f10x.h"
 
void delay(long cycles)
{
  while(cycles >0)
  cycles--; // Some stupid delay, it is not in milliseconds or microseconds, but rather in some 'wasted clock cycles'
}
 
void gpio_ports_enable(void)
{
  RCC->APB2ENR |= RCC_APB2ENR_IOPAEN |     RCC_APB2ENR_IOPBEN		|		RCC_APB2ENR_IOPCEN; //ports A & B clock enabled
  GPIOC->CRH = 0x44344444; //Pin C13 enable. If you don't like number 13, use pin C_1_P.M. LOL
}
 
int main(void)
{
 gpio_ports_enable();
 
 for(;;)  //main loop - read "forever", or you may use 'while(1)'
 {
   GPIOC->BSRR = GPIO_BSRR_BS13; 
   delay(100000);
   GPIOC->BSRR = GPIO_BSRR_BR13; 
   delay(1000000); 
 } 
}
*/

