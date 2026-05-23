// Main scan-and-turn behavior for the master Arduino.

#include "ScanWanderLogic.h"
#include "../Config/Pins.h"
#include "../Config/DriveConfig.h"
#include "../Motors/MotorControl.h"
#include "../Motors/Movement.h"
#include "../Sensors/Ultrasonic.h"
#include "../Sensors/IrSensor.h"
#include "../Arm/ScanArm.h"
#include "../Comm/SlaveLink.h"

struct ScanResult {
  int usDist;
  int irRaw;
  bool blocked;
};

static void driveForwardUntilObstacle() {
  setRightTrack(true, RIGHT_DRIVE_SPEED);
  setLeftTrack(true, LEFT_DRIVE_SPEED);

  while (true) {
    int usDist = readDistanceCm(PIN_TRIG_FRONT, PIN_ECHO_FRONT);
    int irRaw = readIrRaw(PIN_IR);
    bool usHit = (usDist > 0 && usDist < SCAN_STOP_DISTANCE_CM);
    bool irHit = (irRaw > IR_OBSTACLE_THRESHOLD);

    if (usHit || irHit) {
      Serial.print(F("  -> obstacle: "));
      if (usHit) {
        Serial.print(F("US@"));
        Serial.print(usDist);
        Serial.print(F("cm "));
      }
      if (irHit) {
        Serial.print(F("IR="));
        Serial.print(irRaw);
      }
      Serial.println();
      break;
    }

    if (pollForObstacleAlert()) {
      Serial.println(F("  -> slave reports obstacle - veering away"));
      stopMotors();

      unsigned long turnMs = (MS_PER_90_DEG * 2) / 3;
      if (SLAVE_US_ON_LEFT) turnRight(turnMs);
      else                  turnLeft(turnMs);
      delay(200);
      return;
    }

    streamMpuIfDue();
    delay(60);
  }

  stopMotors();
}

static ScanResult scanAt(int panAngle) {
  panTo(panAngle);
  delay(SERVO_SETTLE_MS);

  ScanResult result;
  result.usDist = readDistanceCm(PIN_TRIG_SHOULDER, PIN_ECHO_SHOULDER);
  result.irRaw = readIrRaw(PIN_IR);

  bool usBlocked = (result.usDist > 0 && result.usDist < SCAN_CLEAR_DISTANCE_CM);
  bool irBlocked = (result.irRaw > IR_OBSTACLE_THRESHOLD);
  result.blocked = usBlocked || irBlocked;

  Serial.print(F("  scan @ "));
  Serial.print(panAngle);
  Serial.print(F(" deg: US="));
  if (result.usDist == 0) Serial.print(F("far"));
  else {
    Serial.print(result.usDist);
    Serial.print(F("cm"));
  }
  Serial.print(F("  IR="));
  Serial.print(result.irRaw);
  Serial.print(F("  ->  "));
  Serial.println(result.blocked ? F("BLOCKED") : F("clear"));

  return result;
}

static void decideAndTurn(const ScanResult &left, const ScanResult &right) {
  if (!left.blocked && !right.blocked) {
    int leftCmp = (left.usDist == 0) ? 9999 : left.usDist;
    int rightCmp = (right.usDist == 0) ? 9999 : right.usDist;

    if (leftCmp > rightCmp) {
      Serial.println(F("Both clear, left has more room -> turn left"));
      turnLeft(MS_PER_90_DEG);
    } else if (rightCmp > leftCmp) {
      Serial.println(F("Both clear, right has more room -> turn right"));
      turnRight(MS_PER_90_DEG);
    } else {
      Serial.println(F("Both clear and tied -> random pick"));
      if (random(2) == 0) turnLeft(MS_PER_90_DEG);
      else                turnRight(MS_PER_90_DEG);
    }
  } else if (!left.blocked) {
    Serial.println(F("Only left is clear -> turn left"));
    turnLeft(MS_PER_90_DEG);
  } else if (!right.blocked) {
    Serial.println(F("Only right is clear -> turn right"));
    turnRight(MS_PER_90_DEG);
  } else {
    Serial.println(F("Boxed in! U-turning"));
    turnRight(MS_PER_90_DEG);
    delay(200);
    turnRight(MS_PER_90_DEG);
  }

  delay(200);
}

void runScanWanderLoop() {
  Serial.println(F("Cruising forward..."));
  driveForwardUntilObstacle();

  Serial.println(F("Backing up..."));
  reverse(SCAN_BACKUP_MS);
  delay(300);

  Serial.println(F("Scanning..."));
  ScanResult left = scanAt(PAN_LEFT);
  ScanResult right = scanAt(PAN_RIGHT);
  centerPan();

  decideAndTurn(left, right);
}
