/*
 * MNVIC_Private.h
 *
 *  Created on: Aug 13, 2023
 *      Author: DELL
 */

#ifndef MCAL_MGPIO_MNVIC_PRIVATE_H_
#define MCAL_MGPIO_MNVIC_PRIVATE_H_

#define NVIC_BASE_ADDR 	    0xE000E100
#define AIRCR_ADDR		0xE000ED0C

#include "../LIB/STD_Types.h"


typedef struct {
    volatile u32 ISER[8];   // Interrupt Set-Enable Registers
    u32 RESERVED0[24];      // Reserved space
    volatile u32 ICER[8];   // Interrupt Clear-Enable Registers
    u32 RESERVED1[24];      // Reserved space
    volatile u32 ISPR[8];   // Interrupt Set-Pending Registers
    u32 RESERVED2[24];      // Reserved space
    volatile u32 ICPR[8];   // Interrupt Clear-Pending Registers
    u32 RESERVED3[24];      // Reserved space
    volatile u32 IABR[8];   // Interrupt Active Bit Registers
    u32 RESERVED4[56];      // Reserved space
    volatile u8 IPR[240];   // Interrupt Priority Registers
    u32 RESERVED5[644];     // Reserved space
    volatile u32 STIR;      // Software Trigger Interrupt Register
} NVIC_MemMap_t;

#define NVIC 	((volatile NVIC_MemMap_t*)(NVIC_BASE_ADDR))
#define AIRCR 	(*(volatile u32*)(AIRCR_ADDR))

#define MNVIC_VECTKEY 	0x05FA0000


#define Register_Bits 	32


#endif /* MCAL_MGPIO_MNVIC_PRIVATE_H_ */
