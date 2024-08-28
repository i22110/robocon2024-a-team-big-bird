#include "BallLoader.h" // BallLoaderクラスのヘッダーファイルをインクルード
#include "BallShooter.h" // BallShooterクラスのヘッダーファイルをインクルード
#include "Controller.h" // Controllerクラスのヘッダーファイルをインクルード
#include "Wheel.h" // Wheelクラスのヘッダーファイルをインクルード
#include "components/ImReceiver.h" // ImReceiverクラスのヘッダーファイルをインクルード
#include "utils/DebugLogger.h" // DebugLoggerクラスのヘッダーファイルをインクルード
#include <Arduino.h> // Arduinoの標準ライブラリをインクルード

// 赤外線受信機のインスタンスを作成
// 12番ピンと11番ピンを使用し、ボーレート19200で初期化
ImReceiver receiver(12, 11, 19200);

void setup() {
  // 初期設定があればここに記述
  DebugLogger::init(Serial, 19200); // シリアルポートの初期化
}

void loop() {
  // コントローラーの状態を受信
  while (!receiver.available())
    delay(100); // 受信待ちの間、100ミリ秒待機

  Controller controller; // コントローラーのインスタンスを作成
  receiver.receive(controller); // コントローラーの状態を受信

  // コレクションの操作
  if (controller.load) {
    // デバッグメッセージを出力
    DebugLogger::print("Main", "loop", "Loading balls\n");
    BallLoader::load(); // ボールを集めるメソッドを呼び出す
  }

  // シューティングの操作
  if (controller.shoot)
    BallShooter::shoot(); // ボールを発射するメソッドを呼び出す

  // 左側のモーターを前進
  if (controller.forwardL)
    Wheel::forwardL(); // 左側のモーターを前進させる
  // 左側のモーターを後退
  else if (controller.reverseL)
    Wheel::reverseL(); // 左側のモーターを後退させる
  else
    Wheel::stopL(); // 左側のモーターを停止させる

  // 右側のモーターを前進
  if (controller.forwardR)
    Wheel::forwardR(); // 右側のモーターを前進させる
  // 右側のモーターを後退
  else if (controller.reverseR)
    Wheel::reverseR(); // 右側のモーターを後退させる
  else
    Wheel::stopR(); // 右側のモーターを停止させる
}