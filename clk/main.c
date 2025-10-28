#include <stm32f103xb.h>

//configure the sysclk to use the 72MHz
void clock_config(){

	//enable HSE
	RCC->CR |= RCC_CR_HSEON;

	while(!(RCC->CR & RCC_CR_HSERDY))
		;

	//set HSE as the PLL clk source
	RCC->CFGR |= RCC_CFGR_PLLSRC;

	//set PLL multiplication factor to 9(8MHz * 9 = 72MHz)
	RCC->CFGR |= ((1 << 18) | (1 << 19) | (1 << 20));
	RCC->CFGR &= ~(1 << 21);

	//set usb prescaler to 1.5(72MHz / 1.5 = 48MHz)
	RCC->CFGR |= RCC_CFGR_USBPRE;

	//set apb1 prescaler to 2(72MHz / 2 = 36MHz)
	RCC->CFGR |= (1 << 10);
	RCC->CFGR &= ~((1 << 9) | (1 << 8));

	//set flash latency to 2 wait states(as per the ref manual)
	FLASH->ACR |= (1 << 1);
	FLASH->ACR &= ~((1 << 0) | (1 << 1));

	//enable PLL
	RCC->CR |= RCC_CR_PLLON;

	while(!(RCC->CR & RCC_CR_PLLRDY))
		;

	//set PLL as the clk source
	RCC->CFGR |= (1 << 1);
	RCC->CFGR &= ~(1 << 0);

	while (!(RCC->CFGR & RCC_CFGR_SWS_PLL))
		;

}

void delay_1s();

void main(){

	clock_config();

	//enable clk for GPIOC
	RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;

	//set PINC 13(onboard LED) to output
	GPIOC->CRH |= (1 << 21);
	GPIOC->CRH &= ~((1 << 20) | (1 << 22) | (1 << 23));

	//enable clk for TIM4
	RCC->APB1ENR |= RCC_APB1ENR_TIM4EN;

	//TIM4 is on 72MHz sysclk
	TIM4->PSC = 2880;

	//gives us a delay of about 1sec
	TIM4->ARR = 25000;

	TIM4->CR1 &= ~(TIM_CR1_DIR | TIM_CR1_UDIS | TIM_CR1_URS);

	while(1){
		GPIOC->BSRR |= GPIO_BSRR_BS13;
		delay_1s();
		GPIOC->BSRR |= GPIO_BSRR_BR13;
		delay_1s();
	}


}


void delay_1s(){

	TIM4->CR1 |= TIM_CR1_CEN;

	while(!(TIM4->SR & TIM_SR_UIF))
		;

	TIM4->SR &= ~TIM_SR_UIF;

}
