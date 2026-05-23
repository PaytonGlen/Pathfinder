// Flow step 9 in this folder: this file handles incoming MPU data and outgoing obstacle messages.

#include "MasterLink.h"
#include <string.h>
#include <stdlib.h>

static char    rxBuf[64];
static uint8_t rxLen = 0;

static unsigned long lastObstacleSend = 0;

static bool        mpuValid = false;
static MpuSnapshot latest   = {0, 0, 0, 0, 0, 0};

static void parseMpuLine(char *csv) {
  int16_t *fields[6] = { &latest.ax, &latest.ay, &latest.az,
                         &latest.gx, &latest.gy, &latest.gz };
  char *token = strtok(csv, ",");
  for (int i = 0; i < 6; i++) {
    if (token == NULL) return;
    *fields[i] = (int16_t)atoi(token);
    token = strtok(NULL, ",");
  }
  mpuValid = true;
}

void initMasterLink() {
  rxLen = 0;
  lastObstacleSend = 0;
  mpuValid = false;
}

void processIncomingMessages() {
  while (Serial.available()) {
    char c = Serial.read();

    if (c == '\n' || c == '\r') {
      if (rxLen > 0) {
        rxBuf[rxLen] = '\0';
        if (rxBuf[0] == 'M' && rxBuf[1] == ',') {
          parseMpuLine(rxBuf + 2);
        }
        rxLen = 0;
      }
    } else if (rxLen < sizeof(rxBuf) - 1) {
      rxBuf[rxLen++] = c;
    } else {
      rxLen = 0;
    }
  }
}

void sendObstacleIfDue() {
  if (millis() - lastObstacleSend < OBSTACLE_RESEND_MS) return;
  Serial.println(F("OBSTACLE"));
  lastObstacleSend = millis();
}

bool getLatestMpu(MpuSnapshot &out) {
  out = latest;
  return mpuValid;
}
