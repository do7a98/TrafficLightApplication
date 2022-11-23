/*
 * LED.c
 *
 * Created: 11/7/2022 3:48:50 PM
 *  Author: Dell
 */ 
#include "Button.h"
//Button_init function is used to set a digital Pin to be used as INPUT to be driven by a button
void Button_init(uint8_t buttonPort,uint8_t buttonPin){
	pinMode(buttonPort,buttonPin,INPUT);
}


//Button_read function is used to read the state of the Button and return it as a uint8_t
uint8_t Button_read(uint8_t buttonPort,uint8_t buttonPin){
	return digitalRead(buttonPort,buttonPin);
}
