#ifndef _sample_tube_
#define _sample_tube_

#include <Arduino.h>
#include <Servo.h>
#include <Math.h>

class sample_tube{

  int servo_mid;
  int servo_pin;
  int heater_pin;
  int set_temp;
  int set_test_temp;
  int temp_range;
  int temp_pin;
  int sw_pin;
  int shaker_pin;
  bool heaterOk;
  float getTempReading(int);
  Servo constServo;
public:
  void setSampleTube(int, int, int, int, int);
  void setAct(int, int, int);
  void setUp(void);
  void stopServo();
  void stopHeater();
  void testHeater();
  void testAct(int);
  void actForward(int);
  void actBackward(int);
  void getSample(int);

};

#endif

