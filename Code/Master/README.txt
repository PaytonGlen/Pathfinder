Master
======

This is the single master-side codebase for Project 3.

How to use it:
- open and upload `Master.ino`
- upload the slave code too if you are using the two-board setup
- unplug the D0/D1 serial wires before uploading, then reconnect them after

Important files:
- `Master.ino` is the entry point
- `src/Config/` has shared pin and drive settings
- `src/Motors/` has motor control and movement helpers
- `src/Sensors/` has ultrasonic, IR, and MPU code
- `src/Arm/` has the scan arm servo code
- `src/Comm/` has the serial link to the slave
- `src/Logic/ScanWanderLogic.*` has the main scan-and-turn behavior
- `ScanWander Flow.png` is the flowchart for the scan-wander behavior
