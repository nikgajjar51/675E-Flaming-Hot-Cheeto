#include "autons.hpp"
#include "main.h"
bool triple_shooter_toggle, drive_lock_toggle;
void flywheel_control() {
  if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R1) == 1 && master.get_digital(pros::E_CONTROLLER_DIGITAL_R2) == 1) {
    if (triple_shooter_toggle == 0) {
      indexer_pneum.set_value(true);
    } else if (triple_shooter_toggle == 1) {
      triple_shoot();
    }
  } else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R1) == 1) {
    indexer_pneum.set_value(false);
    flywheel_high();
  } else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R2) == 1) {
    indexer_pneum.set_value(false);
    flywheel_low();
  } else {
    indexer_pneum.set_value(false);
    flywheel_stop();
  }
}
void intake_control() {
  if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L1) == 1) {
    intake_in();
  } else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L2) == 1) {
    intake_out();
  } else {
    intake_stop();
  }
}
void expansion_control() {
  if (master.get_digital(pros::E_CONTROLLER_DIGITAL_LEFT) == 1 && master.get_digital(pros::E_CONTROLLER_DIGITAL_A) == 1 && master.get_digital(pros::E_CONTROLLER_DIGITAL_UP) == 1 && master.get_digital(pros::E_CONTROLLER_DIGITAL_X) == 1) {
    expansion_pneum.set_value(true);
  } else {
    expansion_pneum.set_value(false);
  }
}
void toggle_drive_lock() {
  if (drive_lock_toggle) {
    drive_lock_toggle = !drive_lock_toggle;
    chassis.set_drive_brake(pros::E_MOTOR_BRAKE_COAST);
    chassis.set_active_brake(0.0);
    master.rumble("-");
  } else {
    drive_lock_toggle = !drive_lock_toggle;
    chassis.set_drive_brake(pros::E_MOTOR_BRAKE_HOLD);
    chassis.reset_drive_sensor();
    chassis.set_active_brake(0.1);
    master.rumble("..");
  }
}

void drive_lock_control() {
  if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_Y)) {
    toggle_drive_lock();
  }
}