// Flow step 2 in this folder: this header declares the light sensor functions used by Slave.ino.

#ifndef LIGHT_SENSOR_H
#define LIGHT_SENSOR_H

#include <Arduino.h>

void initLight(byte pin);
int  readLight(byte pin);

#endif
