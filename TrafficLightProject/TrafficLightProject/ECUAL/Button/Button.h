/*
 * Button.h
 *
 * Created: 11/7/2022 3:49:11 PM
 *  Author: Dell
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_

#include "../../MCAL/DIO Driver/DIO.h"
void Button_init(uint8_t buttonPort,uint8_t buttonPin);
uint8_t Button_read(uint8_t buttonPort,uint8_t buttonPin);


#endif /* BUTTON_H_ */