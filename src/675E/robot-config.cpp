#include "main.h"
// V5 Motors
pros::Motor intake(16, pros::E_MOTOR_GEARSET_06, false,
                   pros::E_MOTOR_ENCODER_ROTATIONS);
pros::Motor flywheel(18, pros::E_MOTOR_GEARSET_06, false,
                     pros::E_MOTOR_ENCODER_ROTATIONS);
// V5 Optical
pros::Optical roller_optical(2);
// Line Sensors
pros::ADILineSensor disk_sensor_bottom('A');
pros::ADILineSensor disk_sensor_top('B');
pros::ADILineSensor hopper_sensor_bottom('C');
// Ultrasonic
pros::ADIUltrasonic hopper_sensor('E', 'F');
// Buttons / Switches
pros::ADIDigitalIn alliance_selector_button('D');
// Double Acting
pros::ADIDigitalOut expansion_pneum('H', false);
// Single Acting
pros::ADIDigitalOut indexer_pneum('G', false);

// Vision
pros::Vision vision_sensor(5, pros::E_VISION_ZERO_TOPLEFT);
pros::vision_signature_s_t RED_SIG = pros::Vision::signature_from_utility(
    1, 9215, 9735, 9474, -525, 459, -34, 11.000, 0);
pros::vision_signature_s_t BLUE_SIG = pros::Vision::signature_from_utility(
    2, -1003, -145, -574, 5919, 6785, 6352, 8.100, 0);