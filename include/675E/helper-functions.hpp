#include "api.h"
extern bool alliance_selector_toggle, alliance_color, is_intake_running,
    is_flywheel_running, is_flywheel_idle;
extern int intake_counter;
extern std::string alliance_color_string;
extern pros::c::optical_rgb_s_t rgb_value;
extern int intake_get_velocity();
extern int single_shoot_function();
extern int double_shoot_function();
extern int triple_shoot_function();
extern int shoot_using_counter_function();
extern int shooter_function();
extern int spin_to_red_function();
extern int spin_to_blue_function();
void initialize_675E();
void alliance_selector_function();
void intake_in_fast();
void intake_in_slow();
void intake_out_fast();
void intake_out_slow();
void intake_stop();
void flywheel_idle();
void flywheel_low();
void flywheel_high();
void flywheel_ultra_high();
void flywheel_stop();
void single_shoot();
void double_shoot();
void triple_shoot();
void shooter();
void spin_to_red();
void spin_to_blue();