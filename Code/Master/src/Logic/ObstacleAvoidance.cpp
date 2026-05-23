// Basic forward/back-up/random-turn behavior.

#include "ObstacleAvoidance.h"
#include "../Config/Pins.h"
#include "../Config/DriveConfig.h"
#include "../Motors/MotorControl.h"
#include "../Motors/Movement.h"
#include "../Sensors/Ultrasonic.h"

static void driveUntilObstacle() {
  setRightTrack(true, RIGHT_DRIVE_SPEED);
  setLeftTrack(true, LEFT_DRIVE_SPEED);

  while (true) {
    int distance = readDistanceCm(PIN_TRIG_FRONT, PIN_ECHO_FRONT);
    if (distance > 0 && distance < OBSTACLE_STOP_DISTANCE_CM) {
      Serial.print(F("  -> obstacle at "));
      Serial.print(distance);
      Serial.println(F(" cm"));
      break;
    }
    delay(OBSTACLE_PING_INTERVAL_MS);
  }

  stopMotors();
}

static void randomTurn() {
  if (random(2) == 0) {
    Serial.println(F("Turning left"));
    turnLeft(MS_PER_90_DEG);
  } else {
    Serial.println(F("Turning right"));
    turnRight(MS_PER_90_DEG);
  }
}

void runObstacleAvoidanceLoop() {
  Serial.println(F("Cruising forward..."));
  driveUntilObstacle();

  Serial.println(F("Obstacle! Backing up..."));
  reverse(OBSTACLE_BACKUP_MS);
  delay(200);

  randomTurn();
  delay(200);
}
