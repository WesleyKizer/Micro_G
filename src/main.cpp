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
//const int interruptPin = 6;


//void message();  //serial interupt
void stopAll(); //this function will stop all tubes/main-body actuations and turn of cutting heads


void setup(){

  Serial.begin(9600);
  //pinMode(interruptPin, INPUT_PULLUP);
  //attachInterrupt(digitalPinToInterrupt(interruptPin), message, HIGH);

  //class variable declarations
  tube1.setSampleTube(tempPin1, tempPin1, tempPin1, tempRange, testTemp);
  tube1.setAct(servoMid1, servoPin1, Hall1);
  tube2.setSampleTube(tempPin2, tempPin2, tempPin2, tempRange, testTemp);
  tube2.setAct(servoMid2, servoPin2, Hall2);
  tube3.setSampleTube(tempPin3, tempPin3, tempPin3, tempRange, testTemp);
  tube3.setAct(servoMid3, servoPin3, Hall3);
  mainBody.setAct(mainServoMid, mainServoPin, mainSW1, mainSW2);

  
  //setting pin modes
  tube1.setUp();
  tube2.setUp();
  tube3.setUp();
  mainBody.setUp();

}

void loop(){
    stopAll();
    tube1.actBackward(servoSpeed);
    tube2.actBackward(servoSpeed);
    tube3.actBackward(servoSpeed);
    Serial.println();
    //tube1.testAct(servoSpeed);
    //tube2.testAct(servoSpeed);
    //tube3.testAct(servoSpeed);
}

/*
void message(){

  while(Serial1.available()){
    inChar = (char)Serial1.read();
    
    
  }
  switch(inChar){
    case 'A':
      mainBody.testAct(servoSpeed); 
      Serial1.print('A');
    case 'B':
      tube1.testAct(servoSpeed);
      Serial1.print('B');
    case 'C':
      tube2.testAct(servoSpeed);
      Serial1.print('C');
    case 'D':
      tube3.testAct(servoSpeed);
      Serial1.print('D');
    case 'E':
      tube1.testHeater();
      Serial1.print('E');
    case 'F':
      tube2.testHeater();
      Serial1.print('F');
    case 'G':
      tube3.testHeater();
      Serial1.print('G');
    case 'H':
      
    case 'I':
      
    case 'J':
      
    case 'K':
      
    case 'L':
      mainBody.stopServo();
      Serial1.print('L');
    case 'M':
      mainBody.actForward(servoSpeed);
      Serial1.print('M');
    case 'N':
      mainBody.actBackward(servoSpeed);
      Serial1.print('N');
    case 'O':
      tube1.stopServo();
      Serial1.print('O');
    case 'P':
      tube1.stopHeater();
      Serial1.print('P');
    case 'Q':
      tube1.actForward(servoSpeed);
      Serial1.print('Q');
    case 'R':
      tube1.actBackward(servoSpeed);
      Serial1.print('R');
    case 'T':
      tube1.getSample(servoSpeed);
      Serial1.print('T');
    case 'U':
      tube2.stopServo();
      Serial1.print('U');
    case 'V':
      tube2.stopHeater();
      Serial1.print('V');
    case 'W':
      tube2.actForward(servoSpeed);
      Serial1.print('W');
    case 'X':
      tube2.actBackward(servoSpeed);
      Serial1.print('X');
    case 'Y':
      tube2.getSample(servoSpeed);
      Serial1.print('Y');
    case 'Z':
      tube3.stopServo();
      Serial1.print('Z');
    case 'a':
      tube3.stopHeater();
      Serial1.print('a');
    case 'b':
      tube3.actForward(servoSpeed);
      Serial1.print('b');
    case 'c':
      tube3.actBackward(servoSpeed);
      Serial1.print('c');
    case 'd':
      tube3.getSample(servoSpeed);
      Serial1.print('d');
    case 'e':

    case 'S':
        stopAll();
        Serial1.print('S');
  }
  
}
*/
void stopAll(){
  mainBody.stopServo();
  tube1.stopServo();
  tube2.stopServo();
  tube3.stopServo();
  tube1.stopHeater();
  tube2.stopHeater();
  tube3.stopHeater();
}

