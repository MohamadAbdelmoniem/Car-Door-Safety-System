/*
 * Motor.c
 *
 *  Created on: Aug 31, 2023
 *      Author: DELL
 */

#include "Motor.h"
#include "..//MCAL/LIB/STD_Types.h"  // You need to include the appropriate types
#include "..//MCAL/MGPIO/MGPIO_Int.h"
#include "..//MCAL/MRCC/MRCC_Int.h"



static MotorStatus Motor_Status = MOTOR_STATUS_STOPPED;

/*
void Motor_Init(void) {
    MRCC_vEnableClock(RCC_BUS_AHB1, RCC_PERIPHERAL_GPIOB);
    MGPIO_vSetPinMode(GPIO_PORTA, PIN2, GPIO_MODE_OUTPUT);
}
*/

void Motor_Start(void) {
    MGPIO_vSetPinValue(GPIO_PORTA, PIN2, GPIO_HIGH);
	Motor_Status = MOTOR_STATUS_RUNNING;
}

void Motor_Stop(void) {
    MGPIO_vSetPinValue(GPIO_PORTA, PIN2, GPIO_LOW);
    Motor_Status = MOTOR_STATUS_STOPPED;
}

MotorStatus Motor_GetStatus(void) {
    return Motor_Status;
}

