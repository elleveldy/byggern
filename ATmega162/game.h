#pragma once

#include <stdint.h>
#include "game.h"
/*

typedef struct account account;
struct Menuitem {
	uint8_t adr;
	char name;
};


//make accounts

account P1;
P1->adr = 0;
P1->name = "Erlend";
*/

/*
struct account{
	uint8_t adr;
	char* name;
};

account account_new(uint8_t adr, char* name){
	account this;
	
	this.adr = adr;
	this.name = name;
	
	return this;
}

account player1 = account_new(0, "Erlend");*/


void game_play();
void game_over();
void game_highscore();

void game_save_highscore();

void game_new_accounts();