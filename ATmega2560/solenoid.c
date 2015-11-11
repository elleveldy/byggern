#include <avr/io.h>
#include <avr/delay.h>

void solenoid_init(){
	DDRH |= (1<<PH3);
	PORTH |= (1<<PH3);
}

void solenoid_shoot(){
	PORTH &= ~(1<<PH3);
	_delay_ms(50);
	PORTH |= (1<<PH3);
}