#include "BallLoader.h"
#include "BallShooter.h"
#include "Controller.h"
#include "Wheel.h"
#include "components/ImReceiver.h"
#include "utils/DebugLogger.h"
#include <Arduino.h>

ImReceiver receiver(12, 11, 19200);

void setup() {
  // 初期設定があればここに記述
  DebugLogger::init(Serial, 19200); // シリアルポートの初期化
}

void loop() {
  // コントローラーの状態を受信
  while (!receiver.available())
    delay(100);

  Controller controller;
  receiver.receive(controller);

  // コレクションの操作
  if (controller.load) {
    DebugLogger::print("Main", "loop", "Loading balls\n");
    BallLoader::load();
  }

  // シューティングの操作
  if (controller.shoot)
    BallShooter::shoot();

  // 左側のモーターを前進
  if (controller.forwardL)
    Wheel::forwardL();
  // 左側のモーターを後退
  else if (controller.reverseL)
    Wheel::reverseL();
  else
    Wheel::stopL();

  // 右側のモーターを前進
  if (controller.forwardR)
    Wheel::forwardR();
  // 右側のモーターを後退
  else if (controller.reverseR)
    Wheel::reverseR();
  else
    Wheel::stopR();
}
