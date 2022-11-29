#pragma once
#include "EZ-Template/drive/drive.hpp"
extern Drive chassis;
extern bool triple_shooter_toggle, drive_lock_toggle;
extern int toggle_drive_lock();
void flywheel_manual_control(void);
void intake_manual_control(void);
void expansion_manual_control(void);
void drive_lock_control(void);