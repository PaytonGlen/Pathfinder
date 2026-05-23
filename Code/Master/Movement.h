// Flow step 4 in this folder: this header declares the drive functions WanderLogic.cpp uses to move the tank.

#ifndef MOVEMENT_H
#define MOVEMENT_H

#include <Arduino.h>

void driveForward(unsigned long durationMs);
void reverse(unsigned long durationMs);
void turnRight(unsigned long durationMs);
void turnLeft(unsigned long durationMs);

#endif
