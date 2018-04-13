#ifndef _test_tube_
#define _test_tube_

#include <Arduino.h>
#include <Servo.h>
#include <Math.h>

class test_tube{
  int servo_mid;
  int servo_pin;
  int heater_pin;
  int set_temp;
  int temp_range;
  int temp1_pin;
  int temp2_pin;
  int temp3_pin;
  int sw_close_pin;
  int sw_open_pin;
  bool set;
  void tubeOpen(void);
  void tubeClosed(void);
  float getTempReading(int);
  Servo constServo;
public:
  void setTempPins(int,int,int);
  void setServo(int, int);
  void stopServo();
  void setSw(int, int);
  void setHeater(int, int, int);
  void testHeater();
  void stopHeater();
  void actForward(int);
  void retract(int);
  void test(int);
  void setUp(void);
  void getSample(int);

};

#endif
