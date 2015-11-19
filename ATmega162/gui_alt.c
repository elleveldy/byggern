

//#define F_CPU 4915200

#include <string.h> //for strcmp( str1, str2)
#include <stdlib.h>
#include <util/delay.h>

#include "menu.h"
#include "joystick.h"
#include "oled_alt.h"
#include "gui_alt.h"


void gui_run()
{
	gui_print_menu(menu_selector);
	
	gui_navigate();
	
	oled_invert_line(menu_submenu_number(menu_selector));

}


//Prints the menu you're in and it's submenues
void gui_print_menu(Menuitem* menu){
	
	Menuitem* parent = menu_parent(menu);
	
	
	oled_clear_screen();
	oled_store_string(menu_name(parent), 0, 0);
	//oled_store((char[sizeof(menu_name(parent)) + 1]){menu_name(parent)}, (int[2]){0,0});
	
	for(int n = 0; n < parent->num_submenus; n++){
		oled_store_string(menu_name(parent->submenus[n] ), 8, n+1);
		//oled_store((char[sizeof(menu_name(parent->submenus[n])) + 1]){menu_name(parent->submenus[n])}, (int[2]){0,0});
		
	}
}





//uses global variable menu_selector and changes 
//what submenu it points to according to joystick movement.
//Must be run in a while loop
void gui_navigate(){
	
	
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
	else if(button_right_read()){
		if(menu_selector->fn != NULL ){	//if the function pointer points to a function, call it
			menu_selector->fn();
			_delay_ms(200);
		}
		else{}
	}
	
	
}


