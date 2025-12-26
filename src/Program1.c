/*
 * STM32 Keypad Calculator
 *
 * Implements multi-digit arithmetic with operator precedence
 * using fixed-size arrays and deterministic control flow.
 *
 * Author: Ian Hanna
 */

#include "stm32l4xx.h"

void delay_ms(uint32_t ms);

int main(void) {
    // Enable GPIOA clock
    RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN;

    // Set PA1 as output (01)
    GPIOA->MODER &= ~(3 << (1 * 2)); // Clear mode bits for PA1
    GPIOA->MODER |= (1 << (1 * 2));  // Set PA1 to output mode (01)

    while (1) {
        GPIOA->ODR |= (1 << 1);   // Set PA1 high
        delay_ms(1000);           // High for 1 second
        GPIOA->ODR &= ~(1 << 1);  // Set PA1 low
        delay_ms(4000);           // Low for 4 seconds
    }
}

void delay_ms(uint32_t ms) {
    uint32_t i; // Declare the variable outside the loop
    for (i = 0; i < ms * 4000; i++) {
        __asm("NOP"); // Use a no-operation instruction to prevent optimization
    }
}
