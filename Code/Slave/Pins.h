// Support file for this folder: all hardware pin assignments for the slave board live here.

#ifndef PINS_H
#define PINS_H

#include <Arduino.h>

const byte PIN_TRIG_US = 8;
const byte PIN_ECHO_US = 7;

const byte PIN_LIGHT = A0;   // photoresistor (voltage divider)
const byte PIN_TEMP  = A1;   // TMP36 temperature sensor

#endif
