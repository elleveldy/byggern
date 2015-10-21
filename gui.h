#pragma once


#include "menu.h"


void alt_gui_run();
void gui_run();
void gui_print_page(Menuitem* menu);
void gui_print_menu(Menuitem* menu);

void gui_print_indicator();
void gui_navigate();
void gui_init();

int gui_line_nr;

//void gui_logic();

