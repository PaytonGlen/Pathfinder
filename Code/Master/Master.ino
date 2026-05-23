// Main entry point for the master Arduino codebase.

#include "src/Config/Pins.h"
#include "src/Motors/MotorControl.h"
#include "src/Sensors/Ultrasonic.h"
#include "src/Arm/ScanArm.h"
#include "src/Sensors/Mpu6050.h"
#include "src/Comm/SlaveLink.h"
#include "src/Logic/ScanWanderLogic.h"
#include "src/Logic/ObstacleAvoidance.h"
#include "src/Logic/DriveSequence.h"

enum MasterMode {
  MASTER_MODE_SCAN_WANDER,
  MASTER_MODE_OBSTACLE_AVOIDANCE,
  MASTER_MODE_DRIVE_SEQUENCE
};

const MasterMode ACTIVE_MODE = MASTER_MODE_SCAN_WANDER;

static void printCountdown() {
  Serial.println(F("Starting in 3..."));
  delay(1000);
  Serial.println(F("2..."));
  delay(1000);
  Serial.println(F("1..."));
  delay(1000);
}

void setup() {
  Serial.begin(9600);
  initMotors();

  switch (ACTIVE_MODE) {
    case MASTER_MODE_SCAN_WANDER:
      Serial.println(F("=== Master: Scan Wander ==="));
      initUltrasonic(PIN_TRIG_FRONT, PIN_ECHO_FRONT);
      initUltrasonic(PIN_TRIG_SHOULDER, PIN_ECHO_SHOULDER);
      initScanArm();
      initMpu();
      initSlaveLink();
      randomSeed(analogRead(PIN_RANDOM_SEED));
      printCountdown();
      enableMotors();
      break;

    case MASTER_MODE_OBSTACLE_AVOIDANCE:
      Serial.println(F("=== Master: Obstacle Avoidance ==="));
      initUltrasonic(PIN_TRIG_FRONT, PIN_ECHO_FRONT);
      randomSeed(analogRead(PIN_RANDOM_SEED));
      printCountdown();
      enableMotors();
      break;

    case MASTER_MODE_DRIVE_SEQUENCE:
      Serial.println(F("=== Master: Drive Sequence ==="));
      printCountdown();
      enableMotors();
      runDriveSequence();
      break;
  }
}

void loop() {
  switch (ACTIVE_MODE) {
    case MASTER_MODE_SCAN_WANDER:
      runScanWanderLoop();
      break;

    case MASTER_MODE_OBSTACLE_AVOIDANCE:
      runObstacleAvoidanceLoop();
      break;

    case MASTER_MODE_DRIVE_SEQUENCE:
      delay(1000);
      break;
  }
}
