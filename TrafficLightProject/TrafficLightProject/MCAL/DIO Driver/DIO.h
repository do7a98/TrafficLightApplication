/*
 * DIO.h
 *
 * Created: 11/7/2022 3:47:52 PM
 *  Author: Dell
 */ 


#ifndef DIO_H_
#define DIO_H_

#include "../../Utilities/Registers.h"

#define PORT_A 'A'
#define PORT_B 'B'
#define PORT_C 'C'
#define PORT_D 'D'

#define INPUT 0
#define OUTPUT 1


#define LOW 0
#define HIGH 1

void pinMode(uint8_t portName,uint8_t pinNumber,uint8_t Mode);
void digitalWrite(uint8_t portName,uint8_t pinNumber,uint8_t Value);
void digitalToggle(uint8_t portName,uint8_t pinNumber);
uint8_t digitalRead(uint8_t portName,uint8_t pinNumber);
#endif /* DIO_H_ */