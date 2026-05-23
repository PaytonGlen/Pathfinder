// Main scan-and-turn behavior for the master Arduino.

#ifndef SCAN_WANDER_LOGIC_H
#define SCAN_WANDER_LOGIC_H

#include <Arduino.h>

const int SCAN_STOP_DISTANCE_CM = 20;
const int SCAN_CLEAR_DISTANCE_CM = 30;
const unsigned long SCAN_BACKUP_MS = 600;
const bool SLAVE_US_ON_LEFT = true;

void runScanWanderLoop();

#endif
