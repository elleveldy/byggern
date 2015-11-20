#pragma once

#include <stdint.h>


#define IR_PIN 0x01


void ir_init();

int ir_unblocked();
int ir_blocked();


