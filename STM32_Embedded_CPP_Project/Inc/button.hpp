/*
 * button.hpp
 *
 *  Created on: Nov 23, 2025
 *      Author: Sunil Sutar
 */

#ifndef BUTTON_HPP_
#define BUTTON_HPP_

#include "gpio.hpp"

class Button : public GPIO
{
public:
	//Constructor
	Button(GPIO_RegDef_t* port, uint8_t pin) : GPIO(port, pin)
	{}

	//Member Functions
	void Button_Init();
	bool isPressed();
	bool isReleased();
};

//Macros for Button
#define BUTTON_PIN		GPIO_PIN_13
#define BUTTON_PORT		GPIOC



#endif /* BUTTON_HPP_ */
