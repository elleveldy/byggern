#include <avr/io.h>
#include <util/delay.h>

void solenoid_init(){
	DDRH |= (1<<PH3);
	PORTH |= (1<<PH3);
}

void solenoid_shoot(){
	PORTH &= ~(1<<PH3);
	_delay_ms(150);
	PORTH |= (1<<PH3);
}

void solenoid_extend(){
	PORTH &= ~(1<<PH3);
}

void solenoid_retract(){
	PORTH |= (1<<PH3);	
}
