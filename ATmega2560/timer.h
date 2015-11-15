#pragma once




#include <avr/io.h>
#include <stdio.h>

#define MAX_TIME 65525
#define PRESCALER 1024

//time[sec] = 65535  / 16Mhz = 0.0040959375

void timer_init();

void timer_start();

uint16_t timer_read();
void timer_reset();

int timer_done();

void timer_simple_test();


int timer_cycle_start(int time_max);

//Needs to be called in while loop to increase time_tick
void timer_tick_iterate();
int timer_cycle_done();
int time_ms_start(int ms_time);
