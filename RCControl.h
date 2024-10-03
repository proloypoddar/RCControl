#ifndef RCControl_h
#define RCControl_h

#include <Arduino.h>

class RCControl {
  public:
    RCControl(int enaPin, int in1Pin, int in2Pin, int enbPin, int in3Pin, int in4Pin);
    void begin();
    void control(char command);
    void setSpeed(int speed);

  private:
    int ENA, IN1, IN2, ENB, IN3, IN4;
    int speedValue;
};

#endif
