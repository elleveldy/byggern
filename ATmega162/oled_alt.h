#pragma once

//uint16_t oled_count = 0;


/*

static inline void oled_command_write(char command);


static inline void oled_data_write(char data);*/

void oled_alt_init();
void oled_store(char* string, int* position);

//uncertain 
void oled_store_string(char* string, int col, int line);
void oled_store_string2(char* string, int col, int line);

void oled_write_screen();

void oled_refresh_60Hz();
//uint16_t oled_counter();

void oled_invert_line(uint8_t line);


void oled_alt_clear_line(int line);
void oled_alt_clear_col_line_interval(int col, int line_a, int line_b);

void oled_alt_clear_screen();





void oled_alt_mode_negative();
void oled_alt_mode_normal();

void oled_alt_toggle_negative();

void oled_alt_change_contrast();

void oled_epleptic_seizure();