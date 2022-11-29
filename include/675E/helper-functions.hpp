#pragma once
#include "api.h"
extern bool alliance_selector_toggle, alliance_color;
extern std::string alliance_color_string;
void alliance_selector_function();
void intake_in_fast();
void intake_in_slow();
void intake_out_slow();
void intake_out_fast();
void intake_stop();
void flywheel_low();
void flywheel_idle();
void flywheel_high();
void flywheel_ultra_high();
void flywheel_stop();
void drive_lock();
extern int double_shoot_function();
extern int single_shoot_function();
extern int triple_shoot_function();
extern int spin_to_blue_function();
extern int spin_to_red_function();
void triple_shoot();
void single_shoot();
void double_shoot();
void spin_to_red();
void spin_to_blue();