#include "main.h"

using namespace okapi;

ControllerButton angleCloseHigh = controller[ControllerDigital::down];
ControllerButton angleMidHighBtn = controller[ControllerDigital::up];
ControllerButton angleFarMidBtn = controller[ControllerDigital::left];
ControllerButton angleFarHighBtn = controller[ControllerDigital::right];

namespace macro {

macroStates currMacroState;

void update() {
  if (angleCloseHigh.changedToPressed()) {
    currMacroState = anglerCH; // 350
  }
  if (angleMidHighBtn.changedToPressed()) {
    currMacroState = anglerMH; // 0
  }
  if (angleFarMidBtn.changedToPressed()) {
    currMacroState = anglerFM; // 305
  }
  if (angleFarHighBtn.changedToPressed()) {
    currMacroState = anglerFH; // 120
  }
}

void act(void *) {
  while (true) {
    switch (currMacroState) {
    case none:
      break;
    case singleShot:
      angler::target = 15;
      angler::currState = angler::toTarget;

      differential::currState = differential::intakeIn;
      // should automatically stop when ball loads into puncherMacro

      puncher::currState = puncher::cocking;

      while (!puncher::isLoaded()) {
        pros::delay(10);
      }

      waitUntilSettled(angler::angler);

      puncher::currState = puncher::shooting;
      break;
    case doubleShot:
      angler::target = 15;
      angler::currState = angler::toTarget;
      // will switch out of toTarget automatically when target reached

      puncher::currState = puncher::cocking;
      // switches out of cocking when sensor value achieved

      differential::currState = differential::intakeIn;
      // should automatically stop when ball loads into puncherMacro

      while (!puncher::isLoaded()) {
        pros::delay(10);
      } // waits for puncher to load

      waitUntilSettled(angler::angler); // waits until angler to stop

      puncher::currState = puncher::shooting;
      waitUntilSettled(puncher::puncher);

      angler::target = 125;
      angler::currState = angler::toTarget;

      differential::currState = differential::intakeIn;
      // should automatically stop when ball loads into puncherMacro

      puncher::currState = puncher::cocking;

      while (!puncher::isLoaded()) {
        pros::delay(10);
      }

      waitUntilSettled(angler::angler);

      puncher::currState = puncher::shooting;
      break;
    case anglerCH:
      angler::target = 25;
      angler::currState = angler::toTarget;
      break;
    case anglerMH:
      angler::target = 0;
      angler::currState = angler::toTarget;
      break;
    case anglerFM:
      angler::target = 200;
      angler::currState = angler::toTarget;
      break;
    case anglerFH:
      angler::target = 95;
      angler::currState = angler::toTarget;
      break;
    }
    pros::delay(10);
    currMacroState = none;
  }
}

} // namespace macro
