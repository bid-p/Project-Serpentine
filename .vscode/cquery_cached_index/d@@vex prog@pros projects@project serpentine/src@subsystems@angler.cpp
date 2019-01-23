#include "main.h"

using namespace okapi;

// ControllerButton angleCloseHigh = controller[ControllerDigital::down];
// ControllerButton angleMidHighBtn = controller[ControllerDigital::up];
// ControllerButton angleFarMidBtn = controller[ControllerDigital::left];
// ControllerButton angleFarHighBtn = controller[ControllerDigital::right];

namespace angler {

anglerStates currState;

int target;

Motor angler(ANGLE_CHANGER_PORT, true, AbstractMotor::gearset::blue);

// AsyncPosIntegratedController angleController =
//     AsyncControllerFactory::posIntegrated(angler);

void update() {
  // if (angleCloseHigh.changedToPressed()) {
  //   currState = closeHigh; // 350
  // }
  // if (angleMidHighBtn.changedToPressed()) {
  //   currState = midHigh; // 0
  // }
  // if (angleFarMidBtn.changedToPressed()) {
  //   currState = farMid; // 305
  // }
  // if (angleFarHighBtn.changedToPressed()) {
  //   currState = farHigh; // 120
  // }
}

void act(void *) {
  while (true) {
    switch (currState) {
    case notRunning:
      angler.setBrakeMode(AbstractMotor::brakeMode::coast);
      angler.moveVoltage(0);
      break;
    case toTarget:
      angler.moveAbsolute(target, 600);
      waitUntilSettled(angler);
      currState = brake;
      break;
    case brake:
      angler.setBrakeMode(AbstractMotor::brakeMode::coast);
      angler.moveVoltage(0);
      break;
    }
    pros::delay(10);
  }
}

} // namespace angler
