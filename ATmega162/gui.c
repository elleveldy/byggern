/*
//#define F_CPU 4915200


#include <string.h> //for strcmp( str1, str2)
#include <stdlib.h>
#include <util/delay.h>

#include "menu.h"
#include "joystick.h"
#include "oled.h"
#include "gui.h"
#include "timer.h"


//switch case that only rewrites menu when joystick is moved


void gui_run(){
	
	gui_print_menu(menu_selector);
	gui_navigate();
	gui_print_indicator(menu_selector);
}

void alt_gui_run(){
	
	gui_print_menu(menu_selector);
	//gui_print_indicator(menu_selector);
	
	int print = 0;
	while(1){
	//
	if(strcmp(menu_selector->name, "Main") == 0){
		menu_selector = menu_submenu(menu_selector);
	}

	int threshold = 70;
	
	if(joystick_x_value() > threshold){
		menu_selector = menu_submenu(menu_selector);
		print = 1;
		_delay_ms(200);
	}
	else if(joystick_x_value() < - threshold){
		menu_selector = menu_parent(menu_selector);
		print = 1;
		_delay_ms(200);
		
		
	}
	else if(joystick_y_value() > threshold){
		menu_selector = menu_prev(menu_selector);
		print = 1;
		_delay_ms(200);

		
	}
	else if(joystick_y_value() < - threshold){
		//if there is a next item:
		if(menu_next(menu_selector) != NULL){
			menu_selector = menu_next(menu_selector);
			print = 1;
			_delay_ms(200);
		}
	}
	else if(joystick_button_read()){
		print = 1;
		if(menu_selector->fn != NULL ){	//if the function pointer points to a function, call it
			menu_selector->fn();
			_delay_ms(200);
		}
		else{
			
		}
	}
	if(print){
		gui_print_menu(menu_selector);
		gui_print_indicator(menu_selector);
	}
	print = 0;
	}
}


void gui_print_page(Menuitem* menu){
	oled_home();
	oled_printf(menu->name);

}


//works, (doesn't avoid write/erase spam)
void gui_print_indicator(Menuitem* m){
	
	oled_clear_col_interval(0, 1, 7);
	//oled_clear_col(0);
	int number = menu_submenu_number(m);
	
	oled_goto_pos(0, number);
	oled_printf("-");
	
}


//unfinished
void gui_print_menu(Menuitem* m){
	
	Menuitem* parent = menu_parent(m);
	
	oled_clear_screen();
	oled_home();
	oled_printf(menu_name(parent));
	
	for(int n = 0; n < parent->num_submenus; n++){
		oled_goto_pos(8, n+1);
		oled_printf(menu_name(parent->submenus[n]));
	}
	oled_goto_pos(8,7);
	oled_printf(menu_name(menu_selector));

}

//uses menu_selector and changes it according to joystick movement

void gui_navigate(){
	
	//
	if(strcmp(menu_selector->name, "Main") == 0){
		menu_selector = menu_submenu(menu_selector);
	}

	int threshold = 70;
	
	if(joystick_x_value() > threshold){
		oled_printf("x");
		menu_selector = menu_submenu(menu_selector);
		_delay_ms(200);
	}
	else if(joystick_x_value() < - threshold){
		oled_printf("-x");
		menu_selector = menu_parent(menu_selector);
		_delay_ms(200);
		
		
	}
	else if(joystick_y_value() > threshold){
		oled_printf("y");
		menu_selector = menu_prev(menu_selector);
		_delay_ms(200);

		
	}
	else if(joystick_y_value() < - threshold){
		oled_printf("-y");
		//if there is a next item:
		if(menu_next(menu_selector) != NULL){
			menu_selector = menu_next(menu_selector);
			_delay_ms(200);
		}
	}
	else if(joystick_button_read()){
		oled_printf("button");
		if(menu_selector->fn != NULL ){	//if the function pointer points to a function, call it
			menu_selector->fn();
			_delay_ms(200);
		}
		else{
			
		}
	}
	
	
}
*/
