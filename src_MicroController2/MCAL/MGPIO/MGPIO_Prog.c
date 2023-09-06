/*
 * MGPIO_Prog.c
 *
 *  Created on: Aug 10, 2023
 *      Author: DELL
 */

#include "../LIB/STD_Types.h"
#include "../LIB/BIT_Math.h"
#include "MGPIO_Config.h"
#include "MGPIO_Int.h"
#include "MGPIO_Private.h"



void MGPIO_vSetPinMode(u8 A_u8PortID,u8 A_u8PinNumber,u8 A_u8Mode){
	if(A_u8Mode==GPIO_MODE_INPUT){
		switch(A_u8PortID){
		case GPIO_PORTA:
			GPIOA -> MODER &= ~(0b11<<(A_u8PinNumber*2));
			GPIOA -> MODER |= (A_u8Mode<<(A_u8PinNumber));
			break;
		case GPIO_PORTB:
			GPIOB -> MODER &= ~(0b11<<(A_u8PinNumber*2));
			GPIOB -> MODER |= (A_u8Mode<<(A_u8PinNumber));
			break;
		case GPIO_PORTC:
			GPIOC -> MODER &= ~(0b11<<(A_u8PinNumber*2));
			GPIOC -> MODER |= (A_u8Mode<<(A_u8PinNumber));
			break;
		}
	}
	else if(A_u8Mode==GPIO_MODE_OUTPUT){
		switch(A_u8PortID){
		case GPIO_PORTA:
			GPIOA -> MODER &= ~(0b11<<(A_u8PinNumber*2));
			GPIOA -> MODER |= (A_u8Mode<<(A_u8PinNumber));
			break;
		case GPIO_PORTB:
			GPIOB -> MODER &= ~(0b11<<(A_u8PinNumber*2));
			GPIOB -> MODER |= (A_u8Mode<<(A_u8PinNumber));
			break;
		case GPIO_PORTC:
			GPIOC -> MODER &= ~(0b11<<(A_u8PinNumber*2));
			GPIOC -> MODER |= (A_u8Mode<<(A_u8PinNumber));
			break;
		}
	}
	else if(A_u8Mode==GPIO_MODE_ALT){
		switch(A_u8PortID){
		case GPIO_PORTA:
			GPIOA -> MODER &= ~(0b11<<(A_u8PinNumber*2));
			GPIOA -> MODER |= (A_u8Mode<<(A_u8PinNumber));
			break;
		case GPIO_PORTB:
			GPIOB -> MODER &= ~(0b11<<(A_u8PinNumber*2));
			GPIOB -> MODER |= (A_u8Mode<<(A_u8PinNumber));
			break;
		case GPIO_PORTC:
			GPIOC -> MODER &= ~(0b11<<(A_u8PinNumber*2));
			GPIOC -> MODER |= (A_u8Mode<<(A_u8PinNumber));
			break;
		}
	}
	else if(A_u8Mode==GPIO_MODE_ANALOG){
		switch(A_u8PortID){
		case GPIO_PORTA:
			GPIOA -> MODER &= ~(0b11<<(A_u8PinNumber*2));
			GPIOA -> MODER |= (A_u8Mode<<(A_u8PinNumber));
			break;
		case GPIO_PORTB:
			GPIOB -> MODER &= ~(0b11<<(A_u8PinNumber*2));
			GPIOB -> MODER |= (A_u8Mode<<(A_u8PinNumber));
			break;
		case GPIO_PORTC:
			GPIOC -> MODER &= ~(0b11<<(A_u8PinNumber*2));
			GPIOC -> MODER |= (A_u8Mode<<(A_u8PinNumber));
			break;
		}
	}
}

/*Input*/

