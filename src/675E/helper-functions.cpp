#include "675E/helper-functions.hpp"

#include <string>

#include "autons.hpp"
#include "main.h"
#include "pros/rtos.hpp"

bool drive_lock_toggle;
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
void drive_lock() {
  if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_Y) && drive_lock_toggle) {
    drive_lock_toggle = !drive_lock_toggle;
    chassis.set_drive_brake(pros::E_MOTOR_BRAKE_COAST);
    chassis.set_active_brake(0.0);
    master.rumble("-");
  } else if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_Y) && !drive_lock_toggle) {
    drive_lock_toggle = !drive_lock_toggle;
    chassis.set_drive_brake(pros::E_MOTOR_BRAKE_HOLD);
    chassis.reset_drive_sensor();
    chassis.set_active_brake(0.1);
    master.rumble("..");
  }
}
/*int detect_roller_color() {
  std::string desired_color;
  if (desired_color == "red") {
  }
  while (roller_optical.get_rgb()  {0, 0, 0, 0}){
    intake_out();
  }
    return is_roller_at_desired_color;
}*/
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
  double initial_angle = chassis.get_gyro();
  chassis.set_turn_pid(180, 100);
  double final_angle = chassis.get_gyro();
  return initial_angle - final_angle;
}
void triple_shoot() {
  pros::Task triple_shooter_task(triple_shoot_function);
}
void turn_pid_180() {
  pros::Task turn_pid_180_task(turn_pid_180_function);
}