/*
 * MSTK_Prog.c
 *
 *  Created on: Aug 15, 2023
 *      Author: Mohamad Ahmed Mohamad Abdelmoniem
 */
#include "../LIB/STD_Types.h"
#include "../LIB/BIT_Math.h"
#include "MSTK_Config.h"
#include "MSTK_Private.h"
#include "MSTK_Int.h"

static void (*GS_STK_Callback)(void); /* Function pointer for callback */
static u8 G_u8SingleFlag; /* Flag to differentiate between single-shot and periodic modes */

void MSTK_vInit(void) {
    #if STK_CLKSOURCE == STK_AHB
        SET_BIT(STK->CTRL, STK_CLKSOURCE_BIT); /* Use AHB clock source */
    #elif STK_CLKSOURCE == STK_AHB_8
        CLEAR_BIT(STK->CTRL, STK_CLKSOURCE_BIT); /* Use AHB/8 clock source */
    #else
        #error "Invalid CLOCK_SOURCE specified"
    #endif
}

void MSTK_vStartTimer(u32 A_u32LoadValue) {
    STK->VAL = 0x00000000; /* Reset current value */
    STK->LOAD = A_u32LoadValue; /* Load timer with specified value */
    SET_BIT(STK->CTRL, STK_ENABLE); /* Start the timer */
}

void MSTK_vStopTimer(void) {
    CLEAR_BIT(STK->CTRL, STK_ENABLE); /* Stop the timer */
}

u32 MSTK_u32GetElapsedTime(void) {
    return (STK->LOAD - STK->VAL); /* Calculate elapsed time */
}

u32 MSTK_u32GetRemainingTime(void) {
    return STK->VAL; /* Get remaining time */
}

void MSTK_vIntEnable(void) {
    SET_BIT(STK->CTRL, STK_TICKINT); /* Enable SysTick interrupt */
}

void MSTK_vSetInterval_single(u32 A_u32Ticks, void (*CallbackFunction)(void)) {
    GS_STK_Callback = CallbackFunction; /* Set callback function */
    G_u8SingleFlag = 1; /* Set single-shot mode */
    STK->VAL = 0; /* Reset timer value */
    STK->LOAD = A_u32Ticks; /* Load timer with interval */
    SET_BIT(STK->CTRL, STK_ENABLE); /* Start the timer */
}

void MSTK_vSetInterval_periodic(u32 A_u32Ticks, void (*CallbackFunction)(void)) {
    GS_STK_Callback = CallbackFunction; /* Set callback function */
    G_u8SingleFlag = 0; /* Set periodic mode */
    STK->VAL = 0; /* Reset timer value */
    STK->LOAD = A_u32Ticks; /* Load timer with interval */
    SET_BIT(STK->CTRL, STK_ENABLE); /* Start the timer */
}

void Systick_Handler(void) {
    if (GS_STK_Callback != NULL) {
        GS_STK_Callback(); /* Execute callback function */
    }
    if (G_u8SingleFlag) {
        G_u8SingleFlag = 0; /* Clear single-shot mode */
        CLR_BIT(STK->CTRL, STK_ENABLE); /* Stop the timer */
    }
}
