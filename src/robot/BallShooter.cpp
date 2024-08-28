#include "BallShooter.h"
#include <Arduino.h>

Motor BallShooter::motor = Motor(0, 0);
int BallShooter::sensorPin = 0;
int BallShooter::releasePin = 0;
float BallShooter::releaseLength = 0;

void BallShooter::init() {
  pinMode(sensorPin, INPUT);
  pinMode(releasePin, OUTPUT);
}

void BallShooter::shoot() {
  motor.forward();

  while (analogRead(sensorPin) < releaseLength) {
    delay(10);
  }

  motor.stop();
  digitalWrite(releasePin, HIGH);
  delay(100);
  digitalWrite(releasePin, LOW);
}
