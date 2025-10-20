#include <stm32f103xb.h>

void delay_1s();

void main(){

	//enable clk for GPIOA
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;

	//set pin6 of GPIOA to output
	//max output speed 2mhz
	GPIOA->CRL &= ~((1 << 27) |(1 << 26) |(1 << 24));
	GPIOA->CRL |= (1 << 25);
	
	//enable clk for TIM4
	RCC->APB1ENR |= RCC_APB1ENR_TIM4EN;

	//prescaler value of 800
	TIM4->PSC = 800;

	//gives us a delay of 1 second
	TIM4->ARR = 10000;

	TIM4->CR1 &= ~(TIM_CR1_DIR | TIM_CR1_UDIS | TIM_CR1_URS);

	while(1){

		GPIOA->BSRR |= GPIO_BSRR_BS6;
		delay_1s();
		GPIOA->BSRR |= GPIO_BSRR_BR6_Msk;
		delay_1s();

	}
}

//1 second delay
void delay_1s(){

	TIM4->CR1 |= (TIM_CR1_CEN);
	while(!(TIM4->SR & TIM_SR_UIF))
		;


	TIM4->SR &= ~(TIM_SR_UIF);

}
