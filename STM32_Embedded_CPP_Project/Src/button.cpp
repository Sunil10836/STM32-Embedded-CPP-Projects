/*
 * button.cpp
 *
 *  Created on: Nov 23, 2025
 *      Author: Sunil Sutar
 */

#include "button.hpp"

void Button::Button_Init()
{
	//Enable Clock for Port C
	GPIO::GPIO_ClockEnable(GPIOC);

	//Set Mode as Input
	GPIO::GPIO_ModeInput(BUTTON_PIN);

	 // Configure pull-up/pull-down : Select pull-up
	 port->PUPDR &= ~(3 << (pin * 2));		//Clear bits
	 port->PUPDR |= (1 << (pin * 2));		//Select pull-up
}

bool Button::isPressed()
{
	return (! (port->IDR & (1 << pin)));
}

