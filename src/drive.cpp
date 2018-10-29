#include "main.h"

Motor driveL1(MPORT_DRIVE_L1, false, AbstractMotor::gearset::green);
Motor driveL2(MPORT_DRIVE_L2, false, AbstractMotor::gearset::green);
Motor driveR1(MPORT_DRIVE_R1, true, AbstractMotor::gearset::green);
Motor driveR2(MPORT_DRIVE_R2, true, AbstractMotor::gearset::green);

ChassisControllerIntegrated chassisController =
    ChassisControllerFactory::create(
        {
            MPORT_DRIVE_L1,
            MPORT_DRIVE_L2,
        }, // Left motors
        {
            -MPORT_DRIVE_R1,
            -MPORT_DRIVE_R2,
        },                             // Right motors
        AbstractMotor::gearset::green, // Speed gearset
        {4_in, 9.867_in} // 4 inch wheels, 9.867 inch wheelbase width
    );
