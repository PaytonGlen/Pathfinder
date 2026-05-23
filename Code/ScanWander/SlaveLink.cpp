// Support file for ScanWander: this is the serial send/receive code used for the slave Arduino.

#include "SlaveLink.h"
#include "Mpu6050.h"
#include <string.h>

static unsigned long lastMpuSend = 0;
static char          rxBuf[32];
static uint8_t       rxLen = 0;

void initSlaveLink() {
  lastMpuSend = millis();
  rxLen = 0;
}

void streamMpuIfDue() {
  unsigned long now = millis();
  if (now - lastMpuSend < MPU_SEND_INTERVAL_MS) return;
  lastMpuSend = now;

  int16_t ax, ay, az, gx, gy, gz;
  readMpu(ax, ay, az, gx, gy, gz);

  Serial.print(F("M,"));
  Serial.print(ax); Serial.print(',');
  Serial.print(ay); Serial.print(',');
  Serial.print(az); Serial.print(',');
  Serial.print(gx); Serial.print(',');
  Serial.print(gy); Serial.print(',');
  Serial.println(gz);
}

bool pollForObstacleAlert() {
  bool sawObstacle = false;

  while (Serial.available()) {
    char c = Serial.read();

    if (c == '\n' || c == '\r') {
      if (rxLen > 0) {
        rxBuf[rxLen] = '\0';
        if (strstr(rxBuf, "OBSTACLE") != NULL) {
          sawObstacle = true;
        }
        rxLen = 0;
      }
    } else if (rxLen < sizeof(rxBuf) - 1) {
      rxBuf[rxLen++] = c;
    } else {
      rxLen = 0;
    }
  }
  return sawObstacle;
}
