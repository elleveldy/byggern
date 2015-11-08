#pragma once

#include <avr/io.h>

#include "ir.h"
#include "adc.h"



#define HIGH 500
#define LOW 100
#define MID 300



int ir_alt_unblocked(){
	
	if(adc_read(ADC0D) > HIGH){
		return 1;
	}
	if(adc_read(ADC0D) < LOW){
		return 0;
	}
	
}

int ir_unblocked(){
	
	if(adc_read(IR_PIN) > MID){
		return 1;
	}
	else
		return 0;
		
	
}

int ir_blocked(){
	
	if(adc_read(ADC0D) > 120){
		return 0;
	}
	if(adc_read(ADC0D) < 30){
		return 1;
	}
	
}


void ir_count_goals(){
	
	if(timer_done()){
		ir_goals++;
		timer_start();
	}
}