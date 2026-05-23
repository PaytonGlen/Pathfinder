WanderAvoid
===========

This is the basic autonomous driving sketch for the master board.

How to use it:
- open and upload `WanderAvoid.ino`
- place the tank on the floor and let it run
- press reset if you want to restart it

What it does:
- drives forward until the ultrasonic sees something close
- backs up a little
- turns left or right randomly
- repeats

Important files:
- `WanderAvoid.ino` runs the main loop
- `Pins.h` has the master board pin assignments
- `DriveConfig.h` has drive speed and turn timing values
- `WanderLogic.h` has the obstacle distance and backup timing
- `Ultrasonic.*` reads the front ultrasonic sensor

This one only uses the motors and the front ultrasonic sensor.
