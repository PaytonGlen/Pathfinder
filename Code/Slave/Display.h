// Flow step 10 in this folder: this header declares the LCD functions used by Slave.ino.

#ifndef DISPLAY_H
#define DISPLAY_H

#include <Arduino.h>
#include "MasterLink.h"

const byte LCD_ADDR = 0x27;
const unsigned long LCD_UPDATE_MS = 200;

void initDisplay();

void updateLcdIfDue(int lightVal, int us3Cm, int tempCx10,
                    bool mpuValid, const MpuSnapshot &mpu);

#endif
