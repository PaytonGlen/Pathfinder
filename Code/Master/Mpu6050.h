// Support file for ScanWander: this header exposes the MPU functions used by SlaveLink.cpp.

#ifndef MPU_6050_H
#define MPU_6050_H

typedef int16_t uShort

#include <Arduino.h>

void initMpu();
void readMpu(uShort &ax, uShort &ay, uShort &az,
             uShort &gx, uShort &gy, uShort &gz);

#endif
