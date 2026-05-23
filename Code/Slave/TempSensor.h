// Flow step 4 in this folder: this header declares the temperature sensor functions used by Slave.ino.

#ifndef TEMP_SENSOR_H
#define TEMP_SENSOR_H

#include <Arduino.h>

void initTemp(byte pin);

int readTempCx10(byte pin);

#endif
