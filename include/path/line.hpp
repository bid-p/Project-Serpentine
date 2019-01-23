#pragma once

#include "path.hpp"

namespace path
{
class Line : public Path
{
  private:
    Point start;
    Point end;

  public:
    Line(Point start, Point end, int resolution = 100, int lookahead = -1);
    Point pointAt(int t) override;
};
} // namespace path