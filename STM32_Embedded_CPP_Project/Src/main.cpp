/*
 * main.cpp
 *
 *  Created on: Nov 23, 2025
 *      Author: Sunil Sutar
 */

#include "led.hpp"
#include "button.hpp"
#include "uart.hpp"

void delay();

int main()
{
	//Creating Object or Instance of class
	LED led(LED_PORT, LED_PIN);
	Button button(BUTTON_PORT, BUTTON_PIN);
	UART uart(USART2, USART2_PORT, USART2_TX_PIN);

	//Initialization
	led.LED_Init();
	button.Button_Init();
	uart.UART2_Init();

	uart.UART2_SendString("STM32 UART Embedded CPP Demo\n\r");

	while(1)
	{
		if(button.isPressed())
		{
			led.LED_ON();
			uart.UART2_SendString("LED Turned ON\n\r");
			delay();
		}
		else
		{
			led.LED_OFF();
			uart.UART2_SendString("LED Turned OFF\n\r");
			delay();
		}
	}
}

void delay()
{
	for(int i=0; i<500000; i++);
}
