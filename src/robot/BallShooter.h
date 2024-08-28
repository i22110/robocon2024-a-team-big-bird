#ifndef BALLSHOOTER_H
#define BALLSHOOTER_H

#include "components/Motor.h"

class BallShooter {
private:
  static Motor motor;
  static int sensorPin;
  static int releasePin;
  static float releaseLength;

public:
  static void init();
  static void shoot();
};

#endif
