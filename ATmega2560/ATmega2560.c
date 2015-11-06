/*
 * ATmega2560.c
 *
 * Created: 23.10.2015 16:33:03
 *  Author: erlendvd
 */ 


#include <avr/io.h>
#define F_CPU 16000000
#include <util/delay.h>
#include "can.h"
#include "mcp2515_define.h"
#include "uart.h"
#include "canjoy.h"
#include "pwm.h"
#include "adc.h"
#include "ir.h"

/*
check if header files are included in their respective c files, and if they should be
to avoid "implicit declaration of function*/



int main(void){
	
	/*DDRB = 0xff;
	while(1){
		PORTB = 0xff;
		_delay_ms(500);
		PORTB = 0;
		_delay_ms(500);
	}*/
	
	
	MCUCR |= (1 << SRE);
	uart_Init(MYUBRR);
	//
	
	
	can_init(MODE_NORMAL);
	pwm_init();
	adc_init();

	DDRE |= (1 << 3); //studass PWM bandaid that can be removed? 

	//uint16_t count = 0;
	
	
	int high = adc_read(0x00);
	int low = adc_read(0x00);
	

	
	
	while(1){
		
		canjoy_recieve();
		pwm_joystick_pulse(canjoy_joystick_x());
		int adc = adc_read(ADC0D);
		
		if(adc > high)
			high = adc;
		if(adc < low)
			low = adc;
		printf("\nIR VALUE: %d\tHighest: %d\tLowest: %d\tUnblocked: %d\n", adc, high, low, ir_unblocked());
		
	}
	
	
	
	
}