#pragma once

#include "EZ-Template/drive/drive.hpp"
#include "autons.hpp"

extern Drive chassis;

void wait_until_change_speed();
void swing_example();
void combining_movements();
void interfered_example();

void default_constants();
void one_mogo_constants();
void two_mogo_constants();
void exit_condition_defaults();
void modified_exit_condition();
void left_side_auton();
void right_side_auton();