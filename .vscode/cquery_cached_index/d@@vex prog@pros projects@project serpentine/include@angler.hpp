#ifndef ANGLER_GUARD
#define ANGLER_GUARD
#include "okapi/api.hpp"

using namespace okapi;

namespace angler {

enum anglerStates {
  notRunning,
  toTarget,
  brake,
};

extern anglerStates currState;

extern int target;

extern Motor angler;

extern AsyncPosIntegratedController angleController;

extern char stateIndicator;

extern void update();

extern void act(void *);

} // namespace angler

#endif
