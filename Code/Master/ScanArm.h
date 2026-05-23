// Support file for ScanWander: WanderLogic.cpp uses this header to point the scan arm left, right, or center.

#ifndef SCAN_ARM_H
#define SCAN_ARM_H

#include <Arduino.h>

const int PAN_CENTER = 50;
const int PAN_LEFT   = 110;
const int PAN_RIGHT  = 0;
const int TILT_LEVEL = 160;

const unsigned long SERVO_SETTLE_MS = 400;

void initScanArm();
void panTo(int angle);
void tiltTo(int angle);
void centerPan();

#endif
