//////////////////////////////////////////////////////////////////////////////////////////////////
/*    Author:           Wesley Kizer                                                            */
/*    Name:             Micro-G_TISC                                                            */
/*    Last Updated:     05/28/2018                                                              */
/*    Description:      This program is for SEDS TnTech's entry into 2018 Micro-g NExT          */
//////////////////////////////////////////////////////////////////////////////////////////////////

#include <declarations.h>  //pin constants
#include <Servo.h>
#include <Arduino.h>
#include <sample_tube.h>
#include <main_body.h>
#include <Wire.h>

sample_tube tube1;
sample_tube tube2;
sample_tube tube3;
main_body mainBody;

char inChar;


//operations variables
const int servoSpeed = 50;
const int setTemp = 60;
const int testTemp = 40;
const int tempRange = 5;


void serialEvent();  //serial interupt
void stopAll(); //this function will stop all tubes/main-body actuations and turn of cutting heads


void setup(){

  //class variable declarations
  tube1.setSampleTube(tempPin1, tempPin1, tempPin1, tempRange, testTemp);
  tube1.setAct(servoMid1, servoPin1, Hall1);
  tube2.setSampleTube(tempPin2, tempPin2, tempPin2, tempRange, testTemp);
  tube2.setAct(servoMid2, servoPin2, Hall2);
  tube3.setSampleTube(tempPin3, tempPin3, tempPin3, tempRange, testTemp);
  tube3.setAct(servoMid3, servoPin3, Hall3);
  mainBody.setAct(mainServoMid, mainServoPin, mainHall);

  
  //setting pin modes
  tube1.setUp();
  tube2.setUp();
  tube3.setUp();
  mainBody.setUp();

}

void loop(){

}


void serialEvent(){

  while(Serial.available()){
    inChar = (char)Serial.read();
    
    
  }
  switch(inChar){
    case 'A':
      mainBody.testAct(servoSpeed); 
    case 'B':
      tube1.testAct(servoSpeed);
    case 'C':
      tube2.testAct(servoSpeed);
    case 'D':
      tube3.testAct(servoSpeed);
    case 'E':
      tube1.testHeater();
    case 'F':
      tube2.testHeater();
    case 'G':
      tube3.testHeater();
    case 'H':
      
    case 'I':
      
    case 'J':
      
    case 'K':
      
    case 'L':
      mainBody.stopServo();
    case 'M':
      mainBody.actForward(servoSpeed);
    case 'N':
      mainBody.actBackward(servoSpeed);
    case 'O':
      tube1.stopServo();
    case 'P':
      tube1.stopHeater();
    case 'Q':
      tube1.actForward(servoSpeed);
    case 'R':
      tube1.actBackward(servoSpeed);
    case 'T':
      tube1.getSample(servoSpeed);
    case 'U':
      tube2.stopServo();
    case 'V':
      tube2.stopHeater();
    case 'W':
      tube2.actForward(servoSpeed);
    case 'X':
      tube2.actBackward(servoSpeed);
    case 'Y':
      tube2.getSample(servoSpeed);
    case 'Z':
      tube3.stopServo();
    case 'a':
      tube3.stopHeater();
    case 'b':
      tube3.actForward(servoSpeed);
    case 'c':
      tube3.actBackward(servoSpeed);
    case 'd':
      tube3.getSample(servoSpeed);
    case 'e':

    case 's':
    case 'S':
        stopAll();
  }
  
}

void stopAll(){
  mainBody.stopServo();
  tube1.stopServo();
  tube2.stopServo();
  tube3.stopServo();
  tube1.stopHeater();
  tube2.stopHeater();
  tube3.stopHeater();
}


