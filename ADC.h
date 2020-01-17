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

void ADC_turn_on(void);
void ADC_turn_off(void);
void ADC_start_conversion(void);

void ADC_config();

int ADC_read8(void);
int ADC_read10(void);

#ifdef __cplusplus
}
#endif
#endif //ADC_H