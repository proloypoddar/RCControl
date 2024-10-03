#include "RCControl.h"

RCControl::RCControl(int enaPin, int in1Pin, int in2Pin, int enbPin, int in3Pin, int in4Pin) {
  ENA = enaPin;
  IN1 = in1Pin;
  IN2 = in2Pin;
  ENB = enbPin;
  IN3 = in3Pin;
  IN4 = in4Pin;
  speedValue = 0;
}

void RCControl::begin() {
  Serial.begin(9600);
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void RCControl::control(char command) {
  Serial.print("Received command: ");
  Serial.println(command);

  // Movement Commands
  if (command == 'F') {
    // Move Forward
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    analogWrite(ENA, speedValue);
    analogWrite(ENB, speedValue);

  } else if (command == 'B') {
    // Move Backward
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    analogWrite(ENA, speedValue);
    analogWrite(ENB, speedValue);

  } else if (command == 'L') {
    // Turn Left
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    analogWrite(ENA, speedValue);
    analogWrite(ENB, speedValue);

  } else if (command == 'R') {
    // Turn Right
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    analogWrite(ENA, speedValue);
    analogWrite(ENB, speedValue);

  } else if (command == 'S') {
    // Stop
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
  } 

  // Speed control commands (0 to 9 for speed levels 0 to 100)
  else if (command >= '0' && command <= '9') {
    speedValue = map(command - '0', 0, 9, 0, 255);
    Serial.print("Speed set to: ");
    Serial.println(speedValue);
  }
}
