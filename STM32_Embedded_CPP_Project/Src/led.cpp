/*
 * led.cpp
 *
 *  Created on: Nov 23, 2025
 *      Author: Sunil Sutar
 */

#include "led.hpp"

void LED::LED_Init()
{
	//Enable GPIOA Clock
	GPIO::GPIO_ClockEnable(GPIOA);

	//Set Mode as Output
	GPIO::GPIO_ModeOutput(LED_PIN);
}

void LED::LED_ON()
{
	port->ODR |= (1 << pin);
}

void LED::LED_OFF()
{
	port->ODR &= ~(1 << pin);
}

void LED::LED_Toggle()
{
	port->ODR ^= (1 << pin);
}


