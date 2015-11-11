

#define MOTOR_PORT PORTF
#define MOTOR_DDR DDRF

#define MOTOR_FUCKOFF   2
#define MOTOR_DIR		3
#define MOTOR_EN		4
#define MOTOR_SEL		5
#define MOTOR_RESET		6
#define MOTOR_OUTPUT_EN 7
#define MOTOR_STUFF		10

typedef enum motor_dir motor_dir;
enum motor_dir {right, left};

//void motor_enable(uint8_t enable);


void motor_init();
void motor_speed(uint8_t speed);
void motor_direction(uint8_t direction);
void motor_test();