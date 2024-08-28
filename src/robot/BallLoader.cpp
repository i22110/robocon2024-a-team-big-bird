#include "BallLoader.h"
#include <Arduino.h>

Motor BallLoader::motor = Motor(0, 0);
int BallLoader::upperLimitPin = 0;
int BallLoader::lowerLimitPin = 0;

// コンストラクタ
void BallLoader::init() {
  pinMode(upperLimitPin, INPUT_PULLUP);
  pinMode(lowerLimitPin, INPUT_PULLUP);
  down();
}

// ボールを集めるメソッド
void BallLoader::load() {
  // 上限リミットスイッチが押されるまで正転
  while (digitalRead(upperLimitPin) == HIGH) {
    motor.forward();
  }
  motor.stop(); // 上限に達したら停止
  down();
}

void BallLoader::down() {
  while (digitalRead(lowerLimitPin) == HIGH) {
    motor.reverse();
  }
  motor.stop();
}