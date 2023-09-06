/*
 * Motor.h
 *
 *  Created on: Aug 31, 2023
 *      Author: DELL
 */
typedef enum {
    MOTOR_STATUS_STOPPED,
    MOTOR_STATUS_RUNNING
} MotorStatus;

void Motor_Init(void);
void Motor_Start(void);
void Motor_Stop(void);
MotorStatus Motor_GetStatus(void);


