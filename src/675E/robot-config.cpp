#include "main.h"
pros::Motor intake(5,pros::E_MOTOR_GEARSET_06, false,pros::E_MOTOR_ENCODER_ROTATIONS);
pros::Motor flywheel(5,pros::E_MOTOR_GEARSET_06, false,pros::E_MOTOR_ENCODER_ROTATIONS);
pros::ADIDigitalOut indexer('A', false);
pros::ADIDigitalOut expansion('B', true);