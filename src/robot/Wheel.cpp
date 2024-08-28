#include "Wheel.h" // Wheelクラスのヘッダーファイルをインクルード
#include <Arduino.h> // Arduinoの標準ライブラリをインクルード

// Wheelクラスの静的メンバ変数を初期化
Motor Wheel::leftMotor1 = Motor(0, 0); // 左側のモーター1を初期化
Motor Wheel::leftMotor2 = Motor(0, 0); // 左側のモーター2を初期化
Motor Wheel::rightMotor1 = Motor(0, 0); // 右側のモーター1を初期化
Motor Wheel::rightMotor2 = Motor(0, 0); // 右側のモーター2を初期化

// 初期化メソッド
void Wheel::init() {
  stopL(); // 左側のモーターを停止
  stopR(); // 右側のモーターを停止
}

// 左側のモーターを前進させるメソッド
void Wheel::forwardL() {
  leftMotor1.forward(); // 左側のモーター1を前進させる
  leftMotor2.forward(); // 左側のモーター2を前進させる
}

// 左側のモーターを後退させるメソッド
void Wheel::reverseL() {
  leftMotor1.reverse(); // 左側のモーター1を後退させる
  leftMotor2.reverse(); // 左側のモーター2を後退させる
}

// 右側のモーターを前進させるメソッド
void Wheel::forwardR() {
  rightMotor1.forward(); // 右側のモーター1を前進させる
  rightMotor2.forward(); // 右側のモーター2を前進させる
}

// 右側のモーターを後退させるメソッド
void Wheel::reverseR() {
  rightMotor1.reverse(); // 右側のモーター1を後退させる
  rightMotor2.reverse(); // 右側のモーター2を後退させる
}

// 左側のモーターを停止させるメソッド
void Wheel::stopL() {
  leftMotor1.stop(); // 左側のモーター1を停止させる
  leftMotor2.stop(); // 左側のモーター2を停止させる
}

// 右側のモーターを停止させるメソッド
void Wheel::stopR() {
  rightMotor1.stop(); // 右側のモーター1を停止させる
  rightMotor2.stop(); // 右側のモーター2を停止させる
}