#include "main.h"

#define GPIOA_ODR (*(volatile uint32_t *) 0x40020014)
#define RCC_AHB1ENR (*(volatile uint32_t *) 0x40023830)
#define GPIOA_MODER (*(volatile uint32_t *) 0x48000000)


int main(void)
{
	RCC_AHB1ENR |= (1<<0); 		// Enable Clock GPIOA 	(RCC->AHB1ENR)
	GPIOA_MODER &= ~(3<<(5*2));// PA5 Output			(GPIOA->MODER)
	GPIOA_MODER |= (1<<10);
	
	while(1){
		for(uint32_t i = 0 ; i<100000; i++){}
		GPIOA_ODR ^= (1<<5);	// Toggle PA5		(GPIOA->ODR)	
		//delay(1000);
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
