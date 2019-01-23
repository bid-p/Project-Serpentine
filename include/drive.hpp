#ifndef DRIVE_GUARD
#define DRIVE_GUARD

#include "api.h"
#include "okapi/api.hpp"

using namespace okapi;

namespace drive
{

enum driveStates
{
  notRunning,
  running,
  yield,
};

extern driveStates currState;

extern char stateIndicator;

extern Motor driveL1;
extern Motor driveL2;
extern Motor driveR1;
extern Motor driveR2;

extern ChassisControllerIntegrated chassis;
extern AsyncMotionProfileController profileController;

extern void update(void *);
extern void act(void *);

} // namespace drive

extern void turnAngleVel(QAngle angle, double maxVel);

extern void removePaths(std::string path1, std::string path2);

#endif
