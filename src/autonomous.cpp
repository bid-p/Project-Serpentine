#include "main.h"
using namespace okapi;
/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */

void autonomous()
{
    // initProgSkills();

    // executeProgSkills();

    path::Line BRAIN(
        {0_in, 0_in},
        {12_in, 36_in},
        200, // the resolution (how many T there are)
        40   // the lookahead T, and it's basically the maximum distance the robot will look ahead
    );

    pathfollowing::AdaptivePurePursuit controller(
        std::make_unique<IterativePosPIDController>(0.1, 0.0, 0.0, 0.0, TimeUtilFactory::create(), std::make_unique<AverageFilter<5>>()),
        std::make_unique<IterativePosPIDController>(0.015, 0.0, 0.0, 0.0, TimeUtilFactory::create(), std::make_unique<AverageFilter<5>>()),
        30, 10.0); // the number before the Kf is the lookahead global, but it will use the path's lookahead by default

    controller.setPath(&BRAIN);
    while (true)
    {
        controller.loop();
        pros::delay(10);
    }
}
