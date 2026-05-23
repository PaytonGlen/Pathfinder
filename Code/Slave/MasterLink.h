// Flow step 8 in this folder: this header declares the serial functions used by Slave.ino.

#ifndef MASTER_LINK_H
#define MASTER_LINK_H

#include <Arduino.h>

const int OBSTACLE_THRESHOLD_CM = 25;

const unsigned long OBSTACLE_RESEND_MS = 1000;

struct MpuSnapshot {
  int16_t ax, ay, az;
  int16_t gx, gy, gz;
};

void initMasterLink();

void processIncomingMessages();

void sendObstacleIfDue();

bool getLatestMpu(MpuSnapshot &out);

#endif
