/*
 * DIO.c
 *
 * Created: 11/7/2022 3:48:02 PM
 *  Author: Dell
 */ 
#include "DIO.h"
//pinMode Function enters switch statement to decide which pin in which port is set as input or output
void pinMode(uint8_t portName,uint8_t pinNumber,uint8_t Mode){
	switch(portName){
		case 'A':if(Mode == OUTPUT){DDRA |=(1<<pinNumber);}else if(Mode == INPUT){DDRA &=~(1<<pinNumber);}break;
		case 'B':if(Mode == OUTPUT){DDRB |=(1<<pinNumber);}else if(Mode == INPUT){DDRB &=~(1<<pinNumber);}break;
		case 'C':if(Mode == OUTPUT){DDRC |=(1<<pinNumber);}else if(Mode == INPUT){DDRC &=~(1<<pinNumber);}break;
		case 'D':if(Mode == OUTPUT){DDRD |=(1<<pinNumber);}else if(Mode == INPUT){DDRD &=~(1<<pinNumber);}break;
	}
}
//digitalWrite Function enters switch statement to decide which pin to Output a digital HIGH or LOW signal
void digitalWrite(uint8_t portName,uint8_t pinNumber,uint8_t Value){
	switch(portName){
		case 'A':if(Value == HIGH){PORTA |=(1<<pinNumber);}else if(Value == LOW){PORTA &=~(1<<pinNumber);}break;
		case 'B':if(Value == HIGH){PORTB |=(1<<pinNumber);}else if(Value== LOW){PORTB &=~(1<<pinNumber);}break;
		case 'C':if(Value == HIGH){PORTC |=(1<<pinNumber);}else if(Value == LOW){PORTC &=~(1<<pinNumber);}break;
		case 'D':if(Value == HIGH){PORTD |=(1<<pinNumber);}else if(Value == LOW){PORTD &=~(1<<pinNumber);}break;
	}	
}
//digitalRead Function enters switch statement to decide which pin to read its digital state and return it
uint8_t digitalRead(uint8_t portName,uint8_t pinNumber){
		uint8_t pinState=0;
		switch(portName){
			case 'A':pinState=(PINA&(1<<pinNumber))>>pinNumber;break;
			case 'B':pinState=(PINB&(1<<pinNumber))>>pinNumber;break;
			case 'C':pinState=(PINC&(1<<pinNumber))>>pinNumber;break;
			case 'D':pinState=(PIND&(1<<pinNumber))>>pinNumber;break;
		}
		return pinState;
}
//digitalToggle Function enters switch statement to decide which pin to toggle its digital State
void digitalToggle(uint8_t portName,uint8_t pinNumber){
			switch(portName){
				case 'A':PORTA^=(1<<pinNumber);break;
				case 'B':PORTB^=(1<<pinNumber);break;
				case 'C':PORTC^=(1<<pinNumber);break;
				case 'D':PORTD^=(1<<pinNumber);break;
			}
}

