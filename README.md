# ebb-flow-hydroponics
DIY ebb and flow hydroponic system controlled by an ESP8266, featuring automated pump cycles, status display, and a modular grow bed design.

## Overview
This project is a DIY ebb and flow hydroponic system designed for small-scale indoor growing. The system is controlled by an ESP8266 microcontroller and uses timed flood-and-drain cycles to deliver nutrient solution to plants. The design focuses on simplicity, modularity, and ease of replication.
![Above](https://github.com/user-attachments/assets/3baa9136-e6f9-4356-93ee-e46090bb3e71)

## Motivation
The goal of this project is to explore hydroponic growing while developing skills in embedded systems, electronics, and mechanical design. Ebb and flow systems are mechanically simple, yet effective, as they provide good oxygenation and nutrient delivery to plant roots, making them well suited for experimentation.

I started growing plants outdoors when I was 13 and have done so every spring for the past six years. More recently, I began a new education focused on electronics and automation, which inspired me to combine my interest in plant cultivation with technology by building this system.
### What is Ebb and Flow Hydroponics?
Ebb and flow, also known as flood and drain, is a hydroponic growing method where plants are periodically flooded with a nutrient solution and then allowed to drain completely. During a flood cycle, nutrient-rich water is pumped into the grow bed, saturating the growing medium and plant roots. Once the pump is turned off, gravity allows the solution to drain back into the reservoir, pulling fresh oxygen down into the root zone as it recedes.

This method provides a good balance between nutrient delivery and root oxygenation, which is critical for healthy plant growth. Because the roots are not constantly submerged, the risk of root rot is reduced compared to some continuous-flow systems.

Ebb and flow was chosen for this project because it is mechanically simple, flexible, and well suited for experimentation. The system requires relatively few components, is tolerant to timing variations, and works with a wide range of growing media. This makes it an ideal platform for learning and iteration while developing embedded control logic, electronics, and mechanical design.

Additionally, the clear on/off nature of flood cycles makes ebb and flow particularly suitable for microcontroller-based automation. Pump timing, manual overrides, and visual system feedback can be implemented in a straightforward and transparent way, which aligns well with the educational and exploratory goals of this project.
## System Description
The system consists of two main containers:

- A lower container acting as the nutrient reservoir  
- An upper container acting as the grow bed  

A submersible water pump periodically floods the grow bed with nutrient solution. After each cycle, the solution drains back into the reservoir through the pump. The waterpump does not have a backwards shutoff valve. 

Plants are placed in net pots mounted in the grow bed lid and supported using peat starter plugs and expanded clay pellets. An ESP8266 controls the pump via the relay module and provides system status information on an OLED display. Normaly its recommended to have atleast 2-3 flood cycles per day. The exact timing of the periodic floods will later be determined as this varys by the lighting conditions. As I do now know where to place the system yet, I have not determined the exact timings.

The water pump operates on the basis of periodic timing. For example flooding on 08:00, 13:00, 18:00. Although this sounds like enough. I wanted to be abel to manually controll the pump aswell, in case of very dry conditions. THis leads me to that the ESP8266 also has a manual override switch. 

## Electronics & Power
The ESP8266 is powered via a standard 5 V USB-C power supply. The relay module is controlled directly from the ESP8266 GPIO pins and switches the water pump on and off. The 1.3 inch OLED display communicates with the ESP8266 using the I2C protocol. The Oled display is thought to be displaying system status such as next flood, if the pump is on, if the switch is on etc. 

## Key Features
- Automated ebb and flow watering cycles using 3V one channel relay.
- ESP8266-based control logic
- Manuall override lever to flood the growbed manually, if need be.
- I2C 1.3 inch OLED display for system status and timing
- Modular design using IKEA SAMLA containers
- Designed for future expansion (camera, sensors, timelapse)

## Firmware
The firmware controls:
- Pump on/off timing for ebb and flow cycles
- Flood duration and drain intervals
- Status display on the OLED screen
- To be able to accuratly display and time the floods, the ESP8266 connects to NTP to fech the time.
Firmware source code is located in the `firmware` directory and can be uploaded using the Arduino IDE

## CAD & Mechanical Design
All mechanical components and assemblies are designed in CATIA V5 and exported as STEP files for cross-platform compatibility.

Some components ESP8266 module, relay module, and IKEA SAMLA containers, are intentionally modeled with simplified geometry. These parts are represented as functional volumes rather than detailed, production-ready models. This approach was chosen to focus on system layout, fit, and integration rather than cosmetic detail at this stage.

The CAD models are primarily used to:
- Validate component placement and clearances. Especially for the net pots on the lid. 
- Design the overall system layout
- Ensure sufficient space for electronics and wiring
- Support future iteration and refinement during physical assembly

## Electronic Box
When this readme was originally made, I had not yet designed the electronics box for the design review. Now that I have clearly done the HackClub project the wrong way around, I actually have made an electronics box that is sufficient for testing the OLED display. The design also housing the relay and switch.
![Hydroponic Explanations](https://github.com/user-attachments/assets/b06c82b4-f9af-4f00-84d2-f1c71be2a330)
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
