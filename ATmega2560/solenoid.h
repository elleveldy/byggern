
void solenoid_init();
void solenoid_shoot();

void solenoid_extend();
void solenoid_retract();

//

void solenoid_disallow_shooting();
void solenoid_allow_shooting();
uint8_t solenoid_is_shooting_allowed();