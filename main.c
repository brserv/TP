#include "main.h"

uint32* const GPIOA_ODR = 0x40020014;
uint32* const RCC_AHB1ENR = 0x40023830;
uint32* const GPIOA_MODER = 0x48000000;
int main(void)
{
	RCC->AHB1ENR |= (1<<5); 		// Enable Clock GPIOA 	(RCC->AHB1ENR)
	GPIOA->MODER |= (1<<10);// PA5 Output			(GPIOA->MODER)

	while(1){
		for(uint32_t i = 0 ; i<100000; i++);
		GPIOA_ODR ^= (1<<5);	// Toggle PA5		(GPIOA->ODR)	
		delay(1000);
	}
}
