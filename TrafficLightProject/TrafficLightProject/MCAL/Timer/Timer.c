/*
 * Timer.c
 *
 * Created: 11/7/2022 3:48:14 PM
 *  Author: Dell
 */ 

#include "Timer.h"
//Timer_init function to select the desired timer initializing sequence 
void Timer_init(uint8_t Timer,uint8_t Mode,uint16_t Prescaler,uint16_t initValue){
	switch(Timer){
		case 0:Timer0_init(Mode,Prescaler,initValue);
	}
}
//Timer0_init function is used to initialize Timer0 with the desired configuration
void Timer0_init(uint8_t Mode,uint16_t Prescaler,uint16_t initValue){
	switch(Mode){
		case 0:RESET_BIT(TCCR0,WGM00);RESET_BIT(TCCR0,WGM01);PrescaleTimer(0,Prescaler);Timer_initialValue(0,initValue);break;
		case 1:SET_BIT(TCCR0,WGM00);RESET_BIT(TCCR0,WGM01);PrescaleTimer(0,Prescaler);Timer_initialValue(0,initValue);break;
		case 2:RESET_BIT(TCCR0,WGM00);SET_BIT(TCCR0,WGM01);PrescaleTimer(0,Prescaler);Timer_initialValue(0,initValue);break;
		case 3:SET_BIT(TCCR0,WGM00);SET_BIT(TCCR0,WGM01);PrescaleTimer(0,Prescaler);Timer_initialValue(0,initValue);break;
	}
}
//PrescalerTimer function is used to set the Prescaler Value of the desired Timer
void PrescaleTimer(uint8_t Timer,uint16_t Prescaler){
	if(Timer==0){
			switch(Prescaler){
				case 0:SET_BIT(TCCR0,CS00);RESET_BIT(TCCR0,CS01);RESET_BIT(TCCR0,CS02);break;
				case 8:RESET_BIT(TCCR0,CS00);SET_BIT(TCCR0,CS01);RESET_BIT(TCCR0,CS02);break;
				case 64:SET_BIT(TCCR0,CS00);SET_BIT(TCCR0,CS01);RESET_BIT(TCCR0,CS02);break;
				case 256:RESET_BIT(TCCR0,CS00);RESET_BIT(TCCR0,CS01);SET_BIT(TCCR0,CS02);break;
				case 1024:SET_BIT(TCCR0,CS00);RESET_BIT(TCCR0,CS01);SET_BIT(TCCR0,CS02);break;
				default:RESET_BIT(TCCR0,CS00);RESET_BIT(TCCR0,CS01);RESET_BIT(TCCR0,CS02);break;
			}
	}
}
//Timer_initialValue is used to set the initialValue of the Timer if needed
void Timer_initialValue(uint8_t Timer,uint16_t initValue){
	switch(Timer){
		case 0:TCNT0=initValue;SET_BIT(TIMSK,TOIE0);break;	
	}
}
//TimerStop is used to Stop and reset the desired Timer through a switch statement
void TimerStop(uint8_t Timer){
	switch(Timer){
		case 0:RESET_BIT(TCCR0,CS00);RESET_BIT(TCCR0,CS01);RESET_BIT(TCCR0,CS02);SET_BIT(TIFR,0);break;
	}
}
//TimerStart is used to initialize and start the desired Timer through a switch statement
void TimerStart(uint8_t Timer,uint16_t Prescaler,uint16_t initValue){
	switch(Timer){
	case 0:PrescaleTimer(Timer,Prescaler);Timer_initialValue(Timer,initValue);break;
	}
}

void TimerTestFunction(){
	Timer_init(Timer0,Normal_Mode,1024,0);
}