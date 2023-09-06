/*
 * MSTK_Private.h
 *
 *  Created on: Aug 15, 2023
 *      Author: DELL
 */

#ifndef MCAL_MSTK_MSTK_PRIVATE_H_
#define MCAL_MSTK_MSTK_PRIVATE_H_

typedef struct {
    volatile u32 CTRL;    // SysTick Control and Status Register (SYST_CSR)
    volatile u32 LOAD;    // SysTick Reload Value Register (SYST_RVR)
    volatile u32 VAL;     // SysTick Current Value Register (SYST_CVR)
    volatile u32 CALIB;   // SysTick Calibration Register (SYST_CALIB)
} SysTick_MemMap_t;

#define STK_BASE_ADD 0xE000E010
#define STK ((SysTick_MemMap_t *)STK_BASE_ADD)
#define NULL 0


#endif /* MCAL_MSTK_MSTK_PRIVATE_H_ */
