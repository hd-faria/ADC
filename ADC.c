/*
 * ADC.c
 *
 * Created: 00/jan/2020 
 * Author: Henrique
 * Based on: 
 *  - http://ww1.microchip.com/downloads/en/devicedoc/doc7679.pdf
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdlib.h>
#include <math.h>

#include "ADC.h"

void ADC_turn_on(void){
    ADCSRA |= (1 << ADEN);  //turn on the ADC feature
}

void ADC_turn_off(void){
    ADCSRA &= ~(1 << ADEN);
}

void ADC_start_conversion(void){
    ADCSRA |= (1<<ADSC);    //Start conversion
}

void ADC_config(char resolution){

    const int div_factor_max = F_CPU/50000;
    const int div_factor_min = F_CPU/200000;
   		ADCSRA |= (1<<ADPS2) | (1<<ADPS1) | (1<<ADPS0);	//Enable prescaler F_CPU=16 000 000; 50 000 < fs < 200 000; 320 > Division factor = 128 > 80

    switch(resolution){
        case RIGHTADJUSTED: 
		    ADMUX &= ~(1<<ADLAR);// set to left adjust, clear to right adjust
            break;
        default: //LEFTADJUSTED
		    ADMUX |= (1<<ADLAR);// set to left adjust, clear to right adjust
            break;
    }
	
	// ADMUX &= ~(1<<REFS1) & ~(1<<REFS0) // Selecioanado referência por padrão já é 00
	ADCSRA |= (1<<ADIE);//Enable interrupt function in ADC
}
void ADC_select_reference(uint8_t _reference){
    switch (_reference){
    
    case AREF:
        ADMUX &= ~(1<<REFS1) & ~(1<<REFS0);
        break;

    case AVCC:
        ADMUX |= (1<<REFS0);
        ADMUX &= ~(1<<REFS1);        
        break;
    
    default:
        break;
    }

}
void ADC_channel_selection(uint8_t _pin){
    switch (_pin)
    {
    case PF0:
            ADMUX &= ~(1<<MUX4) & ~(1<<MUX3) & ~(1<<MUX2) & ~(1<<MUX1) & ~(1<<MUX0); 
        break;
    
    case PF1:
            ADMUX &= ~(1<<MUX4) & ~(1<<MUX3) & ~(1<<MUX2) & ~(1<<MUX1) & ~(1<<MUX0);
            ADMUX |= (1<<MUX0);             
        break;
    
    case PF2:
            ADMUX &= ~(1<<MUX4) & ~(1<<MUX3) & ~(1<<MUX2) & ~(1<<MUX1) & ~(1<<MUX0);
            ADMUX |= (1<<MUX1);             
        break;

    case PF3:
            ADMUX &= ~(1<<MUX4) & ~(1<<MUX3) & ~(1<<MUX2) & ~(1<<MUX1) & ~(1<<MUX0);
            ADMUX |= (1<<MUX1) | (1<<MUX0);             
        break;
    
    case PF4:
            ADMUX &= ~(1<<MUX4) & ~(1<<MUX3) & ~(1<<MUX2) & ~(1<<MUX1) & ~(1<<MUX0);
            ADMUX |= (1<<MUX2);             
        break;

    case PF5:
            ADMUX &= ~(1<<MUX4) & ~(1<<MUX3) & ~(1<<MUX2) & ~(1<<MUX1) & ~(1<<MUX0);
            ADMUX |= (1<<MUX2) | (1<<MUX0);             
        break;

    case PF6:
            ADMUX &= ~(1<<MUX4) & ~(1<<MUX3) & ~(1<<MUX2) & ~(1<<MUX1) & ~(1<<MUX0);
            ADMUX |= (1<<MUX2) | (1<<MUX1);             
        break;

    case PF7:
            ADMUX &= ~(1<<MUX4) & ~(1<<MUX3) & ~(1<<MUX2) & ~(1<<MUX1) & ~(1<<MUX0);
            ADMUX |= (1<<MUX2) | (1<<MUX1) | (1<<MUX0);             
        break;        

    default:

        //#error "No valid configuration" 

        break;
    }
}

int ADC_read8(){
    if(ADLAR){ //left adjusted
        return ADCH;
    } else{ //right adjusted
        uint8_t readLOW = ADCL;
        return ((ADCH<<6) | (readLOW>>2));
    }
}
int ADC_read10(){
    uint8_t readLOW = ADCL;   
    uint16_t result;
    if(ADLAR){ //left adjusted
        result = ((ADCH <<2)| (readLOW>>6));
    } else{ //right adjusted
        result = ((ADCH<<8) | (readLOW));
    }
    return result;
}

//INT4_vect

