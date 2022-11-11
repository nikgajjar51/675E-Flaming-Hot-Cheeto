#pragma once
#include "EZ-Template/drive/drive.hpp"
extern Drive chassis;
extern bool triple_shooter_toggle, drive_lock_toggle;
void flywheel_control(void);
void intake_control(void);
void expansion_control(void);
void drive_lock_control(void);