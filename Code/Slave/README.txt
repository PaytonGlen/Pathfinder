Slave
=====

This is the code for the second Arduino on the tank.

How to use it:
- open and upload `Slave.ino` to the second Arduino
- reconnect the serial wires after uploading
- run it together with the master board code if you want obstacle alerts and LCD output

What it does:
- reads its own ultrasonic, light, and temperature sensors
- listens for MPU data from the master board
- updates the LCD and warns the master if something is too close

Important files:
- `Slave.ino` runs the main loop
- `Pins.h` has the slave board pin assignments
- `MasterLink.*` handles serial with the master
- `Display.h` has the LCD address and update timing
- `Ultrasonic.*`, `LightSensor.*`, and `TempSensor.*` read the slave sensors

Unplug the D0/D1 cross-wires before uploading, then plug them back in after.
