#pragma once




#include <avr/io.h>
#include <stdio.h>

#define MAX_TIME 65535
#define PRESCALER 1024

//time[sec] = 65535  / 16Mhz = 0.0040959375

typedef enum {TIMER_1, TIMER_2, TIMER_3}timer;


void timer_init();


uint16_t timer_read(uint8_t timer);
uint16_t timer1_read();
uint16_t timer3_read();
uint16_t timer4_read();
uint16_t timer5_read();


void timer_reset(uint8_t timer);
void timer1_reset();
void timer3_reset();
void timer4_reset();
void timer5_reset();



