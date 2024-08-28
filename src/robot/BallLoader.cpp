#include "BallLoader.h" // BallLoaderクラスのヘッダーファイルをインクルード
#include <Arduino.h> // Arduinoの標準ライブラリをインクルード

// BallLoaderクラスの静的メンバ変数を初期化
Motor BallLoader::motor = Motor(0, 0); // モーターを初期化
int BallLoader::upperLimitPin = 0; // 上限リミットスイッチのピン番号を初期化
int BallLoader::lowerLimitPin = 0; // 下限リミットスイッチのピン番号を初期化

// コンストラクタ
void BallLoader::init() {
  // 上限リミットスイッチのピンを入力モードに設定
  pinMode(upperLimitPin, INPUT_PULLUP);
  // 下限リミットスイッチのピンを入力モードに設定
  pinMode(lowerLimitPin, INPUT_PULLUP);
  // ボールを下げる動作を開始
  down();
}

// ボールを集めるメソッド
void BallLoader::load() {
  // 上限リミットスイッチが押されるまでモーターを正転させる
  while (digitalRead(upperLimitPin) == HIGH) {
    motor.forward(); // モーターを前進させる
  }
  motor.stop(); // 上限に達したらモーターを停止
  down();       // ボールを下げるメソッドを呼び出す
}

// ボールを下げるメソッド
void BallLoader::down() {
  // 下限リミットスイッチが押されるまでモーターを逆転させる
  while (digitalRead(lowerLimitPin) == HIGH) {
    motor.reverse(); // モーターを後退させる
  }
  motor.stop(); // 下限に達したらモーターを停止
}