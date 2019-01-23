#include "path.hpp"
#include <cmath>

namespace path
{
Path::Path(int resolution, int lookahead) : currT(0), resolution(resolution), lookAhead(lookahead) {}

Point Path::nextPoint(int lookahead)
{
    if (currT + lookahead > resolution)
    {
        currT = resolution;
    }
    else
    {
        currT += lookahead;
    }
    return pointAt(currT);
}

PointAndDistance Path::getClosestPointAndDistance(Point inputPoint)
{
    using namespace okapi;

    double x = inputPoint.x.convert(inch);
    double y = inputPoint.x.convert(inch);
    Point closestPoint = pointAt(0);
    double distanceLeast = sqrt(pow((closestPoint.x.convert(inch) - x), 2) + pow((closestPoint.y.convert(inch) - y), 2));

    for (int t = 1; t <= resolution; t++)
    {
        Point tempPoint = pointAt(t);
        double distance = sqrt(pow((tempPoint.x.convert(inch) - x), 2) + pow((tempPoint.y.convert(inch) - y), 2));
        if (distance < distanceLeast)
        {
            distanceLeast = distance;
            closestPoint = tempPoint;
        }
    }

    PointAndDistance closest = {closestPoint, distanceLeast * inch};
    return closest;
}

//
// Point pointAt(int T) = 0;

int Path::getResolution()
{
    return resolution;
}

int Path::getT()
{
    return this->currT;
}

void Path::setT(int t)
{
    currT = t;
}

int Path::getLookahead()
{
    return lookAhead;
}
} // namespace path