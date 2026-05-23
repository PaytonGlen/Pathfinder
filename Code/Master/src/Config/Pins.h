// Shared hardware pin assignments for the master Arduino.

/*
    Some changes will need to be made here:
    - There will be 6 US Sensors instead of just 1
    - There will be 6 IR Sensors
    - I/O will need to be laid out for that
*/

#ifndef PINS_H
#define PINS_H

#include <Arduino.h>

const uint8_t PIN_STBY = 3;
const uint8_t PIN_PWMA = 5;
const uint8_t PIN_PWMB = 6;
const uint8_t PIN_AIN1 = 7;
const uint8_t PIN_BIN1 = 8;

// These US Sensors will be named #1 - #6 starting from the front facing one and go clockwise
const uint8_t PIN_TRIG_FRONT = 13;
const uint8_t PIN_ECHO_FRONT = 12;
const uint8_t PIN_TRIG_SHOULDER = A1;
const uint8_t PIN_ECHO_SHOULDER = A2;

const uint8_t PIN_IR = A0;

const uint8_t PIN_SERVO_PAN = 10;
const uint8_t PIN_SERVO_TILT = 11;

const uint8_t PIN_RANDOM_SEED = A3;

#endif
