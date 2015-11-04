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

	DDRE |= (1 << 3);

	//uint16_t count = 0;

	while(1){
		
		/*can_test_recieve();
		printf("\nin main while\n");*/
		
		
		
		canjoy_recieve();
		pwm_joystick_pulse(canjoy_joystick_x());
		
		
	}
	
	
	
}