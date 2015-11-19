

typedef enum {TIMER_1, TIMER_2, TIMER_3}timer;

void timer_init();

uint16_t timer_read(timer nr);
void timer_reset(timer nr);

