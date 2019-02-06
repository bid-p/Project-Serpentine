#include "main.h"

void executeProgSkills(){

    odometry::currX = 24_in;
    odometry::currY = 36_in;
    odometry::currAngle = 90_deg;

    pros::delay(3000);

    drive::profileController.generatePath(
        {Point{odometry::currY, odometry::currX, odometry::currAngle}, Point{36_in, 63_in, 90_deg}}, "A1");

    drive::profileController.setTarget("A1");
    drive::profileController.waitUntilSettled();

    pros::delay(5000);
    // Drive forward into the cap #1 and intake ball

    // while (!differential::hasBall())
    // {
    //     pros::delay(10);
    // }
    // differential::currState = differential::differentialStates::notRunning;

    drive::profileController.generatePath(
        {Point{36_in, 28_in, 90_deg}, Point{odometry::currY, odometry::currX, odometry::currAngle}}, "A2");

    drive::profileController.setTarget("A2", true);
    drive::profileController.waitUntilSettled();
    //Reverse to starting tile

    removePaths("A1", "A2");

    turnAngleVel(0_deg - odometry::currAngle, 100);
    // Turn left

    drive::profileController.generatePath(
        {Point{odometry::currY, odometry::currX, odometry::currAngle}, Point{88_in, 28_in, 0_deg}}, "forward");

    drive::profileController.setTarget("forward");
    drive::profileController.waitUntilSettled();
    drive::profileController.removePath("forward");
    // Drive robot to shooting position
}
