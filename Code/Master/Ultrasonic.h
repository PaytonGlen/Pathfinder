// Support file for ScanWander: WanderLogic.cpp uses this header to read both ultrasonic sensors.

#ifndef ULTRASONIC_H
#define ULTRASONIC_H

#include <Arduino.h>

void initUltrasonic(byte trigPin, byte echoPin);
int  readDistanceCm(byte trigPin, byte echoPin);

#endif
