// コントローラーの構造体
struct Controller {
  bool load;      // ボールを集めるボタンが押されたかどうか
  bool shoot;     // ボールを発射するボタンが押されたかどうか
  bool forwardL;  // 左側のモーターを前進させるボタンが押されたかどうか
  bool reverseL;  // 左側のモーターを後退させるボタンが押されたかどうか
  bool forwardR;  // 右側のモーターを前進させるボタンが押されたかどうか
  bool reverseR;  // 右側のモーターを後退させるボタンが押されたかどうか
};