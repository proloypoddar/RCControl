/*
Hello! I am Polok Poddar. 

This library, RCControl, is designed to simplify the control of DC motors using an Arduino. With this library, you can easily manage motor movements and speed through a simple interface. 

To use this library in your project:
1. Include the RCControl header file.
2. Initialize an RCControl object with the appropriate pin numbers.
3. Call the `begin()` method in your setup function.
4. Use the `control(char command)` method to control motor movements based on received commands.

This library makes it easy to integrate motor control into your Arduino projects, allowing you to focus on building cool applications without worrying about the complexities of motor management.

Feel free to check out my GitHub repository for more projects and resources: https://github.com/proloypoddar

Connect with me on LinkedIn: https://www.linkedin.com/in/polok-poddar-59b5b7221/

Happy coding!
*/

#include <RCControl.h>

RCControl motor(6, 13, 12, 5, 11, 10); 
/*
Initialize the RCControl object with the following pin assignments:
- ENA (Enable Motor A): Pin 6
- IN1 (Direction Control for Motor A): Pin 13
- IN2 (Direction Control for Motor A): Pin 12
- ENB (Enable Motor B): Pin 5
- IN3 (Direction Control for Motor B): Pin 11
- IN4 (Direction Control for Motor B): Pin 10

This setup allows you to control two DC motors, enabling various movements based on the commands you send to the Arduino. Adjust the pin numbers as needed for your specific hardware configuration.
*/

void setup() {
  motor.begin();
}

void loop() {
  if (Serial.available()) {
    char command = Serial.read();
    motor.control(command);
  }
}
