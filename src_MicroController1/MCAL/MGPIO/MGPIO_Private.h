/*
 * MGPIO_Private.h
 *
 *  Created on: Aug 10, 2023
 *      Author: DELL
 */

#ifndef MCAL_MGPIO_MGPIO_PRIVATE_H_
#define MCAL_MGPIO_MGPIO_PRIVATE_H_

#include "../LIB/STD_Types.h"

/* RCC base address */
#define GPIOA_BASE_ADDR  0x40020000
#define GPIOB_BASE_ADDR  0x40020400
#define GPIOC_BASE_ADDR  0x40020800
#define GPIOD_BASE_ADDR  0x40020C00
#define GPIOE_BASE_ADDR  0x40021000
#define GPIOH_BASE_ADDR  0x40021C00

// GPIO registers structure
typedef struct {
	 	u32 MODER;    /* Mode register: Configure mode for each GPIO pin */
	 	u32 OTYPER;   /* Output type register: Configure output type for each GPIO pin */
	 	u32 OSPEEDR;  /* Output speed register: Configure output speed for each GPIO pin */
	 	u32 PUPDR;    /* Pull-up/pull-down register: Configure pull-up/pull-down for each GPIO pin */
	 	u32 IDR;      /* Input data register: Read input state of GPIO pins */
	 	u32 ODR;      /* Output data register: Set or clear output state of GPIO pins */
	 	u32 BSRR;     /* Bit set/reset register: Atomically set or reset GPIO pins */
	 	u32 LCKR;     /* Configuration lock register: Lock/unlock GPIO configuration settings */
	 	u32 AFRL;     /* Alternate function registers: Configure alternate function for each GPIO pin from 0 to 7 */
	 	u32 AFRH;     /* Alternate function registers: Configure alternate function for each GPIO pin from 8 to 15 */
} GPIO_MemMap_t;

#define GPIOA ((volatile GPIO_MemMap_t*)(GPIOA_BASE_ADDR))
#define GPIOB ((volatile GPIO_MemMap_t*)(GPIOB_BASE_ADDR))
#define GPIOC ((volatile GPIO_MemMap_t*)(GPIOC_BASE_ADDR))
#define GPIOD ((volatile GPIO_MemMap_t*)(GPIOD_BASE_ADDR))
#define GPIOE ((volatile GPIO_MemMap_t*)(GPIOE_BASE_ADDR))
#define GPIOH ((volatile GPIO_MemMap_t*)(GPIOH_BASE_ADDR))

#endif /* MCAL_MGPIO_MGPIO_PRIVATE_H_ */
