#ifndef ODOM_GUARD
#define ODOM_GUARD

#include "api.h"
#include "okapi/api.hpp"

using namespace okapi;

extern const double convFactor;

extern const double chassisWidth;

extern double currPosX;
extern double currPosY;
extern double currAngle;

extern pros::ADIEncoder RTracker;
extern pros::ADIEncoder LTracker;

extern double degToRad(double deg);
extern double radToDeg(double rad);

enum trackType {
  EGETracking,
  EEETracking,
  EETracking,
};

extern trackType currTrackType;

extern void EGETrackPosTask();

extern void EEETrackPosTask();

extern void EETrackPosTask(void *);

#endif
