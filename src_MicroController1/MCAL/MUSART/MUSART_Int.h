/*
 * MUSART_Int.h
 *
 *  Created on: Aug 23, 2023
 *      Author: DELL
 */

#ifndef MCAL_MUSART_MUSART_INT_H_
#define MCAL_MUSART_MUSART_INT_H_

void MUSART_vInit(void);


void MUSART_vSendData(u8* u8Data,u8 u8len);


void MUSART_vSendString(u8* u8Data);

u8 MUSART_u8ReadData(void);

void MUSART_vEnable(void);

void MUSART_vDisable(void);

void MUSART_vCallBack(void(*ptr)(void));

#endif /* MCAL_MUSART_MUSART_INT_H_ */
