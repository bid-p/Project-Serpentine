#include "main.h"

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */

// ControllerButton abortBtn = controller[ControllerDigital::Y];

// void stats()
// {
//   pros::lcd::print(1, "X: %f", currPosX);
//   pros::lcd::print(2, "Y: %f", currPosY);
// }

void opcontrol()
{

  drive::currState = drive::notRunning;

  while (true)
  {
    // stats();

    // pros::lcd::print(4, "LTracker: %f    RTracker: %f", RTracker.get_value(),
    //                  LTracker.get_value());

    pros::delay(10);
  }
}
