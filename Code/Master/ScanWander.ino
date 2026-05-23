// Flow step 1 in this folder: start here, then this file calls WanderLogic.cpp for the main behavior.

#include "Pins.h"
#include "DriveConfig.h"
#include "MotorControl.h"
#include "Movement.h"
#include "Ultrasonic.h"
#include "IrSensor.h"
#include "ScanArm.h"
#include "Mpu6050.h"
#include "SlaveLink.h"
#include "WanderLogic.h"

void setup() {
  Serial.begin(9600);
  Serial.println(F("=== Scan Wander (master) ==="));

  initMotors();
  initUltrasonic(PIN_TRIG_FRONT,    PIN_ECHO_FRONT);
  initUltrasonic(PIN_TRIG_SHOULDER, PIN_ECHO_SHOULDER);
  initScanArm();
  initMpu();
  initSlaveLink();

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

  Serial.println(F("Backing up..."));
  reverse(BACKUP_MS);
  delay(300);

  Serial.println(F("Scanning..."));
  ScanResult left  = scanAt(PAN_LEFT);
  ScanResult right = scanAt(PAN_RIGHT);
  centerPan();

  decideAndTurn(left, right);
}
