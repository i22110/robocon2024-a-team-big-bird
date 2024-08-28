#ifndef BALLSHOOTER_H
#define BALLSHOOTER_H

#include "components/Motor.h" // Motorクラスのヘッダーファイルをインクルード

// BallShooterクラスの定義
class BallShooter {
private:
  static Motor motor;         // モーターのインスタンス
  static int sensorPin;       // センサーピンの番号
  static int releasePin;      // リリースピンの番号
  static float releaseLength; // リリースの長さ

public:
  static void init();  // 初期化メソッド
  static void shoot(); // ボールを発射するメソッド
};

#endif // BALLSHOOTER_H