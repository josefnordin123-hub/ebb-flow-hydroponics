# ebb-flow-hydroponics
DIY ebb and flow hydroponic system controlled by an ESP32, featuring automated pump cycles, status display, and a modular grow bed design.

## Overview
This project is a DIY ebb and flow hydroponic system designed for small-scale indoor growing. The system is controlled by an ESP32 microcontroller and uses timed flood-and-drain cycles to deliver nutrient solution to plants. The design focuses on simplicity, modularity, and ease of replication.

## Motivation
The goal of this project is to explore hydroponic growing while developing skills in embedded systems, electronics, and mechanical design. Ebb and flow systems are mechanically simple, yet effective, as they provide good oxygenation and nutrient delivery to plant roots, making them well suited for experimentation.

I started growing plants outdoors when I was 13 and have done so every spring for the past six years. More recently, I began a new education focused on electronics and automation, which inspired me to combine my interest in plant cultivation with technology by building this system.

## System Description
The system consists of two main containers:

- A lower container acting as the nutrient reservoir  
- An upper container acting as the grow bed  

A submersible water pump periodically floods the grow bed with nutrient solution. After each cycle, the solution drains back into the reservoir by gravity.

Plants are placed in net pots mounted in the grow bed lid and supported using peat starter plugs and expanded clay pellets. An ESP32 controls the pump via a relay module and provides system status information on an OLED display. Normaly its recommended to have atleast 2-3 flood cycles per day.

## Electronics & Power
The ESP32 is powered via a standard 5 V USB-C power supply. The relay module is controlled directly from the ESP32 GPIO pins and switches the water pump on and off. The OLED display communicates with the ESP32 using the I2C protocol.

## Key Features
- Automated ebb and flow watering cycles
- ESP32-based control logic
- I2C OLED display for system status and timing
- Modular design using IKEA SAMLA containers
- Designed for future expansion (camera, sensors, timelapse)

## Firmware
The firmware controls:
- Pump on/off timing for ebb and flow cycles
- Flood duration and drain intervals
- Status display on the OLED screen
Firmware source code is located in the `firmware` directory and can be uploaded using the Arduino IDE

## CAD & Mechanical Design
All mechanical components and assemblies are designed in CATIA V5 and exported as STEP files for cross-platform compatibility.

Some components, such as the electronics housing, ESP32 module, relay module, and IKEA SAMLA containers, are intentionally modeled with simplified geometry. These parts are represented as functional volumes rather than detailed, production-ready models. This approach was chosen to focus on system layout, fit, and integration rather than cosmetic detail at this stage.

The CAD models are primarily used to:
- Validate component placement and clearances
- Design the overall system layout
- Ensure sufficient space for electronics and wiring
- Support future iteration and refinement during physical assembly

All STEP files can be found in the `cad/step` directory.

## Future Improvements
Several future improvements and expansions are planned for this project. Some of these ideas are already reflected in the Bill of Materials as optional or future components.

Planned improvements include:
- Camera-based plant growth timelapse (camera already included in BOM as a future addition)
- Environmental sensors such as temperature, humidity, and water level monitoring.
- Nutriet monitoring, EC.
- WiFi-based monitoring, configuration, and data logging
- Improved electronics enclosure sealing and cable management
- Refinement of CAD models based on physical build feedback
