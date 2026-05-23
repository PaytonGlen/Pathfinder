ServoCalibration
================

Use this to find the pan and tilt angles for the scan arm.

How to use it:
- open and upload `ServoCalibration.ino`
- open Serial Monitor at 9600 baud
- send commands to move the servos and find the angles you want

Commands:
- `p<angle>` moves pan
- `t<angle>` moves tilt
- `c` centers both at 90
- `s` shows the current angles
- `?` prints the help text

Write down the values you want for:
- `TILT_LEVEL`
- `PAN_CENTER`
- `PAN_LEFT`
- `PAN_RIGHT`

Important files:
- `ServoCalibration.ino` runs the calibration tool
- `Pins.h` has the servo pin numbers
- `Servos.*` controls the pan and tilt servos
- after calibration, copy the final angles into `Master/src/Arm/ScanArm.h`
