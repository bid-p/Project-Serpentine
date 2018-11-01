#ifndef ODOM_GUARD
#define ODOM_GUARD

#include "api.h"
#include "okapi/api.hpp"

using namespace okapi;

extern const double convFactor;

extern double currPosX;
extern double currPosY;
extern double currAngle;

extern pros::ADIEncoder RTracker;
extern pros::ADIEncoder LTracker;
extern pros::ADIEncoder MTracker;

extern pros::ADIGyro gyro1;
extern pros::ADIGyro gyro2;

extern void trackPosTask();

#endif
