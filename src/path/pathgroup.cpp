#include "pathgroup.hpp"

namespace path
{
PathGroup::PathGroup(std::initializer_list<std::reference_wrapper<Path>> list, int resolution, int lookahead) : Path::Path(resolution, lookahead),
                                                                                                                paths(list) {}

Point PathGroup::pointAt(int t)
{
    int runningSum = 0;
    Point point;
    for (Path &path : paths)
    {
        int lastRunningSum = runningSum;
        runningSum += path.getResolution();
        if (t <= runningSum)
        {
            return path.pointAt(t - lastRunningSum);
        }
        point = path.pointAt(path.getResolution());
    }
    return point;
}
} // namespace path