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
    path::Line section1(
        {0_in, 0_in},
        {10_in, 20_in},
        // {0_in, 36_in},
        200, // the resolution (how many T there are)
        10   // the lookahead T, and it's basically the maximum distance the robot will look ahead
    );

    path::Line section2(
        {10_in, 20_in},
        {20_in, 0_in},
        // {0_in, 36_in},
        200, // the resolution (how many T there are)
        10   // the lookahead T, and it's basically the maximum distance the robot will look ahead
    );

    path::Line section3(
        {20_in, 20_in},
        {0_in, -20_in},
        // {0_in, 36_in},
        200, // the resolution (how many T there are)
        10   // the lookahead T, and it's basically the maximum distance the robot will look ahead
    );

    path::Line section4(
        {20_in, 0_in},
        {-20_in, 0_in},
        // {0_in, 36_in},
        200, // the resolution (how many T there are)
        10   // the lookahead T, and it's basically the maximum distance the robot will look ahead
    );

    path::PathGroup squareNigga({section1, section2, section3, section4}, 400, 10);

    pathfollowing::AdaptivePurePursuit controller(
        std::make_unique<IterativePosPIDController>(0.1, 0.0, 0.0, 0.0, TimeUtilFactory::create(), std::make_unique<AverageFilter<5>>()),
        std::make_unique<IterativePosPIDController>(0.0075, 0.0, 0.0, 0.0, TimeUtilFactory::create(), std::make_unique<AverageFilter<5>>()),
        30, 0.0); // the number before the Kf is the lookahead global, but it will use the path's lookahead by default

    controller.setPath(&squareNigga);

    while (true)
    {
        controller.loop();
        pros::delay(10);
    }
}
