// Support file for this folder: DriveSequence.ino, Movement.cpp, and MotorControl.cpp all read timing and speed values from here.

#ifndef DRIVE_CONFIG_H
#define DRIVE_CONFIG_H
typedef uint8_t byte;

#include <Arduino.h>

const byte LEFT_DRIVE_SPEED  = 173;   // slowed slightly to fix right-veer
const byte RIGHT_DRIVE_SPEED = 180;
const byte TURN_SPEED        = 220;

const unsigned long MS_PER_FOOT   = 800;
const unsigned long MS_PER_90_DEG = 450;

const bool RIGHT_FORWARD_HIGH = true;
const bool LEFT_FORWARD_HIGH  = true;

#endif
