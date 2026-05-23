// Flow step 4 in this folder: this header declares the servo functions used by Cli.cpp.

#ifndef SERVOS_H
#define SERVOS_H

#include <Arduino.h>

void initServos();
void panTo (int angle);
void tiltTo(int angle);
void centerBoth();

int getPanAngle();
int getTiltAngle();

#endif
