#include "autons.hpp"
#include "main.h"
#include "675E/helper-functions.hpp"
#include "pros/llemu.hpp"
#include "pros/misc.h"
#include "pros/rtos.hpp"

void triple_shooter_macro() {
  indexer.set_value(true);
  pros::delay(10);
  indexer.set_value(false);
  pros::delay(500);
  indexer.set_value(true);
  pros::delay(10);
  indexer.set_value(false);
  pros::delay(500);
  indexer.set_value(true);
  pros::delay(10);
  indexer.set_value(false);
  pros::delay(500);
}