# ebb-flow-hydroponics
DIY ebb and flow hydroponic system controlled by an ESP32, featuring automated pump cycles, status display, and a modular grow bed design.

## Overview
This project is a DIY ebb and flow hydroponic system designed for small-scale indoor growing. The system is controlled by an ESP32 microcontroller and uses timed flood-and-drain cycles to deliver nutrient solution to plants. The design focuses on simplicity, modularity, and ease of replication.

## Motivation
The goal of this project is to explore hydroponic growing while learning more about embedded systems, electronics, and mechanical design. Ebb and flow systems are mechanically simple and provide good oxygenation and nutrient delivery to plant roots, making them ideal for experimentation.

## System Description
The system consists of two main containers:

- A lower container acting as the nutrient reservoir  
- An upper container acting as the grow bed  

A submersible water pump periodically floods the grow bed with nutrient solution. After each cycle, the solution drains back into the reservoir by gravity.

Plants are placed in net pots mounted in the grow bed lid and supported using peat starter plugs and expanded clay pellets. An ESP32 controls the pump via a relay module and provides system status information on an OLED display.

## Key Features
- Automated ebb and flow watering cycles
- ESP32-based control logic
- I2C OLED display for system status and timing
- Modular design using IKEA SAMLA containers
- Designed for future expansion (camera, sensors, timelapse)
