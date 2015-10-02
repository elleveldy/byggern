#define F_CPU 4915200

#include <stdlib.h>
#include <util/delay.h>

#include "menu.h"
#include "joystick.h"
#include "oled.h"
#include "timer.h"




void gui_print_page(Menuitem* menu){
	oled_home();
	oled_printf(menu->name);

}


//works
void gui_print_indicator(Menuitem* m){
	
	oled_clear_col(0);
	
	int number = menu_submenu_number(m);
	
	oled_goto_pos(0, number);
	oled_printf("-");
	
}



void gui_print_menu(Menuitem* m){
	oled_clear_screen();
	oled_goto_pos(8, 0);
	oled_printf(menu_name(m));
	
	for(int n = 0; n < m->num_submenus; n++){
		oled_goto_pos(8, n+1);
		oled_printf(menu_name(m->submenus[n]));
	}
	oled_goto_pos(8,5);
	oled_printf(menu_name(selected_menuitem));

}

//uses selected_menuitem and changes it according to joystick movement
//w
void gui_navigate(){
	
	
	//Needed to avoid navigation spamming (moving through menu faster than you can react to)
	//if(timer_isTimeout()){}
	//else{
		//return;
	//}
	int threshold = 70;
	
	if(joystick_x_value() > threshold){
		oled_printf("x");
		selected_menuitem = menu_submenu(selected_menuitem);
		_delay_ms(200);
	}
	else if(joystick_x_value() < - threshold){
		oled_printf("-x");
		selected_menuitem = menu_parent(selected_menuitem);
		_delay_ms(200);
		
		
	}
	else if(joystick_y_value() > threshold){
		oled_printf("y");
		selected_menuitem = menu_prev(selected_menuitem);
		_delay_ms(200);

		
	}
	else if(joystick_y_value() < - threshold){
		oled_printf("-y");
		//if there is a next item:
		if(
		selected_menuitem = menu_next(selected_menuitem);
		_delay_ms(200);

	}
	else if(joystick_button_read()){
		oled_printf("button");
		if(selected_menuitem->fn != NULL )	//if the function pointer points to a function, call it
			selected_menuitem->fn();	
			_delay_ms(200);
		
	}
	
	
}


//void gui_init(){
//
//}

//void gui_logic(){
	//
	//
	//if(joystick right){
		//gui_print_menu(menu.submenu)
	//}
	//
	//if(joystick left){
		//gui_print_menu(menu.parent)
	//}
	//
	//
//}