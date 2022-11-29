#include "api.h"
// Motors
extern pros::Motor intake;
extern pros::Motor flywheel;
// V5 Optical
extern pros::Optical roller_optical;
// Line Sensors
extern pros::ADILineSensor disk_sensor_bottom;
extern pros::ADILineSensor disk_sensor_top;
extern pros::ADILineSensor hopper_sensor_bottom;
// Ultrasonic
extern pros::ADIUltrasonic hopper_sensor;
// Buttons / Switches
extern pros::ADIDigitalIn alliance_selector_button;
// Pnuematics
extern pros::ADIDigitalOut expansion_pneum;
extern pros::ADIDigitalOut indexer_pneum;

// Vision
extern pros::Vision vision_sensor;

extern pros::vision_signature_s_t RED_SIG;
extern pros::vision_signature_s_t BLUE_SIG;