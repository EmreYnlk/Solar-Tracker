# Arduino Solar Tracker

## About
This project implements a single-axis solar tracking system using an Arduino microcontroller. By utilizing Light Dependent Resistors (LDRs) to measure ambient light intensity, the system calculates the optimal angle and drives a servo motor to orient a panel towards the brightest light source. It serves as a practical example of sensor data processing, actuator control, and hysteresis implementation in embedded systems.

## Features

* **Automatic Orientation:** Calculates the light intensity difference between the right and left LDRs to rotate the motor towards the most intense light source.
* **Hysteresis Control:** Utilizes a threshold value (`tolerans`) to prevent the motor from constantly jittering or oscillating due to minor light fluctuations.
* **Mechanical Constraints:** Implements software-defined minimum (20°) and maximum (150°) movement limits (`sinirMin`, `sinirMax`) to prevent physical strain on the servo motor.

## Hardware Requirements

* 1x Arduino Uno (or Nano/Mega)
* 1x Servo Motor (e.g., SG90 or MG996R)
* 2x LDR (Photoresistor)
* 2x 10kΩ Resistor (as pull-down resistors for the LDRs)
* Breadboard and Jumper Wires



## Pin Connections

| Component / Pin | Arduino Connection |
| :--- | :--- |
| **Servo Motor Signal** | Digital Pin `9` |
| **Right LDR (East)** | Analog Pin `A0` |
| **Left LDR (West)** | Analog Pin `A1` |

*(Note: Connect one leg of each LDR to 5V, and the other leg to the Analog pin as well as to GND through a 10kΩ resistor.)*

## Installation and Usage

1. Clone this repository to your local machine or download the `.ino` file.
2. Open the code using the **Arduino IDE**. (The required `<Servo.h>` library is built into the IDE, so no additional installation is needed).
3. Complete the circuit wiring according to the pin connection table above.
4. Connect your Arduino board to your computer via USB.
5. Select the appropriate Board and Port from the Tools menu, then compile and upload the code.
6. Open the **Serial Monitor** (set to `9600 baud`) to view real-time sensor readings for debugging and calibration purposes.

## Calibration and Tuning

You can optimize the following variables in the code based on your specific ambient lighting conditions:

* `tolerans = 15;`: Increase this threshold value if the motor jitters or makes unnecessary micro-movements. Decrease it if the system responds too slowly to light changes.
* `hareketHizi = 50;`: The delay time (in milliseconds) after each 1-degree step of the motor. Adjust this to change the smoothness and speed of the movement.
