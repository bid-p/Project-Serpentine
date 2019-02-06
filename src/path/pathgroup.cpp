#include "path/pathgroup.hpp"

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
            point = path.pointAt(t - lastRunningSum);
            break;
        }
        point = path.pointAt(path.getResolution());
    }
    point.t = t;
    return point;
}

// Point PathGroup::pointAt(int t) {
//     Point point;

//     int targetPathIndex = 0;
//     int totalResolution = 0;

//     while (totalResolution < t) {
//         targetPathIndex++;
//         totalResolution += ;

//         if (targetPathIndex > paths.size()) {
//             throw std::runtime_error("Path T out of bounds");
//         }
//     }

//     point.t = t;
//     return point;
// }

} // namespace path
