// Flow step 4 in this folder: this header declares the IR sensor functions used by SmokeTest.ino.

#ifndef IR_SENSOR_H
#define IR_SENSOR_H

#include <Arduino.h>

void initIr(byte pin);
int  readIrRaw(byte pin);

#endif
