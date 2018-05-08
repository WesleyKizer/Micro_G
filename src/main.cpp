#include <Arduino.h>
#include <test_tube.h>
#include <Wire.h>

test_tube tube1;
test_tube tube2;
test_tube tube3;

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
const int Hall1 = 4;

void setup(){
  Serial.begin(9600);
  Serial.println("Setting Up.");
  Serial.println("");
  tube1.setServo(servoMid, servoPin);
  tube1.setSw(Hall1);
  pinMode(buttonPin, INPUT);

  //tube1.setHeater(heaterPin, setTemp, tempRange);
  //tube1.setTempPins(tempPin1, tempPin2, tempPin3);
  tube1.setUp();

  Serial.println("Set Up Complete.");
  Serial.println("");

}

void loop(){

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
