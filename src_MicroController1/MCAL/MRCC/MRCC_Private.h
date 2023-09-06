/*
 * MRCC_Private.h
 *
 *  Created on: Aug 10, 2023
 *      Author: Mohamad Ahmed Abdelmoniem
 */

#ifndef MCAL_MRCC_MRCC_PRIVATE_H_
#define MCAL_MRCC_MRCC_PRIVATE_H_
#include "../LIB/STD_Types.h"

/* RCC base address */
#define RCC_BASE_ADDR 0x40023C00

// RCC registers structure
typedef struct {
    u32 CR;        /* Clock control register*/
    u32 PLLCFGR;   /* PLL configuration register*/
    u32 CFGR;      /* Clock configuration register*/
    u32 CIR;
	u32	AHB1RSTR;
	u32 AHB2RSTR;
	u32 Reserved1;
	u32 Reserved2;
	u32	APB1RSTR;
	u32	APB2RSTR;
	u32	Reserved3;
	u32	Reserved4;
	u32	AHB1ENR;	/*RCC AHB1 peripheral clock enable register*/
	u32	AHB2ENR;	/*RCC AHB2 peripheral clock enable register*/
	u32	Reserved5;
	u32	Reserved6;
	u32	APB1ENR;	/*RCC APB1 peripheral clock enable register*/
	u32	APB2ENR;	/*RCC APB2 peripheral clock enable register*/
	u32	Reserved7;
	u32	Reserved8;
	u32 AHB1LPENR;
	u32 AHB2LPENR;
} RCC_MemMap_t;

#define RCC ((volatile RCC_MemMap_t*)(RCC_BASE_ADDR))
#endif /* MCAL_MRCC_MRCC_PRIVATE_H_ */
