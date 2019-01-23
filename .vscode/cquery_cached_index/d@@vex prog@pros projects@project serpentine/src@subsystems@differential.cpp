#include "main.h"

using namespace okapi;

ControllerButton liftUpBtn = controller[ControllerDigital::A];
ControllerButton liftDownBtn = controller[ControllerDigital::Y];
ControllerButton intakeInBtn = controller[ControllerDigital::R1];
ControllerButton intakeOutBtn = controller[ControllerDigital::R2];

namespace differential {

differentialStates currState;

Motor diffLeft(DIFF_PORT_L, false, AbstractMotor::gearset::green);
Motor diffRight(DIFF_PORT_R, true, AbstractMotor::gearset::green);

pros::ADILineSensor lineL(SPORT_INTAKE_L);
pros::ADILineSensor lineR(SPORT_INTAKE_R);

bool hasBall() {
  if (lineL.get_value() < 2000 || lineR.get_value() < 2000) {
    return true;
  }
  return false;
}

void update() {
  // AUTOMATED CHECKERS
  if (currState == intakeIn && !puncher::isLoaded()) {
    currState = intakeIn;
  } // if puncher isn't loaded, run intake
  if (currState == intakeIn && puncher::isLoaded() && !hasBall()) {
    currState = intakeIn;
  } // if is loaded but doesn't have ball ready, keep running intake
  if (currState == intakeIn && puncher::isLoaded() && hasBall()) {
    currState = intakeIn;
  } // if has ball ready and is loaded, turn off intake

  // USER INPUT
  if (intakeInBtn.isPressed() && intakeOutBtn.isPressed()) {
    currState = liftHold;
  }
  if (liftUpBtn.isPressed()) {
    currState = liftUp;
  }
  if (liftDownBtn.isPressed()) {
    currState = liftDown;
  }
  if (intakeInBtn.isPressed() && !intakeOutBtn.isPressed()) {
    currState = intakeIn;
  }
  if (intakeOutBtn.isPressed() && !intakeInBtn.isPressed()) {
    currState = intakeOut;
  }
}

void act(void *) {
  while (true) {
    switch (currState) {
    case notRunning:
      diffLeft.moveVoltage(0);
      diffRight.moveVoltage(0);
      break;
    case liftUp:
      diffLeft.moveVelocity(200);
      diffRight.moveVelocity(200);
      currState = notRunning;
      break;
    case liftDown:
      diffLeft.moveVelocity(-200);
      diffRight.moveVelocity(-200);
      currState = notRunning;
      break;
    case intakeIn:
      diffLeft.moveVelocity(-200);
      diffRight.moveVelocity(200);
      break;
    case intakeOut:
      diffLeft.moveVelocity(150);
      diffRight.moveVelocity(-150);
      currState = notRunning;
      break;
    case liftHold:
      diffLeft.moveVoltage(1500);
      diffRight.moveVelocity(1500);
      currState = notRunning;
      break;
    }

    pros::delay(10);
  }
}

} // namespace differential

void runIntake(int speed) {
  differential::diffLeft.moveVelocity(-1 * speed);
  differential::diffRight.moveVelocity(1 * speed);
}
