// Flow step 1 in this folder: start here, then this file calls WanderLogic.cpp for the drive loop.

#include "Pins.h"
#include "DriveConfig.h"
#include "MotorControl.h"
#include "Movement.h"
#include "Ultrasonic.h"
#include "WanderLogic.h"

void setup() {
  Serial.begin(9600);
  Serial.println(F("=== Wander and Avoid ==="));

  initMotors();
  initUltrasonic(PIN_TRIG, PIN_ECHO);

  randomSeed(analogRead(PIN_RANDOM_SEED));

  Serial.println(F("Starting in 3..."));
  delay(1000);
  Serial.println(F("2..."));
  delay(1000);
  Serial.println(F("1..."));
  delay(1000);

  enableMotors();
}

void loop() {
  Serial.println(F("Cruising forward..."));
  driveForwardUntilObstacle();

  Serial.println(F("Obstacle! Backing up..."));
  reverse(BACKUP_MS);
  delay(200);

  randomTurn();
  delay(200);
}
