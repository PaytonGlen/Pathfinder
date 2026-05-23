ScanWander
==========

This is the master-side code for Project 3.

What it needs:
ScanWander needs to be adjusted to meet the following criteria:
- Connect to a bluetooth device and mark it's location as the "Target"
- scans for strongest bluetooth connections directio.
- Once direction is found, proceed to the direction in a straight line
- While en route, if an object is detected: the rover should navigate around the object
- Once the object is cleared enough, the rover needs to proceed to the target

How to use it right now:
- open and upload `ScanWander.ino` to the master Arduino
- upload the code in `Slave/` to the second Arduino if you are using the full two-board setup
- unplug the D0/D1 cross-wires before uploading, then reconnect them after

Current behavior in this folder:
- drives forward until it detects something
- backs up a little
- scans left and right with the arm
- turns toward the better side
- sends MPU data to the slave board while moving

Important files:
- `ScanWander.ino` runs the main loop
- `Pins.h` has the master board pin assignments
- `DriveConfig.h` has drive speed and turn timing values
- `WanderLogic.*` has the obstacle and turn logic
- `ScanArm.h` has `PAN_LEFT`, `PAN_CENTER`, `PAN_RIGHT`, `TILT_LEVEL`, and `SERVO_SETTLE_MS`
- `SlaveLink.*` handles serial between the two Arduinos
- `ScanWander Flow.png` is the flowchart for the behavior
