#pragma once

#include "api.h"
#include "okapi/api.hpp"
#include <tuple>
#include "drive.hpp"

namespace odometry
{
using namespace okapi;

extern QLength currX;
extern QLength currY;
extern QAngle currAngle;

void init();

void calculate();

// QLength distanceToPoint(QLength x, QLength y);
// QAngle angleToPoint(QLength x, QLength y);

// std::tuple<QLength, QAngle> distanceAndAngleToPoint(QLength x, QLength y);

void run(void *p);
} // namespace odometry
