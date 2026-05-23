// Flow step 1 in this folder: start here, then this file reads the sensor and display helpers each loop.

#include "Pins.h"
#include "LightSensor.h"
#include "IrSensor.h"
#include "Display.h"

const unsigned long REFRESH_MS = 200;
unsigned long lastRefresh = 0;

void setup() {
  Serial.begin(9600);
  while (!Serial) { ; }
  Serial.println();
  Serial.println(F("=== Project 3 Smoke Test ==="));
  Serial.println(F("Reading photoresistor (A0) and IR sensor (A2)."));
  Serial.println();

  initLight(PIN_LIGHT);
  initIr(PIN_IR);
  initDisplay();
}

void loop() {
  if (millis() - lastRefresh < REFRESH_MS) return;
  lastRefresh = millis();

  int lightVal = readLight(PIN_LIGHT);
  int irVal    = readIrRaw(PIN_IR);

  Serial.print(F("Light(A0)="));
  Serial.print(lightVal);
  Serial.print(F("\tIR(A2)="));
  Serial.println(irVal);

  printValueAt(7, 0, lightVal);
  printValueAt(7, 1, irVal);
}
