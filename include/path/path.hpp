#pragma once

#include "okapi/api/units/QLength.hpp"

namespace path
{

struct Point
{
    okapi::QLength x;
    okapi::QLength y;
    int t = 0;
};

struct PointAndDistance
{
    Point point;
    okapi::QLength distance;
};

class Path
{
  protected:
    int currT;
    int resolution;
    int lookAhead;

  public:
    Path(int resolution, int lookahead = -1);

    /**
         * Get next point on path
         */
    Point nextPoint(int lookahead);

    /**
         * Get Point at parametric T
         */
    virtual Point pointAt(int T) = 0;

    /**
         * Get the nearest point to input on the path via seraching them all
         */
    PointAndDistance getClosestPointAndDistance(Point inputPoint);

    int getResolution();
    int getT();
    void setT(int t);
    int getLookahead();
};
} // namespace path