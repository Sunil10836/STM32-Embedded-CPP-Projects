/*
 * gpio.hpp
 *
 *  Created on: Nov 23, 2025
 *      Author: Sunil Sutar
 */

#ifndef GPIO_HPP_
#define GPIO_HPP_

#include "stm32f446xx.h"

class GPIO
{
protected:
	GPIO_RegDef_t* port;
	uint8_t pin;
public:
	//Constructor
	GPIO(GPIO_RegDef_t* port, uint8_t pin) : port(port), pin(pin)
	{ }

	//Member Functions
	void GPIO_ClockEnable(GPIO_RegDef_t* port);
	void GPIO_ModeOutput(uint8_t pin);
	void GPIO_ModeInput(uint8_t pin);
	void GPIO_ModeAltFn(uint8_t pin, uint8_t altfn);
};

//Clock Enable Macros
#define RCC_AHB1ENR_GPIOAEN				0
#define RCC_AHB1ENR_GPIOBEN				1
#define RCC_AHB1ENR_GPIOCEN				2
#define RCC_AHB1ENR_GPIODEN				3
#define RCC_AHB1ENR_GPIOEEN				4
#define RCC_AHB1ENR_GPIOFEN				5
#define RCC_AHB1ENR_GPIOGEN				6
#define RCC_AHB1ENR_GPIOHEN				7

//Macros for GPIO Pins
#define GPIO_PIN_2						2
#define GPIO_PIN_3						3
#define GPIO_PIN_5						5
#define GPIO_PIN_13						13

//Alternate Function Macros
#define AF7				7

#endif /* GPIO_HPP_ */
