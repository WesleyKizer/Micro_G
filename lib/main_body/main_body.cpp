#include "main_body.h"


void main_body::setAct(int mid, int pin, int sw){
  servo_mid = mid;
  servo_pin = pin;
  sw_pin = sw;
}

void main_body::setUp(){
  constServo.attach(servo_pin);
  pinMode(sw_pin, INPUT);

}


void main_body::stopServo(){
  constServo.write(servo_mid);
}


void main_body::testAct(int speed){
	constServo.write(servo_mid - speed);
	while(digitalRead(sw_pin) == CHANGE){}
	constServo.write(servo_mid + speed);
	while(digitalRead(sw_pin) == CHANGE){}
	constServo.write(servo_mid);

}

void main_body::actForward(int speed){
 
  constServo.write(servo_mid - speed);
  while(digitalRead(sw_pin) == CHANGE){}
  constServo.write(servo_mid);

}

void main_body::actBackward(int speed){
	constServo.write(servo_mid + speed);
	while(digitalRead(sw_pin) == CHANGE){}
	constServo.write(servo_mid);

}
