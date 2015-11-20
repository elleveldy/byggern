

#include "Display/oled.h"
#include "input.h"
#include "Display/font.h"
#include "timer.h"
#include <stdlib.h> //abs
#include <stdint.h>
#include <avr/io.h> //allows rand??

#include <util/delay.h>

#include "snake.h"




//typedef enum{ x_left = -1, x_no_dir = 0, x_right = 1 } x_dir;
int8_t x_left = -1, x_no_dir = 0, x_right = 1;
int8_t y_down = -1, y_no_dir = 0, y_up = 1;

//typedef enum{ y_down = -1, y_no_dir = 0, y_up = 1 } y_dir;
typedef enum{ pos_x = 0, pos_y = 1, pos_bool = 2 }s_position;

#define MAX_LENGTH 16
uint8_t slength;

uint8_t s_difficulty = 1;

dir direction = up;
int8_t snake[MAX_LENGTH][3];
uint8_t apple[3]; //x,y,bool isapple

uint8_t snake_points;

//iff boarderds = 0, we can pass through walls
uint8_t no_walls = 1; 

#define THRESHOLD 70


void snake_tests(){

}

void snake_init(int8_t snake[][3]){
	
	slength = 3;
	
	snake[0][pos_x] = 0;
	snake[0][pos_y] = 0;
	
	snake[1][pos_x] = 0;
	snake[1][pos_y] = 1;
	
	snake[2][pos_x] = 0;
	snake[2][pos_y] = 2;


}

void snake_run(){
	_delay_ms(200);

	snake_init(snake);
	snake_print(snake);

	uint16_t delay = 15000 / (s_difficulty * 1.0);

	
	while (1){
		
			
			
		if(timer_read(TIMER_3) > delay){
			timer_reset(TIMER_3);
			
			if(joystick_x_value() > THRESHOLD && (direction != left)){
				direction = right;
			}
			else if(joystick_x_value() < -THRESHOLD && (direction != right)){
				direction = left;
			}
			else if(joystick_y_value() > THRESHOLD && (direction != down)){
				direction = up;
			}
			else if(joystick_y_value() < -THRESHOLD && (direction != up)){
				direction = down;
			}
			
			if(button_right_read()){
				snake_add_size(snake);

				
			}
			
			
			
			snake_move(direction, snake);
			
			
			//if we hit border
			if((snake[0][pos_x] > 15) || (snake[0][pos_x] < 0)){
				snake_game_over();
			}
			if((snake[0][pos_y] > 7) || (snake[0][pos_y] < 0)){
				snake_game_over();
			}
			
			//if snake head position == apple position
			if((snake[0][pos_x] == apple[0]) && (snake[0][pos_y] == apple[1]) && (apple[2])){
				//apple bool value = 0, add snake size
				apple[2] = 0;
				snake_points++;
				snake_add_size(snake);
			}
			if(!(apple[2])){
				snake_make_apple();
			}
			
			if(snake_self_collide(snake)){
				snake_game_over();
			}
			
			snake_print(snake);

		
			oled_write_screen();
		
		
		}
		
		//leave game
		if(button_left_read()){
			return;
		}
	}
	

}

void snake_settings(){
	uint8_t difficulty;
	

	while(1){
		
		
		difficulty = slider_right_read();
		
		if(timer_read(TIMER_3) > 1000){
			
			oled_clear_screen();
			oled_put_string(0*8, 0, "Set difficulty");
			oled_put_string(0, 1, "Difficulty:%u", difficulty);
			oled_put_string(0, 3, "Walls");
			if(no_walls){
				oled_put_string(7*8,3,"OFF");
			}
			else{
				oled_put_string(7*8,3,"ON");
			}
			
			oled_write_screen();
			if(button_right_read()){
				if(no_walls){
					no_walls = 0;
				}
				else{
					no_walls = 1;
				}
			}
			
			timer_reset(TIMER_3);
		}
		
		if(button_left_read()){
			if(difficulty < 1){
				s_difficulty = 1;
			}
			s_difficulty = difficulty / 4;
			return;
		}
	}
}

void snake_game_over(){
	
	oled_clear_screen();
	oled_put_string(3*8, 0, "GAME OVER");
	/*oled_put_string(0*8, 5, "Score:");*/
	
	oled_write_screen();
	while(1){
		
		if(button_left_read()){
			return;
		}
	
	}
	
}


void snake_print(int8_t snake[MAX_LENGTH][3]){

	oled_clear_screen();

	for (uint8_t i = 0; i < slength; i++){
		oled_put_string(snake[i][pos_x]*8, abs(snake[i][pos_y] - 7), "O");
	}
	if(apple[2]){
		oled_put_string(apple[0] * 8, abs(apple[1] - 7), "Q");
	}
	
	oled_write_screen();

}

int8_t snake_self_collide(int8_t snake[MAX_LENGTH][3]){

	for (uint8_t i = 1; i < slength; i++){
		if((snake[i][pos_x] == snake[0][pos_x]) && (snake[i][pos_y] == snake[0][pos_y]) && (snake[i][pos_bool]))
			return 1;
	}
	return 0;
}

void snake_make_apple(){
	
	srand(timer_read(TIMER_1));
	uint8_t x = rand() % 15;
	uint8_t y = rand() % 7;
	
	apple[0] = x;
	apple[1] = y;
 	apple[2] = 1;
	
}




void snake_move(dir direction, int8_t snake[MAX_LENGTH][3]){

	int8_t x = x_no_dir;
	int8_t y = y_no_dir;

	
	if(direction == up){
		y = y_up;
	}
	else if(direction == down){
		y = y_down;
	}
	else if(direction == left){
		x = x_left;
	}
	else if(direction == right){
		x = x_right;
	}


	for (int8_t point8_t = slength -1; point8_t > 0; point8_t--){
		snake[point8_t][pos_x] = snake[point8_t - 1][pos_x];
		snake[point8_t][pos_y] = snake[point8_t - 1][pos_y];
	}
	
	snake[0][pos_x] = snake[0][pos_x] + x;
	snake[0][pos_y] = snake[0][pos_y] + y;
	
	if(no_walls){
		if(snake[0][pos_x] > 15){
			snake[0][pos_x] = 0;
		}
		else if(snake[0][pos_x] < 0){
			snake[0][pos_x] = 15;

		}
		if(snake[0][pos_y] > 7){
			snake[0][pos_y] = 0;
		}
		else if(snake[0][pos_y] < 0){
			snake[0][pos_y] = 7;

		}
			
		
	}
}


void snake_add_size(int8_t snake[8][3]){
	//increases slength, sets correct initial position and bool = 1

	int8_t x;
	int8_t y;

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
