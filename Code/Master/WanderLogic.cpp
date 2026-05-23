// Flow step 3 in this folder: this is the main decision logic, and it calls the sensor, servo, motor, and slave-link files below.

#include "WanderLogic.h"
#include "Pins.h"
#include "DriveConfig.h"
#include "MotorControl.h"
#include "Movement.h"
#include "Ultrasonic.h"
#include "IrSensor.h"
#include "ScanArm.h"
#include "SlaveLink.h"

void driveForwardUntilObstacle() {
  setRightTrack(true, RIGHT_DRIVE_SPEED);
  setLeftTrack (true, LEFT_DRIVE_SPEED);

  while (true) {
    int  usDist = readDistanceCm(PIN_TRIG_FRONT, PIN_ECHO_FRONT);
    int  irRaw  = readIrRaw(PIN_IR);
    bool usHit  = (usDist > 0 && usDist < STOP_DISTANCE_CM);
    bool irHit  = (irRaw > IR_OBSTACLE_THRESHOLD);

    if (usHit || irHit) {
      Serial.print(F("  -> obstacle: "));
      if (usHit) { Serial.print(F("US@")); Serial.print(usDist); Serial.print(F("cm ")); }
      if (irHit) { Serial.print(F("IR=")); Serial.print(irRaw); }
      Serial.println();
      break;
    }

    if (pollForObstacleAlert()) {
      Serial.println(F("  -> slave reports obstacle - veering away"));
      stopMotors();
      reactToSlaveObstacle();
      return;
    }

    streamMpuIfDue();

    delay(60);
  }
  stopMotors();
}

ScanResult scanAt(int panAngle) {
  panTo(panAngle);
  delay(SERVO_SETTLE_MS);

  ScanResult r;
  r.usDist = readDistanceCm(PIN_TRIG_SHOULDER, PIN_ECHO_SHOULDER);
  r.irRaw  = readIrRaw(PIN_IR);

  bool usBlocked = (r.usDist > 0 && r.usDist < CLEAR_DISTANCE_CM);
  bool irBlocked = (r.irRaw > IR_OBSTACLE_THRESHOLD);
  r.blocked = usBlocked || irBlocked;

  Serial.print(F("  scan @ "));
  Serial.print(panAngle);
  Serial.print(F(" deg: US="));
  if (r.usDist == 0) Serial.print(F("far"));
  else { Serial.print(r.usDist); Serial.print(F("cm")); }
  Serial.print(F("  IR="));
  Serial.print(r.irRaw);
  Serial.print(F("  ->  "));
  Serial.println(r.blocked ? F("BLOCKED") : F("clear"));

  return r;
}

void decideAndTurn(ScanResult left, ScanResult right) {
  if (!left.blocked && !right.blocked) {
    int leftCmp  = (left.usDist  == 0) ? 9999 : left.usDist;
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
  }
  else if (!left.blocked) {
    Serial.println(F("Only left is clear -> turn left"));
    turnLeft(MS_PER_90_DEG);
  }
  else if (!right.blocked) {
    Serial.println(F("Only right is clear -> turn right"));
    turnRight(MS_PER_90_DEG);
  }
  else {
    Serial.println(F("Boxed in! U-turning"));
    turnRight(MS_PER_90_DEG);
    delay(200);
    turnRight(MS_PER_90_DEG);
  }
  delay(200);
}

void reactToSlaveObstacle() {
  unsigned long ms = (MS_PER_90_DEG * 2) / 3;
  if (SLAVE_US_ON_LEFT) turnRight(ms);
  else                  turnLeft (ms);
  delay(200);
}
