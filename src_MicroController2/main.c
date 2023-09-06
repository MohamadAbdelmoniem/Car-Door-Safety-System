#include "HAL/Motor.h"
#include "MCAL/MRCC/MRCC_Int.h"
#include "MCAL/MEXTI/MEXTI_Int.h"
#include "MCAL/MNVIC/MNVIC_Int.h"
#include "MCAL/MGPIO/MGPIO_Int.h"
#include "MCAL/MUSART/MUSART_Int.h"

int main(int argc, char *argv[]) {

    MRCC_vInit();

    /* Enable Clock for GPIOA */
    MRCC_vEnableClock(RCC_BUS_AHB1, RCC_PERIPHERAL_GPIOA);
    MRCC_vEnableClock(RCC_BUS_APB2, RCC_PERIPHERAL_USART1);


    /* Set Pin 0 PORTA as Input Button that starts the motor*/
    MGPIO_vSetPinMode(GPIO_PORTA, PIN0, GPIO_MODE_INPUT);
    MGPIO_vSetPinInputPull(GPIO_PORTA, PIN0, GPIO_PULLDOWN);

    /* Set Pin 1 PORTA as Input Button that idicates that the door is open*/
    MGPIO_vSetPinMode(GPIO_PORTA, PIN0, GPIO_MODE_INPUT);
    MGPIO_vSetPinInputPull(GPIO_PORTA, PIN0, GPIO_PULLDOWN);

    /* Set Pins 9 and 10 PORTA as Alternate Function FOR USART */
    MGPIO_vSetPinMode(GPIO_PORTA, PIN9, GPIO_MODE_ALT);
    MGPIO_vSetPinMode(GPIO_PORTA, PIN10, GPIO_MODE_ALT);

    /* Set Pin 2 and 3 PORTA as Output for the DC Motor */
    MGPIO_vSetPinMode(GPIO_PORTA, PIN2, GPIO_MODE_OUTPUT);
    MGPIO_vSetPinMode(GPIO_PORTA, PIN3, GPIO_MODE_OUTPUT);

    MGPIO_vSetPinOutputType(GPIO_PORTA, PIN2, GPIO_PUSHPULL);
    MGPIO_vSetPinOutputType(GPIO_PORTA, PIN3, GPIO_PUSHPULL);

    /* Initialize and enable USART */
    MUSART_vInit();
    MUSART_vEnable();
    MotorStatus status =Motor_GetStatus();
    while (1) {
            if (status==MOTOR_STATUS_RUNNING && MGPIO_u8GetPinValue(GPIO_PORTA,PIN0))
        {
                // Button is pressed and Motor is ON, send a character to the other microcontroller
                MUSART_vSendData("B", 1);
        }
    }
}