void DIOTestFunctionForOutput(){
	pinMode(PORT_A,0,OUTPUT);
	pinMode(PORT_A,1,OUTPUT);
	pinMode(PORT_A,2,OUTPUT);
	pinMode(PORT_A,3,OUTPUT);
	pinMode(PORT_A,4,OUTPUT);
	pinMode(PORT_A,5,OUTPUT);
	pinMode(PORT_A,6,OUTPUT);
	pinMode(PORT_A,7,OUTPUT);
	pinMode(PORT_B,0,OUTPUT);
	pinMode(PORT_B,1,OUTPUT);
	pinMode(PORT_B,2,OUTPUT);
	pinMode(PORT_B,3,OUTPUT);
	pinMode(PORT_B,4,OUTPUT);
	pinMode(PORT_B,5,OUTPUT);
	pinMode(PORT_B,6,OUTPUT);
	pinMode(PORT_B,7,OUTPUT);
	pinMode(PORT_C,0,OUTPUT);
	pinMode(PORT_C,1,OUTPUT);
	pinMode(PORT_C,2,OUTPUT);
	pinMode(PORT_C,3,OUTPUT);
	pinMode(PORT_C,4,OUTPUT);
	pinMode(PORT_C,5,OUTPUT);
	pinMode(PORT_C,6,OUTPUT);
	pinMode(PORT_C,7,OUTPUT);
	pinMode(PORT_D,0,OUTPUT);
	pinMode(PORT_D,1,OUTPUT);
	pinMode(PORT_D,2,OUTPUT);
	pinMode(PORT_D,3,OUTPUT);
	pinMode(PORT_D,4,OUTPUT);
	pinMode(PORT_D,5,OUTPUT);
	pinMode(PORT_D,6,OUTPUT);
	pinMode(PORT_D,7,OUTPUT);
	digitalWrite(PORT_A,0,HIGH);
	digitalWrite(PORT_A,1,HIGH);
	digitalWrite(PORT_A,2,HIGH);
	digitalWrite(PORT_A,3,HIGH);
	digitalWrite(PORT_A,4,HIGH);
	digitalWrite(PORT_A,5,HIGH);
	digitalWrite(PORT_A,6,HIGH);
	digitalWrite(PORT_A,7,HIGH);
	digitalWrite(PORT_B,0,HIGH);
	digitalWrite(PORT_B,1,HIGH);
	digitalWrite(PORT_B,2,HIGH);
	digitalWrite(PORT_B,3,HIGH);
	digitalWrite(PORT_B,4,HIGH);
	digitalWrite(PORT_B,5,HIGH);
	digitalWrite(PORT_B,6,HIGH);
	digitalWrite(PORT_B,7,HIGH);
	digitalWrite(PORT_C,0,HIGH);
	digitalWrite(PORT_C,1,HIGH);
	digitalWrite(PORT_C,2,HIGH);
	digitalWrite(PORT_C,3,HIGH);
	digitalWrite(PORT_C,4,HIGH);
	digitalWrite(PORT_C,5,HIGH);
	digitalWrite(PORT_C,6,HIGH);
	digitalWrite(PORT_C,7,HIGH);
	digitalWrite(PORT_D,0,HIGH);
	digitalWrite(PORT_D,1,HIGH);
	digitalWrite(PORT_D,2,HIGH);
	digitalWrite(PORT_D,3,HIGH);
	digitalWrite(PORT_D,4,HIGH);
	digitalWrite(PORT_D,5,HIGH);
	digitalWrite(PORT_D,6,HIGH);
	digitalWrite(PORT_D,7,HIGH);
}
void DIOTestFunctionForInputA(){
		pinMode(PORT_A,0,INPUT);
		pinMode(PORT_A,1,INPUT);
		pinMode(PORT_A,2,INPUT);
		pinMode(PORT_A,3,INPUT);
		pinMode(PORT_A,4,INPUT);
		pinMode(PORT_A,5,INPUT);
		pinMode(PORT_A,6,INPUT);
		pinMode(PORT_A,7,INPUT);
		pinMode(PORT_D,0,OUTPUT);
		pinMode(PORT_D,1,OUTPUT);
		pinMode(PORT_D,2,OUTPUT);
		pinMode(PORT_D,3,OUTPUT);
		pinMode(PORT_D,4,OUTPUT);
		pinMode(PORT_D,5,OUTPUT);
		pinMode(PORT_D,6,OUTPUT);
		pinMode(PORT_D,7,OUTPUT);
		digitalWrite(PORT_D,0,digitalRead(PORT_A,0));
		digitalWrite(PORT_D,1,digitalRead(PORT_A,1));
		digitalWrite(PORT_D,2,digitalRead(PORT_A,2));
		digitalWrite(PORT_D,3,digitalRead(PORT_A,3));
		digitalWrite(PORT_D,4,digitalRead(PORT_A,4));
		digitalWrite(PORT_D,5,digitalRead(PORT_A,5));
		digitalWrite(PORT_D,6,digitalRead(PORT_A,6));
		digitalWrite(PORT_D,7,digitalRead(PORT_A,7));		
}
void DIOTestFunctionForInputB(){
	pinMode(PORT_B,0,INPUT);
	pinMode(PORT_B,1,INPUT);
	pinMode(PORT_B,2,INPUT);
	pinMode(PORT_B,3,INPUT);
	pinMode(PORT_B,4,INPUT);
	pinMode(PORT_B,5,INPUT);
	pinMode(PORT_B,6,INPUT);
	pinMode(PORT_B,7,INPUT);
	pinMode(PORT_C,0,OUTPUT);
	pinMode(PORT_C,1,OUTPUT);
	pinMode(PORT_C,2,OUTPUT);
	pinMode(PORT_C,3,OUTPUT);
	pinMode(PORT_C,4,OUTPUT);
	pinMode(PORT_C,5,OUTPUT);
	pinMode(PORT_C,6,OUTPUT);
	pinMode(PORT_C,7,OUTPUT);
	digitalWrite(PORT_C,0,digitalRead(PORT_B,0));
	digitalWrite(PORT_C,1,digitalRead(PORT_B,1));
	digitalWrite(PORT_C,2,digitalRead(PORT_B,2));
	digitalWrite(PORT_C,3,digitalRead(PORT_B,3));
	digitalWrite(PORT_C,4,digitalRead(PORT_B,4));
	digitalWrite(PORT_C,5,digitalRead(PORT_B,5));
	digitalWrite(PORT_C,6,digitalRead(PORT_B,6));
	digitalWrite(PORT_C,7,digitalRead(PORT_B,7));
}
void DIOTestFunctionForInputC(){
	pinMode(PORT_C,0,INPUT);
	pinMode(PORT_C,1,INPUT);
	pinMode(PORT_C,2,INPUT);
	pinMode(PORT_C,3,INPUT);
	pinMode(PORT_C,4,INPUT);
	pinMode(PORT_C,5,INPUT);
	pinMode(PORT_C,6,INPUT);
	pinMode(PORT_C,7,INPUT);
	pinMode(PORT_B,0,OUTPUT);
	pinMode(PORT_B,1,OUTPUT);
	pinMode(PORT_B,2,OUTPUT);
	pinMode(PORT_B,3,OUTPUT);
	pinMode(PORT_B,4,OUTPUT);
	pinMode(PORT_B,5,OUTPUT);
	pinMode(PORT_B,6,OUTPUT);
	pinMode(PORT_B,7,OUTPUT);
	digitalWrite(PORT_B,0,digitalRead(PORT_C,0));
	digitalWrite(PORT_B,1,digitalRead(PORT_C,1));
	digitalWrite(PORT_B,2,digitalRead(PORT_C,2));
	digitalWrite(PORT_B,3,digitalRead(PORT_C,3));
	digitalWrite(PORT_B,4,digitalRead(PORT_C,4));
	digitalWrite(PORT_B,5,digitalRead(PORT_C,5));
	digitalWrite(PORT_B,6,digitalRead(PORT_C,6));
	digitalWrite(PORT_B,7,digitalRead(PORT_C,7));
}
void DIOTestFunctionForInputD(){
	pinMode(PORT_D,0,INPUT);
	pinMode(PORT_D,1,INPUT);
	pinMode(PORT_D,2,INPUT);
	pinMode(PORT_D,3,INPUT);
	pinMode(PORT_D,4,INPUT);
	pinMode(PORT_D,5,INPUT);
	pinMode(PORT_D,6,INPUT);
	pinMode(PORT_D,7,INPUT);
	pinMode(PORT_A,0,OUTPUT);
	pinMode(PORT_A,1,OUTPUT);
	pinMode(PORT_A,2,OUTPUT);
	pinMode(PORT_A,3,OUTPUT);
	pinMode(PORT_A,4,OUTPUT);
	pinMode(PORT_A,5,OUTPUT);
	pinMode(PORT_A,6,OUTPUT);
	pinMode(PORT_A,7,OUTPUT);
	digitalWrite(PORT_A,0,digitalRead(PORT_D,0));
	digitalWrite(PORT_A,1,digitalRead(PORT_D,1));
	digitalWrite(PORT_A,2,digitalRead(PORT_D,2));
	digitalWrite(PORT_A,3,digitalRead(PORT_D,3));
	digitalWrite(PORT_A,4,digitalRead(PORT_D,4));
	digitalWrite(PORT_A,5,digitalRead(PORT_D,5));
	digitalWrite(PORT_A,6,digitalRead(PORT_D,6));
	digitalWrite(PORT_A,7,digitalRead(PORT_D,7));
}
void DIOTestFunctionToggle(){
	pinMode(PORT_A,0,OUTPUT);
	pinMode(PORT_A,1,OUTPUT);
	pinMode(PORT_A,2,OUTPUT);
	pinMode(PORT_A,3,OUTPUT);
	pinMode(PORT_A,4,OUTPUT);
	pinMode(PORT_A,5,OUTPUT);
	pinMode(PORT_A,6,OUTPUT);
	pinMode(PORT_A,7,OUTPUT);
	pinMode(PORT_B,0,OUTPUT);
	pinMode(PORT_B,1,OUTPUT);
	pinMode(PORT_B,2,OUTPUT);
	pinMode(PORT_B,3,OUTPUT);
	pinMode(PORT_B,4,OUTPUT);
	pinMode(PORT_B,5,OUTPUT);
	pinMode(PORT_B,6,OUTPUT);
	pinMode(PORT_B,7,OUTPUT);
	pinMode(PORT_C,0,OUTPUT);
	pinMode(PORT_C,1,OUTPUT);
	pinMode(PORT_C,2,OUTPUT);
	pinMode(PORT_C,3,OUTPUT);
	pinMode(PORT_C,4,OUTPUT);
	pinMode(PORT_C,5,OUTPUT);
	pinMode(PORT_C,6,OUTPUT);
	pinMode(PORT_C,7,OUTPUT);
	pinMode(PORT_D,0,OUTPUT);
	pinMode(PORT_D,1,OUTPUT);
	pinMode(PORT_D,2,OUTPUT);
	pinMode(PORT_D,3,OUTPUT);
	pinMode(PORT_D,4,OUTPUT);
	pinMode(PORT_D,5,OUTPUT);
	pinMode(PORT_D,6,OUTPUT);
	pinMode(PORT_D,7,OUTPUT);
digitalToggle(PORT_A,0);
digitalToggle(PORT_A,1);
digitalToggle(PORT_A,2);
digitalToggle(PORT_A,3);
digitalToggle(PORT_A,4);
digitalToggle(PORT_A,5);
digitalToggle(PORT_A,6);
digitalToggle(PORT_A,7);
digitalToggle(PORT_B,0);
digitalToggle(PORT_B,1);
digitalToggle(PORT_B,2);
digitalToggle(PORT_B,3);
digitalToggle(PORT_B,4);
digitalToggle(PORT_B,5);
digitalToggle(PORT_B,6);
digitalToggle(PORT_B,7);
digitalToggle(PORT_C,0);
digitalToggle(PORT_C,1);
digitalToggle(PORT_C,2);
digitalToggle(PORT_C,3);
digitalToggle(PORT_C,4);
digitalToggle(PORT_C,5);
digitalToggle(PORT_C,6);
digitalToggle(PORT_C,7);
digitalToggle(PORT_D,0);
digitalToggle(PORT_D,1);
digitalToggle(PORT_D,2);
digitalToggle(PORT_D,3);
digitalToggle(PORT_D,4);
digitalToggle(PORT_D,5);
digitalToggle(PORT_D,6);	
digitalToggle(PORT_D,7);
}