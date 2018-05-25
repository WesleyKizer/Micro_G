#include <Servo.h>
#include <Arduino.h>
#include <test_tube.h>
#include <Wire.h>

test_tube tube1;
test_tube tube2;
test_tube tube3;

void mainBodyActForward(int);

const int mainServoPin = 9;
const int mainServoMid = 90;
const int servoPin = 9;
const int servoMid = 92;
const int heaterPin = 0;
const int setTemp = 60;
const int tempRange = 5;
const int tempPin1 = 11;
const int tempPin2 = 7;
const int tempPin3 = 8;
const int servoSpeed = 50;
const int buttonPin = 2;
const int eStopPin = 1;
const int Hall1 = 19;

Servo constServo;

void setup(){
  constServo.attach(mainServoPin);

  
  Serial.begin(9600);
  Serial.println("Setting Up.");
  Serial.println("");
  tube1.setServo(servoMid, servoPin);
  tube1.setSw(Hall1);
  pinMode(Hall1, INPUT);

  //tube1.setHeater(heaterPin, setTemp, tempRange);
  //tube1.setTempPins(tempPin1, tempPin2, tempPin3);
  tube1.setUp();

  Serial.println("Set Up Complete.");
  Serial.println("");

}

mainBodyActForward(servoSpeed);

  ///////////// 
  /*
  int dig = 0;
  
  
  dig = digitalRead(Hall1);
  
  Serial.print("Digital Read:  ");
  Serial.println(dig);
  tube1.getSample(servoSpeed);
  //tube1.test(servoSpeed);
  //tube1.actForward(servoSpeed);
  //tube1.actBackward(servoSpeed);
  //tube1.stopServo();
  delay(3000);
  Serial.println("after test");
  tube1.stopServo();
  Serial.println("after stop");

  */ ////////////////
  
  
  /*

  if(Serial.available() > 0){

    char switcher = Serial.read(); //= switcher;

    switch (switcher){

      case '1':
        tube1.test(servoSpeed);
        break;

      case '2':
        tube2.test(servoSpeed);
        break;

      case '3':
        tube3.test(servoSpeed);
        break;
    }
}
}
    /*switch()
  }
  tube1.test(servoSpeed);
}
*/
}


void mainBodyActForward(int speed){
  //pinMode(sw_pin, INPUT_PULLUP);
  constServo.write(mainServoMid - speed);
  //while(digitalRead(sw_pin) != CHANGE){}
  //mainServo.write(mainServo_mid);

}
