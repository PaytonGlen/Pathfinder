// Support file for this folder: this is the actual ultrasonic read code used by WanderLogic.cpp.

#include "Ultrasonic.h"

static const unsigned long ECHO_TIMEOUT_US = 30000;

void initUltrasonic(byte trigPin, byte echoPin) {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  digitalWrite(trigPin, LOW);
}

int readDistanceCm(byte trigPin, byte echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  unsigned long pulseDuration = pulseIn(echoPin, HIGH, ECHO_TIMEOUT_US);
  if (pulseDuration == 0) return 0;
  return pulseDuration / 58;
}
