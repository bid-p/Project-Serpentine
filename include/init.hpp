#ifndef INIT_GUARD
#define INIT_GUARD

#include "api.h"
#include "okapi/api.hpp"

using namespace okapi;

extern Controller controller;

extern const double joyDeadband;

void waitUntilSettled(okapi::AbstractMotor &motor);

extern pros::Task driveActTask;

extern void initActTasks();

#endif
