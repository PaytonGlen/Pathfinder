Project 3 Parts Notes
=====================

This folder is just the hardware notes for the tank.

Main idea:
- we are using two Arduino Unos
- the master handles driving and navigation
- the slave handles the LCD, extra sensors, and side obstacle alerts
- the two boards talk over UART on D0/D1 at 9600 baud

Files in here:
- `arduinos.txt` has the board split
- `motors.txt` has the drive system
- `servos.txt` has the scan arm servos
- `distance_sensors.txt` has the ultrasonics and IR sensor
- `imu.txt` has the MPU-6050 notes
- `light_and_temp.txt` has the photoresistor and TMP36
- `lcd.txt` has the 16x2 LCD notes
- `uart_link.txt` has the board-to-board serial wiring
- `power.txt` has the power setup

If someone is trying to debug one part, they can just open that file.
