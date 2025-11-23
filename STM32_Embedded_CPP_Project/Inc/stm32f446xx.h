/*
 * stm32f466xx.h
 *
 *  Created on: Nov 23, 2025
 *      Author: Sunil Sutar
 */

#ifndef INC_STM32F446XX_H_
#define INC_STM32F446XX_H_

#include <stdint.h>

#define __vo 	volatile

/**************	START : ARM Cortex Mx Processor Specific Details ***********************/

/*
 * ARM Cortex Mx Processor NVIC_ISERx Register Addresses
 */
#define NVIC_ISER0			((__vo uint32_t *) 0xE000E100)
#define NVIC_ISER1			((__vo uint32_t *) 0xE000E104)
#define NVIC_ISER2			((__vo uint32_t *) 0xE000E108)
#define NVIC_ISER3			((__vo uint32_t *) 0xE000E10C)

/*
 * ARM Cortex Mx Processor NVIC_ICERx Register Addresses
 */

#define NVIC_ICER0			((__vo uint32_t *) 0XE000E180)
#define NVIC_ICER1			((__vo uint32_t *) 0XE000E184)
#define NVIC_ICER2			((__vo uint32_t *) 0XE000E188)
#define NVIC_ICER3			((__vo uint32_t *) 0XE000E18C)

#define NVIC_PR_BASEADDR	((__vo uint32_t *) 0xE000E400)

#define NO_PR_BITS_IMPLEMENTED		4


/**************	END : ARM Cortex Mx Processor Specific Details ***********************/


/*
 *	Base addresses of Flash and SRAM Memories
 */
#define FLASH_BASEADDR			0x08000000U
#define SRAM1_BASEADDR			0x20000000U			//112KB
#define SRAM					SRAM1_BASEADDR

#define SRAM2_BASEADDR			0x20001C00U
#define ROM_BASEADDR			0x1FFF0000U


/*
 * The base addresses of various bus domains such as (AHBx domain, APBx domain)
 */
#define PERIPH_BASEADDR 		0x40000000U
#define APB1PERIPH_BASEADDR		PERIPH_BASEADDR
#define APB2PERIPH_BASEADDR		0x40010000U
#define AHB1PERIPH_BASEADDR		0x40020000U
#define AHB2PERIPH_BASEADDR		0x50000000U


/*
 * Base addresses of AHB1 Bus Peripherals
 */
#define GPIOA_BASEADDR			(AHB1PERIPH_BASEADDR + 0x0000)
#define GPIOB_BASEADDR			(AHB1PERIPH_BASEADDR + 0x0400)
#define GPIOC_BASEADDR			(AHB1PERIPH_BASEADDR + 0x0800)
#define GPIOD_BASEADDR			(AHB1PERIPH_BASEADDR + 0x0C00)
#define GPIOE_BASEADDR			(AHB1PERIPH_BASEADDR + 0x1000)
#define GPIOF_BASEADDR			(AHB1PERIPH_BASEADDR + 0x1400)
#define GPIOG_BASEADDR			(AHB1PERIPH_BASEADDR + 0x1800)
#define GPIOH_BASEADDR			(AHB1PERIPH_BASEADDR + 0x1C00)


/*
 * Base addresses of APB1 Bus Peripherals
 */
#define I2C1_BASEADDR			(APB1PERIPH_BASEADDR + 0x5400)
#define I2C2_BASEADDR			(APB1PERIPH_BASEADDR + 0x5800)
#define I2C3_BASEADDR			(APB1PERIPH_BASEADDR + 0x5C00)

#define SPI2_BASEADDR			(APB1PERIPH_BASEADDR + 0x3800)
#define SPI3_BASEADDR			(APB1PERIPH_BASEADDR + 0x3C00)

#define USART2_BASEADDR			(APB1PERIPH_BASEADDR + 0x4400)
#define USART3_BASEADDR			(APB1PERIPH_BASEADDR + 0x4800)
#define UART4_BASEADDR			(APB1PERIPH_BASEADDR + 0x4C00)
#define UART5_BASEADDR			(APB1PERIPH_BASEADDR + 0x5000)


/*
 * Base addresses of APB2 Bus Peripherals
 */
#define SPI1_BASEADDR			(APB2PERIPH_BASEADDR + 0x3000)
#define SPI4_BASEADDR			(APB2PERIPH_BASEADDR + 0x3400)

#define USART1_BASEADDR			(APB2PERIPH_BASEADDR + 0x1000)
#define USART6_BASEADDR			(APB2PERIPH_BASEADDR + 0x1400)

#define SYSCFG_BASEADDR			(APB2PERIPH_BASEADDR + 0x3800)
#define EXTI_BASEADDR			(APB2PERIPH_BASEADDR + 0x3C00)

#define RCC_BASEADDR			(AHB1PERIPH_BASEADDR + 0x3800)


/****************** Peripheral Register Definition Structures *********************/
/*
 * Peripheral Register Definition structure for GPIO
 */
typedef struct
{
	__vo uint32_t MODER;		/*!< GPIO Mode Register, Address Offset = 0x00 */
	__vo uint32_t OTYPER;
	__vo uint32_t OSPEEDR;
	__vo uint32_t PUPDR;
	__vo uint32_t IDR;
	__vo uint32_t ODR;
	__vo uint32_t BSRR;
	__vo uint32_t LCKR;
	__vo uint32_t AFR[2];
}GPIO_RegDef_t;

