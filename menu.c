#pragma once
#include "menu.h"
#include <stdint.h>



Menuitem* new_Menuitem(
char* name,
void (fn*)(void),
uint8_t num_submenus,
){
	Menuitem* this = malloc(sizeof(Menuitem));
	this->name = name;
	this->fn = fn;
	
	this->num_submenus = num_submenus;
	this->submenu = malloc(sizeof(Menuitem) * num_submenus);
	
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
	
	Menuitem* base = new_Menuitem("Menu", NULL, 3);
	base->submenus[0] = new_Menuitem("Sub 1", NULL, 0);
	base->submenus[1] = new_Menuitem("Sub 2", NULL, 2);
	base->submenus[1]->submenus[0] = new_Menuitem("Sub 2-1", NULL, 0);
	base->submenus[1]->submenus[1] = new_Menuitem("Sub 2-2", NULL, 0);
	base->submenus[2] = new_Menuitem("Sub 3", NULL, 0);
	
	assign_parents(base);
	
	return base;
}




Menuitem* menu_submenu(Menuitem* m){
	if (m->submenus){
		return m->submenus[0];
	}
	
	else{
		return m;
	}
}

Menuitem* menu_parent(Menuitem* m){
	if (m->parent){
		return parent;
	}
	else{
		return m;
	}
}

Menuitem* menu_next(Menuitem* m){
	Menuitem* parent = menu_parent(m);
	for(uint8_t n = 0; n < parent->num_submenus; n++){
		if(parent->submenus[n] == m  &&  n < parent->num_submenus){
			return parent->submenus[n+1];
		}
	}
	return m;
}

Menuitem* menu_prev(Menuitem* m){
	Menuitem* parent = menu_parent(m);
	
	for(uint8_t n = 0; n < parent->num_submenus; n++){
		if(parent->submenus[n] == m  &&  n > 0){
			return parent->submenus[n-1];
		}
	}
	return m;
}


int menu_submenu_number(Menuitem* m){
	Menuitem* parent = menu_parent(m);
	for(int i = 0; i < parent->num_submenus; i++){
		if(parent->submenus[i] == m)
			return i;
	}
	return 0; 		//make safeguarding form this?
}

char* menu_name(){
	return this->name;
}

char* menu_name(Menuitem* m){
	return m->name;
}