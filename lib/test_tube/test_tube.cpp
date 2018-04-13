#include "test_tube.h"


void test_tube::setTempPins(int temp1, int temp2, int temp3){
  temp1_pin = temp1; //needs to be the sensor closed to the heater
  temp2_pin = temp2;
  temp3_pin = temp3;
}

void test_tube::setServo(int mid, int pin){
  servo_mid = mid;
  servo_pin = pin;

}

void test_tube::setSw(int close, int open){
  sw_close_pin = close;
  sw_open_pin = open;

}

void test_tube::setHeater(int pin, int temp, int range){
  heater_pin = pin;
  set_temp = temp;
  temp_range = range;


}

void test_tube::actForward(int speed){
  pinMode(sw_open_pin, INPUT_PULLUP);
  constServo.write(servo_mid + speed);

}

void test_tube::stopHeater(){
  digitalWrite(heater_pin, LOW);
}

void test_tube::testHeater(){
  float temp;
  while(1){
    //Take temp reading
    temp = getTempReading(temp1_pin);

    if(temp<=(set_temp-temp_range)) digitalWrite(heater_pin, HIGH);

    if(temp>=(set_temp+temp_range)) digitalWrite(heater_pin, LOW);

  }
}

void test_tube::getSample(int speed){
  pinMode(sw_open_pin, INPUT_PULLUP);
  attachInterrupt(sw_open_pin, tubeOpen, RISING);
  //start servo
  constServo.write(servo_mid + speed);
  //start heater

  float temp;
  while(1){
    //Take temp reading
    temp = getTempReading(temp1_pin);

    if(temp<=(set_temp-temp_range)) digitalWrite(heater_pin, HIGH);

    if(temp>=(set_temp+temp_range)) digitalWrite(heater_pin, LOW);

  }

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
  bool button1 = analogRead(sw_open_pin);
  bool button2 = analogRead(sw_close_pin);
  do{
    constServo.write(servo_mid + speed);
  }while(!button1);
    constServo.write(servo_mid);
    //delay(500);
  do{
    constServo.write(servo_mid - speed);
  }while(!button2);
  constServo.write(servo_mid);
  //delay(500);

}

void test_tube::tubeOpen(){
  //stop servo
  if(!set){setUp();}
  constServo.write(servo_mid);
  //stop heater
}

void test_tube::tubeClosed(){
  constServo.write(servo_mid);
}

void test_tube::setUp(){
  constServo.attach(servo_pin);
  set = true;
  pinMode(heater_pin, OUTPUT);
  digitalWrite(heater_pin, LOW);
  digitalPinToInterrupt(sw_open_pin);


}
