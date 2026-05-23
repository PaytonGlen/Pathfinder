// Support file for this folder: WanderLogic.cpp uses this header to read the front ultrasonic sensor.

#ifndef ULTRASONIC_H
#define ULTRASONIC_H

#include <Arduino.h>

void initUltrasonic(byte trigPin, byte echoPin);
int  readDistanceCm(byte trigPin, byte echoPin);

#endif
