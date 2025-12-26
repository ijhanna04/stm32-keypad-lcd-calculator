# STM32 Keypad + LCD Calculator (Bare-Metal C)

## Overview
A bare-metal calculator implemented on an STM32 microcontroller that accepts
keypad input and displays results on an LCD. The firmware supports multi-digit
arithmetic with operator precedence.

## Features
- Multi-digit input
- Operators: +, -, *, /
- Operator precedence (* and / before + and -)
- `#` evaluates expression, `*` clears/reset
- Deterministic, bare-metal execution (no RTOS)

## Hardware
- STM32 microcontroller
- Matrix keypad
- Character LCD

## Implementation Details
- Digits and operators are stored in separate arrays
- On evaluation, the expression is reduced in two passes:
  1. Multiplication and division
  2. Addition and subtraction
- No dynamic memory allocation
- GPIO accessed directly for keypad and LCD interfacing

## Repository Structure
- `src/` firmware source code
- `docs/` project report
- `media/` demo images

## Limitations
- No parentheses
- No floating-point support
- Designed for educational hardware constraints
