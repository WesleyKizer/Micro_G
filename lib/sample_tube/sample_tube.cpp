#include "sample_tube.h"


float sample_tube::getTempReading(int pin){
  long int sum = 0;
  float voltage, rt, temp;

  for(int i=0; i<100; i++){
	
    sum += analogRead(pin);
  }
  voltage = (5/1023.0)*(sum/100.0);
  rt = (5 - voltage)* 67450/voltage;
  temp = 1/(0.0008169 + 0.0001964*log(rt)+0.00000001869*pow(log(rt), 3))-273.15;

  return temp;
}

void sample_tube::setSampleTube(int tempPin, int pin, int temp, int range, int test_Temp){
  temp_pin = tempPin; 
  heater_pin = pin;
  set_temp = temp;
  temp_range = range;
  set_test_temp = test_Temp;

}

void sample_tube::setAct(int mid, int pin, int sw){
  servo_mid = mid;
  servo_pin = pin;
  sw_pin = sw;
}

void sample_tube::setPWM(){
	char input = 'N';
	while(input != 'Y'){
		Serial.println("What % duty cycle?");
		duty = Serial.read();
		Serial.println("Is " duty "% correct(Y/N)");
		input = Serial.read();
		
	}
	
	
}

void sample_tube::setUp(){
  constServo.attach(servo_pin);
  pinMode(heater_pin, OUTPUT);
  digitalWrite(heater_pin, LOW);
  pinMode(sw_pin, INPUT);
  duty = 0.2;

}


void sample_tube::stopServo(){
  constServo.detach();
}

void sample_tube::stopHeater(){
  digitalWrite(heater_pin, LOW);
}

void sample_tube::testHeater(){
  float voltage, rt, temp, read;
  float readSum = 0;
  long int sum = 0;
  
  
  for(int i=0; i<250; i++){
	delay(25);
	read = analogRead(temp_pin);
	if((read < 10) || (read > 1010)){
		readSum++;
		
	}else{
		for(int i=0; i<100; i++){
			sum += analogRead(temp_pin);
		}
		voltage = (5/1023.0)*(sum/100.0);
		rt = (5 - voltage)* 67450/voltage;
		temp = 1/(0.0008169 + 0.0001964*log(rt)+0.00000001869*pow(log(rt), 3))-273.15;
		if(temp<=(set_temp-temp_range)) {digitalWrite(heater_pin, HIGH);}
		if(temp>=(set_temp+temp_range)) {digitalWrite(heater_pin, LOW);}
	}
  }	
  digitalWrite(heater_pin, LOW);
  if(readSum > 50){
	heaterOk = false;
  }else{
	heaterOk = true;
  }
}

void sample_tube::testAct(int speed){
	constServo.attach(servo_pin);
	while(!digitalRead(sw_pin))constServo.write(servo_mid - speed);
	while(digitalRead(sw_pin))constServo.write(servo_mid + speed);
	constServo.detach();

}

void sample_tube::actForward(int speed){
	constServo.attach(servo_pin);
	constServo.write(servo_mid + speed);
	//while(!digitalRead(sw_pin))constServo.write(servo_mid + speed);
	//constServo.detach();

}

void sample_tube::actBackward(int speed){
	constServo.attach(servo_pin);
	while(digitalRead(sw_pin))constServo.write(servo_mid - speed);
	constServo.detach();

}




void sample_tube::getSample(int speed){
    //start servo
	constServo.attach(servo_pin);
	constServo.write(servo_mid - speed);
	//start heater

	//float temp;
	digitalWrite(heater_pin, HIGH);
	while(!digitalRead(sw_pin)){
		
		digitalWrite(heater_pin, HIGH);
		delayMictosectonds(period*(duty/100));
		digitalWrite(heater_pin, LOW);
		delayMicrosectonds(period-(period*(duty/100));
		
		//if((micros()-startTime) >= 1000000){
			
			//digitalWrite(heater_pin, CHANGE);
			
			
			//startTime = micros();
		//}
		
		
		//Take temp reading
		//temp = getTempReading(temp_pin);
		//Serial.println(temp);

		//if(temp<=(set_temp-temp_range)) digitalWrite(heater_pin, HIGH);

		//if(temp>=(set_temp+temp_range)) digitalWrite(heater_pin, LOW);

	}
	constServo.detach();
	digitalWrite(heater_pin, LOW);
	delay(2000);
	constServo.attach(servo_pin);
	constServo.write(servo_mid + speed);
	delay(2000);
	while(digitalRead(sw_pin))constServo.write(servo_mid + speed);
	constServo.detach();


}
