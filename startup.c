#include <stdint.h>

#define SRAM_START 0x20000000U
#define SRAM_SIZE (20U * 1024U)
#define SRAM_END ((SRAM_START) + (SRAM_SIZE))
#define STACK_START SRAM_END

int main();
void default_handler();
void reset_handler();

extern uint32_t _sbss;
extern uint32_t _ebss;
extern uint32_t _sdata;
extern uint32_t _edata;
extern uint32_t _la_data;

void NMI_Handler(void) __attribute__((weak, alias("default_handler")));
void HardFault_Handler(void) __attribute__((weak, alias("default_handler")));
void MemManage_Handler(void) __attribute__((weak, alias("default_handler")));
void BusFault_Handler(void) __attribute__((weak, alias("default_handler")));
void UsageFault_Handler(void) __attribute__((weak, alias("default_handler")));
void SVC_Handler(void) __attribute__((weak, alias("default_handler")));
void DebugMon_Handler(void) __attribute__((weak, alias("default_handler")));
void PendSV_Handler(void) __attribute__((weak, alias("default_handler")));
void SysTick_Handler(void) __attribute__((weak, alias("default_handler")));
void WWDG_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void PVD_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void TAMP_STAMP_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void RTC_WKUP_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void RCC_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void EXTI0_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void EXTI1_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void EXTI2_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void EXTI3_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void EXTI4_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void DMA1_Channel1_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void DMA1_Channel2_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void DMA1_Channel3_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void DMA1_Channel4_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void DMA1_Channel5_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void DMA1_Channel6_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void DMA1_Channel7_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void ADC_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void USB_HP_CAN_TX_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void USB_LP_CAN_RX0_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void CAN_RX1_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void CAN_SCE_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void EXTI9_5_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void TIM1_BRK_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void TIM1_UP_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void TIM1_TRG_COM_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void TIM1_CC_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void TIM2_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void TIM3_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void TIM4_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void I2C1_EV_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void I2C1_ER_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void I2C2_EV_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void I2C2_ER_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void SPI1_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void SPI2_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void USART1_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void USART2_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void USART3_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void EXTI15_10_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void RTC_Alarm_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void USB_Wakeup_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void TIM8_BRK_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void TIM8_UP_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void TIM8_TRG_COM_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void TIM8_CC_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void ADC3_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void FSMC_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void SDIO_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void TIM5_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void SPI3_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void UART4_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void UART5_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void TIM6_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void TIM7_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void DMA2_Channel1_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void DMA2_Channel2_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void DMA2_Channel3_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void DMA2_Channel4_5_IRQHandler(void) __attribute__((weak, alias("default_handler")));

//vector table
uint32_t vectors[] __attribute__((section(".isr_vector"))) = {
    STACK_START,
    (uint32_t)reset_handler,
    (uint32_t)NMI_Handler,
    (uint32_t)HardFault_Handler,
    (uint32_t)MemManage_Handler,
    (uint32_t)BusFault_Handler,
    (uint32_t)UsageFault_Handler,
    0, // reserved
    0, // reserved
    0, // reserved
    0, // reserved
    (uint32_t)SVC_Handler,
    (uint32_t)DebugMon_Handler,
    0, // reserved
    (uint32_t)PendSV_Handler,
    (uint32_t)SysTick_Handler,
    (uint32_t)WWDG_IRQHandler,
    (uint32_t)PVD_IRQHandler,
    (uint32_t)TAMP_STAMP_IRQHandler,
    (uint32_t)RTC_WKUP_IRQHandler,
    0, // Flash global interrupt
    (uint32_t)RCC_IRQHandler,
    (uint32_t)EXTI0_IRQHandler,
    (uint32_t)EXTI1_IRQHandler,
    (uint32_t)EXTI2_IRQHandler,
    (uint32_t)EXTI3_IRQHandler,
    (uint32_t)EXTI4_IRQHandler,
    (uint32_t)DMA1_Channel1_IRQHandler,
    (uint32_t)DMA1_Channel2_IRQHandler,
    (uint32_t)DMA1_Channel3_IRQHandler,
    (uint32_t)DMA1_Channel4_IRQHandler,
    (uint32_t)DMA1_Channel5_IRQHandler,
    (uint32_t)DMA1_Channel6_IRQHandler,
    (uint32_t)DMA1_Channel7_IRQHandler,
    (uint32_t)ADC_IRQHandler,
    (uint32_t)USB_HP_CAN_TX_IRQHandler,
    (uint32_t)USB_LP_CAN_RX0_IRQHandler,
    (uint32_t)CAN_RX1_IRQHandler,
    (uint32_t)CAN_SCE_IRQHandler,
    (uint32_t)EXTI9_5_IRQHandler,
    (uint32_t)TIM1_BRK_IRQHandler,
    (uint32_t)TIM1_UP_IRQHandler,
    (uint32_t)TIM1_TRG_COM_IRQHandler,
    (uint32_t)TIM1_CC_IRQHandler,
    (uint32_t)TIM2_IRQHandler,
    (uint32_t)TIM3_IRQHandler,
    (uint32_t)TIM4_IRQHandler,
    (uint32_t)I2C1_EV_IRQHandler,
    (uint32_t)I2C1_ER_IRQHandler,
    (uint32_t)I2C2_EV_IRQHandler,
    (uint32_t)I2C2_ER_IRQHandler,
    (uint32_t)SPI1_IRQHandler,
    (uint32_t)SPI2_IRQHandler,
    (uint32_t)USART1_IRQHandler,
    (uint32_t)USART2_IRQHandler,
    (uint32_t)USART3_IRQHandler,
    (uint32_t)EXTI15_10_IRQHandler,
    (uint32_t)RTC_Alarm_IRQHandler,
    (uint32_t)USB_Wakeup_IRQHandler,
    (uint32_t)TIM8_BRK_IRQHandler,
    (uint32_t)TIM8_UP_IRQHandler,
    (uint32_t)TIM8_TRG_COM_IRQHandler,
    (uint32_t)TIM8_CC_IRQHandler,
    (uint32_t)ADC3_IRQHandler,
    (uint32_t)FSMC_IRQHandler,
    (uint32_t)SDIO_IRQHandler,
    (uint32_t)TIM5_IRQHandler,
    (uint32_t)SPI3_IRQHandler,
    (uint32_t)UART4_IRQHandler,
    (uint32_t)UART5_IRQHandler,
    (uint32_t)TIM6_IRQHandler,
    (uint32_t)TIM7_IRQHandler,
    (uint32_t)DMA2_Channel1_IRQHandler,
    (uint32_t)DMA2_Channel2_IRQHandler,
    (uint32_t)DMA2_Channel3_IRQHandler,
    (uint32_t)DMA2_Channel4_5_IRQHandler,
};

void default_handler(){
	while(1)
		;
}


void reset_handler(){

	//copy data section from flashrom to sram
	uint32_t data_size = (uint32_t *)&_edata - (uint32_t *)&_sdata;
	uint8_t *rom = (uint8_t *)&_la_data;
	uint8_t *ram = (uint8_t *)&_sdata;

	for(uint32_t i = 0;i < data_size;i++)
		ram[i] = rom[i];

	//zero fill the bss section
	uint32_t bss_size = (uint32_t *)&_ebss - (uint32_t *)&_sbss;
	uint8_t *bss = (uint8_t*) &_sbss;

	for (uint32_t i = 0; i < bss_size; i++)
		bss[i] = 0;

	//invoke main
	main();

}
