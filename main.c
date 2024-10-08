#include "main.h"

uint* const GPIOA_ODR = 0x40020014;
uint* const RCC_AHB1ENR = 0x40023830;
uint* const GPIOA_MODER = 0x48000000;


int main(void)
{
	*RCC_AHB1ENR |= (1<<5); 		// Enable Clock GPIOA 	(RCC->AHB1ENR)
	*GPIOA_MODER |= (1<<10);// PA5 Output			(GPIOA->MODER)

	while(1){
		for(uint32_t i = 0 ; i<100000; i++){
		*GPIOA_ODR ^= (1<<5);	// Toggle PA5		(GPIOA->ODR)	
		//delay(1000);
		}
	}
}


/*void delay(uint time)
{
	uint start = time();
	uint time_now = 0;
	

	while(time_now < time)
	{
		time_now = time();
		time_now = start - time_now; 
	}
}*/
