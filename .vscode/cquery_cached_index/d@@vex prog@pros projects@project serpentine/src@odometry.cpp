#include "main.h"

const double convFactor =
    2 * pi * 2.75 /*2.54*/ / 360; // assumes 2.75in tracker wheels and inches

const double chassisWidth = 7.25;

double currPosX = 0;
double currPosY = 0;
double heading = 0;

pros::ADIEncoder RTracker(SPORT_ENC_RTOP, SPORT_ENC_RBOT, true);
pros::ADIEncoder LTracker(SPORT_ENC_LTOP, SPORT_ENC_LBOT, false);

double degToRad(double deg) { return deg * pi / 180; }

double radToDeg(double rad) { return rad * 180 / pi; }

// trackType currTrackType;

// void EGETrackPosTask() {
//   double deltaX;
//   double deltaY;
//   double deltaAngle;
//   double deltaSector;
//   double genRadius;
//
//   double trackerVal;
//   double gyroVal;
//   double lastTrackerVal;
//   double lastGyroVal;
//
//   while (true) {
//
//     trackerVal = ((RTracker.get_value() * convFactor) +
//                   (LTracker.get_value() * convFactor)) /
//                  2;
//     // gyroVal = degToRad(gyro1.get_value());
//
//     deltaSector = trackerVal - lastTrackerVal;
//     deltaAngle = gyroVal - lastGyroVal;
//
//     genRadius = deltaAngle == 0 ? 0 : deltaSector / deltaAngle;
//
//     deltaX = deltaAngle == 0 ? 0 : genRadius - (genRadius * cos(deltaAngle));
//     deltaY = deltaAngle == 0 ? deltaSector : genRadius * sin(deltaAngle);
//
//     currPosX += deltaX * cos(heading) + deltaY * sin(heading);
//     currPosY += deltaY * cos(heading) - deltaX * sin(heading);
//     heading += deltaAngle;
//
//     lastTrackerVal = trackerVal;
//     lastTrackerVal = gyroVal;
//
//     pros::delay(10);
//   }
// }
//
// void EEETrackPosTask() {
//   double deltaX;
//   double deltaY;
//   double deltaAngle;
//   double deltaSector;
//   double genRadius;
//
//   double REncVal;
//   double LEncVal;
//   double HEncVal;
//   double lastREncVal;
//   double lastLEncVal;
//   double lastHEncVal;
//
//   while (true) {
//
//     REncVal = RTracker.get_value() * convFactor;
//     LEncVal = LTracker.get_value() * convFactor;
//     // HEncVal = HTracker.get_value() * convFactor;
//
//     deltaSector = ((REncVal - lastREncVal) + (LEncVal - lastLEncVal)) / 2;
//
//     deltaAngle = (REncVal - LEncVal) / chassisWidth;
//
//     lastREncVal = REncVal;
//     lastLEncVal = LEncVal;
//     lastHEncVal = HEncVal;
//
//     pros::delay(10);
//   }
// }

void EETrackPosTask(void *) {

  double deltaX;
  double deltaY;
  double deltaTheta;
  double deltaSector;
  double genRadius;

  double REncVal;
  double LEncVal;
  double lastREncVal;
  double lastLEncVal;

  double avgTrackerVal;
  double lastAvgTrackerVal;

  double turnVal;
  double lastTurnVal;

  pros::lcd::print(3, "odom started");

  while (true) {

    REncVal = RTracker.get_value() * convFactor;
    LEncVal = LTracker.get_value() * convFactor;

    avgTrackerVal = (REncVal + LEncVal) / 2;

    turnVal = (REncVal - LEncVal) / chassisWidth;

    deltaSector = avgTrackerVal - lastAvgTrackerVal;
    deltaTheta = turnVal - lastTurnVal;

    genRadius = deltaTheta == 0 ? 0 : deltaSector / deltaTheta;

    deltaX = deltaTheta == 0 ? 0 : genRadius - (genRadius * cos(deltaTheta));
    deltaY = deltaTheta == 0 ? deltaSector : genRadius * sin(deltaTheta);

    currPosX += deltaX * cos(heading) + deltaY * sin(heading);
    currPosY += deltaY * cos(heading) - deltaX * sin(heading);
    heading += deltaTheta;

    lastAvgTrackerVal = avgTrackerVal;
    lastTurnVal = turnVal;

    // pros::lcd::print(4, "LTracker: %f    RTracker: %f", RTracker.get_value(),
    //                  LTracker.get_value());
    pros::lcd::print(5, "LENC VAL: %f    RENC VAL: %f", LEncVal, REncVal);
    pros::lcd::print(6, "deltaSector: %f    deltaTheta: %f", deltaSector,
                     deltaTheta);

    pros::delay(5);
  }
}
