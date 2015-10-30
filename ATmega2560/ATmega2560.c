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


int main(void){
	
	fdevopen(uart_Transmit, uart_Receive);
	MCUCR |= (1 << SRE);
	uart_Init(MYUBRR);
	
	
	
	can_init(MODE_NORMAL);

	while(1){
		/*_delay_ms(200);
		
		can_message stuff = can_recieve();
		printf("id: %d\t\tlength: %d\tdata: %d\n", stuff.id, stuff.length, stuff.data[0]);*/
		canjoy_recieve();
		_delay_ms(100);
		/*can_message joy = can_recieve();
		printf("X: %d\tY: %d\n", joy.data[0], joy.data[1]);*/
		printf("X: %d\n", canjoy_joystick_x());
	}
	
	
	
}