// Shared serial link helpers for the slave Arduino.

#ifndef SLAVE_LINK_H
#define SLAVE_LINK_H

#include <Arduino.h>

const unsigned long MPU_SEND_INTERVAL_MS = 200;

void initSlaveLink();
void streamMpuIfDue();
bool pollForObstacleAlert();

#endif
