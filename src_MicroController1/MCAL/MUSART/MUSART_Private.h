/*
 * MUSART_Private.h
 *
 *  Created on: Aug 23, 2023
 *      Author: DELL
 */

#ifndef MCAL_MUSART_MUSART_PRIVATE_H_
#define MCAL_MUSART_MUSART_PRIVATE_H_

typedef struct {
    u32 SBK : 1;   // Send Break
    u32 RWU : 1;   // Receiver Wakeup
    u32 RE : 1;    // Receiver Enable
    u32 TE : 1;    // Transmitter Enable
    u32 IDLEIE : 1;  // IDLE Interrupt Enable
    u32 RXNEIE : 1;  // RXNE Interrupt Enable
    u32 TCIE : 1;    // Transmission Complete Interrupt Enable
    u32 TXEIE : 1;   // TXE Interrupt Enable
    u32 PEIE : 1;    // Parity Error Interrupt Enable
    u32 PS : 1;      // Parity Selection
    u32 PCE : 1;     // Parity Control Enable
    u32 WAKE : 1;    // Wakeup method
    u32 M : 1;       // Word length
    u32	UE: 1;		//USART Enable
    u32	OVER8: 1;	//Sampling Config
    u32 Reserved:16;
} USART_CR1;


typedef struct {
    volatile u32 SR;   // Status Register
    volatile u32 DR;   // Data Register
    volatile u32 BRR;  // Baud Rate Register
    USART_CR1 CR1;  // Control Register 1
    volatile u32 CR2;  // Control Register 2
    volatile u32 CR3;  // Control Register 3
    volatile u32 GTPR; // Guard time and prescaler Register
} USART_MemMap_t;


#define USART_BASE_ADD	0x40011000
#define USART ((USART_MemMap_t *)USART_BASE_ADD)


#endif /* MCAL_MUSART_MUSART_PRIVATE_H_ */
