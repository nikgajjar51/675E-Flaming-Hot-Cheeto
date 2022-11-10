#include "main.h"
pros::Motor intake(6, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_ROTATIONS);
pros::Motor flywheel(2, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_ROTATIONS);
pros::ADIDigitalOut indexer_pneum('H', false);
pros::ADIDigitalOut expansion_pneum('G', false);
pros::Optical roller_optical(1);
pros::Vision vision_sensor(2, pros::E_VISION_ZERO_TOPLEFT);
pros::ADIUltrasonic ultrasonic_disk_sensor('A', 'B');
