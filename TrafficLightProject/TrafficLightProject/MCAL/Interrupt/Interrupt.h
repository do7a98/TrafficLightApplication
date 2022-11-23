/*
 * Interrupt.h
 *
 * Created: 11/7/2022 3:47:40 PM
 *  Author: Dell
 */ 


#ifndef INTERRUPT_H_
#define INTERRUPT_H_

#define INT0 0
#define INT1 1
#define INT2 2

#define RISING 0
#define FALLING 1

#include "../../Utilities/Registers.h"
void ExternalInterrupt_init(uint8_t InterruptPin,uint8_t Detection);

#if (__GNUC__ == 4 && __GNUC_MINOR__ >= 1) || (__GNUC__ > 4)
#  define __INTR_ATTRS used, externally_visible
#else /* GCC < 4.1 */
#  define __INTR_ATTRS used
#endif
#  define ISR(vector, ...)            \
    void vector (void) __attribute__ ((signal,__INTR_ATTRS)) __VA_ARGS__; \
    void vector (void)
#endif