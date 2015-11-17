#include <avr/io.h>

#include "ir.h"
#include "adc.h"



#define HIGH 500
#define LOW 100
#define MID 300


uint8_t ir_score = 0;

void ir_init(){
	adc_init();
}

//
int ir_alt_unblocked(){
	
	if(adc_read(ADC0D) > HIGH){
		return 1;
	}
	else{
		return 0;
	}
	
}

int ir_alt_blocked(){
	
	if(adc_read(IR_PIN) > MID){
		return 0;
	}
	else
		return 1;
	
	
}

int ir_unblocked(){
	
	if(adc_read(IR_PIN) > MID){
		return 1;
	}
	else
		return 0;
		
	
}

int ir_blocked(){
	
	if(adc_read(ADC0D) > HIGH){
		return 0;
	}
	if(adc_read(ADC0D) < LOW){
		return 1;
	}
	return -1;
}



void ir_count_score(){
 
}