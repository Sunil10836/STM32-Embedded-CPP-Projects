/*
 * uart.hpp
 *
 *  Created on: Nov 23, 2025
 *      Author: Sunil Sutar
 */

#ifndef UART_HPP_
#define UART_HPP_

#include "stm32f446xx.h"
#include "gpio.hpp"

class UART : public GPIO
{
private:
	USART_RegDef_t* uart;
public:
	UART(USART_RegDef_t* uart, GPIO_RegDef_t* txPort, uint8_t txPin) : GPIO(txPort, txPin), uart(uart)
	{ }

	void UART2_Init();
	void UART2_GPIO_Pin_Config();
	void UART2_SendChar(char ch);
	void UART2_SendString(const char *str);
};

//UART Parameters
#define RCC_APB1ENR_USART2EN		17

//UART Registers bits
#define USART2_CR1_TE				(1U << 3)
#define USART2_CR1_RE				(1U << 2)
#define USART2_CR1_UE				(1U << 13)

#define USART2_SR_TXE				(1U << 7)
#define USART2_SR_RXNE				(1U << 5)

#define USART2_TX_PIN				GPIO_PIN_2
#define USART2_RX_PIN				GPIO_PIN_3
#define USART2_PORT					GPIOA

#endif /* UART_HPP_ */
