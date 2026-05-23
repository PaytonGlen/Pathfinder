// Flow step 3 in this folder: this is the obstacle logic, and it calls the movement and ultrasonic files below.

#include "WanderLogic.h"
#include "Pins.h"
#include "DriveConfig.h"
#include "MotorControl.h"
#include "Movement.h"
#include "Ultrasonic.h"

void driveForwardUntilObstacle() {
  setRightTrack(true, RIGHT_DRIVE_SPEED);
  setLeftTrack (true, LEFT_DRIVE_SPEED);

  while (true) {
    int distance = readDistanceCm(PIN_TRIG, PIN_ECHO);

    if (distance > 0 && distance < STOP_DISTANCE_CM) {
      Serial.print(F("  -> obstacle at "));
      Serial.print(distance);
      Serial.println(F(" cm"));
      break;
    }

    delay(PING_INTERVAL_MS);
  }
  stopMotors();
}

void randomTurn() {
  if (random(2) == 0) {
    Serial.println(F("Turning left"));
    turnLeft(MS_PER_90_DEG);
  } else {
    Serial.println(F("Turning right"));
    turnRight(MS_PER_90_DEG);
  }
}
