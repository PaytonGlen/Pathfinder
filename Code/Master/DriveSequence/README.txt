DriveSequence
=============

This is the drive test code for Project 3.

How to use it:
- open and upload `DriveSequence.ino`
- power the tank and let it run the sequence once
- press reset if you want to run it again

What it does:
- drives forward 5 feet
- turns right 90 degrees
- drives forward 2 feet
- stops

Important files:
- `DriveSequence.ino` runs the sequence
- `DriveConfig.h` has drive timing and speed values
- `MotorPins.h` has the motor driver pin numbers
- `Movement.*` has the movement functions
- `MotorControl.*` talks to the motor driver
