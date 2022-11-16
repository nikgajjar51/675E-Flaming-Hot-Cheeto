#include "main.h"
void intake_in() { intake.move_voltage(12000); }
void intake_out_slow() { intake.move_voltage(-6000); }
void intake_out_fast(){ intake.move_voltage(-12000); }
void intake_stop() { intake.move_velocity(0); }
void flywheel_low() { flywheel.move_voltage(10000); }
void flywheel_high() { flywheel.move_voltage(11000); }
void flywheel_ultra_high() { flywheel.move_voltage(12000); }
void flywheel_stop() { flywheel.move_velocity(0); }
int single_shoot_function() {
  int single_shoot_timer = 0;
  indexer_pneum.set_value(true);
  pros::delay(single_shoot_timer + 500);
  indexer_pneum.set_value(false);
  pros::delay(single_shoot_timer + 1000);
  return single_shoot_timer;
}
int double_shoot_function() {
  int double_shoot_timer = 0;
  indexer_pneum.set_value(true);
  pros::delay(double_shoot_timer + 500);
  indexer_pneum.set_value(false);
  pros::delay(double_shoot_timer + 1000);
  indexer_pneum.set_value(true);
  pros::delay(double_shoot_timer + 500);
  indexer_pneum.set_value(false);
  pros::delay(double_shoot_timer + 1000);
  return double_shoot_timer;
}
int triple_shoot_function() {
  int triple_shoot_timer = 0;
  indexer_pneum.set_value(true);
  pros::delay(triple_shoot_timer + 500);
  indexer_pneum.set_value(false);
  pros::delay(triple_shoot_timer + 1000);
  indexer_pneum.set_value(true);
  pros::delay(triple_shoot_timer + 500);
  indexer_pneum.set_value(false);
  pros::delay(triple_shoot_timer + 1000);
  indexer_pneum.set_value(true);
  pros::delay(triple_shoot_timer + 500);
  indexer_pneum.set_value(false);
  pros::delay(triple_shoot_timer + 1000);
  return triple_shoot_timer;
}
void single_shoot() { pros::Task single_shoot_task(single_shoot_function); }
void double_shoot() { pros::Task single_shoot_task(double_shoot_function); }
void triple_shoot() { pros::Task triple_shoot_task(triple_shoot_function); }
