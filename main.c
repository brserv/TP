#include <stdint.h>

int main(void)
{
	// Enable Clock GPIOA 	(RCC->AHB1ENR)
	// PA5 Output			(GPIOA->MODER)

	while(1){
		for(uint32_t i = 0 ; i<100000; i++);
		// Toggle PA5		(GPIOA->ODR)	
	}
}