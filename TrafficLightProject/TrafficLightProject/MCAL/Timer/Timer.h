/*
 * Timer.h
 *
 * Created: 11/7/2022 3:48:24 PM
 *  Author: Dell
 */ 


#ifndef TIMER_H_
#define TIMER_H_

#include "../../Utilities/Registers.h"
#include "../../Utilities/Types.h"
#define Normal_Mode 0
#define CTC 1
#define Fast_PWM 2
#define PhaseCorrect_PWM 3

#define Timer0 0
#define Timer1 1
#define Timer2 2

void Timer_init(uint8_t Timer,uint8_t Mode,uint16_t Prescaler,uint16_t initValue);
void Timer0_init(uint8_t Mode,uint16_t Prescaler,uint16_t initValue);
void PrescaleTimer(uint8_t Timer,uint16_t Prescaler);
void Timer_initialValue(uint8_t Timer,uint16_t initValue);
void TimerStart(uint8_t Timer,uint16_t Prescale,uint16_t initValue);
void TimerStop(uint8_t Timer);
#endif /* TIMER_H_ */