#include "helper-functions.hpp"
#include "main.h"
#include "pros/rtos.hpp"
#include <string>
bool alliance_selector_toggle = 0, alliance_color;
std::string alliance_color_string;
pros::c::optical_rgb_s_t rgb_value = roller_optical.get_rgb();
// Alliance Selector - Push a button to set the alliance color for rollers in
// autonomous.
void alliance_selector_function() {
  if (alliance_selector_button.get_value() == 1) {
    if (alliance_selector_toggle) {
      alliance_selector_toggle = !alliance_selector_toggle;
      alliance_color_string = "Blue";
      alliance_color = 0;
      pros::c::controller_clear_line(pros::E_CONTROLLER_MASTER, 1);
      pros::c::controller_print(pros::E_CONTROLLER_MASTER, 1, 1, "Blue");
    } else {
      alliance_selector_toggle = !alliance_selector_toggle;
      alliance_color_string = "Red";
      alliance_color = 1;
      pros::c::controller_clear_line(pros::E_CONTROLLER_MASTER, 1);
      pros::c::controller_print(pros::E_CONTROLLER_MASTER, 1, 1, "Red");
    }
  }
}
// Intake In - Fast speed for intaking and rollers.
void intake_in() { intake.move_voltage(12000); }
// Intake Out (Slow Speed) - More torque for more precise roller control
void intake_out_slow() { intake.move_voltage(-6000); }
// Intake Out (Fast Speed) -  For unjamming the intake and rollers in the other
//                            direction
void intake_out_fast() { intake.move_voltage(-12000); }
// Intake Stop - Stop the intake (using velocity because?)
void intake_stop() { intake.move_velocity(0); }
// Flywheel (Low Speed) - Lower speed for closer shots(Set by benny :D )
void flywheel_low() { flywheel.move_voltage(10000); }
// Flywheel (High Speed) - Higher speed for more distant shots or for jiggling
//                         basket around to shift disks (Set by benny :D )
void flywheel_high() { flywheel.move_voltage(11000); }
// Flywheel (Ultra High Speed) - The ultra nightmare setting in case we come up
//                               against 4082B and need to just go full ham
void flywheel_ultra_high() { flywheel.move_voltage(12000); }
// Flywheel Stop - Stop the flywheel (using velocity because?)
void flywheel_stop() { flywheel.move_velocity(0); }
// Single Shoot Function - Shoot a single disk
int single_shoot_function() {
  int single_shoot_timer = 0;
  indexer_pneum.set_value(true);
  pros::delay(single_shoot_timer + 500);
  indexer_pneum.set_value(false);
  pros::delay(single_shoot_timer + 1000);
  return single_shoot_timer;
}
// Double Shoot Function - Shoot 2 disks, typically for match preloads
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
// Triple Shoot Function - Shoot 3 disks, typically for a full hopper
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
// Spin to Red Function - Spin the roller to the red side using optical
int spin_to_red_function() {
  // Set the threshold for detecting red
  int red_threshold;
  // While the sensor detects less then desired amount of red in the roller
  while (rgb_value.red <= red_threshold) {
    // Spin the intake
    intake_in();
  }
  // Return the red value for debugging purposes
  return rgb_value.red;
}
// Spin to Blue Function - Spin the roller to the blue side using optical
int spin_to_blue_function() {
  // Set the threshold for detecting blue
  int blue_threshold;
  // While the sensor detects less then desired amount of blue in the roller
  while (rgb_value.blue <= blue_threshold) {
    // Spin the intake
    intake_in();
  }
  // Return the blue value for debugging purposes
  return rgb_value.blue;
}

// Tasks!!!!!!!!!!!!!!!

// Single Shoot - Asynchronous so the bot can continue adjusting while shooting
void single_shoot() { pros::Task single_shoot_task(single_shoot_function); }
// Double Shoot - Asynchronous so the bot can continue adjusting while shooting
void double_shoot() { pros::Task single_shoot_task(double_shoot_function); }
// Triple Shoot - Asynchronous so the bot can continue adjusting while shooting
void triple_shoot() { pros::Task triple_shoot_task(triple_shoot_function); }
// Spin to Red - Asynchronous so the bot can continue moving while spinning
void spin_to_red() { pros::Task spin_to_red_task(spin_to_red_function); }
// Spin to Blue - Asynchronous so the bot can continue moving while spinning
void spin_to_blue() { pros::Task spin_to_blue_task(spin_to_blue_function); }