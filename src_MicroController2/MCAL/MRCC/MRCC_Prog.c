/*
 * MRCC_Prog.c
 *
 *  Created on: Aug 10, 2023
 *      Author: Mohamad Ahmed Abdelmoniem
 */
#include "../LIB/STD_Types.h"
#include "../LIB/BIT_Math.h"
#include "MRCC_Config.h"
#include "MRCC_Private.h"
#include "MRCC_Int.h"



void MRCC_vInit(void){

	#if RCC_CLK_Source==RCC_HSI
		SET_BIT(RCC->CR,HSION);				/*Put 1 in the HSION Register */
		while(GET_BIT(RCC->CR,HSIRDY)==0); 	/*Wait until HSIRDY take value */
		CLEAR_BIT(RCC->CFGR,SW0);
		CLEAR_BIT(RCC->CFGR,SW1);				/*Select RCC_HSI as the clock source */

	#elif RCC_CLK_Source == RCC_HSE
		#if RCC_HSE_SOURCE==RCC_HSE_HSEBYP
			SET_BIT(RCC->CR,HSEBYP);
		#elif RCC_HSE_SOURCE==RCC_HSE_OSCLLATOR
			CLEAR_BIT(RCC->CR,HSEBYP);
		#endif
		SET_BIT(RCC->CR,HSEON);				/*Put 1 in the HSEON Register */
		while(GET_BIT(RCC->CR,HSERDY)==0);	/*Wait until HSIRDY take value */
		SET_BIT(RCC->CFGR,SW0);
		CLEAR_BIT(RCC->CFGR,SW1);				/*Select RCC_HSE as the clock source */

	#elif RCC_CLK_Source == RCC_PLL
		SET_BIT(RCC->CR,PLLON);
		while(GET_BIT(RCC->CR,PLLRDY)==0);
		CLEAR_BIT(RCC->CFGR,SW0);
		SET_BIT(RCC->CFGR,SW1);				/*Select RCC_PLL as the clock source */

	#elif RCC_CLK_Source == RCC_CSS
		SET_BIT(RCC->CR,CSSON);
	#else
		#error "Invalid CLOCK_SOURCE specified"
	#endif
}

void MRCC_vEnableClock(u8 bus, u8 peripheral){
	switch(bus){
		case RCC_BUS_AHB1:
			SET_BIT(RCC->AHB1ENR,peripheral);
			break;
		case RCC_BUS_AHB2:
			SET_BIT(RCC->AHB2ENR,peripheral);
			break;
		case RCC_BUS_APB1:
			SET_BIT(RCC->APB1ENR,peripheral);
			break;
		case RCC_BUS_APB2:
			SET_BIT(RCC->APB2ENR,peripheral);
			break;
		default:
			/* Return Error */
			break;
	}
}

void MRCC_vDisableClock(u8 bus, u8 peripheral){
	switch(bus){
		case RCC_BUS_AHB1:
			CLEAR_BIT(RCC->AHB1ENR,peripheral);
			break;
		case RCC_BUS_AHB2:
			CLEAR_BIT(RCC->AHB2ENR,peripheral);
			break;
		case RCC_BUS_APB1:
			CLEAR_BIT(RCC->APB1ENR,peripheral);
			break;
		case RCC_BUS_APB2:
			CLEAR_BIT(RCC->APB2ENR,peripheral);
			break;
		default:
			break;

	}
}






