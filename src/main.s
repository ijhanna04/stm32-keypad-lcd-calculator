#include "stm32f4xx.h"  // Adjust as per your STM32 series

void delay_ms(uint32_t ms);

int main(void) {
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN; // Enable clock for GPIOA
    GPIOA->MODER |= (1 << 2); // Set PA1 as output

    while (1) {
        GPIOA->ODR |= (1 << 1); // Set PA1 high
        delay_ms(1000); // High for 1 second
        GPIOA->ODR &= ~(1 << 1); // Set PA1 low
        delay_ms(4000); // Low for 4 seconds
    }
}

void delay_ms(uint32_t ms) {
    for (uint32_t i = 0; i < ms * 4000; i++); // Rough delay (adjust for your clock speed)
}
