#include <iostream>
using namespace std;

#include "oled.h"
#include <stdlib.h>
//#include <util/delay.h>

#include "snake.h"


typedef enum{ left = -1, right = 1, down = -2, up = 2, none = 0 } dir;

typedef enum{ x_left = -1, x_no_dir = 0, x_right = 1 } x_dir;
typedef enum{ y_down = -1, y_no_dir = 0, y_up = 1 } y_dir;
typedef enum{ pos_x = 0, pos_y, pos_bool }s_position;

const int SCREEN_WIDTH = 128;
const int SCREEN_HEIGHT = 64;
const int MAX_LENGTH = 8;
int slength;

int direction = up;
int snake[MAX_LENGTH][3];



void snake_tests(){

	snake_init(snake);

	snake_print(snake);

	snake_move(dir::up, snake);
	cout << endl;
	snake_print(snake);

	snake_move(dir::right, snake);
	cout << endl;
	snake_print(snake);

	snake_move(dir::right, snake);
	cout << endl;
	snake_print(snake);

	snake_move(dir::down, snake);
	cout << endl;
	snake_print(snake);
}

void snake_init(int snake[][3]){
	slength = 3;
	snake[0][pos_x] = 0;
	snake[0][pos_y] = 3;
	snake[1][pos_x] = 0;
	snake[1][pos_y] = 2;
	snake[2][pos_x] = 0;
	snake[2][pos_y] = 1;

}

void snake_run(int snake[][3]){
	//controls move speed

	//_delay_ms(200);

	while (1){
		snake_print(snake);
		snake_move(direction, snake);

		if (snake_self_collide(snake)){
			return;
		}
		if (snake_boarder_reached(snake)){
			return;
		}
	}
	

}


void snake_print_part(int x, int y){
	cout << x << " " << y << endl;
}

void snake_print_part(int snake[][3], int index){
	cout << snake[index][pos_x] << " " << snake[index][pos_y] << endl;
}

void snake_print(int snake[][3]){

	//oled_clear_screen();
	//remove clear screen, and clear previously last snake part instead?
	for (int i = 0; i < slength; i++){
		//snake_print_part(snake[slength][pos_x], snake[slength][pos_y]);
		snake_print_part(snake, i);
	}

}

int snake_self_collide(int snake[][3]){

	for (int i = 0; i < MAX_LENGTH; i++){
		if (snake[i][pos_x] == snake[0][pos_x] && snake[i][1] == snake[i][pos_y])
			return 1;
	}
	return 0;
}


void snake_move(int dir, int snake[][3]){

	int x = x_no_dir;
	int y = y_no_dir;

	switch (dir){
	case dir::up:
		cout << "switch: " << "up";
		y = y_up;
	case dir::down:
		cout << "switch: " << "down";
		y = y_down;
	}
	switch (dir){
	case dir::left:
		cout << "switch: " << "left";
		x = x_left;
	case dir::right:
		cout << "switch: " << "right";
		x = x_right;
	}


	for (int point = slength -1; point > 0; point--){
		snake[point][pos_x] = snake[point - 1][pos_x];
		snake[point][pos_y] = snake[point - 1][pos_y];
	}
	cout  << endl << "dir: "<< dir << " x: " << x << " y: " << y;
	snake[0][pos_x] = snake[0][pos_x] + x;
	snake[0][pos_y] = snake[0][pos_y] + y;
}

int snake_boarder_reached(int snake[8][3]){
	if (snake[0][pos_x] >= SCREEN_WIDTH || snake[0][pos_y] >= SCREEN_HEIGHT)
		return 1;
	else
		return 0;
}

void snake_add_size(int snake[8][3]){
	//increases slength, sets correct initial position and bool = 1

	int x;
	int y;

	if (snake[slength - 1][pos_x] < snake[slength - 2][pos_x])		//tail moving right
		x = x_left;
	else if (snake[slength - 1][pos_x] > snake[slength - 2][pos_x])	//tail movingleft
		x = x_right;
	else													//not moving in x-direction
		x = x_no_dir;


	if (snake[slength - 1][pos_y] < snake[slength - 2][pos_y])		//tail moving up
		y = y_down;
	if (snake[slength - 1][pos_y] > snake[slength - 2][pos_y])		//tail moving down
		y = y_up;
	else													//not moving in y-direction													
		y = y_no_dir;

	snake[slength][pos_x] = snake[slength - 1][pos_x] + x;
	snake[slength][pos_y] = snake[slength - 1][pos_y] + y;
	snake[slength][pos_bool] = 1;


	slength++;
}
