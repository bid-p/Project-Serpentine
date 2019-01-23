#pragma once

#include "path.hpp"
#include <vector>
#include <functional>

namespace path
{
class PathGroup : public Path
{
  private:
    std::vector<std::reference_wrapper<Path>> paths;

  public:
    PathGroup(std::initializer_list<std::reference_wrapper<Path>> list, int resolution, int lookahead = -1);

    Point pointAt(int t) override;
};
} // namespace path