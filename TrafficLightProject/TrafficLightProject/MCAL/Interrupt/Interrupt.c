/*
 * Interrupt.c
 *
 * Created: 11/7/2022 3:47:26 PM
 *  Author: Dell
 */ 

#include "Interrupt.h"
//ExternalInterrupt_init Function sets global interrupt flag then sits the corresponding Interrupt Pin Trigger signal and then enables it
void ExternalInterrupt_init(uint8_t InterruptPin,uint8_t Detection){
	SET_BIT(SREG,GIE);
	switch(InterruptPin){
		case 0:	if(Detection==RISING){SET_BIT(MCUCR,ISC00);SET_BIT(MCUCR,ISC01);}else if(Detection==FALLING){RESET_BIT(MCUCR,ISC00);SET_BIT(MCUCR,ISC01);}SET_BIT(GICR,INT0E);
		}
	}

void InterruptTestFunction(){
	ExternalInterrupt_init(INT0,RISING);
}
	
