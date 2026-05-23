// Flow step 5 in this folder: this is where the pan and tilt commands finally move the servos.

#include "Servos.h"
#include "Pins.h"
#include <Servo.h>

static Servo panServo;
static Servo tiltServo;

static int panAngle  = 90;
static int tiltAngle = 90;

void initServos() {
  panServo.attach (PIN_SERVO_PAN);
  tiltServo.attach(PIN_SERVO_TILT);
  panServo.write (panAngle);
  tiltServo.write(tiltAngle);
}

void panTo(int angle) {
  angle = constrain(angle, 0, 180);
  panAngle = angle;
  panServo.write(angle);
}

void tiltTo(int angle) {
  angle = constrain(angle, 0, 180);
  tiltAngle = angle;
  tiltServo.write(angle);
}

void centerBoth() {
  panTo(90);
  tiltTo(90);
}

int getPanAngle()  { return panAngle; }
int getTiltAngle() { return tiltAngle; }
