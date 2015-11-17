

//#define F_CPU 4915200

#include <string.h> //for strcmp( str1, str2)
#include <stdlib.h>
#include <util/delay.h>

#include "menu.h"
#include "joystick.h"
#include "oled_alt.h"
#include "gui_alt.h"


void gui_alt_run()
{
	gui_alt_print_menu(menu_selector);
	gui_alt_navigate();
	gui_alt_print_indicator(menu_selector);
}


//Prints the menu you're in and it's submenues
void gui_alt_print_menu(Menuitem* menu){
	Menuitem* parent = menu_parent(menu);
	
	oled_alt_clear_screen();
	oled_store_string(menu_name(parent), 0, 0);
	
	for(int n = 0; n < parent->num_submenus; n++){
		oled_store_string(menu_name(parent->submenus[n] ), 8, n+1);
	}
}

//uses menu_selector and changes it according to joystick movement

void gui_alt_navigate(){
	

	//If we're pointing at Main menu, point to first submenu instead
	if(strcmp(menu_selector->name, "Main") == 0){
		menu_selector = menu_submenu(menu_selector);
	}

	int threshold = 70;
	
	if(joystick_x_value() > threshold){
		menu_selector = menu_submenu(menu_selector);
		_delay_ms(200);
	}
	else if(joystick_x_value() < -threshold){
		menu_selector = menu_parent(menu_selector);
		_delay_ms(200);
		
	}
	else if(joystick_y_value() > threshold){
		menu_selector = menu_prev(menu_selector);
		_delay_ms(200);

		
	}
	else if(joystick_y_value() < -threshold){
		//if there is a next item:
		if(menu_next(menu_selector) != NULL){
			menu_selector = menu_next(menu_selector);
			_delay_ms(200);
		}
	}
	else if(joystick_button_read()){
		if(menu_selector->fn != NULL ){	//if the function pointer points to a function, call it
			menu_selector->fn();
			_delay_ms(200);
		}
		else{}
	}
	
	
}

void gui_alt_print_indicator(Menuitem* m){
	
	//oled_alt_clear_col_line_interval(0, 1, 7);
	
	//oled_clear_col(0);
	//int line = menu_submenu_number(m);
	uint8_t line = menu_submenu_number(m);
	oled_invert_line(line);
	//oled_store_string("-", 0, number);
	
}

