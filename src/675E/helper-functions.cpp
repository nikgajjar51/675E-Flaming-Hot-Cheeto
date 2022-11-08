#include "main.h"
#include "pros/misc.h"
#include "robot-config.hpp"
std::string alliance;
bool is_roller_at_desired_color = false;
void intake_in() {
  intake.move_voltage(12000);
}
void intake_out() {
  intake.move_voltage(-6000);
}
void intake_stop() {
  intake.move_voltage(0);
}
void flywheel_low() {
  flywheel.move_voltage(9000);
}
void flywheel_high() {
  flywheel.move_voltage(12000);
}
void flywheel_stop() {
  intake.move_voltage(0);
}
int detect_roller_color_function() {
  pros::c::optical_rgb_s_t rgb_value = roller_optical.get_rgb();
  while (rgb_value.red != 255 || rgb_value.blue != 255) {
    intake_out();
    is_roller_at_desired_color = 1;
  }
  return is_roller_at_desired_color;
}
void single_shoot_function() {
  indexer_pneum.set_value(true);
  pros::delay(100);
  indexer_pneum.set_value(false);
  pros::delay(1000);
}
int triple_shoot_function() {
  indexer_pneum.set_value(true);
  pros::delay(100);
  indexer_pneum.set_value(false);
  pros::delay(1000);
  indexer_pneum.set_value(true);
  pros::delay(100);
  indexer_pneum.set_value(false);
  pros::delay(1000);
  indexer_pneum.set_value(true);
  pros::delay(100);
  indexer_pneum.set_value(false);
  pros::delay(1000);
  return 1;
}
int turn_pid_180_function() {
  if (master.get_digital(pros::E_CONTROLLER_DIGITAL_B) == 1) {
    if (pros::E_CONTROLLER_DIGITAL_B == 1) {
      chassis.set_turn_pid(180, 100);
    }
  }
  return 1;
}
void detect_roller_color() {
  pros::Task detect_roller_color_task(detect_roller_color_function);
}
void triple_shoot() {
  pros::Task triple_shooter_task(triple_shoot_function);
}
void turn_pid_180() {
  pros::Task turn_pid_180_task(turn_pid_180_function, TASK_PRIORITY_DEFAULT, TASK_STACK_DEPTH_DEFAULT, "180 Turn");
}