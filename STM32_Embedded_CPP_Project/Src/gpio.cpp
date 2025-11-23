/*
 * gpio.cpp
 *
 *  Created on: Nov 23, 2025
 *      Author: Sunil Sutar
 */

#include "gpio.hpp"

void GPIO::GPIO_ClockEnable(GPIO_RegDef_t* port)
{
	if(port == GPIOA) (RCC->AHB1ENR |= (1 << RCC_AHB1ENR_GPIOAEN));
	else if(port == GPIOB) (RCC->AHB1ENR |= (1 << RCC_AHB1ENR_GPIOBEN));
	else if(port == GPIOC) (RCC->AHB1ENR |= (1 << RCC_AHB1ENR_GPIOCEN));
	else if(port == GPIOD) (RCC->AHB1ENR |= (1 << RCC_AHB1ENR_GPIODEN));
	else if(port == GPIOE) (RCC->AHB1ENR |= (1 << RCC_AHB1ENR_GPIOEEN));
	else if(port == GPIOF) (RCC->AHB1ENR |= (1 << RCC_AHB1ENR_GPIOFEN));
	else if(port == GPIOG) (RCC->AHB1ENR |= (1 << RCC_AHB1ENR_GPIOGEN));
	else if(port == GPIOH) (RCC->AHB1ENR |= (1 << RCC_AHB1ENR_GPIOHEN));
}

void GPIO::GPIO_ModeOutput(uint8_t pin)
{
	//Set Mode LED Mode as Ouput
	port->MODER &= ~(0x3 << (pin * 2));	//Clear Bits
	port->MODER |= (0x1 << (pin * 2));	//Set Mode as Output
}

void GPIO::GPIO_ModeInput(uint8_t pin)
{
	//Set Mode LED Mode as Ouput
	port->MODER &= ~(0x3 << (pin * 2));	//Set Mode as Input
}

void GPIO::GPIO_ModeAltFn(uint8_t pin, uint8_t altfn)
{
	//Set GPIO Mode as AF Mode
    port->MODER &= ~(3 << (pin * 2));
    port->MODER |=  (2 << (pin * 2));       // AF mode

    if (pin < 8)
    {
        port->AFR[0] &= ~(0xF << (pin * 4));			//Clear Bits
        port->AFR[0] |=  (altfn << (pin * 4));			//Set AFx to Pin Number
    }
    else
    {
        port->AFR[1] &= ~(0xF << ((pin - 8) * 4));		//Clear Bits
        port->AFR[1] |=  (altfn << ((pin - 8) * 4));	//Set AFx to Pin Number
    }
}
