#pragma once
#include "menu.h"


//typedef enum{ left, right, down, up, click }gui_input;



void gui_run();

//void alt_gui_run();

//Prints the menu you're in and its sub menus
void gui_print_menu(Menuitem* m);
void gui_navigate();
