#pragma once
#include <stdint.h>




typedef struct Menuitem Menuitem;
struct Menuitem {
	uint8_t			num_submenus;
	Menuitem**		submenus;
	Menuitem*		parent;
	char*			name;
	void (*fn)(void);
};

Menuitem* menu_selector;
int menu_line_nr;

Menuitem* new_Menuitem(
char* name,
void (*fn)(void),
uint8_t num_submenus
);

void assign_parents(Menuitem* menu);

Menuitem* create_menu();

Menuitem* menu_submenu(Menuitem* m);
Menuitem* menu_parent(Menuitem* m);
Menuitem* menu_next(Menuitem* m);
Menuitem* menu_prev(Menuitem* m);

int menu_submenu_number(Menuitem* m);

//char* menu_name();
char* menu_name(Menuitem* m);

//submenu functions
//snake function
void menu_snake_fn();

//settings functions
void menu_toggle_negative();