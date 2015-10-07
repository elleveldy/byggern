#include "oled.h"
#include "joystick.h"
#include <stdlib.h>
#include <time.h>
#include <util/delay.h>
#include "snake.h"


typedef enum{left = -1, right = 1, down = -2, up = 2, none = 0} dir;
typedef enum{x_left = -1, x_no_dir = 0, x_right = 1} x_dir;
typedef enum{y_down = -1, y_no_dir = 0, y_up = 1} y_dir;
typedef enum{pos_x= 0, pos_y, pos_bool}


//devide by four, and print 4x4pixel squares?
int WIDTH = 16;
int HEIGHT = 8;
int MAX_LENGTH = 8;


//head
int snake_x;
int snake_y;



int slength;

//{(x,y, bool), (x,y, bool),(x,y, bool)} coordinates and bool
int snake[max_length][3] = {{0,2,1}, {0,1,1}, {0,0,1}}; 


//make arrays for apples?
int apple; //true or false
int apple_x;
int apple_y;


void snake_start_game(){
	int direction = up;

	oled_clear_screen();
	srand(time(NULL));

	snake_make_apple();

	while(1){
		
		snake_move();

		direction = snake_direction();
		
		if(snake_apple_eaten){
			apple = 0;
			snake_add_size();
			snake_make_apple();
		}


		snake_print_snake();
		snake_print_snake();

		if(snake_boarder_reached())
			break;
		if(snake_self_collide())
			break,
		if(button_left_read())
			return;

		_delay_ms(200);

	}

}

void snake_game_over(){

}

void snake_print_part(int x, int y){

}

void snake_print_apple(){
	snake_print_part(apple_x,apple_y);
}


void snake_print_snake(){ //should only erases the pervious last point
	oled_clear_screen();
	for(int i = 0; i < slength; i++){
		snake_print_part(snake[slength][0], snake[slength][1]);
	}
}

int snake_self_collide(){

	for(int i = 0; i < max_length; i ++){
		if(snake[i][0] == snake_x && snake[i][1] == snake_y)
			return 1;
	}
	return 0;
}

void snake_add_size(){
//increases slength, sets correct initial position and bool = 1
	int x;
	int y;

	if(snake[slength - 1][x_pos] < snake[slength - 2][x_pos]){		//tail going right
		
		x = x_left;
	else if(snake[slength - 1][x_pos] > snake[slength - 2][x_pos]){	//tail going left
		x = x_right;
	else													//not moving in x-direction
		x = x_no_dir;


	if(snake[slength - 1][y_pos] < snake[slength - 2][y_pos])		//tail going up
		y = y_down;
	if(snake[slength - 1][y_pos] > snake[slength - 2][y_pos])		//tail going down
		y = y_up;												
	else													//not moving in y-direction													
		y = y_no_dir;

	snake[slength][x_pos] = snake[slength - 1][x_pos] + x;
	snake[slength][y_pos] = snake[slength - 1][y_pos] + y;
	snake[slength][pos_bool] = 1;

	slength++;
}

void snake_move(int dir){

	int x;
	int y;

	switch(dir){
		case up;:
			y = y_up;
		case down:
			y = y_down;
		case left:
			x = x_left;
		case right:
			x = x_right;
	}


	for(int point = slength - 1; point > 0; point--){
		snake[point][x_pos] = snake[point + 1][x_pos];
		snake[point][y_pos] = snake[point + 1][y_pos];
	}
	snake[0][x_pos] = snake[0][x_pos] + x; 
	snake[0][y_pos] = snake[0][y_pos] + y; 
	

}

//direction (one axis at a time)
int snake_direction(){

	//add delay?
	int direction;
	int threshold = 10;
	//too little push on joystick
	if( !(abs(joystick_x_value()) > threshold || abs(joystick_y_value()) > threshold))
		return 0;

	//picks dominant axis
	if(abs(joystick_x_value()) > abs(joystick_y_value())){

		if(joystick_x_value() > 0)
			return right;

		else
			return left;
	}
	else{
		if(joystick_y_value() > 0)
			return up;
		else
			return down;
	}
}

int snake_boarder_reached(){
	if(snake_x >= snake_screen_width || snake_y >= snake_screen_width)
		return 1;
	else
		return 0;
}

int snake_apple_eaten(){
	if((snake[0][x_pos] == apple_x) && (snake[0][y_pos] == apple_y))
		return 1;
	else
		return 0;
}

void snake_make_apple(){
	if(apple)
		return;

	//randomise x between 0 and 128
	apple = 1;
	int x = rand() % snake_screen_width;
	int y = rand() % snake_screen_height;
	//randomise y between 0 and 64
	//set the global variables apple_x and apple_y

	//print apple to oled, which size?                                                                                                                                                                                                       

}