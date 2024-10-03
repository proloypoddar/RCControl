# RCControl Library

## Overview
The **RCControl** library is designed to simplify the control of DC motors using Arduino. With this library, you can easily manage motor movements and speed through a simple interface, making it ideal for robotics and automation projects.

## Features
- Control two DC motors independently.
- Easily manage direction and speed using simple commands.
- Simple setup with customizable pin assignments.

## Getting Started

### Installation
1. Download the RCControl library files.
2. Place the downloaded files in your Arduino libraries folder (typically located in `Documents/Arduino/libraries`).
3. Restart the Arduino IDE to recognize the new library.

### Usage
To use the RCControl library in your project, follow these steps:

1. Include the RCControl header file in your Arduino sketch:

    ```cpp
    #include <RCControl.h>
    ```

2. Initialize an RCControl object with the appropriate pin numbers:

    ```cpp
    RCControl motor(ENA, IN1, IN2, ENB, IN3, IN4);
    ```

   - **ENA**: Pin to enable Motor A (PWM).
   - **IN1**: Direction control for Motor A (HIGH/LOW).
   - **IN2**: Direction control for Motor A (HIGH/LOW).
   - **ENB**: Pin to enable Motor B (PWM).
   - **IN3**: Direction control for Motor B (HIGH/LOW).
   - **IN4**: Direction control for Motor B (HIGH/LOW).

3. Call the `begin()` method in your `setup()` function:

    ```cpp
    void setup() {
      motor.begin();
    }
    ```

4. Use the `control(char command)` method in the `loop()` function to control motor movements based on received commands:

    ```cpp
    void loop() {
      if (Serial.available()) {
        char command = Serial.read();
        motor.control(command);
      }
    }
    ```

### Commands
The library responds to the following commands:
- **F**: Move Forward
- **B**: Move Backward
- **L**: Turn Left
- **R**: Turn Right
- **S**: Stop
- **0-9**: Adjust speed from 0 (stop) to 9 (maximum speed)

## Example Code
Here’s an example sketch that demonstrates how to use the RCControl library:

```cpp
#include <RCControl.h>

RCControl motor(6, 13, 12, 5, 11, 10); // Initialize with pin numbers

void setup() {
  motor.begin();
}

void loop() {
  if (Serial.available()) {
    char command = Serial.read();
    motor.control(command);
  }
}
