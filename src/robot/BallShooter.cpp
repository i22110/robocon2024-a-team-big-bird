#include "BallShooter.h" // BallShooterクラスのヘッダーファイルをインクルード
#include <Arduino.h> // Arduinoの標準ライブラリをインクルード

// BallShooterクラスの静的メンバ変数を初期化
Motor BallShooter::motor = Motor(0, 0); // モーターを初期化
int BallShooter::sensorPin = 0;       // センサーピンの番号を初期化
int BallShooter::releasePin = 0;      // リリースピンの番号を初期化
float BallShooter::releaseLength = 0; // リリースの長さを初期化

// 初期化メソッド
void BallShooter::init() {
  pinMode(sensorPin, INPUT);   // センサーピンを入力モードに設定
  pinMode(releasePin, OUTPUT); // リリースピンを出力モードに設定
}

// ボールを発射するメソッド
void BallShooter::shoot() {
  motor.forward(); // モーターを前進させる

  // センサーの値がリリースの長さに達するまで待つ
  while (analogRead(sensorPin) < releaseLength) {
    delay(10); // 10ミリ秒待機
  }

  motor.stop();                   // モーターを停止
  digitalWrite(releasePin, HIGH); // リリースピンをHIGHに設定
  delay(100);                     // 100ミリ秒待機
  digitalWrite(releasePin, LOW);  // リリースピンをLOWに設定
}