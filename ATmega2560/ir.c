#include <avr/io.h>

#include "ir.h"
#include "Drivers/adc.h"



#define HIGH 500
#define LOW 100
#define MID 300


uint8_t ir_score = 0;

void ir_init(){
	adc_init();
}



int ir_blocked(){
	
	if(adc_read(IR_PIN) > MID){
		return 0;
	}
	else
		return 1;
	
	
}

