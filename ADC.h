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

void ADC_enable(void);
void ADC_disable(void);

#ifdef __cplusplus
}
#endif
#endif //ADC_H