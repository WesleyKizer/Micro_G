#include "test_tube.h"


void test_tube::setTempPins(int temp1, int temp2){
  temp1_pin = temp1; //needs to be the sensor closed to the heater
  temp2_pin = temp2;
  //temp3_pin = temp3;
}

void test_tube::setServo(int mid, int pin){
  servo_mid = mid;
  servo_pin = pin;

}

void test_tube::setSw(int sw){
  sw_pin = sw;

}

void test_tube::setShaker(int shaker){
  shaker_pin = shaker;
}


void test_tube::setHeater(int pin, int temp, int range){
  heater_pin = pin;
  set_temp = temp;
  temp_range = range;


}

void test_tube::actForward(int speed){
  pinMode(sw_pin, INPUT_PULLUP);
  constServo.write(servo_mid + speed);

}

void test_tube::stopHeater(){
  digitalWrite(heater_pin, LOW);
}

void test_tube::testHeater(){
  float temp;
  float t=0;
  while(t<240){
    //Take temp reading
    delay(250);
    temp = getTempReading(temp1_pin);
    if(temp<=(set_temp-temp_range)) digitalWrite(heater_pin, HIGH);
    if(temp>=(set_temp+temp_range)) digitalWrite(heater_pin, LOW);
    t++;
  }
  stopHeater();
}

void test_tube::getSample(int speed){
    //start servo
  constServo.write(servo_mid + speed);
  //start heater

  float temp;
  while(sw_pin != CHANGE){
    //Take temp reading
    temp = getTempReading(temp1_pin);

    if(temp<=(set_temp-temp_range)) digitalWrite(heater_pin, HIGH);

    if(temp>=(set_temp+temp_range)) digitalWrite(heater_pin, LOW);

  }
  stopServo();
  analogWrite(shaker_pin, HIGH);
  delay(2000);
  analogWrite(shaker_pin, LOW);
  retract(speed);
  delay(2000);
  while(sw_pin != CHANGE){}
  stopServo();


}

void test_tube::stopServo(){
  constServo.write(servo_mid);
}

float test_tube::getTempReading(int pin){
  long int sum = 0;
  float voltage, rt, temp;

  for(int i=0; i<100; i++){
    sum += analogRead(pin);
  }
  voltage = (3.3/1023.0)*(sum/100.0);
  rt = (3.3 - voltage)* 67450/voltage;
  temp = 1/(0.0008169 + 0.0001964*log(rt)+0.00000001869*pow(log(rt), 3))-273.15;

  return temp;
}



void test_tube::retract(int speed){
  constServo.write(servo_mid - speed);
}

void test_tube::test(int speed){
  constServo.write(servo_mid + speed);
  while(sw_pin != CHANGE){}
  constServo.write(servo_mid - speed);
  delay(1000);
  while(sw_pin != CHANGE){}
  stopServo();

}
/*
void test_tube::tubeOpen(){
  //stop servo
  if(!set){setUp();}
  constServo.write(servo_mid);
  //stop heater
}

void test_tube::tubeClosed(){
  constServo.write(servo_mid);
}*/

void test_tube::setUp(){
  constServo.attach(servo_pin);
  //set = true;
  pinMode(heater_pin, OUTPUT);
  digitalWrite(heater_pin, LOW);
  pinMode(sw_pin, INPUT);
  //digitalPinToInterrupt(sw_open_pin);


}
