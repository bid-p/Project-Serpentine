#include "line.hpp"
#include "okapi/api/units/QLength.hpp"

namespace path
{
Line::Line(Point start, Point end, int resolution, int lookahead) : Path(resolution, lookahead), start(start), end(end)
{
    // if (resolution <= 0)
    //     throw std::invalid_argument("Adaptive Pure Pursuit Controller resolution cannot be <= 0!");
}

Point Line::pointAt(int T)
{
    int lilT = (T > resolution) ? resolution : (T < 0) ? 0 : T;
    double x = (end.x.convert(okapi::inch) * (double)lilT) / ((double)resolution) + start.x.convert(okapi::inch);
    double y = (end.y.convert(okapi::inch) * (double)lilT) / ((double)resolution) + start.y.convert(okapi::inch);
    return {x * okapi::inch, y * okapi::inch, lilT};
}
} // namespace path