// Flow step 1 in this folder: start here, then this file calls the movement functions.

#include "MotorPins.h"
#include "DriveConfig.h"
#include "MotorControl.h"
#include "Movement.h"

void setup() {
  Serial.begin(9600);
  Serial.println(F("=== Drive Sequence Test ==="));

  initMotors();

  Serial.println(F("Starting in 3..."));
  delay(1000);
  Serial.println(F("2..."));
  delay(1000);
  Serial.println(F("1..."));
  delay(1000);

  enableMotors();

  Serial.println(F("Forward 5 ft"));
  driveForward(5 * MS_PER_FOOT);
  delay(400);

  Serial.println(F("Turn right 90 deg"));
  turnRight(MS_PER_90_DEG);
  delay(400);

  Serial.println(F("Forward 2 ft"));
  driveForward(2 * MS_PER_FOOT);

  Serial.println(F("Done"));
  disableMotors();
}

void loop() {
}
