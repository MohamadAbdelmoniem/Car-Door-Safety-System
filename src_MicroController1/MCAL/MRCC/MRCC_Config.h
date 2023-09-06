/*
 * MRCC_Config.h
 *
 *  Created on: Aug 10, 2023
 *      Author: Mohamad Ahmed Mohamad Abdelmoniem
 */

#ifndef MCAL_MRCC_MRCC_CONFIG_H_
#define MCAL_MRCC_MRCC_CONFIG_H_


#define RCC_HSI 	1
#define RCC_HSE		2
#define RCC_PLL		3
#define RCC_CSS		4
/*
 * Choose 1 from the following for system clock
 * 	RCC_HSI
 * 	RCC_HSE
 * 	RCC_PLL
 * 	RCC_CSS
 * */
#define RCC_CLK_Source		RCC_HSI

/*
 * Choose 1 from the following for HSE
 * 	RCC_HSE_HSEBYP
 * 	RCC_HSE_OSCLLATOR
 * */

#define RCC_HSE_HSEBYP			1
#define RCC_HSE_OSCLLATOR		2

#define RCC_HSE_SOURCE		RCC_HSE_OSCLLATOR



#endif /* MCAL_MRCC_MRCC_CONFIG_H_ */
