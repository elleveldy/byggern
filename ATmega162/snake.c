

#include "oled_alt.h"
#include "joystick.h"
#include "font.h"
#include <stdlib.h> //abs
#include <stdio.h> //uint


#include <util/delay.h>

#include "snake.h"


typedef enum{ left = -1, right = 1, down = -2, up = 2, none = 0 } dir;

typedef enum{ x_left = -1, x_no_dir = 0, x_right = 1 } x_dir;
typedef enum{ y_down = -1, y_no_dir = 0, y_up = 1 } y_dir;
typedef enum{ pos_x = 0, pos_y, pos_bool }s_position;

#define MAX_LENGTH 8
uint8_t slength;

uint8_t direction = up;
uint8_t snake[MAX_LENGTH][3];




void snake_tests(){

	snake_init(snake);

	snake_print(snake);

	snake_move(up, snake);
	snake_print(snake);

	snake_move(right, snake);
	snake_print(snake);

	snake_move(right, snake);
	snake_print(snake);

	snake_move(down, snake);

	snake_print(snake);
}

void snake_init(int snake[][3]){
	slength = 1;
	
	snake[0][pos_x] = 5;
	snake[0][pos_y] = 5;
	
	snake[1][pos_x] = 1;
	snake[1][pos_y] = 2;
	
	snake[2][pos_x] = 2;
	snake[2][pos_y] = 2;


}

void snake_run(int snake[][3]){


	snake_init(snake);
	
	while (1){
		snake_print(snake);
		
		oled_clear_screen();
		
		//oled_store((char[2]){full_square}, (int[2]){0,2*8});
		
		oled_refresh_60Hz();
		
	/*	if(joystick_x_value() > 70)
			snake_move(snake, right);
		_delay_ms(400);
		*/
		
		if(button_left_read()){
			return;
		}
	}
	

}



/*
void snake_print_part(){

	
}

*/

void snake_print(int snake[MAX_LENGTH][3]){

	oled_clear_screen();
	

	
	for (uint8_t i = 0; i < slength; i++){
		oled_store((char[2]){"O"}, (int[2]){abs(snake[i][2] - 8), snake[i][0]*8});

	}

}

int snake_self_collide(int snake[][3]){

	for (int i = 0; i < MAX_LENGTH; i++){
		if (snake[i][pos_x] == snake[0][pos_x] && snake[i][1] == snake[i][pos_y])
			return 1;
	}
	return 0;
}


void snake_move(int direction, int snake[MAX_LENGTH][3]){

	int x = x_no_dir;
	int y = y_no_dir;

	switch (direction){
	case up:
		y = y_up;
	case down:
		y = y_down;
	}
	switch (direction){
	case left:
		x = x_left;
	case right:
		x = x_right;
	}


	for (int point = slength -1; point > 0; point--){
		snake[point][pos_x] = snake[point - 1][pos_x];
		snake[point][pos_y] = snake[point - 1][pos_y];
	}
	
	snake[0][pos_x] = snake[0][pos_x] + x;
	snake[0][pos_y] = snake[0][pos_y] + y;
}

/*
int snake_boarder_reached(int snake[MAX_LENGTH][3]){
	if (snake[0][pos_x] >= SCREEN_WIDTH || snake[0][pos_y] >= SCREEN_HEIGHT)
		return 1;
	else
		return 0;
}*/

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
