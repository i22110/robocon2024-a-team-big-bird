#ifndef BALLLOADER_H
#define BALLLOADER_H

#include "components/Motor.h"

class BallLoader {
private:
  static Motor motor;
  static int upperLimitPin; // 上限リミットスイッチのピン番号
  static int lowerLimitPin; // 下限リミットスイッチのピン番号
  static void down();

public:
  static void init();
  static void load();
};

#endif
