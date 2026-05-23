// Support file for ScanWander: WanderLogic.cpp uses this header to read the IR sensor.

#ifndef IR_SENSOR_H
#define IR_SENSOR_H

#include <Arduino.h>

const int IR_OBSTACLE_THRESHOLD = 125;

int  readIrRaw(byte pin);
bool isIrBlocked(byte pin);

#endif
