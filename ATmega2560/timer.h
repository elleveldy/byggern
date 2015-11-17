#pragma once




#include <avr/io.h>
#include <stdio.h>

#define MAX_TIME 65535
#define PRESCALER 1024

//time[sec] = 65535  / 16Mhz = 0.0040959375

void timer_init();

void timer_start();

uint16_t timer_read();
void timer_reset();

uint16_t timer5_read(uint8_t timer);
void timer5_reset(uint8_t timer_nr);

int timer_done();

void timer_simple_test();


int timer_cycle_start(int time_max);

//Needs to be called in while loop to increase time_tick
void timer_tick_iterate();
int timer_cycle_done();
int time_ms_start(int ms_time);
