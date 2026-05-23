// Support file for ScanWander: all hardware pin assignments for the master board live here.

#ifndef PINS_H
#define PINS_H
typedef uint8_t byte;

#include <Arduino.h>

const byte PIN_STBY = 3;
const byte PIN_PWMA = 5;   // right track speed
const byte PIN_PWMB = 6;   // left  track speed
const byte PIN_AIN1 = 7;   // right track direction
const byte PIN_BIN1 = 8;   // left  track direction

const byte PIN_TRIG_FRONT    = 13;   // fixed forward sensor
const byte PIN_ECHO_FRONT    = 12;
const byte PIN_TRIG_SHOULDER = A1;   // scanning arm sensor
const byte PIN_ECHO_SHOULDER = A2;

const byte PIN_IR = A0;

const byte PIN_SERVO_PAN  = 10;   // left/right rotation
const byte PIN_SERVO_TILT = 11;   // up/down (kept level)

const byte PIN_RANDOM_SEED = A3;

#endif
