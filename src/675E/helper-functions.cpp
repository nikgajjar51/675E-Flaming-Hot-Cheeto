#include "helper-functions.hpp"
#include "main.h"
#include "pros/rtos.hpp"
void intake_in() {
  intake.move_voltage(12000);
}
void intake_out() {
  intake.move_voltage(-6000);
}
void intake_stop() {
  intake.move_velocity(0);
}
void flywheel_low() {
  flywheel.move_voltage(9000);
}
void flywheel_high() {
  flywheel.move_voltage(12000);
}
void flywheel_stop() {
  flywheel.move_velocity(0);
}
int single_shoot_function() {
  int single_shoot_timer = 0;
  indexer_pneum.set_value(true);
  pros::delay(single_shoot_timer + 500);
  indexer_pneum.set_value(false);
  pros::delay(single_shoot_timer + 1500);
  return single_shoot_timer;
}
int triple_shoot_function() {
  int counter, triple_shoot_timer = 0;
  for (int i; i < 3; i++) {
    indexer_pneum.set_value(true);
    pros::delay(triple_shoot_timer + 500);
    indexer_pneum.set_value(false);
    pros::delay(triple_shoot_timer + 1500);
    counter++;
  }
  return triple_shoot_timer;
}
void triple_shoot() {
  pros::Task triple_shoot_task(triple_shoot_function);
}
void single_shoot() {
  pros::Task single_shoot_task(single_shoot_function);
}