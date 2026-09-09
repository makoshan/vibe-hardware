---
name: vibe-hardware-firmware
description: Select a development board and bring up firmware for sensors, displays, audio, wireless, and actuators. Use for ESP32, Arduino, ESP-IDF, PlatformIO, Raspberry Pi or Radxa board selection, pin planning, flashing, peripheral drivers, and hardware bring-up.
---

# Vibe Hardware Firmware

Read `../../docs/boards.md`, `../../docs/wiring.md`, `../../docs/safety.md`, and `../../docs/learning-path.md`.

1. Identify the exact board, revision, chip, Flash/PSRAM, USB interface, logic voltage, and framework.
2. Start from the board vendor's smallest official example and preserve a serial log.
3. Bring up one peripheral at a time: power → bus scan → device ID → raw readings → application behavior.
4. Keep pin mappings, I²C addresses, bus speed, calibration, sample rate, timeouts, and power assumptions explicit.
5. On moving hardware, validate a single actuator with limits and a physical stop before full motion.
6. Compile success is not device success; record flash, boot, peripheral detection, measured behavior, and remaining integration gates separately.

Use ESP32-S3-DevKitC-1 N8R8 as the default general board only when the project does not require Linux. Treat Raspberry Pi and Radxa migrations as software and GPIO adaptations, not board swaps.
