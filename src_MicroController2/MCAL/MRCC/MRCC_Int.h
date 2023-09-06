/*
 * MRCC_Int.h
 *
 *  Created on: Aug 10, 2023
 *      Author: Mohamad Ahmed Abdelmoiem
 */

#ifndef MCAL_MRCC_MRCC_INT_H_
#define MCAL_MRCC_MRCC_INT_H_
#include "../LIB/STD_Types.h"
/*RCC clock control register (RCC_CR)*/

#define	HSION	0
#define HSIRDY	1
#define HSEON	16
#define HSERDY	17
#define HSEBYP	18
#define CSSON	19
#define PLLON	24
#define PLLRDY 	25


/*RCC clock configuration register (RCC_CFGR)*/
#define SW0	0
#define SW1 1


/*Bus options*/
#define RCC_BUS_AHB1	 1
#define RCC_BUS_AHB2 	 2
#define RCC_BUS_APB1 	 3
#define RCC_BUS_APB2 	 4



	/* peripheral numbers */

		/*BUS_AHB1*/
#define RCC_PERIPHERAL_GPIOA 	0
#define RCC_PERIPHERAL_GPIOB 	1
#define RCC_PERIPHERAL_GPIOC 	2
#define RCC_PERIPHERAL_GPIOD 	3
#define RCC_PERIPHERAL_GPIOE 	4
#define RCC_PERIPHERAL_GPIOH 	7
#define RCC_PERIPHERAL_CRC	 	12
#define RCC_PERIPHERAL_DMA1 	21
#define RCC_PERIPHERAL_DMA2 	22

		/*BUS_APB1*/
#define  RCC_PERIPHERAL_TIM2	0
#define  RCC_PERIPHERAL_TIM3	1
#define  RCC_PERIPHERAL_TIM4	2
#define  RCC_PERIPHERAL_TIM5	3
#define  RCC_PERIPHERAL_SPI2	14
#define  RCC_PERIPHERAL_SPI3	15
#define  RCC_PERIPHERAL_USART2	17

		/*BUS_APB2*/
#define  RCC_PERIPHERAL_TIM1	0
#define  RCC_PERIPHERAL_USART1	4
#define  RCC_PERIPHERAL_USART6	5
#define  RCC_PERIPHERAL_ADC1	8
#define  RCC_PERIPHERAL_SPI1	12
#define  RCC_PERIPHERAL_SPI4	13
#define  RCC_PERIPHERAL_TIM9	16
#define  RCC_PERIPHERAL_TIM10	17
#define  RCC_PERIPHERAL_TIM11	18

void MRCC_vInit(void);
void MRCC_vDisableClock(u8 bus, u8 peripheral);
void MRCC_vEnableClock(u8 bus, u8 peripheral);


#endif /* MCAL_MRCC_MRCC_INT_H_ */
