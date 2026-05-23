// Shared MPU-6050 helpers.

#ifndef MPU_6050_H
#define MPU_6050_H

#include <Arduino.h>

void initMpu();
void readMpu(int16_t &ax, int16_t &ay, int16_t &az,
             int16_t &gx, int16_t &gy, int16_t &gz);

#endif
