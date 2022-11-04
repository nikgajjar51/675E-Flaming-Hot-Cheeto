#include "main.h"
//Constructor for the Intake Motor
pros::Motor intake(6,pros::E_MOTOR_GEARSET_06, false,pros::E_MOTOR_ENCODER_ROTATIONS);
//Constructor for the Flywheel Motor
pros::Motor flywheel(2,pros::E_MOTOR_GEARSET_06, true,pros::E_MOTOR_ENCODER_ROTATIONS);
//Constructor for the Indexer Pneumatic
pros::ADIDigitalOut indexer('H', false);
//Constructor for the Expansion Pneumatic
pros::ADIDigitalOut expansion('G', false);

//Brain and Controller are already defined in the EZ-Template
//The Inertial sensor and all the drive motors are referenced in the main.cpp file under the chassis configuration