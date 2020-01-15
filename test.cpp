
#ifndef __cplusplus
	#define __cplusplus
#endif //__cplusplus

#ifndef F_CPU
	#define F_CPU 16000000
#endif //F_CPU

#include <avr/io.h>
#include <util/delay.h>

#include "usart.h"

int main(){

	DDRG |= (1<<PG0);			//Make pin PB5 be an output.
	USART0_Init8(9600);

	while(1){
		PORTG &= ~(1<<PG0);			//Clear Pin 5 in PORTB
		_delay_ms(500);
		PORTG |= (1<<PG0);
		_delay_ms(500);
	}
}