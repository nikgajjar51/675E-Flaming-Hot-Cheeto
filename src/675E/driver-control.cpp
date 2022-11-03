#include <ratio>

#include "main.h"

// flywheel_control(): Controls the flywheel and indexer mechanism.
//   When the R1 button is pressed, the fywheel spins at "high speed"
//   When the R2 button is pressed, the fywheel spins at "low speed"
//   When both the R1 and R2 buttons are pressed, the indexer fires to launch the disk
void flywheel_control() {
  // The if-statement for if both the R1 and R2 buttons are pressed
  //   This needs to come first as if this is false, the rest of the functions will follow through.
  //   If this was later on in the if-else chain, it would never fire as other conditions would be met BEFORE coming to this one
  if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R1) == 1 && master.get_digital(pros::E_CONTROLLER_DIGITAL_R2) == 1) {
    // Sets the indexer pneumatic to true (towards the flywheel in this case)
    indexer.set_value(true);
  } else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R1) == 1) {
    // Sets the indexer pneumatic to false (away from the flywheel in this case)
    indexer.set_value(false);
    // Spins the flywheel motor at 'high speed' (12000 mV or 12 V)
    flywheel.move_voltage(12000);
  } else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R2) == 1) {
    // Sets the indexer pneumatic to false (away from the flywheel in this case)
    indexer.set_value(false);
    // Spins the flywheel motor at 'low speed' (9000 mV or 9 V)
    flywheel.move_voltage(9000);
  } else {
    // Sets the indexer pneumatic to false (away from the flywheel in this case)
    indexer.set_value(false);
    // Stops the flywheel motor
    flywheel.move_voltage(0);
  }
}

// intake_control(): Controls the intake and roller mechanism
//   When the L1 button is pressed, the intake intakes at a "high speed"
//   When the L2 button is pressed, the intake spins in reverse at a "low speed" to un-jam and spin the roller mechanism with more torque.
//   When both the L1 and L2 buttons are pressed, the intake spins 
void intake_control() {
  // 
  if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L1) == 1) {
    intake.move_voltage(12000);
  } else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L2) == 1) {
    intake.move_voltage(-6000);
  } else {
    intake.move_voltage(0);
  }
}
void expansion_control() {
  if (master.get_digital(pros::E_CONTROLLER_DIGITAL_LEFT) == 1 && master.get_digital(pros::E_CONTROLLER_DIGITAL_A) == 1 && master.get_digital(pros::E_CONTROLLER_DIGITAL_UP) == 1 && master.get_digital(pros::E_CONTROLLER_DIGITAL_X) == 1) {
    expansion.set_value(false);
  } else {
    expansion.set_value(true);
  }
}