/*
 * led.hpp
 *
 *  Created on: Nov 23, 2025
 *      Author: Sunil Sutar
 */

#ifndef LED_HPP_
#define LED_HPP_

#include "gpio.hpp"

class LED : public GPIO
{
public:
	//Constructor
	LED(GPIO_RegDef_t* port, uint8_t pin) : GPIO(port, pin)
	{ }

	//Member Functions
	void LED_Init();
	void LED_ON();
	void LED_OFF();
	void LED_Toggle();
};

//Macros for LED
#define LED_PIN			GPIO_PIN_5
#define LED_PORT		GPIOA



#endif /* LED_HPP_ */
