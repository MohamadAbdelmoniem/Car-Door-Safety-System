/*
 * Buzzer.c
 *
 *  Created on: Aug 31, 2023
 *      Author: DELL
 */

#include "Buzzer.h"
#include "../MCAL/MGPIO/MGPIO_Int.h"
#include "../MCAL/MRCC/MRCC_Int.h"

void Buzzer_Init(void) {
	//Enable clock to PortB
    MRCC_vEnableClock(RCC_BUS_AHB1, RCC_PERIPHERAL_GPIOB);
    // Initialize buzzer pin as output
    MGPIO_vSetPinMode(GPIO_PORTB, PIN0, GPIO_MODE_OUTPUT);
    // Set buzzer pin low initially
    Buzzer_TurnOff();
}

void Buzzer_TurnOn(void) {
    // Turn on the buzzer by setting the pin high
    MGPIO_vSetPinValue(GPIO_PORTB, PIN0, GPIO_HIGH);
}

void Buzzer_TurnOff(void) {
    // Turn off the buzzer by setting the pin low
    MGPIO_vSetPinValue(GPIO_PORTB, PIN0, GPIO_LOW);
}



