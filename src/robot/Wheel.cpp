#include "Wheel.h"
#include <Arduino.h>

Motor Wheel::leftMotor1 = Motor(0, 0);
Motor Wheel::leftMotor2 = Motor(0, 0);
Motor Wheel::rightMotor1 = Motor(0, 0);
Motor Wheel::rightMotor2 = Motor(0, 0);

void Wheel::init() {
  stopL();
  stopR();
}

void Wheel::forwardL() {
  leftMotor1.forward();
  leftMotor2.forward();
}

void Wheel::reverseL() {
  leftMotor1.reverse();
  leftMotor2.reverse();
}

void Wheel::forwardR() {
  rightMotor1.forward();
  rightMotor2.forward();
}

void Wheel::reverseR() {
  rightMotor1.reverse();
  rightMotor2.reverse();
}

void Wheel::stopL() {
  leftMotor1.stop();
  leftMotor2.stop();
}

void Wheel::stopR() {
  rightMotor1.stop();
  rightMotor2.stop();
}