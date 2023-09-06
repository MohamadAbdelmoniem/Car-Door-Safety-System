/*
 * MSTK_Int.h
 *
 *  Created on: Aug 15, 2023
 *      Author: DELL
 */

#ifndef MCAL_MSTK_MSTK_INT_H_
#define MCAL_MSTK_MSTK_INT_H_


#define STK_ENABLE			0
#define STK_TICKINT			1
#define STK_CLKSOURCE_BIT 	2
#define STK_COUNTFLAG 		16

void MSTK_vInit(void);

void MSTK_vStartTimer(u32 A_u32LoadValue);
void MSTK_vStopTimer(void);

void MSTK_vSetBusyWait(u32 A_u32Ticks);

void MSTK_vSetInterval_single(u32 A_u32Ticks, void (*CallbackFunction)(void));
void MSTK_vSetInterval_periodic(u32 A_u32Ticks, void (*CallbackFunction)(void));

u32  MSTK_u32GetElapsedTime(void);
u32  MSTK_u32GetRemainingTime(void);


#endif /* MCAL_MSTK_MSTK_INT_H_ */
