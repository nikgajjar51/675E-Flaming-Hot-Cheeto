#include "main.h"
void flywheel_control() {
  if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R1) && master.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
    indexer.set_value(true);
  } else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
    flywheel.move_voltage(12);
  } else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
    flywheel.move_voltage(9);
  } else {
    flywheel.move_voltage(0);
  }
}
void intake_control() {
  if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
    intake.move_voltage(10);
  } else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) {
    intake.move_voltage(-10);
  } else {
    intake.move_voltage(0);
  }
}
void expansion_control() {
  if (master.get_digital(pros::E_CONTROLLER_DIGITAL_LEFT) && master.get_digital(pros::E_CONTROLLER_DIGITAL_A) && master.get_digital(pros::E_CONTROLLER_DIGITAL_UP) && master.get_digital(pros::E_CONTROLLER_DIGITAL_X)) {
    expansion.set_value(false);
  }
}