// Fixed drive demo behavior.

#include "DriveSequence.h"
#include "../Config/DriveConfig.h"
#include "../Motors/MotorControl.h"
#include "../Motors/Movement.h"

void runDriveSequence() {
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
