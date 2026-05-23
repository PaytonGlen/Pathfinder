// Flow step 2 in this folder: this header declares the behavior functions used by ObstacleAvoidance.ino.

#ifndef WANDER_LOGIC_H
#define WANDER_LOGIC_H

#include <Arduino.h>

const int STOP_DISTANCE_CM = 20;
const unsigned long BACKUP_MS = 600;
const unsigned long PING_INTERVAL_MS = 60;

void driveForwardUntilObstacle();
void randomTurn();

#endif
