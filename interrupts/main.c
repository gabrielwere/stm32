#include <stm32f103xb.h>

#define TIM4_IRQ_POSITION 30
#define NVIC_ISER_ADDRESS 0xE000E100

//toggle LED but using timer interrupts(instead of polling)
void main(){

	//enable TIM4 clock
	RCC->APB1ENR |= RCC_APB1ENR_TIM4EN;

	//enable GPIOB clock
	RCC->APB2ENR |= RCC_APB2ENR_IOPBEN;

	//set PINB6 to output
	GPIOB->CRL &= ~((1 << 27) | (1 << 26) | (1 << 24));
	GPIOB->CRL |= (1 << 25);

	//enable interrupts for TIM4
	TIM4->DIER |= TIM_DIER_UIE;

	unsigned int *NVIC_ISER = (unsigned int *)NVIC_ISER_ADDRESS;
	NVIC_ISER[0] |= (1 << TIM4_IRQ_POSITION);

	TIM4->PSC = 400;

	//delay of 1 sec
	TIM4->ARR = 20000;

	TIM4->CR1 |= TIM_CR1_CEN;

	//simulate the CPU doing something else
	while(1)	
		;

}


void TIM4_IRQHandler(){

	TIM4->SR &= ~(1 << 0);
	GPIOB->ODR ^= (1 << 6);

}
