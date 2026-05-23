// Flow step 2 in this folder: this header declares the movement functions used by DriveSequence.ino.

#ifndef MOVEMENT_H
#define MOVEMENT_H

#include <Arduino.h>

void driveForward(unsigned long durationMs);

void turnRight(unsigned long durationMs);

#endif
