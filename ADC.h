/*
 * ADC.h
 *
 * Created: 00/jan/2020 
 * Author: Henrique
 * Based on: 
 *  - http://ww1.microchip.com/downloads/en/devicedoc/doc7679.pdf
 */ 

#ifndef ADC_H
#define ADC_H

#ifdef __cplusplus
extern "C" {
#endif

#define LEFTADJUSTED 0
#define RIGHTADJUSTED 1

#define AREF 0 
#define AVCC 1
#define INTERNAL_REF 3

void ADC_turn_on(void);
void ADC_turn_off(void);
void ADC_start_conversion(void);

void ADC_config(char resolution);

void ADC_select_reference(uint8_t _reference);
void ADC_channel_selection(uint8_t _pin);

int ADC_read8();
int ADC_read10(void);



#ifdef __cplusplus
}
#endif
#endif //ADC_H

