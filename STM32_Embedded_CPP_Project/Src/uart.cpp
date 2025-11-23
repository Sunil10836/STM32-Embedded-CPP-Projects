/*
 * uart.cpp
 *
 *  Created on: Nov 23, 2025
 *      Author: Sunil Sutar
 */

#include "uart.hpp"

void UART::UART2_GPIO_Pin_Config()
{
	//1. Enable Clock for GPIOA
	GPIO::GPIO_ClockEnable(GPIOA);

	//2. Set Mode to Alt Fun for GPIO Pin : PA2
	//2. Set PA2 Alt Fun Type to USART2_TX : AF7
	GPIO::GPIO_ModeAltFn(USART2_TX_PIN, AF7);

	//3. Set Mode to Alt Fun for GPIO Pin : PA3
	//Set PA3 Alt Fun Type to USART2_RX : AF7
	GPIO::GPIO_ModeAltFn(USART2_RX_PIN, AF7);

}

void UART::UART2_Init()
{
	/********** Configure USART GPIO Pins ***********/
	UART2_GPIO_Pin_Config();

	/********** Configure USART Module *************/
	//4. Enable Clock for USART2
	RCC->APB1ENR |= (1U << RCC_APB1ENR_USART2EN);

	//5. Configure UART Baudrate
	USART2->BRR |= 0x88;			//Baudrate = 112500 @ 16MHz
	//USART2->BRR |= 0x683;			//Baudrate = 9600 @ 16MHz

	//6. Configure the transfer direction
	USART2->CR1 |= USART2_CR1_TE;	//TE=1, TE: Transmitter enable

	//7. Enable UART Module
	USART2->CR1 |= USART2_CR1_UE;	//UE=1, UE: USART enable
}

void UART::UART2_SendChar(char ch)
{
	//1. Make sure UART Transmit Data Register Empty
	while( !(USART2->SR & (USART2_SR_TXE))){}

	//2. Write to UART Transmit Data Register
	USART2->DR = (ch & 0xFF);
}

void UART::UART2_SendString(const char *str)
{
	while(*str)
	{
		UART2_SendChar(*str++);
	}
}
