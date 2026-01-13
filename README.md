# AirSystem for Soft Robotics
Modular Air System for Soft Robotics using ESP32\
Designed and created by [C.M. van Riet](https://research.tue.nl/en/persons/cm-katrien-van-riet) - Jan 2026\
With thanks to d.search at Eindhoven University of Technology for their guidance.\
Special thanks to Geert van den Boomen for checking the schematics and debugging the circuits.

## The system
![Example application](https://github.com/kvriet/AirSystem-ESP32-for-Soft-Robotics/blob/main/Media/airsystem_ESP32.png)

**AirSystem-ESP32** was designed as a low-cost way to rapidly prototype with air, costing roughly €60 for the entire system. AirSystem consists of 1 controller, 4 pneumatic components (pumps and valves), and 2 pressure sensors. Through a 12V power brick, the board provides 12V power and as such, any pump or solenoid that requires 12V power can be attached to the board. 

![System overview](https://github.com/kvriet/AirSystem-ESP32-for-Soft-Robotics/blob/main/Media/air%20system%20board.png)

### Pneumatic Components
For the pneumatic board, easy-to-find components are used:
1. Pump 370A, 12V, 3.2LPM
2. Solenoid valve Skoocom SC0829GW, 12V
3. MCP-H10 pressure sensor, 0-200kPa, 3.3V

### Manual
A manual for AirSystem describes in detail how the system works and how the Arduino library can be installed: [AirSystem Manual](https://github.com/kvriet/AirSystem-ESP32-for-Soft-Robotics/blob/main/Air%20System%20manual%20pcb%20v1.0.pdf)
Users are free to connect the sensor, pump, and valve to their inflatables as desired. Example Arduino sketches are provided that work well with the board to control inflatables.

## Arduino Library
The system is controlled by a Waveshare ESP32-C3-Zero and can be programmed through the Arduino IDE with a custom library: [AirSystem](https://github.com/kvriet/AirSystem-ESP32-for-Soft-Robotics/tree/main/Arduino%20library/AirSystem-ESP) This folder should be placed in the libraries folder of the Arduino folder. I select the XIAO_ESP32C3 board to upload sketches to the board.

The library comes with 7 examples that showcase the abilities of **AirSystem**:
  1. Manual control
  2. Pressure reading
  3. Pump control
  4. Valve control
  5. Pump control without delay
  6. Other configurations
  7. Object arrays

## Schematics and KiCAD Files
The schematics for this project and the KiCAD files can be found here: [KiCAD folder](https://github.com/kvriet/AirSystem-for-Soft-Robotics/tree/main/KiCAD).

## 3D Printing Files
The STLs for this project can be found here: [Design Files](https://github.com/kvriet/AirSystem-ESP32-for-Soft-Robotics/tree/main/Design%20files).
- The prints will fit most regular printers and can be printed out of PLA, 0.3 layer height, 4 perimeters (walls), 20% infill. The cushions for the pumps and solenoids are printed in TPU. These cushions can be replaced with some sponge (simple kitchen sponges work well) if TPU printing is not an option.
- To minimise vibrations and prevent the cases from sliding around on a hard surface, 6mm silicone feet can be added to the bottom of the base.

The screws needed for these cases are:
- 4x M3x5 for the PCB 
- 12x M3x10 for the clamps (or 16x M3x10 depending on the configuration)

## Limitations
- The Skoocom solenoid valve is able to remain closed up to pressures of 100kPa, whereas the pump is able to deliver 150kPa. This means the valve will start leaking at pressures over 100kPa. In practice, this is not a major issue, as our projects rarely need pressures of over 100kPa (usually maxing out at 50kPa for haptic purposes). However, this overpressure might reduce valve longevity in the long run. In the future, a higher-pressure solenoid valve could be found, or a pump could be found that delivers max 100kPa. This would also allow for a lower-range pressure sensor to be used, the MCP-H10 0-100kPa, 3.3V. Switching to the 0-100kPa sensor would also double pressure measuring resolution.
- Currently no PID has been implemented in the library. As many inflatables or the tubing used are somewhat elastic, I have found that setting a target pressure (feedback loop sensor reading to pump power) is enough to achieve that pressure with a minimal offset. However, for more high-end applications, PID should be implemented.
- The Skoocom solenoid valve is not proportional. It is just open/closed. This means that controller deflation is a challenge. This can be worked around by turning on the pump simultaneously to opening the valve to reduce the air flowing out. Additionally, a resistor (very thin tube) could be connected to the valve outlet to reduce airflow out of the system. However, such a resistor also slows down response times when air does need to evacuate the system quickly. This is a trade-off for how cheap this entire system is.
