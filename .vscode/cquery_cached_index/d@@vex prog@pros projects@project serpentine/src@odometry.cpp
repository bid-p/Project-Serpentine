#include "main.h"

const double convFactor =
    2 * pi * 2.75 * 2.54 / 360; // assumes 2.75in tracker wheels and centimeters

double currPosX = 0;
double currPosY = 0;
double currAngle = 0;

pros::ADIEncoder RTracker(SPORT_ENC_RTOP, SPORT_ENC_RBOT, false);
pros::ADIEncoder LTracker(SPORT_ENC_LTOP, SPORT_ENC_LBOT, false);
pros::ADIEncoder MTracker(SPORT_ENC_MTOP, SPORT_ENC_MBOT, false);

pros::ADIGyro gyro1(SPORT_GYRO_1);
pros::ADIGyro gyro2(SPORT_GYRO_2);

double degToRad(double deg) { return deg * pi / 180; }

double radToDeg(double rad) { return rad * 180 / pi; }

void trackPosTask() {
  double deltaX;
  double deltaY;
  double deltaAngle;
  double deltaSector;
  double genRadius;

  double trackerVal;
  double gyroVal;
  double lastTrackerVal;
  double lastGyroVal;

  while (true) {

    trackerVal = ((RTracker.get_value() * convFactor) +
                  (LTracker.get_value() * convFactor)) /
                 2;
    gyroVal = degToRad(gyro1.get_value());

    deltaSector = trackerVal - lastTrackerVal;
    deltaAngle = gyroVal - lastGyroVal;

    genRadius = deltaAngle == 0 ? 0 : deltaSector / deltaAngle;

    deltaX = deltaAngle == 0 ? 0 : genRadius - (genRadius * cos(deltaAngle));
    deltaY = deltaAngle == 0 ? deltaSector : genRadius * sin(deltaAngle);

    currPosX += deltaX * cos(currAngle) + deltaY * sin(currAngle);
    currPosY += deltaY * cos(currAngle) - deltaX * sin(currAngle);
    currAngle += deltaAngle;

    lastTrackerVal = trackerVal;
    lastTrackerVal = gyroVal;

    pros::delay(10);
  }
}
