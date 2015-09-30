#pragma once
typedef struct Menuitem Menuitem;
#include <stdint.h>


struct Menuitem {
	uint8_t			num_submenus;
	Menuitem**		submenus;
	Menuitem*		parent;
	char*			name;
	void (*fn)(void);
};





typedef struct Menuitem Menuitem;

void assign_parents(Menuitem* menu);

Menuitem* create_menu();

Menuitem* menu_submenu(Menuitem* m);
Menuitem* menu_parent(Menuitem* m);
Menuitem* menu_next(Menuitem* m);
Menuitem* menu_prev(Menuitem* m);

char* menu_name(Menuitem* m);
