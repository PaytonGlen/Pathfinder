// Support file for ScanWander: this is the actual IR sensor read code used by WanderLogic.cpp.

#include "IrSensor.h"

int readIrRaw(byte pin) {
  return analogRead(pin);
}

bool isIrBlocked(byte pin) {
  return analogRead(pin) > IR_OBSTACLE_THRESHOLD;
}
