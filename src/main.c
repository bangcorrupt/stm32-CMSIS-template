/* Minimal blink example for stm32f411ce using CMSIS */

#include <stm32f411xe.h>

void blink();
void delay(int d);

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


void blink() {
        
        int d = 0x100000;
        
        // Set GPIO_13
        GPIOC->BSRR = GPIO_BSRR_BS13;
        
        delay(d);
        
        // Clear GPIO_13
        GPIOC->BSRR = GPIO_BSRR_BR13;
        
        delay(d);
}

void delay(int d) {
    
    // Wait a while    
    for (int i = 0; i < d; i++) {
        __asm__("nop");
    }
}
