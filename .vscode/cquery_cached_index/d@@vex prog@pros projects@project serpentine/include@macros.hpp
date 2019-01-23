#ifndef MACRO_GUARD
#define MACRO_GUARD
#include "okapi/api.hpp"

using namespace okapi;

namespace macro {

enum macroStates {
  none,
  singleShot,
  doubleShot,
  anglerCH,
  anglerMH,
  anglerFM,
  anglerFH
};

extern macroStates currMacroState;

extern void update();

extern void act(void *);

} // namespace macro

#endif
