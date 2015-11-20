#include <stdint.h>
#include "avr/interrupt.h"
#include "../Communication/TWI_Master.h"
#include "max520.h"



#define MAX520_TWI_ADDR 0b01011110



void max520_init(){
	TWI_Master_Initialise();
	sei();//interrupts on
}


void max520_send(uint8_t val)
{
	//printf("In max520_send\n");
	uint8_t message[3] = {MAX520_TWI_ADDR, 0, val};
	
	TWI_Start_Transceiver_With_Data(message, 3);
	
}



/*
canjoy_recieve();

speed = 2*abs(canjoy_joystick_x());

if(canjoy_joystick_x() > 128){
	motor_direction(right);
}
else
motor_direction(left);

max520_send(speed);
*/