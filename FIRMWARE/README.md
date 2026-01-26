# Firmware

This firmware controls the ebb and flow cycle of the hydroponic system.

## Features
- Timed pump control via relay
- OLED status display
- Adjustable flood and drain intervals

## Upload
The firmware is written for an ESP32 and can be uploaded using the Arduino IDE.

Required libraries:
- Adafruit SSD1306
- Adafruit GFX

Adjust timing constants in `main.ino` to match your setup.
