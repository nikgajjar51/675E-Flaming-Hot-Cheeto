#include "main.h"
pros::Motor intake(6,pros::E_MOTOR_GEARSET_06, false,pros::E_MOTOR_ENCODER_ROTATIONS);
pros::Motor flywheel(2,pros::E_MOTOR_GEARSET_06, true,pros::E_MOTOR_ENCODER_ROTATIONS);
pros::ADIDigitalOut indexer('H', false);
pros::ADIDigitalOut expansion('G', true);