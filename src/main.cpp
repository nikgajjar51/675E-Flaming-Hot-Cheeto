#include "main.h"
// Chassis constructor
Drive chassis(
    // Left Chassis Ports (negative port will reverse it!)
    {-20, -19, -18}
    // Right Chassis Ports (negative port will reverse it!)
    ,
    {15, 14, 13}
    // IMU Port
    ,
    11
    // Wheel Diameter
    ,
    3.25
    // Cartridge RPM
    ,
    600
    // External Gear Ratio (MUST BE DECIMAL)
    ,
    1.66);
void initialize() {
  ez::print_ez_template();
  pros::delay(500);
  chassis.toggle_modify_curve_with_controller(true);
  chassis.set_active_brake(0.1);
  chassis.set_curve_default(2, 2);
  default_constants();
  ez::as::auton_selector.add_autons({
      Auton("Example Drive\n\nDrive forward and come back.", drive_example),
  });
  chassis.initialize();
  ez::as::initialize();
}
void disabled() {
}

void competition_initialize() {
}
void autonomous() {
  chassis.reset_pid_targets();                   // Resets PID targets to 0
  chassis.reset_gyro();                          // Reset gyro position to 0
  chassis.reset_drive_sensor();                  // Reset drive sensors to 0
  chassis.set_drive_brake(MOTOR_BRAKE_HOLD);     // Set motors to hold.  This helps autonomous consistency.
  ez::as::auton_selector.call_selected_auton();  // Calls selected auton from autonomous selector.
}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {
  // This is preference to what you like to drive on.
  chassis.set_drive_brake(MOTOR_BRAKE_COAST);
  while (true) {
    intake_control();
    flywheel_control();
    expansion_control();
    chassis.arcade_standard(ez::SPLIT);
    pros::delay(ez::util::DELAY_TIME);  // This is used for timer calculations!  Keep this ez::util::DELAY_TIME
  }
}