void MGPIO_vSetPinOutputType(u8 A_u8PortID,u8 A_u8PinNumber,u8 A_u8Direction){
	if(A_u8Direction==GPIO_OPEN_DRAIN){
		switch(A_u8PortID){
			case (GPIO_PORTA):
				SET_BIT(GPIOA->OTYPER,A_u8PinNumber);
				break;
			case (GPIO_PORTB):
				SET_BIT(GPIOB->OTYPER,A_u8PinNumber);
				break;
			case (GPIO_PORTC):
				SET_BIT(GPIOC->OTYPER,A_u8PinNumber);
				break;
		}
	}
	if(A_u8Direction==GPIO_PUSHPULL){
		switch(A_u8PortID){
			case (GPIO_PORTA):
				CLEAR_BIT(GPIOA->OTYPER,A_u8PinNumber);
				break;
			case (GPIO_PORTB):
				CLEAR_BIT(GPIOB->OTYPER,A_u8PinNumber);
				break;
			case (GPIO_PORTC):
				CLEAR_BIT(GPIOC->OTYPER,A_u8PinNumber);
				break;
		}
	}
}


u8 MGPIO_u8GetPinValue(u8 A_u8PortID, u8 A_u8PinNumber) {
    u8 u8_PinValue = 0;
    switch (A_u8PortID) {
        case GPIO_PORTA:
        	u8_PinValue = GET_BIT(GPIOA->IDR, A_u8PinNumber);
            break;
        case GPIO_PORTB:
        	u8_PinValue = GET_BIT(GPIOB->IDR, A_u8PinNumber);
            break;
        case GPIO_PORTC:
        	u8_PinValue = GET_BIT(GPIOC->IDR, A_u8PinNumber);
            break;
        default:
            break;
    }

    return u8_PinValue;
}



void MGPIO_vSetPinInputPull(u8 A_u8PortID,u8 A_u8PinNumber,u8 A_u8OutPutType){
	if(A_u8OutPutType==GPIO_PULLUP){
		switch(A_u8PortID){
		case GPIO_PORTA:
			GPIOA -> PUPDR &= ~(0b11<<(A_u8PinNumber*2));
			GPIOA -> PUPDR |= (A_u8OutPutType<<(A_u8PinNumber));
			break;
		case GPIO_PORTB:
			GPIOB -> PUPDR &= ~(0b11<<(A_u8PinNumber*2));
			GPIOB -> PUPDR |= (A_u8OutPutType<<(A_u8PinNumber));
			break;
		case GPIO_PORTC:
			GPIOC -> PUPDR &= ~(0b11<<(A_u8PinNumber*2));
			GPIOC -> PUPDR |= (A_u8OutPutType<<(A_u8PinNumber));
			break;
		}
	}
	else if(A_u8OutPutType==GPIO_PULLDOWN){
		switch(A_u8PortID){
		case GPIO_PORTA:
			GPIOA -> PUPDR &= ~(0b11<<(A_u8PinNumber*2));
			GPIOA -> PUPDR |= (A_u8OutPutType<<(A_u8PinNumber));
			break;
		case GPIO_PORTB:
			GPIOB -> PUPDR &= ~(0b11<<(A_u8PinNumber*2));
			GPIOB -> PUPDR |= (A_u8OutPutType<<(A_u8PinNumber));
			break;
		case GPIO_PORTC:
			GPIOC -> PUPDR &= ~(0b11<<(A_u8PinNumber*2));
			GPIOC -> PUPDR |= (A_u8OutPutType<<(A_u8PinNumber));
			break;
		}
	}
}

