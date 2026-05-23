// Flow step 1 in this folder: start here, then this file waits for commands and passes them into Cli.cpp.

#include "Pins.h"
#include "Servos.h"
#include "Cli.h"

void setup() {
  Serial.begin(9600);
  while (!Serial) { ; }

  initServos();
  printHelp();
  printState();
}

void loop() {
  if (Serial.available()) handleSerialCommand();
}
