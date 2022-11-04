#include "main.h"

const double MAX_VEL     = 2.0; // in meters per second
const double MAX_ACCEL   = 3.0; // in meters per second per second
const double MAX_JERK    = 6.0; // in meters per second per second per second
const double ROBOT_WIDTH = 0.4; // in meters

squiggles::Constraints constraints = squiggles::Constraints(MAX_VEL, MAX_ACCEL, MAX_JERK);
squiggles::SplineGenerator generator = squiggles::SplineGenerator(
  constraints,
  std::make_shared<squiggles::TankModel>(ROBOT_WIDTH, constraints));

std::vector<squiggles::ProfilePoint> path = generator.generate({
  squiggles::Pose(0.0, 0.0, 1.0),
  squiggles::Pose(4.0, 4.0, 1.0)});