void MGPIO_vSetPinOutPutSpeed(u8 A_u8PortID,u8 A_u8PinNumber,u8 A_u8A_Speed){
	if(A_u8A_Speed==GPIO_LOW_SPEED){
		switch(A_u8PortID){
		case (GPIO_PORTA):
			GPIOA -> OSPEEDR &= ~(0b11<<(A_u8PinNumber*2));
			GPIOA -> OSPEEDR |= (A_u8A_Speed<<(A_u8PinNumber));
			break;
		case GPIO_PORTB:
			GPIOB -> OSPEEDR &= ~(0b11<<(A_u8PinNumber*2));
			GPIOB -> OSPEEDR |= (A_u8A_Speed<<(A_u8PinNumber));
			break;
		case GPIO_PORTC:
			GPIOC -> OSPEEDR &= ~(0b11<<(A_u8PinNumber*2));
			GPIOC -> OSPEEDR |= (A_u8A_Speed<<(A_u8PinNumber));
			break;
		}
	}
	else if(A_u8A_Speed==GPIO_MEDIUM_SPEED){
		switch(A_u8PortID){
		case GPIO_PORTA:
			GPIOA -> OSPEEDR &= ~(0b11<<(A_u8PinNumber*2));
			GPIOA -> OSPEEDR |= (A_u8A_Speed<<(A_u8PinNumber));
			break;
		case GPIO_PORTB:
			GPIOB -> OSPEEDR &= ~(0b11<<(A_u8PinNumber*2));
			GPIOB -> OSPEEDR |= (A_u8A_Speed<<(A_u8PinNumber));
			break;
		case GPIO_PORTC:
			GPIOC -> OSPEEDR &= ~(0b11<<(A_u8PinNumber*2));
			GPIOC -> OSPEEDR |= (A_u8A_Speed<<(A_u8PinNumber));
			break;
		}
	}
	else if(A_u8A_Speed==GPIO_HIGH_SPEED){
		switch(A_u8PortID){
		case GPIO_PORTA:
			GPIOA -> OSPEEDR &= ~(0b11<<(A_u8PinNumber*2));
			GPIOA -> OSPEEDR |= (A_u8A_Speed<<(A_u8PinNumber));
			break;
		case GPIO_PORTB:
			GPIOB -> OSPEEDR &= ~(0b11<<(A_u8PinNumber*2));
			GPIOB -> OSPEEDR |= (A_u8A_Speed<<(A_u8PinNumber));
			break;
		case GPIO_PORTC:
			GPIOC -> OSPEEDR &= ~(0b11<<(A_u8PinNumber*2));
			GPIOC -> OSPEEDR |= (A_u8A_Speed<<(A_u8PinNumber));
			break;
		}
	}
	else if(A_u8A_Speed==GPIO_VERY_HIGH_SPEED){
		switch(A_u8PortID){
		case GPIO_PORTA:
			GPIOA -> OSPEEDR &= ~(0b11<<(A_u8PinNumber*2));
			GPIOA -> OSPEEDR |= (A_u8A_Speed<<(A_u8PinNumber));
			break;
		case GPIO_PORTB:
			GPIOB -> OSPEEDR &= ~(0b11<<(A_u8PinNumber*2));
			GPIOB -> OSPEEDR |= (A_u8A_Speed<<(A_u8PinNumber));
			break;
		case GPIO_PORTC:
			GPIOC -> OSPEEDR &= ~(0b11<<(A_u8PinNumber*2));
			GPIOC -> OSPEEDR |= (A_u8A_Speed<<(A_u8PinNumber));
			break;
		}
	}
}


void MGPIO_vSetPinValue(u8 A_u8PortID, u8 A_u8PinNumber, u8 A_u8PinValue) {
    switch (A_u8PortID) {
        case GPIO_PORTA:
            if (A_u8PinValue == GPIO_HIGH) {
                SET_BIT(GPIOA->ODR, A_u8PinNumber);
            } else if (A_u8PinValue == GPIO_LOW) {
                CLEAR_BIT(GPIOA->ODR, A_u8PinNumber);
            }
            break;

        case GPIO_PORTB:
            if (A_u8PinValue == GPIO_HIGH) {
                SET_BIT(GPIOB->ODR, A_u8PinNumber);
            } else if (A_u8PinValue == GPIO_LOW) {
                CLEAR_BIT(GPIOB->ODR, A_u8PinNumber);
            }
            break;

        case GPIO_PORTC:
            if (A_u8PinValue == GPIO_HIGH) {
                SET_BIT(GPIOC->ODR, A_u8PinNumber);
            } else if (A_u8PinValue == GPIO_LOW) {
                CLEAR_BIT(GPIOC->ODR, A_u8PinNumber);
            }
            break;

        default:
            break;
    }
}


