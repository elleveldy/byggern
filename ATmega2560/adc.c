/*

The analog input channel is selected by writing to the
MUX bits in ADMUX and ADCSRB.


The ADC is enabled by setting the ADC Enable bit, ADEN
in ADCSRA.
Voltage reference and input channel selections will not go into effect until ADEN
is set. The ADC does not
consume power when ADEN
is cleared, so it is
recommended to switch off the ADC before entering power saving sleep modes


*/

#include <avr/io.h>
#include <stdio.h>
#include "adc.h"

void adc_init(){
	
	// Division factor 128
	ADCSRA |= (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
	
	/*We find max voltage to be 1.1 V
	Internal 1.1 V Voltage Reference with external capacitor at AREF pin  ->  REFS1 = 1 REFS0 = 0 
	*/  
	ADMUX |= (1 << REFS0);
	//ADMUX &= ~(1 << REFS1);
	ADMUX |= (1 << REFS1);
	
	
}

uint16_t adc_read(uint8_t ch){ //IR set to ADC0 = PF0
	ADMUX |= (ch & 0x03);
	ADCSRA |= (1 << ADSC);
	
	while((ADCSRA & (1 << ADSC))){}

	return ADC; //sexy premade code
}