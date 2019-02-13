#include "main.h"

using namespace okapi;

namespace drive
{

driveStates currState;

Motor driveL1(MPORT_DRIVE_L1, false, AbstractMotor::gearset::green, AbstractMotor::encoderUnits::degrees);
Motor driveL2(MPORT_DRIVE_L2, false, AbstractMotor::gearset::green, AbstractMotor::encoderUnits::degrees);
Motor driveR1(MPORT_DRIVE_R1, true, AbstractMotor::gearset::green, AbstractMotor::encoderUnits::degrees);
Motor driveR2(MPORT_DRIVE_R2, true, AbstractMotor::gearset::green, AbstractMotor::encoderUnits::degrees);

ChassisControllerIntegrated chassis =
    ChassisControllerFactory::create(
        {MPORT_DRIVE_L1, MPORT_DRIVE_L2}, {-MPORT_DRIVE_R1, -MPORT_DRIVE_R2},
        AbstractMotor::gearset::green, {4.125_in, 12.863_in});

AsyncMotionProfileController profileController =
    AsyncControllerFactory::motionProfile(/*1.09*/ 1.0, 2.0,
                                          10.0, // maxvel, accel, max jerk
                                          chassis);

void update(void *)
{
  while (true)
  {
    if (abs(controller.getAnalog(ControllerAnalog::leftY)) > joyDeadband ||
        abs(controller.getAnalog(ControllerAnalog::rightY)) > joyDeadband)
    {
      currState = running;
    }
    // else
    // {
    //   currState = notRunning;
    // }
    pros::delay(10);
  }
}

void act(void *)
{
  while (true)
  {
    switch (currState)
    {
    case notRunning:
      chassis.setBrakeMode(AbstractMotor::brakeMode::coast);
      chassis.tank(0, 0, 0);
      break;

    case running:
      chassis.tank(
          controller.getAnalog(ControllerAnalog::leftY) * 1.0,
          controller.getAnalog(ControllerAnalog::rightY) * 1.0,
          joyDeadband * 1.0);
      currState = notRunning;
      break;

    case yield:
      break;
    }
    pros::delay(10);
  }
}

} // namespace drive

void turnAngleVel(QAngle angle, double maxVel)
{
  drive::chassis.setMaxVelocity(maxVel);
  drive::chassis.turnAngle(angle);
  drive::chassis.setMaxVelocity(200);
}

void removePaths(std::string path1, std::string path2)
{
  drive::profileController.removePath(path1);
  drive::profileController.removePath(path2);
}
