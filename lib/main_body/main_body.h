#ifndef _main_body_
#define _main_body_

#include <Arduino.h>
#include <Servo.h>
#include <Math.h>

class main_body{

  int servo_mid;
  int servo_pin;
  int heater_pin;
  int sw_pin;
  Servo constServo;
public:
  void setAct(int, int, int);
  void setUp(void);
  void stopServo();
  void testAct(int);
  void actForward(int);
  void actBackward(int);
  

};

#endif