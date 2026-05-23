// Flow step 11 in this folder: this is where the LCD actually gets updated with the latest sensor and MPU data.

#include "Display.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

static LiquidCrystal_I2C lcd(LCD_ADDR, 16, 2);
static unsigned long lastLcdUpdate = 0;

void initDisplay() {
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(F("Slave booting..."));
  delay(600);
  lcd.clear();
}

void updateLcdIfDue(int lightVal, int us3Cm, int tempCx10,
                    bool mpuValid, const MpuSnapshot &mpu) {
  if (millis() - lastLcdUpdate < LCD_UPDATE_MS) return;
  lastLcdUpdate = millis();

  char tempStr[8];
  int tempF_x10 = (tempCx10 * 9) / 5 + 320;
  int tempInt = tempF_x10 / 10;
  int tempDec = abs(tempF_x10 % 10);
  snprintf(tempStr, sizeof(tempStr), "%d.%dF", tempInt, tempDec);

  char row0[17];
  snprintf(row0, sizeof(row0), "L:%-4d T:%-7s", lightVal, tempStr);
  lcd.setCursor(0, 0);
  lcd.print(row0);

  char row1[17];
  if (mpuValid) {
    int axG100 = (long)mpu.ax * 100L / 16384L;
    int azG100 = (long)mpu.az * 100L / 16384L;
    snprintf(row1, sizeof(row1), "Ax:%-4d Az:%-4d", axG100, azG100);
  } else {
    snprintf(row1, sizeof(row1), "(no MPU yet)    ");
  }
  lcd.setCursor(0, 1);
  lcd.print(row1);
}
