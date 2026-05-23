PROJECT 3 - PARTS NOTES
=======================

hey, this folder is basically my notes on every part we're
using on the tank. split into smaller files so you can just
read whatever section you're working on.


the short version
-----------------
we're building an autonomous tracked robot on the elegoo
conqueror tank kit. the main thing to know is that we use
TWO arduino unos instead of one, talking to each other over
a serial wire.

  - master arduino = "the driver"
    motors, navigation sensors, ir remote, scanning arm

  - slave arduino = "the recorder"
    lcd, light/temp sensors, side obstacle alerts

  they talk over hardware uart at 9600 baud on pins d0/d1.

we split into two arduinos because one uno didn't have enough
pins for everything we wanted (imu + multiple ultrasonics +
servo arm + lcd was too much).


what's in this folder
---------------------

  README.txt              <- you're reading it

  arduinos.txt            the two arduino unos and how we
                          split up their jobs

  motors.txt              tb6612fng motor driver shield + the
                          two dc gear motors that spin the
                          rubber tracks

  servos.txt              the two sg90 micro servos that
                          pan/tilt the scanning sensor arm

  distance_sensors.txt    3 hc-sr04 ultrasonics (front,
                          scanning arm, slave shoulder) and
                          the sharp gp2y0a41 ir sensor

  imu.txt                 mpu-6050 (accelerometer + gyro) on
                          the gy-521 breakout board

  light_and_temp.txt      photoresistor (light) + tmp36
                          (temperature). both on the slave.

  lcd.txt                 16x2 lcd with i2c backpack

  uart_link.txt           how the two arduinos talk to each
                          other - PROTOCOL + GOTCHAS in here,
                          read this one

  power.txt               how everything is powered + the
                          common ground rule


if you want to read it all
--------------------------
honestly just start with arduinos.txt and then jump around to
whatever sounds interesting. if you're trying to actually
hack on a specific part, go straight to that file.


deeper stuff
------------
  ../Pathfinder_Technical_Details.md   full technical writeup
  ../Project_2_Code/                   current master/slave code
  ../Project 2 Rubric.docx             last project's rubric
  ../Project 3 rubric coming soon - i'll drop it in Project 3/
