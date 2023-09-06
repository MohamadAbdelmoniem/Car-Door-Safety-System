/*
 * MEXTI_Prog.c
 *
 *  Created on: Aug 14, 2023
 *      Author: Mohamad Ahmed Mohamad Abdelmoniem
 */
#include "../LIB/STD_Types.h"
#include "../LIB/BIT_Math.h"
#include "MEXTI_Config.h"
#include "MEXTI_Int.h"
#include "MEXTI_Private.h"

static void(*EXTI0_CallBack)(void)=NULL;
static void(*EXTI1_CallBack)(void)=NULL;
static void(*EXTI2_CallBack)(void)=NULL;



void MEXTI_vInterruptSetLine(EXTI_Line EXTI_LineNumber) {
    if (EXTI_LineNumber <= 15)
        SET_BIT(EXTI->IMR, EXTI_LineNumber);
    else {
    	// Print an error message or handle the error
    }
}


void MEXTI_vInterruptClearLine(EXTI_Line EXTI_LineNumber){
    if (EXTI_LineNumber <= 15)
        CLEAR_BIT(EXTI->IMR, EXTI_LineNumber);
    else {
    	// Print an error message or handle the error
    }
}

void MEXTI_vInterruptTrigger(EXTI_Line EXTI_LineNumber,EXTI_Trigger EXTI_Edge){
	switch(EXTI_Edge){
		case EXTI_FALLING_EDGE:
		    SET_BIT(EXTI->FTSR, EXTI_LineNumber);
			break;
		case EXTI_RISING_EDGE:
		    SET_BIT(EXTI->RTSR, EXTI_LineNumber);
			break;
		case EXTI_ON_EVENT:
		    SET_BIT(EXTI->FTSR, EXTI_LineNumber);
		    SET_BIT(EXTI->RTSR, EXTI_LineNumber);
			break;
		default:
	    	// Print an error message or handle the error
			break;
	}
}

void MEXTI_vInterruptSoftware(EXTI_Line EXTI_LineNumber){
    SET_BIT(EXTI->SWIER, EXTI_LineNumber);
}

void MEXTI_vInterruptPort(EXTI_Line EXTI_LineNumber, EXTI_PORT EXTI_PortNumber) {
    // Calculate the array index based on the EXTI line number
    //u8 arrayIndex = (EXTI_LineNumber / 4);
    //	Calculate the Shifting Value
    //u8 ShiftingValue=4*(EXTI_LineNumber%4);
    switch (EXTI_LineNumber) {
        case EXTI_Line0:
        	SYSCFG -> EXTICR[1] &=EXTI_CONFG_MASK1;
            SYSCFG->EXTICR[1] |=EXTI_PortNumber ;
            break;
        case EXTI_Line1:
        	SYSCFG -> EXTICR[1] &=EXTI_CONFG_MASK2;
            SYSCFG->EXTICR[1] |=EXTI_PortNumber<<4 ;
            break;
        case EXTI_Line2:
        	SYSCFG -> EXTICR[1] &=EXTI_CONFG_MASK3;
            SYSCFG->EXTICR[1] |=EXTI_PortNumber<<8 ;
            break;
        case EXTI_Line3:
        	SYSCFG -> EXTICR[1] &=EXTI_CONFG_MASK4;
            SYSCFG->EXTICR[1] |=EXTI_PortNumber<<12 ;
            break;
        default: break;
    }
}


void MEXTI0_VoidCallBack(void(*ptr)(void)){
	EXTI0_CallBack=ptr;
}

void MEXTI1_VoidCallBack(void(*ptr)(void)){
	EXTI1_CallBack=ptr;
}

void MEXTI2_VoidCallBack(void(*ptr)(void)){
	EXTI2_CallBack=ptr;
}

void EXTI0_IRQHandler(void) {
	EXTI0_CallBack();
	SET_BIT(EXTI->PR,0);
}

void EXTI1_IRQHandler(void) {
	EXTI1_CallBack();
	SET_BIT(EXTI->PR,1);
}

void EXTI2_IRQHandler(void) {
	EXTI2_CallBack();
	SET_BIT(EXTI->PR,2);
}

















