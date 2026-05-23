// Flow step 2 in this folder: this header declares the command functions used by ServoCalibration.ino.

#ifndef CLI_H
#define CLI_H

#include <Arduino.h>

void handleSerialCommand();
void printHelp();
void printState();

#endif
