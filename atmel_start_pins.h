/*
 * Code generated from Atmel Start.
 *
 * This file will be overwritten when reconfiguring your Atmel Start project.
 * Please copy examples or other code you want to keep to a separate file
 * to avoid losing it when reconfiguring.
 */
#ifndef ATMEL_START_PINS_H_INCLUDED
#define ATMEL_START_PINS_H_INCLUDED

#include <hal_gpio.h>

// SAMD20 has 8 pin functions

#define GPIO_PIN_FUNCTION_A 0
#define GPIO_PIN_FUNCTION_B 1
#define GPIO_PIN_FUNCTION_C 2
#define GPIO_PIN_FUNCTION_D 3
#define GPIO_PIN_FUNCTION_E 4
#define GPIO_PIN_FUNCTION_F 5
#define GPIO_PIN_FUNCTION_G 6
#define GPIO_PIN_FUNCTION_H 7

#define digit1_on GPIO(GPIO_PORTA, 23)
#define digit2_on GPIO(GPIO_PORTB, 23)
#define digit3_on GPIO(GPIO_PORTB, 22)
#define decimal_pt GPIO(GPIO_PORTA, 19)
#define sevseg1 GPIO(GPIO_PORTB, 16)
#define sevseg3 GPIO(GPIO_PORTA, 20)
#define sevseg4 GPIO(GPIO_PORTB, 17)
#define sevseg2 GPIO(GPIO_PORTA, 21)
#define button1 GPIO(GPIO_PORTA, 27)
#define button2 GPIO(GPIO_PORTB, 30)
#define mode_button GPIO(GPIO_PORTA, 13)
#define LED1 GPIO(GPIO_PORTA, 16)
#define LED2 GPIO(GPIO_PORTA, 17)
#define LED3 GPIO(GPIO_PORTA, 18)
#define sensor GPIO(GPIO_PORTA, 8)

#define LED0 GPIO(GPIO_PORTA, 14)
#define SW0 GPIO(GPIO_PORTA, 15)

#define PWMpos GPIO(GPIO_PORTA, 10)
#define PWMneg GPIO(GPIO_PORTA, 11)

#endif // ATMEL_START_PINS_H_INCLUDED
