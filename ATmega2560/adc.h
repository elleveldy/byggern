#ifndef ADC_H_
#define ADC_H_

#include <stdio.h>

void adc_init();

uint16_t adc_read(uint8_t ch); //IR set to ADC0 = PF0

#endif /* ADC_H_ */