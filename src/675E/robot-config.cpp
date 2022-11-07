#include "main.h"
#include "pros/adi.hpp"
#include "pros/optical.hpp"
#include "pros/vision.hpp"
// Constructor for the Intake Motor
pros::Motor intake(6, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_ROTATIONS);
// Constructor for the Flywheel Motor
pros::Motor flywheel(2, pros::E_MOTOR_GEARSET_06, true, pros::E_MOTOR_ENCODER_ROTATIONS);
// Constructor for the Indexer Pneumatic
pros::ADIDigitalOut indexer_pneum('H', false);
// Constructor for the Expansion Pneumatic
pros::ADIDigitalOut expansion_pneum('G', true);
// Constructor for the Optical Sensor to detect roller colors
pros::Optical roller_optical(1);
// Constructor for the Vision Sensor for Autonomous and vision PID
pros::Vision vision_sensor(2, pros::E_VISION_ZERO_TOPLEFT);
// Constructor for the Ultrasonic Sensor for detecting disks
pros::ADIUltrasonic ultrasonic_disk_sensor('A', 'B');
// Brain and Controller are already defined in the EZ-Template
// The Inertial sensor and all the drive motors are referenced in the main.cpp file under the chassis configuration