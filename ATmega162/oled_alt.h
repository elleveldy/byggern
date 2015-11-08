

void oled_alt_init();
void oled_store(char* string, int* position);
void oled_store_string(char* string, int line, int col);
void oled_write_screen();

void oled_alt_clear_line(int line);
void oled_alt_clear_col_line_interval(int col, int line_a, int line_b);

void oled_alt_clear_screen();





void oled_alt_mode_negative();
void oled_alt_mode_normal();

void oled_alt_toggle_negative();

void oled_alt_change_contrast();