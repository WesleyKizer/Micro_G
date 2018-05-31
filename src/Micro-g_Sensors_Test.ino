#define THM1 A0
#define THM2 A1
#define THM3 A2

#define HES1 8
#define HES2 9
#define HES3 10
 
float Voltage, Rt, Temp;
float Vsupply = 5;

void setup() {
  pinMode(HES1,INPUT);
  pinMode(HES1,INPUT);
  pinMode(HES1,INPUT);

  Serial.begin(9600);
  
}

void loop() {
  //Serial.print(digitalRead(HES1)); Serial.print(" ");
  //Serial.print(digitalRead(HES2)); Serial.print(" ");
  //Serial.print(digitalRead(HES3)); Serial.print(" ");
    
  Voltage = (Vsupply / 1023.0) * (analogRead(THM1));
  Rt = (Vsupply - Voltage) * 68000 / Voltage;
  Temp = 1/(0.0008169 + 0.0001964*log(Rt)+0.0000001869*pow(log(Rt), 3))-273.15;\

  Serial.print(Temp); Serial.print(" ");

  Voltage = (Vsupply / 1023.0) * (analogRead(THM2));
  Rt = (Vsupply - Voltage) * 68000 / Voltage;
  Temp = 1/(0.0008169 + 0.0001964*log(Rt)+0.0000001869*pow(log(Rt), 3))-273.15;\

  Serial.print(Temp); Serial.print(" ");

  Voltage = (Vsupply / 1023.0) * (analogRead(THM3));
  Rt = (Vsupply - Voltage) * 68000 / Voltage;
  Temp = 1/(0.0008169 + 0.0001964*log(Rt)+0.0000001869*pow(log(Rt), 3))-273.15;\

  Serial.print(Temp); Serial.print(" ");

  Serial.println();
}
