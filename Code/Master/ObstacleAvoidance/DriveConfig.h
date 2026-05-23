// Support file for this folder: drive speed and turn timing values live here.

#ifndef DRIVE_CONFIG_H
#define DRIVE_CONFIG_H

#include <Arduino.h>

const byte LEFT_DRIVE_SPEED  = 173;   // slowed a hair to fix right-veer
const byte RIGHT_DRIVE_SPEED = 180;
const byte TURN_SPEED        = 220;

const unsigned long MS_PER_FOOT   = 800;
const unsigned long MS_PER_90_DEG = 450;

const bool RIGHT_FORWARD_HIGH = true;
const bool LEFT_FORWARD_HIGH  = true;

#endif
