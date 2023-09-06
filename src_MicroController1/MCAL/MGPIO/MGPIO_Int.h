/*
 * MGPIO_Int.h
 *
 *  Created on: Aug 10, 2023
 *      Author: Mohamad Ahmed Abdelmoniem
 */

#ifndef MCAL_MGPIO_MGPIO_INT_H_
#define MCAL_MGPIO_MGPIO_INT_H_

#include "../LIB/STD_Types.h"


/*A_u8PortID*/
#define GPIO_PORTA	0
#define GPIO_PORTB	1
#define GPIO_PORTC	2

/*A_u8PinNumber*/

#define PIN0	0
#define PIN1	1
#define PIN2	2
#define PIN3	3
#define PIN4	4
#define PIN5	5
#define PIN6	6
#define PIN7	7
#define PIN8	8
#define PIN9	9
#define PIN10	10
#define PIN11	11
#define PIN12	12
#define PIN13	13
#define PIN14	14
#define PIN15	15

/*A_u8Mode*/
#define GPIO_MODE_INPUT 	00
#define GPIO_MODE_OUTPUT 	01
#define GPIO_MODE_ALT		10
#define	GPIO_MODE_ANALOG	11

/*A_u8OutPutType*/
#define GPIO_PUSHPULL 		0
#define GPIO_OPEN_DRAIN 	1

/*A_u8Direction*/
#define GPIO_PULLUP 		01
#define GPIO_PULLDOWN 		10

/*A_u8PinValue*/
#define GPIO_LOW	0
#define GPIO_HIGH	1

/*A_u8AlternateFunction*/
#define AF0		0000
#define AF1		0001
#define AF2		0010
#define AF3		0011
#define AF4		0100
#define AF5		0101
#define AF6		0110
#define AF7		0111
#define AF8		1000
#define AF9		1001
#define AF10	1010
#define AF11	1011
#define AF12	1100
#define AF13	1101
#define AF14	1110
#define AF15	1111


/*A_u8A_Speed*/
#define GPIO_LOW_SPEED			00
#define GPIO_MEDIUM_SPEED		01
#define GPIO_HIGH_SPEED			10
#define GPIO_VERY_HIGH_SPEED	11

void MGPIO_vSetPinMode(u8 A_u8PortID,u8 A_u8PinNumber,u8 A_u8Mode);

/*Input*/
void MGPIO_vSetPinInputPull(u8 A_u8PortID,u8 A_u8PinNumber,u8 A_u8Direction);
u8 MGPIO_u8GetPinValue(u8 A_u8PortID,u8 A_u8PinNumber);


/*Output*/
void MGPIO_vSetPinOutputType(u8 A_u8PortID,u8 A_u8PinNumber,u8 A_u8OutPutType);
void MGPIO_vSetPinOutPutSpeed(u8 A_u8PortID,u8 A_u8PinNumber,u8 A_u8A_Speed);
void MGPIO_vSetPinValue(u8 A_u8PortID,u8 A_u8PinNumber,u8 A_u8PinValue);
void MGPIO_vSetPinValueFast(u8 A_u8PortID,u8 A_u8PinNumber,u8 A_u8PinValue);	/*BSRR*/
void MGPIO_vSetAlternativeFunction(u8 A_u8PortID,u8 A_u8PinNumber,u8 A_u8AlternateFunction);

void MEXTI0_VoidCallBack(void(*ptr)(void));
void MEXTI1_VoidCallBack(void(*ptr)(void));
void MEXTI2_VoidCallBack(void(*ptr)(void));



#endif /* MCAL_MGPIO_MGPIO_INT_H_ */
