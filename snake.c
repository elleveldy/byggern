//#include "oled.h"
//#include "joystick.h"
//#include <stdlib.h>
//#include <time.h>
//#include <util/delay.h>
//
//
//
//typedef enum{left = -1, x_no_dir = 0, right = 1} x_dir;
//typedef enum{down = -1, y_no_dir = 0, up = 1} y_dir;
//
//
////devide by four, and print 4x4pixel squares?
//int WIDTH = 16;
//int HEIGHT = 8;
//int MAX_LENGTH = 8;
//
//
////head
//int snake_x;
//int snake_y;
//
//
//
//int slength;
//
////{(x,y, bool), (x,y, bool),(x,y, bool)} coordinates and bool
//int snake[max_length][3] = {{0,2,1}, {0,1,1}, {0,0,1}}; 
//
//
////make arrays for apples?
//int apple; //true or false
//int apple_x;
//int apple_y;
//srand(time(NULL));
//
//
//void snake_start_game(){
//
	//while(1){
		//_delay_ms(200);
		//
//
//
		////if left button clicked, return to menu
	//}
//
//}
//
//void snake_game_over(){
//
//}
//
//void snake_print_part(int x, int y){
//
//}
//
//void snake_print_snake(){
	//for(int i = 0; i < slength; i++){
		//snake_print_part(snake[slength][0], snake[slength][1]);
	//}
//}
//
//int snake_self_collide(){
//
	//for(int i = 0; i < max_length; i ++){
		//if(snake[i][0] == snake_x && snake[i][1] == snake_y)
			//return 1;
	//}
	//return 0;
//}
//
//void snake_add_size(){
////increases slength, sets correct initial position and bool = 1
	//int x;
	//int y;
//
	//if(snake[slength - 1][0] < snake[slength - 2][0]){		//tail going right
		//
		//x = left;
	//else if(snake[slength - 1][0] > snake[slength - 2][0]){	//tail going left
		//x = right;
	//else													//not moving in x-direction
		//x = x_no_dir;
//
	//if(snake[slength - 1][1] < snake[slength - 2][1])		//tail going up
		//y = down;
	//if(snake[slength - 1][1] > snake[slength - 2][1])		//tail going down
		//y = up;												
	//else													//not moving in y-direction													
		//y = y_no_dir;
//
	//snake[slength][0] = snake[slength - 1][0] + x;
	//snake[slength][1] = snake[slength - 1][1] + y;
	//snake[snakelength][2] = 1;
//
	//slength++;
//}
//
//
////direction (one axis at a time)
//int snake_direction(){
//
	////add delay?
	//int direction;
	////too little push on joystick
	//if( !(abs(joystick_x_value()) > 10 || abs(joystick_y_value()) > 10))
		//return 0;
//
	////picks dominant axis
	//if(abs(joystick_x_value()) > abs(joystick_y_value())){
//
		//if(joystick_x_value() > 0)
			//return right;
//
		//else
			//return left;
	//}
	//else{
		//if(joystick_y_value > 0)
			//return up;
		//else
			//return down;
	//}
//}
//
//int snake_boarder_reached(){
	//if(snake_x >= snake_screen_width || snake_y >= snake_screen_width)
		//return 1;
	//else
		//return 0;
//}
//
//void snake_make_apple(){
	//
//
	////randomise x between 0 and 128
	//int x = rand() % snake_screen_width;
	//int y = rand() % snake_screen_height;
	////randomise y between 0 and 64
	////set the global variables apple_x and apple_y
//
	////print apple to oled, which size?                                                                                                                                                                                                       
//
//}