#include "main.h"
#include "pros/vision.h"
pros::Motor intake(6, pros::E_MOTOR_GEARSET_06, false,
                   pros::E_MOTOR_ENCODER_ROTATIONS);
pros::Motor flywheel(2, pros::E_MOTOR_GEARSET_06, false,
                     pros::E_MOTOR_ENCODER_ROTATIONS);
pros::ADIDigitalOut indexer_pneum('H', false);
pros::ADIDigitalOut expansion_pneum('G', false);
pros::Optical roller_optical(1);
pros::Vision vision_sensor(2, pros::E_VISION_ZERO_TOPLEFT);
pros::ADIUltrasonic disk_sensor_bottom('A', 'B');
pros::ADIUltrasonic disk_sensor_top('C', 'D');
pros::vision_signature_s_t RED_SIG = pros::Vision::signature_from_utility(
    1, 9215, 9735, 9474, -525, 459, -34, 11.000, 0);
pros::vision_signature_s_t BLUE_SIG = pros::Vision::signature_from_utility(
    2, -1003, -145, -574, 5919, 6785, 6352, 8.100, 0);