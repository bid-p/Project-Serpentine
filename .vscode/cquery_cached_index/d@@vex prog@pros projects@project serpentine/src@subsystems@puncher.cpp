#include "main.h"

using namespace okapi;

ControllerButton puncherShootBtn = controller[ControllerDigital::L1];
ControllerButton puncherCockingBtn = controller[ControllerDigital::L2];

namespace puncher {

puncherStates currState;

Motor puncher(PUNCHER_PORT, true, AbstractMotor::gearset::green);

// AsyncPosIntegratedController puncherController =
//     AsyncControllerFactory::posIntegrated(puncher);

pros::ADILineSensor lineP(SPORT_PUNCHERB);

pros::ADILineSensor lineCock(SPORT_LINECOCK);

bool isCocked() {
  if (lineCock.get_value() < 2000) {
    return true;
  }
  return false;
}

bool isLoaded() {
  if (lineP.get_value() < 2000) {
    return true;
  }
  return false;
}

void update() {
  if (puncherShootBtn.isPressed()) {
    currState = shooting;
  }
  if (puncherCockingBtn.changedToPressed()) {
    puncher.tarePosition(); // puncher has to be reset before cocked
    currState = cocking;
  }
}

void act(void *) {
  while (true) {
    switch (currState) {
    case notRunning:
      puncher.setBrakeMode(AbstractMotor::brakeMode::coast);
      puncher.moveVoltage(0);
      break;
    case shooting:
      // puncher.moveVoltage(12000);
      puncher.moveRelative(360, 200);
      waitUntilSettled(puncher);
      currState = notRunning;
      break;
    case cocking:
      if (!isCocked()) {
        puncher.moveVoltage(12000);
      } else {
        puncher.moveVoltage(0);
      }
      break;
    }
    pros::delay(10);
  }
}

} // namespace puncher
