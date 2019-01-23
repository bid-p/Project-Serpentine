#include "main.h"

Controller controller;

const double joyDeadband = .08;

void waitUntilSettled(okapi::AbstractMotor &motor) {
  auto settledUtil = SettledUtilFactory::create();

  while (
      !settledUtil.isSettled(motor.getTargetPosition() - motor.getPosition())) {
    pros::delay(10);
  }
}

void initActTasks() {

  pros::Task driveActTask(drive::act, NULL, TASK_PRIORITY_DEFAULT,
                          TASK_STACK_DEPTH_DEFAULT, "Act Drive");

  pros::Task odometry(EETrackPosTask, NULL, TASK_PRIORITY_DEFAULT,
                      TASK_STACK_DEPTH_DEFAULT, "ODOM");
}
