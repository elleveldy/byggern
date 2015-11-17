

void snake_init(int snake[][3]);
void snake_run(int snake[][3]);

void snake_print_part(int snake[][3], int index);

void snake_print(int snake[][3]);

void snake_move(int dir, int snake[][3]);
int snake_boarder_reached(int snake[][3]);
int snake_self_collide(int snake[][3]);

void snake_add_size(int snake[][3]);



void snake_tests();