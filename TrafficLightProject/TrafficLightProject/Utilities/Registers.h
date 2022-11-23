/*
 * Registers.h
 *
 * Created: 11/7/2022 5:11:22 PM
 *  Author: Dell
 */ 


#ifndef REGISTERS_H_
#define REGISTERS_H_

#include "Types.h"
#define SET_BIT(Register,Bit) Register |=(1<<Bit)
#define RESET_BIT(Register,Bit) Register &=~(1<<Bit)
#define TOGGLE_BIT(Register,Bit) Register ^=(1<<Bit)
#define READ_BIT(Register,Bit) Register&(1<<Bit)
//DIO Registers
#define PINA *((volatile uint8_t*)0x39)
#define DDRA *((volatile uint8_t*)0x3A)
#define PORTA *((volatile uint8_t*)0x3B)

#define PINB *((volatile uint8_t*)0x36)
#define DDRB *((volatile uint8_t*)0x37)
#define PORTB *((volatile uint8_t*)0x38)

#define PINC *((volatile uint8_t*)0x33)
#define DDRC *((volatile uint8_t*)0x34)
#define PORTC *((volatile uint8_t*)0x35)

#define PIND *((volatile uint8_t*)0x30)
#define DDRD *((volatile uint8_t*)0x31)
#define PORTD *((volatile uint8_t*)0x32)

#define TCCR0 *((volatile uint8_t*)0x53)
#define TCNT0 *((volatile uint8_t*)0x52)
#define TIFR *((volatile uint8_t*)0x58)
#define TIMSK *((volatile uint8_t*)0x59)

#define SREG *((volatile uint8_t*)0x5F)
#define MCUCR *((volatile uint8_t*)0x55)
#define GICR *((volatile uint8_t*)0x5B)

#define GIE 7
#define ISC00 0
#define ISC01 1
#define ISC10 2
#define ISC11 3
#define INT0E 6
#define INT1E 7
#define INT2E 5

/* External Interrupt Request 0 */
#define INT0_vect_num		1
#define INT0_vect			__vector_1
#define SIG_INTERRUPT0			_VECTOR(1)

/* External Interrupt Request 1 */
#define INT1_vect_num		2
#define INT1_vect			__vector_2
#define SIG_INTERRUPT1			_VECTOR(2)

/* External Interrupt Request 2 */
#define INT2_vect_num		3
#define INT2_vect			__vector_3
#define SIG_INTERRUPT2			_VECTOR(3)

/* Timer/Counter2 Compare Match */
#define TIMER2_COMP_vect_num	4
#define TIMER2_COMP_vect		__vector_4
#define SIG_OUTPUT_COMPARE2		_VECTOR(4)

/* Timer/Counter2 Overflow */
#define TIMER2_OVF_vect_num		5
#define TIMER2_OVF_vect			__vector_5
#define SIG_OVERFLOW2			_VECTOR(5)

/* Timer/Counter1 Capture Event */
#define TIMER1_CAPT_vect_num	6
#define TIMER1_CAPT_vect		__vector_6
#define SIG_INPUT_CAPTURE1		_VECTOR(6)

/* Timer/Counter1 Compare Match A */
#define TIMER1_COMPA_vect_num	7
#define TIMER1_COMPA_vect		__vector_7
#define SIG_OUTPUT_COMPARE1A		_VECTOR(7)

/* Timer/Counter1 Compare Match B */
#define TIMER1_COMPB_vect_num	8
#define TIMER1_COMPB_vect		__vector_8
#define SIG_OUTPUT_COMPARE1B		_VECTOR(8)

/* Timer/Counter1 Overflow */
#define TIMER1_OVF_vect_num		9
#define TIMER1_OVF_vect			__vector_9
#define SIG_OVERFLOW1			_VECTOR(9)

/* Timer/Counter0 Compare Match */
#define TIMER0_COMP_vect_num	10
#define TIMER0_COMP_vect		__vector_10
#define SIG_OUTPUT_COMPARE0		_VECTOR(10)

/* Timer/Counter0 Overflow */
#define TIMER0_OVF_vect_num		11
#define TIMER0_OVF_vect			__vector_11
#define SIG_OVERFLOW0			_VECTOR(11)

#define CS00 0
#define CS01 1
#define CS02 2
#define WGM01 3
#define C0M00 4
#define COM01 5
#define WGM00 6
#define FOC0 7
#define TOIE0 0

#endif /* REGISTERS_H_ */