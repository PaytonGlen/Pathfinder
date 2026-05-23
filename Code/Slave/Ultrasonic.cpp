// Flow step 7 in this folder: this is the actual ultrasonic read code.

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

  unsigned long t = pulseIn(echoPin, HIGH, ECHO_TIMEOUT_US);
  if (t == 0) return 0;
  return t / 58;
}
