#pragma once
#include "api.h"
extern bool alliance_selector_toggle, alliance_color;
extern std::string alliance_color_string;
void initialize_675e(void);
void alliance_selector_function(void);
void intake_in_fast(void);
void intake_in_slow(void);
void intake_out_slow(void);
void intake_out_fast(void);
void intake_stop(void);
void flywheel_low(void);
void flywheel_idle(void);
void flywheel_high(void);
void flywheel_ultra_high(void);
void flywheel_stop(void);
extern int double_shoot_function();
extern int single_shoot_function();
extern int triple_shoot_function();
extern int spin_to_blue_function();
extern int spin_to_red_function();
void triple_shoot(void);
void single_shoot(void);
void double_shoot(void);
void spin_to_red(void);
void spin_to_blue(void);