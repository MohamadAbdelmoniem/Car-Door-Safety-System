/*
 * MUSART_Prog.c

 *
 *  Created on: Aug 23, 2023
 *      Author: Mohamad Ahmed Mohamad Abdelmoniem
 */

#include "../LIB/STD_Types.h"
#include "../LIB/BIT_Math.h"
#include "MUSART_Config.h"
#include "MUSART_Private.h"
#include "MUSART_Int.h"

void (*G_MUSART_Callback)(void);

void MUSART_vInit(void){
    // Configure Baud Rate
    USART->BRR = 0x0000008b;

    // Configure Sampling
    #if Sampling == Sampling_16
    	USART->CR1.OVER8 = 0;
    #elif Sampling == Sampling_8
    	USART->CR1.OVER8 = 1;
    #else
    	#error "Invalid Sampling specified"
    #endif

    // Configure Word Length
    #if Length == Length_8
    	USART->CR1.M = 0;
    #elif Length == Length_9
    	USART->CR1.M = 1;
    #else
    	#error "Invalid Length specified"
    #endif

    // Enable Transmitter and Receiver
    USART->CR1.TE = 1; // TRANSMIT ENABLE
    USART->CR1.RE = 1; // RECEIVER ENABLE
}

void MUSART_vSendData(u8* u8Data, u8 u8len){
    for(u8 u8index = 0; u8index < u8len; u8index++) {
        // Write data to Data Register
        USART->DR = u8Data[u8index];

        // Wait until TXE flag is set (Transmit Data Register Empty)
        while (GET_BIT(USART->SR, 7) == 0);
    }
}

void MUSART_vSendString(u8* u8Data){
    u8 u8index = 0;
    while (u8Data[u8index] != '\n') {
        // Write character to Data Register
        USART->DR = u8Data[u8index];

        // Wait until TXE flag is set (Transmit Data Register Empty)
        while (GET_BIT(USART->SR, 7) == 0);
        u8index++;
    }
}


u8 MUSART_u8ReadData(void){
    u8 Received_Data;

    // Wait until RXNE flag is set (Receive Data Register Not Empty)
    while (GET_BIT(USART->SR, 5) == 0);

    // Read the received data from DR
    Received_Data = USART->DR;

    return Received_Data;
}


void MUSART_vEnable(void){
    // Enable USART
    USART->CR1.UE = 1;
}


void MUSART_vDisable(void){
    // Disable USART
    USART->CR1.UE = 0;
}


void MUSART_vCallBack(void (*ptr)(void)) {
    G_MUSART_Callback = ptr;
}


void USART1_IRQHandler(){
	G_MUSART_Callback();
}


