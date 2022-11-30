#include "helper-functions.hpp"
#include "main.h"
bool triple_shooter_toggle, drive_lock_toggle;
void flywheel_manual_control() {
  if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R1) == 1 &&
      master.get_digital(pros::E_CONTROLLER_DIGITAL_R2) == 1) {
    indexer_pneum.set_value(true);
  } else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R1) == 1) {
    indexer_pneum.set_value(false);
    flywheel_high();
  } else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R2) == 1) {
    indexer_pneum.set_value(false);
    flywheel_low();
  } else {
    indexer_pneum.set_value(false);
    flywheel_idle();
  }
}
void intake_manual_control() {
  if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L1) == 1) {
    intake_in_fast();
  } else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L2) == 1) {
    intake_out_fast();
  } else {
    intake_stop();
  }
}
void expansion_manual_control() {
  if (master.get_digital(pros::E_CONTROLLER_DIGITAL_LEFT) == 1 &&
      master.get_digital(pros::E_CONTROLLER_DIGITAL_A) == 1 &&
      master.get_digital(pros::E_CONTROLLER_DIGITAL_UP) == 1 &&
      master.get_digital(pros::E_CONTROLLER_DIGITAL_X) == 1) {
    expansion_pneum.set_value(true);
  } else {
    expansion_pneum.set_value(false);
  }
}
int toggle_drive_lock() {
  if (drive_lock_toggle) {
    drive_lock_toggle = !drive_lock_toggle;
    chassis.set_drive_brake(pros::E_MOTOR_BRAKE_COAST);
    chassis.set_active_brake(0.0);
    master.rumble("-");
    return drive_lock_toggle;
  } else {
    drive_lock_toggle = !drive_lock_toggle;
    chassis.set_drive_brake(pros::E_MOTOR_BRAKE_HOLD);
    chassis.reset_drive_sensor();
    chassis.set_active_brake(0.1);
    master.rumble(". .");
    return drive_lock_toggle;
  }
}

void drive_lock_control() {
  if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_Y)) {
    toggle_drive_lock();
  }
}