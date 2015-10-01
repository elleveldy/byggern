
#include "menu.h"
#include "joystick.h"
#include "oled.h"




void gui_print_page(Menuitem* menu){
	oled_home();
	oled_printf(menu->name);

}

void gui_print_inticator(){
	
}

void gui_print_menu(Menuitem* m){
	oled_printf(m.menu_name());
	for(int n = 0; n < m->num_submenus; n++){
		oled_printf("\t%d\n", m->submenus[n].menu_name());
	}
}

//uses SELECTED_MENUITEM and changes it according to joystick movement
void gui_navigate(){
	int threshold = 70;
	if(joystick_read_x() > threshold){
		SELECTED_MENUITEM = menu_submenu(SELECTED_MENUITEM);
	}
	else if(joystick_read_x() < - threshold){
		SELECTED_MENUITEM = menu_parent(SELECTED_MENUITEM);
	}
	else if(joystick_read_y() > threshold){
		SELECTED_MENUITEM = menu_prev(SELECTED_MENUITEM);
	}
	else if(joystick_read_y() < - threshold){
		SELECTED_MENUITEM = menu_next(SELECTED_MENUITEM);
	}
	else if(joystick_button_read()){
		if(SELECTED_MENUITEM != NULL){
			SELECTED_MENUITEM->fn();
	}
}

void gui_init(){

}

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