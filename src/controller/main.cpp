#include <Arduino.h>
#include "Controller.h"
#include "components/ImSender.h"

#define LOAD_PIN 0
#define SHOOT_PIN 0
#define FORWARD_L_PIN 0
#define REVERSE_L_PIN 0
#define FORWARD_R_PIN 0
#define REVERSE_R_PIN 0

ImSender imSender(0, 0, 0);

void setup() {
  // put your setup code here, to run once:
  pinMode(LOAD_PIN, INPUT);
  pinMode(SHOOT_PIN, INPUT);
  pinMode(FORWARD_L_PIN, INPUT);
  pinMode(REVERSE_L_PIN, INPUT);
  pinMode(FORWARD_R_PIN, INPUT);
  pinMode(REVERSE_R_PIN, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Controller controller;
  controller.load = digitalRead(LOAD_PIN);
  controller.shoot = digitalRead(SHOOT_PIN);
  controller.forwardL = digitalRead(FORWARD_L_PIN);
  controller.reverseL = digitalRead(REVERSE_L_PIN);
  controller.forwardR = digitalRead(FORWARD_R_PIN);
  controller.reverseR = digitalRead(REVERSE_R_PIN);
  imSender.send(controller);
}