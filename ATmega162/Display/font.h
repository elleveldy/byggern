#include <avr/pgmspace.h>

#ifndef FONT_H_
#define FONT_H_

#define font_width 8
#define FONT_OFFSET 32

const unsigned char PROGMEM font[95][8];

const unsigned char full_square[8];
const unsigned char empty_square[8];



#endif
