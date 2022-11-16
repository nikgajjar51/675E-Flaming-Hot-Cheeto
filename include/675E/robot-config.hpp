#include "api.h"
#include "pros/optical.hpp"
extern pros::Motor intake;
extern pros::Motor flywheel;
extern pros::ADIUltrasonic disk_sensor_bottom;
extern pros::Optical roller_optical;
extern pros::ADIUltrasonic disk_sensor_top;
extern pros::ADIDigitalIn alliance_selector_button;
extern pros::ADIDigitalOut expansion_pneum;
extern pros::ADIDigitalOut indexer_pneum;
extern pros::Vision vision_sensor;
extern pros::vision_signature_s_t RED_SIG;
extern pros::vision_signature_s_t BLUE_SIG;