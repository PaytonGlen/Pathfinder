// Flow step 4 in this folder: this header declares the low-level motor functions used by Movement.cpp.

#ifndef MOTOR_CONTROL_H
#define MOTOR_CONTROL_H

#include <Arduino.h>

void initMotors();
void enableMotors();
void disableMotors();

void setRightTrack(bool forward, uint8_t speed);
void setLeftTrack (bool forward, uint8_t speed);
void stopMotors();

#endif
