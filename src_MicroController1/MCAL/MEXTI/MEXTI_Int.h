/*
 * MEXTI_Int.h
 *
 *  Created on: Aug 14, 2023
 *      Author: DELL
 */

#ifndef MCAL_MEXTI_MEXTI_INT_H_
#define MCAL_MEXTI_MEXTI_INT_H_

typedef enum {
    EXTI_Line0 = 0,
    EXTI_Line1,
    EXTI_Line2,
    EXTI_Line3,
    EXTI_Line4,
    EXTI_Line5,
    EXTI_Line6,
    EXTI_Line7,
    EXTI_Line8,
    EXTI_Line9,
    EXTI_Line10,
    EXTI_Line11,
    EXTI_Line12,
    EXTI_Line13,
    EXTI_Line14,
    EXTI_Line15,
} EXTI_Line;


typedef enum {
    EXTI_FALLING_EDGE = 0,
	EXTI_RISING_EDGE,
	EXTI_ON_EVENT,
} EXTI_Trigger;

typedef enum {
    EXTI_PORTA = 0,
    EXTI_PORTB,
    EXTI_PORTC,
} EXTI_PORT;

void MEXTI_vInterruptSetLine(EXTI_Line EXTI_LineNumber);
void MEXTI_vInterruptClearLine(EXTI_Line EXTI_LineNumber);
void MEXTI_vInterruptTrigger(EXTI_Line EXTI_LineNumber,EXTI_Trigger EXTI_Edge);
void MEXTI_vInterruptSoftware(EXTI_Line EXTI_LineNumber);
void MEXTI_vInterruptPort(EXTI_Line EXTI_LineNumber,EXTI_PORT EXTI_PortNumber);

void MEXTI0_VoidCallBack(void(*ptr)(void));

void MEXTI1_VoidCallBack(void(*ptr)(void));

void MEXTI2_VoidCallBack(void(*ptr)(void));




#endif /* MCAL_MEXTI_MEXTI_INT_H_ */
