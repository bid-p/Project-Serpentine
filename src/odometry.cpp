#include "odometry.hpp"
#include "drive.hpp"

namespace odometry
{
// ADIEncoder rightEnc(RIGHT_ENC.front(), RIGHT_ENC.back(), false);
// ADIEncoder leftEnc(LEFT_ENC.front(), LEFT_ENC.back());

double rEncLast;
double lEncLast;

const double ENC_WHEEL = 4.125;
const double CHASSISWIDTH = 12.25;
const double TICKSINCH = ENC_WHEEL * PI / 360.0;

QLength currX;
QLength currY;
QAngle currAngle;

void init()
{
    currX = 0_ft;
    currY = 0_ft;
    currAngle = 0_deg;

    rEncLast = /*rightEnc.get()*/ drive::driveR2.get_position() * TICKSINCH;
    lEncLast = /*leftEnc.get()*/ drive::driveL2.get_position() * TICKSINCH;
}

/**
     * Iterate
     */
void calculate()
{
    using namespace okapi;

    double dX = 0.0;
    double dY = 0.0;
    double dTheta = 0.0;

    double rCurrEnc = /*rightEnc.get()*/ drive::driveR2.get_position() * TICKSINCH;
    double lCurrEnc = /*leftEnc.get()*/ drive::driveL2.get_position() * TICKSINCH;

    double rDEnc = rCurrEnc - rEncLast;
    double lDEnc = lCurrEnc - lEncLast;

    double dCenterArc = (rDEnc + lDEnc) / 2.0;
    // dCenterArc *= TICKSINCH;

    dTheta = (lDEnc - rDEnc) / CHASSISWIDTH /** PI / 180.0*/;

    double radius = (dTheta == 0) ? 0 : dCenterArc / dTheta;
    dX = dTheta == 0 ? 0 : (radius - radius * cos(dTheta));
    dY = dTheta == 0 ? dCenterArc : radius * sin(dTheta);

    currX = (dX * cos(currAngle.convert(radian)) + dY * sin(currAngle.convert(radian)) + currX.convert(inch)) * inch;
    currY = (dY * cos(currAngle.convert(radian)) - dX * sin(currAngle.convert(radian)) + currY.convert(inch)) * inch;

    currAngle = ((dTheta * 180.0 / PI) + currAngle.convert(degree)) * degree;

    rEncLast = rCurrEnc;
    lEncLast = lCurrEnc;
}

// QLength distanceToPoint(QLength x, QLength y) {}

// QAngle angleToPoint(QLength x, QLength y) {}

// std::tuple<QLength, QAngle> distanceAndAngleToPoint(QLength x, QLength y)
// {
//     return std::tuple<QLength, QAngle>(distanceToPoint(x, y), angleToPoint(x, y));
// }

// void printPosition(void *p)
// {
//     pros::Controller controller(pros::E_CONTROLLER_MASTER);
//     controller.clear();
//     using namespace okapi;

//     while (true)
//     {
//         double x = currX.convert(okapi::foot);
//         double y = currY.convert(okapi::foot);
//         controller.print(0, 0, "X: %.2f", x);
//         pros::delay(51);
//         controller.print(1, 0, "Y: %.2f", y);
//         pros::delay(51);
//     }
// }

void printPosition(void *p)
{
    pros::Controller controller(pros::E_CONTROLLER_MASTER);
    controller.clear();
    using namespace okapi;
    okapi::Logger *log = okapi::Logger::instance();

    while (true)
    {
        double x = currX.convert(okapi::inch);
        double y = currY.convert(okapi::inch);
        double angle = currAngle.convert(okapi::degree);
        // log->debug("X: " + std::to_string(x) + " Y: " + std::to_string(y));

        // printf("X: %f Y: %f", x, y);

        pros::lcd::print(1, "X: %f inches", x);
        pros::lcd::print(2, "Y: %f inches", y);
        pros::lcd::print(3, "THETA: %f degs", angle);

        pros::lcd::print(4, "dL2 RPM: %f", drive::driveL2.getActualVelocity());

        pros::delay(10);
    }
}

void run(void *p)
{
    // pros::Task odometryPrint(printPosition, nullptr, TASK_PRIORITY_DEFAULT, TASK_STACK_DEPTH_DEFAULT, "Position Print --> Controller");
    pros::Task odometryPrint(printPosition, nullptr, TASK_PRIORITY_DEFAULT, TASK_STACK_DEPTH_DEFAULT, "Position Print --> Screen");

    while (true)
    {
        calculate();
        pros::delay(5);
    }
}

} // namespace odometry