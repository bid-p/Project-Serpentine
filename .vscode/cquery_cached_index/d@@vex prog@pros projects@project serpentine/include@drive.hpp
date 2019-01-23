#ifndef DRIVE_GUARD
#define DRIVE_GUARD

#include "api.h"
#include "okapi/api.hpp"

using namespace okapi;

namespace drive {

enum driveStates {
  notRunning,
  running,
};

extern driveStates currState;

extern char stateIndicator;

extern Motor driveL1;
extern Motor driveL2;
extern Motor driveR1;
extern Motor driveR2;

extern ChassisControllerIntegrated chassisController;
extern AsyncMotionProfileController profileController;

extern void update();
extern void act(void *);

} // namespace drive

extern void turnAngleVel(QAngle angle, double maxVel);

#endif
