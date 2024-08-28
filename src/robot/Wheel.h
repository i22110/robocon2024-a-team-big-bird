#ifndef WHEEL_H
#define WHEEL_H

#include "components/Motor.h"

class Wheel {
private:
  static Motor leftMotor1;  // 左側のモーター1
  static Motor leftMotor2;  // 左側のモーター2
  static Motor rightMotor1; // 右側のモーター1
  static Motor rightMotor2; // 右側のモーター2

public:
  static void init();
  static void forwardL();
  static void reverseL();
  static void stopL();
  static void forwardR();
  static void reverseR();
  static void stopR();
};

#endif
