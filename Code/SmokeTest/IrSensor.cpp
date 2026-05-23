// Flow step 5 in this folder: this is the actual IR sensor read code.

#include "IrSensor.h"

void initIr(byte pin) {
  pinMode(pin, INPUT);
}

int readIrRaw(byte pin) {
  return analogRead(pin);
}
