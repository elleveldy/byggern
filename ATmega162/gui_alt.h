#pragma once


#include "menu.h"


int gui_line_nr;

void gui_alt_run();

//void alt_gui_run();

//Prints the menu you're in and its sub menues
void gui_alt_print_menu(Menuitem* m);
void gui_alt_navigate();

void gui_alt_print_indicator(Menuitem* m);