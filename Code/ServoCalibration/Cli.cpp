// Flow step 3 in this folder: typed commands get handled here, then servo moves are passed into Servos.cpp.

#include "Cli.h"
#include "Servos.h"

void printState() {
  Serial.print(F("[Pan="));
  Serial.print(getPanAngle());
  Serial.print(F("  Tilt="));
  Serial.print(getTiltAngle());
  Serial.println(F("]"));
}

void printHelp() {
  Serial.println();
  Serial.println(F("=== Servo Calibration ==="));
  Serial.println(F("Commands (end with Enter):"));
  Serial.println(F("  p<angle>  Pan to <angle>     example: p90"));
  Serial.println(F("  t<angle>  Tilt to <angle>    example: t45"));
  Serial.println(F("  c         Center both at 90"));
  Serial.println(F("  s         Show current state"));
  Serial.println(F("  ?         This help"));
  Serial.println(F("Angles must be 0-180. Listen for buzzing -"));
  Serial.println(F("if you hear it, the servo is hitting a stop."));
  Serial.println();
}

void handleSerialCommand() {
  char cmd = Serial.read();

  if (cmd == '\r' || cmd == '\n' || cmd == ' ') return;

  switch (cmd) {
    case 'p':
    case 'P': {
      int angle = Serial.parseInt();
      panTo(angle);
      Serial.print(F("Pan -> "));
      Serial.print(getPanAngle());
      Serial.println(F(" deg"));
      break;
    }
    case 't':
    case 'T': {
      int angle = Serial.parseInt();
      tiltTo(angle);
      Serial.print(F("Tilt -> "));
      Serial.print(getTiltAngle());
      Serial.println(F(" deg"));
      break;
    }
    case 'c':
    case 'C':
      centerBoth();
      Serial.println(F("Centered both servos at 90"));
      printState();
      break;

    case 's':
    case 'S':
      printState();
      break;

    case '?':
    case 'h':
    case 'H':
      printHelp();
      break;

    default:
      Serial.print(F("Unknown command: '"));
      Serial.print(cmd);
      Serial.println(F("'   (type ? for help)"));
      Serial.parseInt();
      break;
  }
}
