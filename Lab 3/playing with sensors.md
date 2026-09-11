# Objectives
The objectives of this lab is to learn how to use two sensors with similar pins. First we used a potentiometer then we used a touch sensor. First one acquires an analogue voltage from the sensor then display it. Second one just prints out a statement and turns on LED when it detects touch.
# Setup

The setup is very simple. I am pushing code using PlatFormIO extension in VSCode. Currently I am using a Mac.
In this repository you will find in potentiometer.cpp code to get started with a potentiometer and get a value from it. This value by itself is just the analogue value which must be converted to voltage reading using the formula voltage = (analogvalue * 3.3) / 4095.0. This calculation and extra step can be found in voltage.cpp. Both files are reading data from pin A0. In voltage.cpp i implemented a function called voltage() to do this calculation.

For the touch.cpp i basically copy pasted from lab 2 the led code. I used "sensorValue > 2000" which i figured out by increasing it with first 100 increments then 500 to figure out which touch worked. If touched it prints out "Touch detected!" in a loop and if not then "No touch detected..." 

## Pin Maps

**Potentiometer (potentiometer.cpp and voltage.cpp)**

| Potentiometer Pin | ESP32 Feather Pin |
|---|---|
| VCC | 3V3 |
| GND | GND |
| OUT (wiper) | A0 |

**Touch Sensor (touch.cpp)**

| Touch Sensor Pin | ESP32 Feather Pin |
|---|---|
| VCC | 3V3 |
| GND | GND |
| OUT (S) | A0 |
| Onboard LED | GPIO 13 (LED_PIN) |

# Time Reporting and Reflection

1. **How long did it take you to complete this assignment?** 
1-2 hours.
2. **What level of difficulty would you associate with this assignment**
 - [ ] Easy
 - [x] Medium
 - [ ] Hard
3. **If you associated medium/high difficulty with this assignment, what aspect did you find the most difficult?** 
Debugging the sensorPin = 0 vs A0 GPIO issue. The skeleton code used the raw GPIO number 0 instead of the A0. I spent some time wondering what was wrong (did not realize I didnt have the A for A0)
4. **How comfortable do you currently feel with the course content?** Somewhat comfortable.
5. **Do you have any additional information or feedback you would like to share with the instructors?** 
no

