#include "main.h"

Controller controller;

const double joyDeadband = .08;

void robotStats() {
  pros::lcd::print(1, "Drive State: %c | Drive Temp: %i", driveState,
                   (int)driveR1.get_temperature());
  pros::lcd::print(2, "DL Value: %i, DR Value: %i", (int)driveL2.get_position(),
                   (int)driveR2.get_position());
  pros::lcd::print(3, "Gyro Val: %i, gyro.get_value(); ");

  pros::delay(10);
}
