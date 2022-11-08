#include "main.h"
// Chassis constructor
Drive chassis(
    // Left Chassis Ports (negative port will reverse it)
    {-15, -14, -13}
    // Right Chassis Ports (negative port will reverse i)
    ,
    {20, 19, 18}
    // Inertial Sensor Port
    ,
    11
    // Wheel Diameter
    ,
    3.25
    // Cartridge RPM
    ,
    600
    // External Gear Ratio
    ,
    1.66);
void initialize() {
  ez::print_ez_template();
  pros::delay(500);
  chassis.toggle_modify_curve_with_controller(false);
  chassis.set_active_brake(0.1);
  chassis.set_curve_default(2, 2);
  default_constants();
  ez::as::auton_selector.add_autons({
      Auton("Auton for starting line \n 2 tiles away from edge of field", side_2_tiles),
      Auton("Auton for starting line \n 1 tile away from edge of field", side_1_tile),
  });
  chassis.initialize();
  ez::as::initialize();
}
void disabled() {
}

void competition_initialize() {
}
void autonomous() {
  // Resets PID targets to 0
  chassis.reset_pid_targets();
  // Reset gyro position to 0
  chassis.reset_gyro();
  // Reset drive sensors to 0
  chassis.reset_drive_sensor();
  // Set motors to hold.  This helps autonomous consistency.
  chassis.set_drive_brake(MOTOR_BRAKE_HOLD);
  // Calls selected auton from autonomous selector.
  ez::as::auton_selector.call_selected_auton();
}

void opcontrol() {
  // Boolean to set the triple shooter on or off
  //   0 is off (single shooter)
  //   1 is on (triple shooter)
  triple_shooter = 0;
  // This is preference to what you like to drive on.
  chassis.set_drive_brake(MOTOR_BRAKE_COAST);
  flywheel.set_brake_mode(MOTOR_BRAKE_COAST);
  intake.set_brake_mode(MOTOR_BRAKE_COAST);
  while (true) {
    intake_control();
    flywheel_control();
    expansion_control();
    drive_lock_control();
    // EZ-Template's function for drive code
    chassis.arcade_standard(ez::SPLIT);
    // Used for timer calculations(ez::util::DELAY_TIME = 10)
    pros::delay(ez::util::DELAY_TIME);
  }
}