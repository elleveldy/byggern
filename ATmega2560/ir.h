//#pragma once

#include <stdint.h>


#ifndef IR_H_
#define IR_H_
#define IR_PIN 0x01

uint16_t max_left;//rename this mofo

/*
typedef struct can_message IR;
struct can_message{
	uint8_t nr_of_reads; //16bit
	uint8_t sum; //4bit
	uint8_t avg; //8*8bit
};
*/


int ir_unblocked();
int ir_blocked();

int ir_alt_unblocked();
int ir_alt_blocked();

void ir_count_goals();

#endif
