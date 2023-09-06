/*
 * MNVIC_Prog.c
 *
 *  Created on: Aug 13, 2023
 *      Author: DELL
 */
#include "../LIB/STD_Types.h"
#include "../LIB/BIT_Math.h"
#include "MNVIC_Config.h"
#include "MNVIC_Private.h"
#include "MNVIC_Int.h"

u32 Global_u32SetGroup;

void MNVIC_vInterruptSetEnable(u8 u8_InterruptId){
	u8 Register=u8_InterruptId / Register_Bits; 			//GET Register ID
	u8 Bit_Number=u8_InterruptId % Register_Bits;			//GET Bit Number
	SET_BIT(NVIC->ISER[Register],Bit_Number);
}

void MNVIC_vInterruptClearEnable(u8 u8_InterruptId){
	u8 Register=u8_InterruptId / Register_Bits; 			//GET Register ID
	u8 Bit_Number=u8_InterruptId % Register_Bits;			//GET Bit Number
	SET_BIT(NVIC->ICER[Register],Bit_Number);
}

void MNVIC_SetGroupMode(Group_Mode GROUPMODE){
	Global_u32SetGroup=(MNVIC_VECTKEY|(GROUPMODE<<8));
	AIRCR = Global_u32SetGroup;
}

void MNVIC_SetInterruptPirority(u8 u8_InterruptId,u8 u8_GroupId,u8 u8_SubGroupId){
	switch(Global_u32SetGroup){
	case MNVIC_16G_0SG:
		NVIC -> IPR[u8_InterruptId] = (u8_GroupId<<4); break;
	case MNVIC_8G_2SG:
		NVIC -> IPR[u8_InterruptId] = (u8_GroupId<<5);
		NVIC -> IPR[u8_InterruptId] = (u8_SubGroupId<<4);
		break;
	case MNVIC_4G_4SG:
		NVIC -> IPR[u8_InterruptId] = (u8_GroupId<<6);
		NVIC -> IPR[u8_InterruptId] = (u8_SubGroupId<<4);
		break;
	case MNVIC_2G_8SG:
		NVIC -> IPR[u8_InterruptId] = (u8_GroupId<<7);
		NVIC -> IPR[u8_InterruptId] = (u8_SubGroupId<<4);
		break;
	case MNVIC_0G_16SG:
		NVIC -> IPR[u8_InterruptId] = (u8_SubGroupId<<4);
		break;
	}
}

