/*
 * MNVIC_Int.h
 *
 *  Created on: Aug 13, 2023
 *      Author: DELL
 */

#ifndef MCAL_MNVIC_MNVIC_INT_H_
#define MCAL_MNVIC_MNVIC_INT_H_

#include "../LIB/STD_Types.h"

typedef enum {
    MNVIC_16G_0SG = 3,
    MNVIC_8G_2SG,
    MNVIC_4G_4SG,
    MNVIC_2G_8SG,
    MNVIC_0G_16SG,
} Group_Mode;



void MNVIC_vInterruptSetEnable(u8 u8_InterruptId);
void MNVIC_vInterruptClearEnable(u8 u8_InterruptId);
void MNVIC_SetGroupMode(Group_Mode GROUPMODE);

void MNVIC_SetInterruptPirority(u8 u8_InterruptId,u8 u8_GroupId,u8 u8_SubGroupId);





#endif /* MCAL_MNVIC_MNVIC_INT_H_ */
