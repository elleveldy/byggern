
#include "menu.h"
#include "Joystick.h"
#include "oled.h"




void gui_print_page(Menuitem* menu){
	oled_home();
	oled_printf(menu->name);
	
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