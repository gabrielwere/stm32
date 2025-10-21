#include <stm32f103xb.h>

void usart_transmit(char letter);

void main(){

	//enable clk for USART1
	RCC->APB2ENR |= RCC_APB2ENR_USART1EN;

	//enable usart,transmitter mode
	USART1->CR1 |= (USART_CR1_UE | USART_CR1_TE);

	//no parity,8 data bit
	USART1->CR1 &= ~(USART_CR1_M | USART_CR1_PCE);

	//1 stop bit
	USART1->CR2 &= ~(USART_CR2_STOP);

	//set baud rate to 9600
	USART1->BRR = 52.0833;

	char word[] = "hello";
	int i = 0;

	while(word[i] != '\0'){
		usart_transmit(word[i]);
		i++;
	}

}


void usart_transmit(char letter){

	USART1->DR = letter;

	while(!(USART1->SR & USART_SR_TXE))
		;

}
