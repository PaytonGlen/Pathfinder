// Flow step 1 in this folder: start here, then this file reads sensors and calls the slave helper files below.

#include "Pins.h"
#include "Ultrasonic.h"
#include "LightSensor.h"
#include "TempSensor.h"
#include "MasterLink.h"
#include "Display.h"

void setup() {
  Serial.begin(9600);

  initUltrasonic(PIN_TRIG_US, PIN_ECHO_US);
  initLight(PIN_LIGHT);
  initTemp (PIN_TEMP);
  initMasterLink();
  initDisplay();
}

void loop() {
  int us3Cm    = readDistanceCm(PIN_TRIG_US, PIN_ECHO_US);
  int lightVal = readLight(PIN_LIGHT);
  int tempCx10 = readTempCx10(PIN_TEMP);

  processIncomingMessages();

  if (us3Cm > 0 && us3Cm < OBSTACLE_THRESHOLD_CM) {
    sendObstacleIfDue();
  }

  MpuSnapshot mpu;
  bool mpuValid = getLatestMpu(mpu);
  updateLcdIfDue(lightVal, us3Cm, tempCx10, mpuValid, mpu);

  delay(50);
}
