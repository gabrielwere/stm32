#include <stm32f103xb.h>

//crude delay function
void delay(int ms){

	 while (ms-- > 0){
        volatile int x = 1000;

        while (x-- > 0)
            __asm("nop");
    }

}

void main(){

	//enable the clock for GPIOB
	RCC->APB2ENR |= (1 << 3);

	//set GPIOB to output
	//output peed to 2 MHz
	GPIOB->CRH &= ~((1 << 15) | (1 << 14) | (1 << 12));
	GPIOB->CRH |= (1 << 13);

	while(1){
		//turn pin 11 of GPIOB on and off
		//delay of ~1sec
		GPIOB->BSRR |= (1 << 11);
		delay(1000);
		GPIOB->BSRR |= (1 << 27);
		delay(1000);
	}

}
