#pragma once

#include <stdint.h>


typedef enum{ left = -1, right = 1, down = -2, up = 2, none = 0 } dir;
void snake_init(int8_t snake[][3]);
void snake_run();

void snake_print_part(int8_t snake[][3], int8_t index);

void snake_print(int8_t snake[][3]);

void snake_move(dir direction, int8_t snake[][3]);
int8_t snake_boarder_reached(int8_t snake[][3]);
int8_t snake_self_collide(int8_t snake[][3]);

void snake_add_size(int8_t snake[][3]);
void snake_make_apple();

void snake_game_over();

void snake_tests();
void snake_settings();