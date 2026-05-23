SmokeTest
=========

This is a quick check for the LCD, photoresistor, and IR sensor.

How to use it:
- open and upload `SmokeTest.ino`
- open Serial Monitor at 9600 baud
- watch the live values on Serial and on the LCD

What it does:
- reads the light sensor
- reads the IR sensor
- prints both values to Serial
- shows both values on the LCD

Important files:
- `SmokeTest.ino` runs the test loop
- `Pins.h` has the sensor pin numbers
- `Display.h` has the LCD address
- `LightSensor.*` reads the photoresistor
- `IrSensor.*` reads the IR sensor

If the LCD stays blank, try changing `LCD_ADDR` in `Display.h` from `0x27` to `0x3F`.
