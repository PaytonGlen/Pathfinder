// Flow step 3 in this folder: this is the actual light sensor read code.

#include "LightSensor.h"

void initLight(byte pin) {
  pinMode(pin, INPUT);
}

int readLight(byte pin) {
  return analogRead(pin);
}
