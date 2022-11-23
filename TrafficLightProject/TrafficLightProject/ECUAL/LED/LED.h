/*
 * LED.h
 *
 * Created: 11/7/2022 3:48:31 PM
 *  Author: Dell
 */ 


#ifndef LED_H_
#define LED_H_

#include "../../MCAL/DIO Driver/DIO.h"

void LED_init(uint8_t ledPort, uint8_t ledPin);
void LED_on(uint8_t ledPort, uint8_t ledPin);
void LED_off(uint8_t ledPort, uint8_t ledPin);
void LED_toggle(uint8_t ledPort, uint8_t ledPin);




#endif /* LED_H_ */