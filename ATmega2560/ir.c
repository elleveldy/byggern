#pragma once

#include <avr/io.h>

#include "ir.h"
#include "adc.h"


#define HIGH 120
#define LOW 30

int ir_unblocked(){
	
	if(adc_read(ADC0D) > 120){
		return 1;
	}
	if(adc_read(ADC0D) < 30){
		return 0;
	}
	
}

int ir_blocked(){
	
	if(adc_read(ADC0D) > 120){
		return 0;
	}
	if(adc_read(ADC0D) < 30){
		return 1;
	}
	
}