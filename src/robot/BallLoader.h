#ifndef BALLLOADER_H
#define BALLLOADER_H

#include "components/Motor.h" // Motorクラスのヘッダーファイルをインクルード

// BallLoaderクラスの定義
class BallLoader {
private:
  static Motor motor;       // モーターのインスタンス
  static int upperLimitPin; // 上限リミットスイッチのピン番号
  static int lowerLimitPin; // 下限リミットスイッチのピン番号
  static void down();       // ボールを下げるメソッド

public:
  static void init(); // 初期化メソッド
  static void load(); // ボールを集めるメソッド
};

#endif // BALLLOADER_H