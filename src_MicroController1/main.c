/*
 * Created on: Aug 15, 2023
 * Author: Mohamad Ahmed Mohamad Abdelmoniem
 */
#include <stdio.h>
#include <stdlib.h>

#include "MCAL/MRCC/MRCC_Int.h"
#include "MCAL/MEXTI/MEXTI_Int.h"
#include "MCAL/MNVIC/MNVIC_Int.h"
#include "MCAL/MGPIO/MGPIO_Int.h"
#include "MCAL/MUSART/MUSART_Int.h"
#include "HAL/Buzzer.h"

int main(int argc, char *argv[]) {

    MRCC_vInit();
    /* Enable Clock for GPIOA */
    MRCC_vEnableClock(RCC_BUS_AHB1, RCC_PERIPHERAL_GPIOA);
    MRCC_vEnableClock(RCC_BUS_APB2, RCC_PERIPHERAL_USART1);


    /* Set Pins 1 and 2 PORTA as Alternate Function */
    MGPIO_vSetPinMode(GPIO_PORTA, PIN9, GPIO_MODE_ALT);
    MGPIO_vSetPinMode(GPIO_PORTA, PIN10, GPIO_MODE_ALT);

    MGPIO_vSetAlternativeFunction(GPIO_PORTA, PIN9, AF1);
    MGPIO_vSetAlternativeFunction(GPIO_PORTA, PIN10, AF1);

    /* Initialize and enable USART */
    MUSART_vInit();
    MUSART_vEnable();
    Buzzer_Init();

    while (1) {
        // Receive data from the other microcontroller
        char receivedData = MUSART_u8ReadData();
        // Check if the received data is 'B'
        if (receivedData == 'B') {
            // Turn on the Buzzer
        	Buzzer_TurnOn();
        } else {
            // Turn off the Buzzer
        	Buzzer_TurnOff();
        }
    }
}