/*
 * Peripheral Register Definition structure for RCC
 */
typedef struct
{
	__vo uint32_t CR;			/*!<    Address Offset = 0x00 */
	__vo uint32_t PLLCFGR;		/*!<    Address Offset = 0x04 */
	__vo uint32_t CFGR;			/*!<    Address Offset = 0x08 */
	__vo uint32_t CIR;			/*!<    Address Offset = 0x0C */
	__vo uint32_t AHB1RSTR;		/*!<    Address Offset = 0x10 */
	__vo uint32_t AHB2RSTR;		/*!<    Address Offset = 0x14 */
	__vo uint32_t AHB3RSTR;		/*!<    Address Offset = 0x18 */
	__vo uint32_t RESERVED1;	/*!<    Address Offset = 0x1C */
	__vo uint32_t APB1RSTR;		/*!<    Address Offset = 0x20 */
	__vo uint32_t APB2RSTR;		/*!<    Address Offset = 0x24 */
	__vo uint32_t RESERVED2[2];	/*!<    Address Offset = 0x28 and 0x2C */
	__vo uint32_t AHB1ENR;		/*!<    Address Offset = 0x30 */
	__vo uint32_t AHB2ENR;		/*!<    Address Offset = 0x34 */
	__vo uint32_t AHB3ENR;		/*!<    Address Offset = 0x38 */
	__vo uint32_t RESERVED3;	/*!<    Address Offset = 0x3C */
	__vo uint32_t APB1ENR;		/*!<    Address Offset = 0x40 */
	__vo uint32_t APB2ENR;		/*!<    Address Offset = 0x44 */
	__vo uint32_t RESERVED4[2];	/*!<    Address Offset = 0x48 and 0x4C */
	__vo uint32_t AHB1LPENR;	/*!<    Address Offset = 0x50 */
	__vo uint32_t AHB2LPENR;	/*!<    Address Offset = 0x54 */
	__vo uint32_t AHB3LPENR;	/*!<    Address Offset = 0x58 */
	__vo uint32_t RESERVED5;	/*!<    Address Offset = 0x5C */
	__vo uint32_t APB1LPENR;	/*!<    Address Offset = 0x60 */
	__vo uint32_t APB2LPENR;	/*!<    Address Offset = 0x64 */
	__vo uint32_t RESERVED6[2];	/*!<    Address Offset = 0x68 and 06C */
	__vo uint32_t BDCR;			/*!<    Address Offset = 0x70 */
	__vo uint32_t CSR;			/*!<    Address Offset = 0x74 */
	__vo uint32_t RESERVED7[2];	/*!<    Address Offset = 0x78 and 07C */
	__vo uint32_t SSCGR;		/*!<    Address Offset = 0x80 */
	__vo uint32_t PLLI2SCFGR;	/*!<    Address Offset = 0x84 */
	__vo uint32_t PLLSAISCFGR;	/*!<    Address Offset = 0x88 */
	__vo uint32_t DCKCFGR;		/*!<    Address Offset = 0x8C */
	__vo uint32_t CKGATENR;		/*!<    Address Offset = 0x90 */
	__vo uint32_t DCKCFGR2;		/*!<    Address Offset = 0x94 */

}RCC_RegDef_t;


/*
 * peripheral register definition structure for USART
 */
typedef struct
{
	__vo uint32_t SR;         /*!< TODO,     										Address offset: 0x00 */
	__vo uint32_t DR;         /*!< TODO,     										Address offset: 0x04 */
	__vo uint32_t BRR;        /*!< TODO,     										Address offset: 0x08 */
	__vo uint32_t CR1;        /*!< TODO,     										Address offset: 0x0C */
	__vo uint32_t CR2;        /*!< TODO,     										Address offset: 0x10 */
	__vo uint32_t CR3;        /*!< TODO,     										Address offset: 0x14 */
	__vo uint32_t GTPR;       /*!< TODO,     										Address offset: 0x18 */
} USART_RegDef_t;


/*
 * Peripheral Definition (Peripheral Base addresses type-casted to xxx_RegDef_t
 */

#define GPIOA		( (GPIO_RegDef_t*) GPIOA_BASEADDR )
#define GPIOB		( (GPIO_RegDef_t*) GPIOB_BASEADDR )
#define GPIOC		( (GPIO_RegDef_t*) GPIOC_BASEADDR )
#define GPIOD		( (GPIO_RegDef_t*) GPIOD_BASEADDR )
#define GPIOE		( (GPIO_RegDef_t*) GPIOE_BASEADDR )
#define GPIOF		( (GPIO_RegDef_t*) GPIOF_BASEADDR )
#define GPIOG		( (GPIO_RegDef_t*) GPIOG_BASEADDR )
#define GPIOH		( (GPIO_RegDef_t*) GPIOH_BASEADDR )

#define RCC			( (RCC_RegDef_t*) RCC_BASEADDR )

#define USART1  	((USART_RegDef_t*)USART1_BASEADDR)
#define USART2  	((USART_RegDef_t*)USART2_BASEADDR)
#define USART3  	((USART_RegDef_t*)USART3_BASEADDR)
#define UART4  		((USART_RegDef_t*)UART4_BASEADDR)
#define UART5  		((USART_RegDef_t*)UART5_BASEADDR)
#define USART6  	((USART_RegDef_t*)USART6_BASEADDR)


#endif /* INC_STM32F446XX_H_ */
