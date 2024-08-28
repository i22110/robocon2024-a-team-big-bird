#ifndef WHEEL_H
#define WHEEL_H

#include "components/Motor.h" // Motorクラスのヘッダーファイルをインクルード

// Wheelクラスの定義
class Wheel {
private:
  static Motor leftMotor1;  // 左側のモーター1
  static Motor leftMotor2;  // 左側のモーター2
  static Motor rightMotor1; // 右側のモーター1
  static Motor rightMotor2; // 右側のモーター2

public:
  static void init(); // 初期化メソッド
  static void forwardL(); // 左側のモーターを前進させるメソッド
  static void reverseL(); // 左側のモーターを後退させるメソッド
  static void stopL(); // 左側のモーターを停止させるメソッド
  static void forwardR(); // 右側のモーターを前進させるメソッド
  static void reverseR(); // 右側のモーターを後退させるメソッド
  static void stopR(); // 右側のモーターを停止させるメソッド
};

#endif // WHEEL_H