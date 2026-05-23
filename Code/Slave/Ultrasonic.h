// Flow step 6 in this folder: this header declares the ultrasonic functions used by Slave.ino.

#ifndef ULTRASONIC_H
#define ULTRASONIC_H

#include <Arduino.h>

void initUltrasonic(byte trigPin, byte echoPin);
int  readDistanceCm(byte trigPin, byte echoPin);

#endif
