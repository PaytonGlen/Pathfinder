// Shared hardware pin assignments for the master Arduino.

#ifndef PINS_H
#define PINS_H

#include <Arduino.h>

const uint8_t PIN_STBY = 3;
const uint8_t PIN_PWMA = 5;
const uint8_t PIN_PWMB = 6;
const uint8_t PIN_AIN1 = 7;
const uint8_t PIN_BIN1 = 8;

const uint8_t PIN_TRIG_FRONT = 13;
const uint8_t PIN_ECHO_FRONT = 12;
const uint8_t PIN_TRIG_SHOULDER = A1;
const uint8_t PIN_ECHO_SHOULDER = A2;

const uint8_t PIN_IR = A0;

const uint8_t PIN_SERVO_PAN = 10;
const uint8_t PIN_SERVO_TILT = 11;

const uint8_t PIN_RANDOM_SEED = A3;

#endif
