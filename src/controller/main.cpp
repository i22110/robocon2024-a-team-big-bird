#include "Controller.h"
#include "components/ImSender.h"
#include <Arduino.h>

// ピンの定義。これらはマイクロコントローラの特定のピン番号を表す。
#define LOAD_PIN 0      // ボールを回収するモーターのピン
#define SHOOT_PIN 0     // ボールを射出するモーターのピン
#define FORWARD_L_PIN 0 // 左モーターの前進ピン
#define REVERSE_L_PIN 0 // 左モーターの後退ピン
#define FORWARD_R_PIN 0 // 右モーターの前進ピン
#define REVERSE_R_PIN 0 // 右モーターの後退ピン

// ImSenderオブジェクトの作成。引数は初期化に使用される。
// 引数でrxPin, txPin, baudRateを指定する。
ImSender imSender(0, 0, 0);

// setup関数は、プログラムの開始時に一度だけ実行される。
void setup() {
  // ピンのモードを設定する。INPUTは入力モードを意味する。
  pinMode(LOAD_PIN, INPUT);      // LOAD_PINを入力モードに設定
  pinMode(SHOOT_PIN, INPUT);     // SHOOT_PINを入力モードに設定
  pinMode(FORWARD_L_PIN, INPUT); // FORWARD_L_PINを入力モードに設定
  pinMode(REVERSE_L_PIN, INPUT); // REVERSE_L_PINを入力モードに設定
  pinMode(FORWARD_R_PIN, INPUT); // FORWARD_R_PINを入力モードに設定
  pinMode(REVERSE_R_PIN, INPUT); // REVERSE_R_PINを入力モードに設定
}

// loop関数は、プログラムが停止するまで繰り返し実行される。
void loop() {
  // Controllerオブジェクトを作成。これにより、コントローラの状態を管理する。
  Controller controller;

  // 各ピンの状態を読み取り、controllerオブジェクトに保存する。
  controller.load =
      digitalRead(LOAD_PIN); // LOAD_PINの状態を読み取ってcontroller.loadに保存
  controller.shoot = digitalRead(
      SHOOT_PIN); // SHOOT_PINの状態を読み取ってcontroller.shootに保存
  controller.forwardL = digitalRead(
      FORWARD_L_PIN); // FORWARD_L_PINの状態を読み取ってcontroller.forwardLに保存
  controller.reverseL = digitalRead(
      REVERSE_L_PIN); // REVERSE_L_PINの状態を読み取ってcontroller.reverseLに保存
  controller.forwardR = digitalRead(
      FORWARD_R_PIN); // FORWARD_R_PINの状態を読み取ってcontroller.forwardRに保存
  controller.reverseR = digitalRead(
      REVERSE_R_PIN); // REVERSE_R_PINの状態を読み取ってcontroller.reverseRに保存

  // controllerオブジェクトをimSenderを使って送信する。
  imSender.send(controller);
}