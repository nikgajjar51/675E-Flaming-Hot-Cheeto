#include "675E/autons.hpp"
#include "main.h"
const double high_speed_multiplier = 4, normal_speed_multiplier = 2,
             low_speed_multiplier = 1;
const int drive_speed = 25, turn_speed = 15, swing_speed = 15;
void default_constants() {
  chassis.set_slew_min_power(80, 80);
  chassis.set_slew_distance(7, 7);
  chassis.set_pid_constants(&chassis.headingPID, 11, 0, 20, 0);
  chassis.set_pid_constants(&chassis.forward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.backward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.turnPID, 5, 0.003, 35, 15);
  chassis.set_pid_constants(&chassis.swingPID, 7, 0, 45, 0);
}
void exit_condition_defaults() {
  chassis.set_exit_condition(chassis.turn_exit, 100, 3, 500, 7, 500, 500);
  chassis.set_exit_condition(chassis.swing_exit, 100, 3, 500, 7, 500, 500);
  chassis.set_exit_condition(chassis.drive_exit, 80, 50, 300, 150, 500, 500);
}
void modified_exit_condition() {
  chassis.set_exit_condition(chassis.turn_exit, 100, 3, 500, 7, 500, 500);
  chassis.set_exit_condition(chassis.swing_exit, 100, 3, 500, 7, 500, 500);
  chassis.set_exit_condition(chassis.drive_exit, 80, 50, 300, 150, 500, 500);
}
void wait_until_change_speed() {
  // wait_until will wait until the robot gets to a desired position

  // When the robot gets to 6 inches, the robot will travel the remaining
  // distance at a max speed of 40
  chassis.set_drive_pid(24, drive_speed, true);
  chassis.wait_until(6);
  chassis.set_max_speed(40); // After driving 6 inches at drive_speed, the robot
                             // will go the remaining distance at 40 speed
  chassis.wait_drive();

  chassis.set_turn_pid(45, turn_speed);
  chassis.wait_drive();

  chassis.set_turn_pid(-45, turn_speed);
  chassis.wait_drive();

  chassis.set_turn_pid(0, turn_speed);
  chassis.wait_drive();

  // When the robot gets to -6 inches, the robot will travel the remaining
  // distance at a max speed of 40
  chassis.set_drive_pid(-24, drive_speed, true);
  chassis.wait_until(-6);
  chassis.set_max_speed(40); // After driving 6 inches at drive_speed, the robot
                             // will go the remaining distance at 40 speed
  chassis.wait_drive();
}
void swing_example() {
  // The first parameter is ez::LEFT_SWING or ez::RIGHT_SWING
  // The second parameter is target degrees
  // The third parameter is speed of the moving side of the drive

  chassis.set_swing_pid(ez::LEFT_SWING, 45, swing_speed);
  chassis.wait_drive();

  chassis.set_drive_pid(24, drive_speed, true);
  chassis.wait_until(12);

  chassis.set_swing_pid(ez::RIGHT_SWING, 0, swing_speed);
  chassis.wait_drive();
}
void combining_movements() {
  chassis.set_drive_pid(24, drive_speed, true);
  chassis.wait_drive();

  chassis.set_turn_pid(45, turn_speed);
  chassis.wait_drive();

  chassis.set_swing_pid(ez::RIGHT_SWING, -45, turn_speed);
  chassis.wait_drive();

  chassis.set_turn_pid(0, turn_speed);
  chassis.wait_drive();

  chassis.set_drive_pid(-24, drive_speed, true);
  chassis.wait_drive();
}
void tug(int attempts) {
  for (int i = 0; i < attempts - 1; i++) {
    // Attempt to drive backwards
    printf("i - %i", i);
    chassis.set_drive_pid(-12, 127);
    chassis.wait_drive();

    // If failsafed...
    if (chassis.interfered) {
      chassis.reset_drive_sensor();
      chassis.set_drive_pid(-2, 20);
      pros::delay(1000);
    }
    // If robot successfully drove back, return
    else {
      return;
    }
  }
}
// If there is no interference, robot will drive forward and turn 90 degrees.
// If interfered, robot will drive forward and then attempt to drive backwards.
void interfered_example() {
  chassis.set_drive_pid(24, drive_speed, true);
  chassis.wait_drive();

  if (chassis.interfered) {
    tug(3);
    return;
  }

  chassis.set_turn_pid(90, turn_speed);
  chassis.wait_drive();
}
// Right Side Auton: 3 disks high goal
void right_side_1() {
  // Start the flywheel - Allow it to reach high speed in time
  flywheel_high();
  // Go forward - Approach the disk
  chassis.set_drive_pid(18, drive_speed * high_speed_multiplier);
  chassis.wait_drive();
  // Start the intake
  intake_in_fast();
  // Go Forward - To start intaking
  chassis.set_drive_pid(15, drive_speed * high_speed_multiplier);
  chassis.wait_drive();
  // Turn - Towards the other 2 disks
  chassis.set_swing_pid(ez::LEFT_SWING, -45,
                        drive_speed * high_speed_multiplier);
  // chassis.set_turn_pid(-45, drive_speed_high);
  chassis.wait_drive();
  // Go Forward - At a lower speed to continue intaking without jamming
  chassis.set_drive_pid(33, drive_speed * high_speed_multiplier);
  chassis.wait_drive();
  // Turn - Towards the goal
  chassis.set_turn_pid(-135, drive_speed * high_speed_multiplier);
  chassis.wait_drive();
  // Go Forward - approach the low goal
  chassis.set_drive_pid(-7, drive_speed * high_speed_multiplier);
  chassis.wait_drive();
  // Stop the intake
  intake_stop();
  // Shoot the 3 disks
  // Wait - Make the disks are shot before stopping the flywheel
  pros::delay(triple_shoot_function() + 500);
  // Stop the flywheel
  flywheel_stop();
}
// Right Side Auton: Rollers and 5 disks high goal
void right_side_2() {
  // Start the flywheel - Allow it to reach high speed in time
  flywheel_high();
  // Go Backwards - Move to position to shoot disks
  chassis.set_drive_pid(-20, drive_speed * low_speed_multiplier);
  chassis.wait_drive();
  // Turn - Aim towards the high goal
  chassis.set_turn_pid(25, turn_speed * high_speed_multiplier);
  chassis.wait_drive();
  // Shoot the 2 disks
  pros::c::delay(1000);
  pros::delay(double_shoot_function());
  // Swing - Away from the roller to face the roller mech with the roller
  chassis.set_swing_pid(ez::LEFT_SWING, -75,
                        turn_speed * high_speed_multiplier);
    chassis.wait_drive();
  // Go Forward - Move towards the roller
  chassis.set_drive_pid(28, drive_speed * high_speed_multiplier);
  chassis.wait_drive();
  // Swing - To the 0 postion of the IMU to be in line with the roller
  chassis.set_swing_pid(ez::LEFT_SWING, 0, turn_speed * high_speed_multiplier);
  chassis.wait_drive();
  intake_in_fast();
  // Move Forwards - Towards the roller to spin it
  chassis.set_drive_pid(18, drive_speed * high_speed_multiplier);
  chassis.wait_drive();
  // Wait for the robot to move the roller (TODO: Replace with color detect)
  pros::c::delay(500);
  // Stop the intake
  intake_stop();
  // Go Backwards - Move away from the roller
  chassis.set_drive_pid(-2, drive_speed * high_speed_multiplier);
  chassis.wait_drive();
  // Turn around - face the intake to the disks
  chassis.set_turn_pid(135, turn_speed * high_speed_multiplier);
  chassis.wait_drive();
  // Re-Start the intake
  intake_in_fast();
  // Start the flywheel
  flywheel_high();
  // Move to collect the 3 disks
  chassis.set_drive_pid(100, drive_speed * high_speed_multiplier);
  chassis.wait_drive();
  // flywheel_stop();
}
// Right Side Auton: Roller only
void right_side_3() {
  chassis.set_drive_pid(-12, drive_speed * high_speed_multiplier);
  chassis.wait_drive();
  chassis.set_swing_pid(ez::LEFT_SWING, -70,
                        turn_speed * high_speed_multiplier);
  chassis.wait_drive();
  chassis.set_drive_pid(28, drive_speed * high_speed_multiplier);
  chassis.wait_drive();
  chassis.set_swing_pid(ez::LEFT_SWING, 0, turn_speed * high_speed_multiplier);
  chassis.wait_drive();
  chassis.set_drive_pid(15, drive_speed * high_speed_multiplier);
  chassis.wait_drive();
  spin_to_red();
}
// Right Side Auton: 2 Preloads and roller
void right_side_4() {
  flywheel_ultra_high();
  chassis.set_drive_pid(-12, drive_speed * high_speed_multiplier);
  chassis.wait_drive();
  chassis.set_turn_pid(25, turn_speed * high_speed_multiplier);
  chassis.wait_drive();
  pros::delay(double_shoot_function());
  chassis.set_swing_pid(ez::LEFT_SWING, -70,
                        turn_speed * high_speed_multiplier);
  chassis.wait_drive();
  chassis.set_drive_pid(28, drive_speed * high_speed_multiplier);
  chassis.wait_drive();
  intake_in_fast();
  chassis.set_swing_pid(ez::LEFT_SWING, 0, turn_speed * high_speed_multiplier);
  chassis.wait_drive();
  chassis.set_drive_pid(18, drive_speed * high_speed_multiplier);
  chassis.wait_drive();
}
// Left Side Auton: Roller only
void left_side_1() {
  intake_out_fast();
  pros::delay(500);
  intake_stop();
}
// Left Side Auton: Roller and 5 disks high goals
void left_side_2() {}
void play_it_safe(){
  
}