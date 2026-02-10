# ESP8266 Pump Control with OLED Status (NTP Time + Manual Switch)

This firmware is a simple control and status system intended for an ebb and flow hydroponic setup. An **ESP8266** is used to:
- connect to **WiFi**
- fetch the current time via **NTP**
- read a **manual switch**
- control a **water pump through a relay**
- display system status on a **1.3" SH1106 OLED** using I2C (U8g2)

## Overview
The pump is controlled purely by a physical switch in this version of the firmware. The OLED display provides real-time feedback, showing the current time, switch state, and pump state. Time is synchronized over WiFi using an NTP server to ensure accurate system timing.

## How It Works
- **Manual switch on D7 (GPIO13) to GND**
  - `LOW` = switch **ON** (due to `INPUT_PULLUP`)
  - `HIGH` = switch **OFF**
- **Relay / pump on D5 (GPIO14)**
  - `RELAY_ACTIVE_LOW = true` means the relay is enabled by pulling the pin `LOW`
- **OLED displays**
  - current time (`HH:MM:SS`)
  - switch state (ON / OFF)
  - pump state (ON / OFF), currently mirroring the switch

## Wiring (ESP8266 / NodeMCU)
### Manual Switch
- D7 / GPIO13 → one side of the switch  
- GND → the other side of the switch  

The internal pull-up resistor is used, so no external resistor is required.

### Relay and Pump
- D5 / GPIO14 → relay control input  
- 5 V and GND → relay power (depending on relay module)

### OLED Display (SH1106 128×64, I2C)
- SDA → D2 (GPIO4)  
- SCL → D1 (GPIO5)  
- VCC / GND → according to the display specifications

## Code Structure
- **`setup()`**
  - initializes Serial communication
  - configures the switch input with `INPUT_PULLUP`
  - configures the pump pin and ensures the pump starts OFF
  - initializes the OLED display
  - connects to WiFi
  - synchronizes time using `configTime()` and `pool.ntp.org`

- **`loop()`**
  - `updateTime()` updates the current time structure
  - `updatePumpFromSwitch()` turns the pump ON or OFF based on the switch
  - `drawOLED()` renders time and system status to the display
  - runs continuously with a short delay for smooth updates

## Uploading & Requirements
- **Arduino IDE**
- Board: **ESP8266** (e.g. NodeMCU)
- Required libraries:
  - ESP8266WiFi
  - time.h
  - Wire
  - **U8g2**

## Next Steps
Planned improvements for this firmware include:
- scheduled pump cycles based on time of day
- timed manual override (run pump for a fixed duration)
- clearer OLED layout with icons and upcoming flood times