void MGPIO_vSetPinValueFast(u8 A_u8PortID,u8 A_u8PinNumber,u8 A_u8PinValue){
				/*SET_BIT_FAST(REG,BIT_NUM) (REG=1<<BIT_NUM)
				 * Added to the BIT_Math.h */
    switch (A_u8PortID) {
        case GPIO_PORTA:
            if (A_u8PinValue == GPIO_HIGH) {
                SET_BIT_FAST(GPIOA->BSRR, A_u8PinNumber);
            } else if (A_u8PinValue == GPIO_LOW) {
            	SET_BIT_FAST(GPIOA->BSRR, (A_u8PinNumber+16));
            }
            break;

        case GPIO_PORTB:
            if (A_u8PinValue == GPIO_HIGH) {
                SET_BIT(GPIOB->BSRR, A_u8PinNumber);
            } else if (A_u8PinValue == GPIO_LOW) {
            	SET_BIT_FAST(GPIOB->BSRR, (A_u8PinNumber+16));
            }
            break;

        case GPIO_PORTC:
            if (A_u8PinValue == GPIO_HIGH) {
            	SET_BIT_FAST(GPIOC->BSRR, A_u8PinNumber);
            } else if (A_u8PinValue == GPIO_LOW) {
            	SET_BIT_FAST(GPIOC->BSRR, (A_u8PinNumber+16));
            }
            break;

        default:
            break;
    }
}	/*BSRR*/

