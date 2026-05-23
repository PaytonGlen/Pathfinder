// Flow step 3 in this folder: this file runs the moves, then drops down to MotorControl.cpp.

#include "Movement.h"
#include "MotorControl.h"
#include "DriveConfig.h"

void driveForward(unsigned long durationMs) {
  setRightTrack(true, RIGHT_DRIVE_SPEED);
  setLeftTrack (true, LEFT_DRIVE_SPEED);
  delay(durationMs);
  stopMotors();
}

void turnRight(unsigned long durationMs) {
  setLeftTrack (true,  TURN_SPEED);
  setRightTrack(false, TURN_SPEED);
  delay(durationMs);
  stopMotors();
}
