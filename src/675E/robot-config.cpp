#include <memory>

#include "main.h"
#include "okapi/api/control/async/asyncPositionController.hpp"
#include "okapi/api/device/motor/abstractMotor.hpp"
#include "okapi/api/util/mathUtil.hpp"
#include "okapi/impl/chassis/controller/chassisControllerBuilder.hpp"
#include "okapi/impl/control/async/asyncMotionProfileControllerBuilder.hpp"
#include "okapi/impl/control/async/asyncPosControllerBuilder.hpp"

const double FlywheelliftkP = 0.001;
const double FlywheelliftkI = 0.0001;
const double FlywheelliftkD = 0.0001;

const double IntakeliftkP = 0.001;
const double IntakeliftkI = 0.0001;
const double IntakeliftkD = 0.0001;

// Constructor for the Intake Motor
pros::Motor intake(6, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_ROTATIONS);
// Constructor for the Flywheel Motor
pros::Motor flywheel(2, pros::E_MOTOR_GEARSET_06, true, pros::E_MOTOR_ENCODER_ROTATIONS);
// Constructor for the Indexer Pneumatic
pros::ADIDigitalOut indexer('H', false);
// Constructor for the Expansion Pneumatic
pros::ADIDigitalOut expansion('G', true);

// Brain and Controller are already defined in the EZ-Template
// The Inertial sensor and all the drive motors are referenced in the main.cpp file under the chassis configuration
/*
std::shared_ptr<okapi::ChassisController> okapi_chassis =
    okapi::ChassisControllerBuilder()
        .withMotors({-15, -14, -13}, {20, 19, 18})
        .withDimensions(okapi::AbstractMotor::gearset::blue, {{3.25, 11}, okapi::imev5RedTPR})
        .withLogger(okapi::defaultLogger)
        .build();
std::shared_ptr<okapi::AsyncPositionController<double, double>> okapi_flywheel =
    okapi::AsyncPosControllerBuilder()
        .withMotor(2)
        .withGearset(okapi::AbstractMotor::gearset::blue)
        .withLogger(okapi::defaultLogger)
        .withGains({FlywheelliftkP, FlywheelliftkI, FlywheelliftkD})
        .build();
std::shared_ptr<okapi::AsyncPositionController<double, double>> okapi_intake =
    okapi::AsyncPosControllerBuilder()
        .withMotor(6)
        .withGearset(okapi::AbstractMotor::gearset::blue)
        .withLogger(okapi::defaultLogger)
        .withGains({IntakeliftkP, IntakeliftkI, IntakeliftkD})
        .build();*/