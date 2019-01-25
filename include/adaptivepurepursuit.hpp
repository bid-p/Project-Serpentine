#pragma once

#include "path/path.hpp"
#include "okapi/api.hpp"
#include "odometry.hpp"

namespace pathfollowing
{
class AdaptivePurePursuit
{
private:
  std::unique_ptr<okapi::IterativePosPIDController> straightController;
  std::unique_ptr<okapi::IterativePosPIDController> turnController;
  int mainLookahead;
  int lookahead;
  double lookaheadKf;
  path::Path *path;
  path::Point target;
  int direction;

public:
  AdaptivePurePursuit(
      std::unique_ptr<okapi::IterativePosPIDController> straight,
      std::unique_ptr<okapi::IterativePosPIDController> turn,
      int lookahead, double lookaheadKf);

  void setPath(path::Path *path);

  void setLookahead(int lookahead);

  void loop();
};
} // namespace pathfollowing
