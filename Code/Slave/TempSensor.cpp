// Flow step 5 in this folder: this is the actual temperature sensor read code.

#include "TempSensor.h"

void initTemp(byte pin) {
  pinMode(pin, INPUT);
}

int readTempCx10(byte pin) {
  int raw = analogRead(pin);
  long mV = (long)raw * 5000L / 1024L;
  return (int)(mV - 500);
}
