// Support file for this folder: all hardware pin assignments for the master board live here.

#ifndef PINS_H
#define PINS_H

#include <Arduino.h>

const byte PIN_STBY = 3;
const byte PIN_PWMA = 5;   // right track speed
const byte PIN_PWMB = 6;   // left  track speed
const byte PIN_AIN1 = 7;   // right track direction
const byte PIN_BIN1 = 8;   // left  track direction

const byte PIN_TRIG = 13;
const byte PIN_ECHO = 12;

const byte PIN_RANDOM_SEED = A5;

#endif
