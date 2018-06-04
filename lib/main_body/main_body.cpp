#include "main_body.h"


void main_body::setAct(int mid, int pin, int sw1, int sw2){
  servo_mid = mid;
  servo_pin = pin;
  sw1_pin = sw1;
  sw2_pin = sw2;
}

void main_body::setUp(){
  constServo.attach(servo_pin);
  pinMode(sw1_pin, OUTPUT);
  digitalWrite(sw1_pin, LOW);
  pinMode(sw2_pin, INPUT_PULLUP);

}


void main_body::stopServo(){
	constServo.detach();
}


void main_body::testAct(int speed){
	constServo.attach(servo_pin);
	while(digitalRead(sw2_pin))constServo.write(servo_mid - speed);
	constServo.detach();
	delay(1000);
	constServo.attach(servo_pin);
	constServo.write(servo_mid + speed);
	delay(10000);
	constServo.detach();

}

void main_body::actForward(int speed){
	constServo.attach(servo_pin);
	while(digitalRead(sw2_pin))constServo.write(servo_mid - speed);
	constServo.detach();

}

void main_body::actBackward(int speed){
	//constServo.attach(servo_pin);
	//while(digitalRead(sw_pin) == CHANGE)constServo.write(servo_mid + speed);
	//constServo.detach();

}

