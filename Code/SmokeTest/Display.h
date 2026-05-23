// Flow step 6 in this folder: this header declares the LCD functions used by SmokeTest.ino.

#ifndef DISPLAY_H
#define DISPLAY_H

#include <Arduino.h>

const byte LCD_ADDR = 0x27;

void initDisplay();
void printValueAt(byte col, byte row, int value);

#endif