void MGPIO_vSetAlternativeFunction(u8 A_u8PortID,u8 A_u8PinNumber,u8 A_u8AlternateFunction){
if(A_u8PinNumber>=7){
	if(A_u8PortID==GPIO_PORTA){
		switch(A_u8AlternateFunction){
		case AF0:
			GPIOA -> AFRL &= ~(0b1111<<(A_u8PinNumber*4));
			GPIOA -> AFRL |= (A_u8AlternateFunction<<(A_u8PinNumber));
			break;
		case AF1:
			GPIOA -> AFRL &= ~(0b1111<<(A_u8PinNumber*4));
			GPIOA -> AFRL |= (A_u8AlternateFunction<<(A_u8PinNumber));
			break;
		case AF2:
			GPIOA -> AFRL &= ~(0b1111<<(A_u8PinNumber*4));
			GPIOA -> AFRL |= (A_u8AlternateFunction<<(A_u8PinNumber));
			break;
		case AF3:
			GPIOA -> AFRL &= ~(0b1111<<(A_u8PinNumber*4));
			GPIOA -> AFRL |= (A_u8AlternateFunction<<(A_u8PinNumber));
			break;
		case AF4:
			GPIOA -> AFRL &= ~(0b1111<<(A_u8PinNumber*4));
			GPIOA -> AFRL |= (A_u8AlternateFunction<<(A_u8PinNumber));
			break;
		case AF5:
			GPIOA -> AFRL &= ~(0b1111<<(A_u8PinNumber*4));
			GPIOA -> AFRL |= (A_u8AlternateFunction<<(A_u8PinNumber));
			break;
		case AF6:
			GPIOA -> AFRL &= ~(0b1111<<(A_u8PinNumber*4));
			GPIOA -> AFRL |= (A_u8AlternateFunction<<(A_u8PinNumber));
			break;
		case AF7:
			GPIOA -> AFRL &= ~(0b1111<<(A_u8PinNumber*4));
			GPIOA -> AFRL |= (A_u8AlternateFunction<<(A_u8PinNumber));
			break;
		}
	}
	else if(A_u8PortID==GPIO_PORTB){
		switch(A_u8AlternateFunction){
		case AF0:
			GPIOB -> AFRL &= ~(0b1111<<(A_u8PinNumber*4));
			GPIOB -> AFRL |= (A_u8AlternateFunction<<(A_u8PinNumber));
			break;
		case AF1:
			GPIOB -> AFRL &= ~(0b1111<<(A_u8PinNumber*4));
			GPIOB -> AFRL |= (A_u8AlternateFunction<<(A_u8PinNumber));
			break;
		case AF2:
			GPIOB -> AFRL &= ~(0b1111<<(A_u8PinNumber*4));
			GPIOB -> AFRL |= (A_u8AlternateFunction<<(A_u8PinNumber));
			break;
		case AF3:
			GPIOB -> AFRL &= ~(0b1111<<(A_u8PinNumber*4));
			GPIOB -> AFRL |= (A_u8AlternateFunction<<(A_u8PinNumber));
			break;
		case AF4:
			GPIOB -> AFRL &= ~(0b1111<<(A_u8PinNumber*4));
			GPIOB -> AFRL |= (A_u8AlternateFunction<<(A_u8PinNumber));
			break;
		case AF5:
			GPIOB -> AFRL &= ~(0b1111<<(A_u8PinNumber*4));
			GPIOB -> AFRL |= (A_u8AlternateFunction<<(A_u8PinNumber));
			break;
		case AF6:
			GPIOB -> AFRL &= ~(0b1111<<(A_u8PinNumber*4));
			GPIOB -> AFRL |= (A_u8AlternateFunction<<(A_u8PinNumber));
			break;
		case AF7:
			GPIOB -> AFRL &= ~(0b1111<<(A_u8PinNumber*4));
			GPIOB -> AFRL |= (A_u8AlternateFunction<<(A_u8PinNumber));
			break;
		}
	}
	else if(A_u8PortID==GPIO_PORTC){
		switch(A_u8AlternateFunction){
		case AF0:
			GPIOC -> AFRL &= ~(0b1111<<(A_u8PinNumber*4));
			GPIOC -> AFRL |= (A_u8AlternateFunction<<(A_u8PinNumber));
			break;
		case AF1:
			GPIOC -> AFRL &= ~(0b1111<<(A_u8PinNumber*4));
			GPIOC -> AFRL |= (A_u8AlternateFunction<<(A_u8PinNumber));
			break;
		case AF2:
			GPIOC -> AFRL &= ~(0b1111<<(A_u8PinNumber*4));
			GPIOC -> AFRL |= (A_u8AlternateFunction<<(A_u8PinNumber));
			break;
		case AF3:
			GPIOC -> AFRL &= ~(0b1111<<(A_u8PinNumber*4));
			GPIOC -> AFRL |= (A_u8AlternateFunction<<(A_u8PinNumber));
			break;
		case AF4:
			GPIOC -> AFRL &= ~(0b1111<<(A_u8PinNumber*4));
			GPIOC -> AFRL |= (A_u8AlternateFunction<<(A_u8PinNumber));
			break;
		case AF5:
			GPIOC -> AFRL &= ~(0b1111<<(A_u8PinNumber*4));
			GPIOC -> AFRL |= (A_u8AlternateFunction<<(A_u8PinNumber));
			break;
		case AF6:
			GPIOC -> AFRL &= ~(0b1111<<(A_u8PinNumber*4));
			GPIOC -> AFRL |= (A_u8AlternateFunction<<(A_u8PinNumber));
			break;
		case AF7:
			GPIOC -> AFRL &= ~(0b1111<<(A_u8PinNumber*4));
			GPIOC -> AFRL |= (A_u8AlternateFunction<<(A_u8PinNumber));
			break;
		}
	}
}
else{
	/*The rest of the pins from 8 to 15 and the register will be AFRH*/
	if(A_u8PortID==GPIO_PORTA){
			switch(A_u8AlternateFunction){
			case AF0:
				GPIOA -> AFRH &= ~(0b1111<<(A_u8PinNumber*4));
				GPIOA -> AFRH |= (A_u8AlternateFunction<<(A_u8PinNumber));
				break;
			case AF1:
				GPIOA -> AFRH &= ~(0b1111<<(A_u8PinNumber*4));
				GPIOA -> AFRH |= (A_u8AlternateFunction<<(A_u8PinNumber));
				break;
			case AF2:
				GPIOA -> AFRH &= ~(0b1111<<(A_u8PinNumber*4));
				GPIOA -> AFRH |= (A_u8AlternateFunction<<(A_u8PinNumber));
				break;
			case AF3:
				GPIOA -> AFRH &= ~(0b1111<<(A_u8PinNumber*4));
				GPIOA -> AFRH |= (A_u8AlternateFunction<<(A_u8PinNumber));
				break;
			case AF4:
				GPIOA -> AFRH &= ~(0b1111<<(A_u8PinNumber*4));
				GPIOA -> AFRH |= (A_u8AlternateFunction<<(A_u8PinNumber));
				break;
			case AF5:
				GPIOA -> AFRH &= ~(0b1111<<(A_u8PinNumber*4));
				GPIOA -> AFRH |= (A_u8AlternateFunction<<(A_u8PinNumber));
				break;
			case AF6:
				GPIOA -> AFRH &= ~(0b1111<<(A_u8PinNumber*4));
				GPIOA -> AFRH |= (A_u8AlternateFunction<<(A_u8PinNumber));
				break;
			case AF7:
				GPIOA -> AFRH &= ~(0b1111<<(A_u8PinNumber*4));
				GPIOA -> AFRH |= (A_u8AlternateFunction<<(A_u8PinNumber));
				break;
			}
		}
		else if(A_u8PortID==GPIO_PORTB){
			switch(A_u8AlternateFunction){
			case AF0:
				GPIOB -> AFRH &= ~(0b1111<<(A_u8PinNumber*4));
				GPIOB -> AFRH |= (A_u8AlternateFunction<<(A_u8PinNumber));
				break;
			case AF1:
				GPIOB -> AFRH &= ~(0b1111<<(A_u8PinNumber*4));
				GPIOB -> AFRH |= (A_u8AlternateFunction<<(A_u8PinNumber));
				break;
			case AF2:
				GPIOB -> AFRH &= ~(0b1111<<(A_u8PinNumber*4));
				GPIOB -> AFRH |= (A_u8AlternateFunction<<(A_u8PinNumber));
				break;
			case AF3:
				GPIOB -> AFRH &= ~(0b1111<<(A_u8PinNumber*4));
				GPIOB -> AFRH |= (A_u8AlternateFunction<<(A_u8PinNumber));
				break;
			case AF4:
				GPIOB -> AFRH &= ~(0b1111<<(A_u8PinNumber*4));
				GPIOB -> AFRH |= (A_u8AlternateFunction<<(A_u8PinNumber));
				break;
			case AF5:
				GPIOB -> AFRH &= ~(0b1111<<(A_u8PinNumber*4));
				GPIOB -> AFRH |= (A_u8AlternateFunction<<(A_u8PinNumber));
				break;
			case AF6:
				GPIOB -> AFRH &= ~(0b1111<<(A_u8PinNumber*4));
				GPIOB -> AFRH |= (A_u8AlternateFunction<<(A_u8PinNumber));
				break;
			case AF7:
				GPIOB -> AFRH &= ~(0b1111<<(A_u8PinNumber*4));
				GPIOB -> AFRH |= (A_u8AlternateFunction<<(A_u8PinNumber));
				break;
			}
		}
		else if(A_u8PortID==GPIO_PORTC){
			switch(A_u8AlternateFunction){
			case AF0:
				GPIOC -> AFRH &= ~(0b1111<<(A_u8PinNumber*4));
				GPIOC -> AFRH |= (A_u8AlternateFunction<<(A_u8PinNumber));
				break;
			case AF1:
				GPIOC -> AFRH &= ~(0b1111<<(A_u8PinNumber*4));
				GPIOC -> AFRH |= (A_u8AlternateFunction<<(A_u8PinNumber));
				break;
			case AF2:
				GPIOC -> AFRH &= ~(0b1111<<(A_u8PinNumber*4));
				GPIOC -> AFRH |= (A_u8AlternateFunction<<(A_u8PinNumber));
				break;
			case AF3:
				GPIOC -> AFRH &= ~(0b1111<<(A_u8PinNumber*4));
				GPIOC -> AFRH |= (A_u8AlternateFunction<<(A_u8PinNumber));
				break;
			case AF4:
				GPIOC -> AFRH &= ~(0b1111<<(A_u8PinNumber*4));
				GPIOC -> AFRH |= (A_u8AlternateFunction<<(A_u8PinNumber));
				break;
			case AF5:
				GPIOC -> AFRH &= ~(0b1111<<(A_u8PinNumber*4));
				GPIOC -> AFRH |= (A_u8AlternateFunction<<(A_u8PinNumber));
				break;
			case AF6:
				GPIOC -> AFRH &= ~(0b1111<<(A_u8PinNumber*4));
				GPIOC -> AFRH |= (A_u8AlternateFunction<<(A_u8PinNumber));
				break;
			case AF7:
				GPIOC -> AFRH &= ~(0b1111<<(A_u8PinNumber*4));
				GPIOC -> AFRH |= (A_u8AlternateFunction<<(A_u8PinNumber));
				break;
			}
		}
}

}


