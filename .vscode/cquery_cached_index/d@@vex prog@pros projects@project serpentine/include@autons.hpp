#ifndef AUTONS_GUARD
#define AUTONS_GUARD

enum autonRoutines {
  notSelected,
  progSkills,
  redNear1,
  redNear2,
  redFar1,
  redFar2,
  blueNear1,
  blueNear2,
  blueFar1,
  blueFar2,
};

extern autonRoutines autonRoutine;

extern void initProgSkills();
extern void executeProgSkills();

extern void initRedNear1();
extern void executeRedNear1();

extern void initRedNear2();
extern void executeRedNear2();

extern void initRedFar1();
extern void executeRedFar1();

extern void initRedFar2();
extern void executeRedFar2();

extern void initBlueNear1();
extern void executeBlueNear1();

extern void initBlueNear2();
extern void executeBlueNear2();

extern void initBlueFar1();
extern void executeBlueFar1();

extern void initBlueFar2();
extern void executeBlueFar2();

#endif
