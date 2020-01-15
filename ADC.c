/*
 * ADC.c
 *
 * Created: 00/jan/2020 
 * Author: Henrique
 * Based on: 
 *  - http://ww1.microchip.com/downloads/en/devicedoc/doc7679.pdf
 */ 

#include <avr/io.h>
#include "ADC.h"

void ADC_enable(void){
    ADCSRA |= (1 << ADEN);
}

void ADC_disable(void){
    ADCSRA &= ~(1 << ADEN);
}
