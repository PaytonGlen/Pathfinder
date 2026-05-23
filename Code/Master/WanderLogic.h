// Flow step 2 in this folder: this header declares the main behavior functions used by ScanWander.ino.

#ifndef WANDER_LOGIC_H
#define WANDER_LOGIC_H

#include <Arduino.h>

const int STOP_DISTANCE_CM  = 20;
const int CLEAR_DISTANCE_CM = 30;
const unsigned long BACKUP_MS = 600;

const bool SLAVE_US_ON_LEFT = true;

struct ScanResult {
  int  usDist;
  int  irRaw;
  bool blocked;
};

void driveForwardUntilObstacle();
ScanResult scanAt(int panAngle);
void decideAndTurn(ScanResult left, ScanResult right);
void reactToSlaveObstacle();

#endif
