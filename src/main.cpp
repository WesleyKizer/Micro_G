#include <Arduino.h>
#include <test_tube.h>
#include <Wire.h>

test_tube tube1;

const int servoPin = 3;
const int servoMid = 90;
const int heaterPin = 4;
const int setTemp = 60;
const int tempRange = 5;
const int tempPin1 = 6;
const int tempPin2 = 7;
const int tempPin3 = 8;
const int servoSpeed = 90;
const int buttonPin = 2;
const int eStopPin = 1;

void setup(){
  Serial.begin(9600);
  Serial.println("hello world");
  tube1.setServo(servoMid, servoPin);
  pinMode(buttonPin, INPUT);
  //tube1.setHeater(heaterPin, setTemp, tempRange);
  //tube1.setTempPins(tempPin1, tempPin2, tempPin3);
  tube1.setUp();

}

void loop(){


  
  //tube1.stopServo();
  //delay(500);
  //tube1.actForward(servoSpeed);
  //delay(10000);
  //tube1.stopServo();
  //delay(500);
  //tube1.retract(servoSpeed);
  //delay(10000);

/*
  while(!digitalRead(buttonPin)){
    Serial.println("1");
    tube1.stopServo();
  }
  delay(750);
  Serial.println("2");
  while(!digitalRead(buttonPin)){
    tube1.actForward(servoSpeed);
    Serial.println("3");
  }
  delay(750);
  Serial.println("4");
  while(!digitalRead(buttonPin)){
    tube1.stopServo();
    Serial.println("5");
  }
  delay(750);
  Serial.println("6");
  while(!digitalRead(buttonPin)){
    tube1.retract(servoSpeed);
    Serial.println("7");
  }
  Serial.println("8");
  delay(750);
  Serial.println("9");

  //tube1.stopServo();*/
}
