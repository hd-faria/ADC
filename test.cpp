
#ifndef __cplusplus
	#define __cplusplus
#endif //__cplusplus

#ifndef F_CPU
	#define F_CPU 16000000
#endif //F_CPU

#include <avr/io.h> 
#include <util/delay.h> //usado para os delays
#include <stdlib.h> //atoi function
#include <avr/interrupt.h>

#include "ADC.h" //TODO:
#include "usart.h"

void print_REG(void);

int main(){

	DDRG |= (1<<PG0);			//Make pin PB5 be an output.
	PORTG |= (1<<PG0); 			//Set(Turn LED off) PG0
	USART0_Init8(9600);
	
	//ADC_enable();
	
	//Configure ADC				
	ADC_config(RIGHTADJUSTED);
	
	print_REG();
	
	sei();	//Enable global interrupt

	
	ADC_turn_on(); //turn on the ADC feature
	ADC_start_conversion(); //Start first conversion

	
	while(1){
	//	PORTG &= ~(1<<PG0);		//Clear(Turn LED on) PG0 in PORTB
	//	_delay_ms(500);
	//	PORTG |= (1<<PG0);		//Set(Turn LED off) PG0
	//	_delay_ms(500);
	}
}

ISR(ADC_vect){	//Add interrupt routine and send resoult over USART
	char adcResult[4];	//String variable declaration
	itoa(ADC_read10(), adcResult,10);	//Convert the ADC result
	ADC_start_conversion();	//start the next conversion(?)
	USART0_println(adcResult);
}

void print_REG(){
	char showREG[1]; //debug

	USART0_println("Configuration:"); //debug
	USART0_print(" - ADMUC: "); //debug
	itoa(ADMUX, showREG,16); //debug
	USART0_println(showREG); //debug

}
