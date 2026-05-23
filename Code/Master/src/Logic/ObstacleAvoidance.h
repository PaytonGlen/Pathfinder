// Basic forward/back-up/random-turn behavior.

#ifndef OBSTACLE_AVOIDANCE_H
#define OBSTACLE_AVOIDANCE_H

#include <Arduino.h>

const int OBSTACLE_STOP_DISTANCE_CM = 20;
const unsigned long OBSTACLE_BACKUP_MS = 600;
const unsigned long OBSTACLE_PING_INTERVAL_MS = 60;

void runObstacleAvoidanceLoop();

#endif
