
#include <stdint.h>
#include <stdlib.h>
#include "oled.h"
#include "menu.h"


Menuitem* new_Menuitem(
char* name,
void (*fn)(void),
uint8_t num_submenus
){
	Menuitem* this = malloc(sizeof(Menuitem));
	this->name = name;
	this->fn = fn;
	
	this->num_submenus = num_submenus;
	this->submenus = malloc(sizeof(Menuitem) * num_submenus);
	
	return this;
}


void assign_parents(Menuitem* menu){
	for(uint8_t n = 0; n < menu->num_submenus; n++){
		menu->submenus[n]->parent = menu;
		if(menu->submenus[n]->num_submenus > 0){
			assign_parents(menu->submenus[n]);
		}
	}
}


Menuitem* create_menu(){
	
	Menuitem* base = new_Menuitem("Main", NULL, 3);
	base->submenus[0] = new_Menuitem("Snake", menu_snake_fn, 0);
	base->submenus[1] = new_Menuitem("Settings", NULL, 2);
	base->submenus[1]->submenus[0] = new_Menuitem("Contrast", NULL, 0);
	base->submenus[1]->submenus[1] = new_Menuitem("Inverse", menu_toggle_negative, 0);
	base->submenus[2] = new_Menuitem("Ping Pong", NULL, 0);
	
	assign_parents(base);
	
	return base;
}



//works
Menuitem* menu_submenu(Menuitem* m){
	if (m->num_submenus != 0){
		return m->submenus[0];
	}
	else{
		return m;
	}
}

//works
Menuitem* menu_parent(Menuitem* m){
	if (m->parent != NULL){
		return m->parent;
	}
	else{
		return m;
	}
}

//works
Menuitem* menu_next(Menuitem* m){
	Menuitem* parent = menu_parent(m);
	for(uint8_t n = 0; n < parent->num_submenus; n++){
		if(parent->submenus[n] == m  &&  n < parent->num_submenus){
			return parent->submenus[n+1];
		}
	}
	return m;
}

//works
Menuitem* menu_prev(Menuitem* m){
	Menuitem* parent = menu_parent(m);
	
	for(uint8_t n = 0; n < parent->num_submenus; n++){
		if(parent->submenus[n] == m  &&  n > 0){
			return parent->submenus[n-1];
		}
	}
	return m;
}

//works
int menu_submenu_number(Menuitem* m){
	oled_goto_pos(0,5);
	Menuitem* parent = menu_parent(m);
	for(int i = 0; i < parent->num_submenus; i++){
		if(parent->submenus[i] == m)

			return i + 1;
	}
	return 0; 		//make safeguarding from this?
}

//char* menu_name(){
	//return this->name;
//}

char* menu_name(Menuitem* m){
	return m->name;
}


void menu_snake_fn(){
	oled_clear_screen();
	while(1){
		oled_home();
		oled_printf("snake funk");
	}
	
}

void menu_change_contrast(){
	
}

volatile char *oled_data = (char *) 0x1200; //dirty fix


void menu_toggle_negative(){
	//A6 / A7
	*oled_data = 0xa7;
	oled_home();
	oled_printf("toggle neg");
}