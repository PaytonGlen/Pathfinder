// Support file for this folder: MotorControl.cpp uses these pin numbers for the final motor writes.

#ifndef MOTOR_PINS_H
#define MOTOR_PINS_H

#include <Arduino.h>

const byte PIN_STBY = 3;
const byte PIN_PWMA = 5;   // Right track speed
const byte PIN_PWMB = 6;   // Left  track speed
const byte PIN_AIN1 = 7;   // Right track direction
const byte PIN_BIN1 = 8;   // Left  track direction

#endif
