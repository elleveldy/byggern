/*
#pragma once

#include <stdint.h>



#ifndef OLED_H_
#define OLED_H_

//#define oled_command ((volatile char*)0x1000)
//#define oled_data ((volatile char*)0x1200)



static inline void oled_command_write(char command);
static inline void oled_data_write(char data);
static inline void oled_testo(char command);

void oled_init();
void oled_print_char(char character);
void oled_printf(char* fmt, ...);
void oled_printf2(char* str);


void oled_goto_page(int page);
void oled_goto_col(int col);
void oled_goto_pos(int col, int page);
void oled_home();



void oled_clear_page(int page);
void oled_clear_col(int col);
void oled_clear_col_interval(int col, int a, int b);
void oled_clear_screen();

void oled_mode_negative();
void oled_mode_normal();
void oled_toggle_negative();

void oled_change_contrast();




#endif

*/
