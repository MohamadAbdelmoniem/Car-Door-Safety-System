/*
 * MEXTI_Private.h
 *
 *  Created on: Aug 14, 2023
 *      Author: Mohamad Ahmed Mohamad Abdelmoniem
 */


#ifndef MCAL_MEXTI_MEXTI_PRIVATE_H_
#define MCAL_MEXTI_MEXTI_PRIVATE_H_

#include "../LIB/STD_Types.h"

typedef struct {
    volatile u32 IMR;    // Interrupt Mask Register
    volatile u32 EMR;    // Event Mask Register
    volatile u32 RTSR;   // Rising Trigger Selection Register
    volatile u32 FTSR;   // Falling Trigger Selection Register
    volatile u32 SWIER;  // Software Interrupt Event Register
    volatile u32 PR;     // Pending Register
} EXTI_MemMap_t;

typedef struct {
    volatile u32 MEMRMP;    // Memory Remap Register
    volatile u32 PMC;       // Peripheral Mode Configuration Register
    volatile u32 EXTICR[4]; // External Interrupt Configuration Registers
    volatile u32 CMPCR;     // Compensation Cell Control Register
} SYSCFG_MemMap_t;

#define SYSCFG_BASE_ADDR      0x40013800  // SYSCFG base address
#define EXTI_BASE_ADDR        0x40013C00  // EXTI base address
#define NULL 0
#define EXTI_CONFG_MASK1	0xFFFFFFF0
#define EXTI_CONFG_MASK2	0xFFFFFF0F
#define EXTI_CONFG_MASK3	0xFFFFF0FF
#define EXTI_CONFG_MASK4	0xFFFF0FFF


#define SYSCFG   ((volatile SYSCFG_MemMap_t*)(SYSCFG_BASE_ADDR))

#define EXTI 	((volatile EXTI_MemMap_t*)(EXTI_BASE_ADDR))



#endif /* MCAL_MEXTI_MEXTI_PRIVATE_H_ */
