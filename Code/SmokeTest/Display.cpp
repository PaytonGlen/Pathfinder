// Flow step 7 in this folder: this is where the LCD actually gets updated with the sensor values.

#include "Display.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

static LiquidCrystal_I2C lcd(LCD_ADDR, 16, 2);

void initDisplay() {
  lcd.init();
  lcd.backlight();
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("Light:");
  lcd.setCursor(0, 1);
  lcd.print("IR:");
}

void printValueAt(byte col, byte row, int value) {
  char buf[6];
  snprintf(buf, sizeof(buf), "%-5d", value);
  lcd.setCursor(col, row);
  lcd.print(buf);
}
