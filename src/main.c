/* Minimal blink example for stm32f411ce using CMSIS */

#include <stm32f411xe.h>

int blink();

int main() {
	// Enable GPIOC Clock
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;
	
    // GPIO_13 Output
    GPIOC->MODER |= GPIO_MODER_MODER13_0;       // Set first bit
    GPIOC->MODER &= ~(GPIO_MODER_MODER13_1);    // Clear second bit
	
    // GPIO_13 High speed
    GPIOC->OSPEEDR |= GPIO_OSPEEDR_OSPEED13;
     
    while(1) {
        blink();
    }
    
    return 0;
}


int blink() {
        
        int delay = 0x100000;
        
        // Set GPIO_13
        GPIOC->BSRR = GPIO_BSRR_BS13;
        
        // Wait a while    
        for (int i = 0; i < delay; i++) {
            __asm__("nop");
        }
        
        // Clear GPIO_13
        GPIOC->BSRR = GPIO_BSRR_BR13;
        
        // Wait a while
        for (int i = 0; i < delay; i++) {
            __asm__("nop");
        }
        
        return 0;
}
