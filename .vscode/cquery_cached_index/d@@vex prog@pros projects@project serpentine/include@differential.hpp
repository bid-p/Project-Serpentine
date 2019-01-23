#ifndef DIFFERENTIAL_GUARD
#define DIFFERENTIAL_GUARD

#include "okapi/api.hpp"

using namespace okapi;

namespace differential {

enum differentialStates {
  notRunning,
  liftHold,
  liftUp,
  liftDown,
  intakeIn,
  intakeOut
};

extern differentialStates currState;

extern okapi::Motor diffLeft, diffRight;

extern pros::ADILineSensor lineL;
extern pros::ADILineSensor lineR;

extern char stateIndicator;

extern void update();

extern void act(void *);

extern bool hasBall();

} // namespace differential

extern void runIntake(int speed);

#endif
