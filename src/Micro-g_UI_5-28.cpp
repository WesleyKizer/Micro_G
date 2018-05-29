bool Success;
char reading;

bool SendChar(char,char,int,int);
char waitForUser();
bool waitForCompleteOrCancel(char);

void setup() {
  Serial.begin(9600);
  Serial1.begin(9600);
  //pinMode(18,OUTPUT);
  //pinMode(19,INPUT);
}

void loop() {
  Serial.println("\t\t\t\t   HOME:");
  Serial.println("\t\t\t\t-----------");
  Serial.println("Select Operation:");
  Serial.println("\ta) Extend main body to ice");
  Serial.println("\tb) Take sample");
  Serial.println("\tc) Retract main body");
  Serial.println("\td) Test sample tube actuation");
  Serial.println("\te) Test heating element");
  Serial.println("\tf) Emergency stop");
  Serial.println("(type letter and press enter)");
  reading = waitForUser();
  
  switch(reading) {
    case 'a':
    
      Serial.println("Selected 'a) Extend main body to ice'.");
      Serial.println("\ty) Proceed");
      Serial.println("\tn) Cancel");
      if(waitForUser()!='y') break;
      
      if(!SendChar('M','M',500,5)) {
        Serial1.print('S');
        Serial.println("\t\tCommunication failure! Returning HOME...\n\n");
        break;
      }

      Serial.println("\t\tExtending full body forward to surface of ice...");
      Serial.println("\t\tWaiting on Teensy 2.0 for confirmation of completion...");
      Serial.println("\t\t(hit 'S' at any time for emergency stop)");Serial.println();
      
      if(waitForCompleteOrCancel('M')) {
        Serial.print("\t\tExtension complete. Return HOME...\n\n");
      }
      
      break;
      
    case 'b':
    
      Serial.println("Selected 'b) Take sample'.");
      Serial.println("\ty) Proceed");
      Serial.println("\tn) Cancel");
      if(waitForUser()!='y') break;
      
      Serial.println("Select sample tube number:");
      Serial.println("\t1)\t2)\t3)");
      reading = waitForUser();

      switch(reading) {
        case '1':
        
          Serial.println("Selected sample tube #1:");
          Serial.println("\ty) Proceed");
          Serial.println("\tn) Cancel");
          if(waitForUser()!='y') break;

          if(!SendChar('T','T',500,5)) {
            Serial1.print('S');
            Serial.println("\t\tCommunication failure! Returning HOME...\n\n");
            break;
          }
          
          Serial.println("\t\tHeating Sample Tube #1 to 80 degrees C...");
          Serial.println("\t\tWaiting on Teensy 2.0 for confirmation of completion...");
          Serial.println("\t\t(hit 'S' at any time for emergency stop)");
          if(waitForCompleteOrCancel('T')) {
            Serial.print("\t\tHeating complete.\n");
          } else {
            break;
          }
          
          Serial.println("\t\tBoring into ice block with Sample Tube #1...");
          Serial.println("\t\tWaiting on Teensy 2.0 for confirmation of completion...");
          Serial.println("\t\t(hit 'S' at any time for emergency stop)");
          if(waitForCompleteOrCancel('T')) {
            Serial.print("\t\tBoring complete.\n");
          } else {
            break;
          }

          Serial.println("\t\tHeating Sample Tube #1 to 100 degrees C...");
          Serial.println("\t\tWaiting on Teensy 2.0 for confirmation of completion...");
          Serial.println("\t\t(hit 'S' at any time for emergency stop)");
          if(waitForCompleteOrCancel('T')) {
            Serial.print("\t\tHeating complete.\n");
          } else {
            break;
          }
          
          Serial.println("\t\tSevering core...");
          Serial.println("\t\tWaiting on Teensy 2.0 for confirmation of completion...");
          Serial.println("\t\t(hit 'S' at any time for emergency stop)");
          if(waitForCompleteOrCancel('T')) {
            Serial.print("\t\tSevering complete.\n");
          } else {
            break;
          }

          Serial.println("\t\tHeating element off. Retracting Sample Tube #1 from ice");
          Serial.println("\t\tWaiting on Teensy 2.0 for confirmation of completion...");
          Serial.println("\t\t(hit 'S' at any time for emergency stop)");
          if(waitForCompleteOrCancel('T')) {
            Serial.print("\t\tRetracting complete.\n");
          } else {
            break;
          }
          
          break;
          
        case '2':
        
          Serial.println("Selected sample tube #1:");
          Serial.println("\ty) Proceed");
          Serial.println("\tn) Cancel");
          if(waitForUser()!='y') break;

          if(!SendChar('T','T',500,5)) {
            Serial1.print('S');
            Serial.println("\t\tCommunication failure! Returning HOME...\n\n");
            break;
          }
          
          Serial.println("\t\tHeating Sample Tube #1 to 80 degrees C...");
          Serial.println("\t\tWaiting on Teensy 2.0 for confirmation of completion...");
          Serial.println("\t\t(hit 'S' at any time for emergency stop)");
          if(waitForCompleteOrCancel('T')) {
            Serial.print("\t\tHeating complete.\n");
          } else {
            break;
          }
          
          Serial.println("\t\tBoring into ice block with Sample Tube #1...");
          Serial.println("\t\tWaiting on Teensy 2.0 for confirmation of completion...");
          Serial.println("\t\t(hit 'S' at any time for emergency stop)");
          if(waitForCompleteOrCancel('T')) {
            Serial.print("\t\tBoring complete.\n");
          } else {
            break;
          }

          Serial.println("\t\tHeating Sample Tube #1 to 100 degrees C...");
          Serial.println("\t\tWaiting on Teensy 2.0 for confirmation of completion...");
          Serial.println("\t\t(hit 'S' at any time for emergency stop)");
          if(waitForCompleteOrCancel('T')) {
            Serial.print("\t\tHeating complete.\n");
          } else {
            break;
          }
          
          Serial.println("\t\tSevering core...");
          Serial.println("\t\tWaiting on Teensy 2.0 for confirmation of completion...");
          Serial.println("\t\t(hit 'S' at any time for emergency stop)");
          if(waitForCompleteOrCancel('T')) {
            Serial.print("\t\tSevering complete.\n");
          } else {
            break;
          }

          Serial.println("\t\tHeating element off. Retracting Sample Tube #1 from ice");
          Serial.println("\t\tWaiting on Teensy 2.0 for confirmation of completion...");
          Serial.println("\t\t(hit 'S' at any time for emergency stop)");
          if(waitForCompleteOrCancel('T')) {
            Serial.print("\t\tRetracting complete.\n");
          } else {
            break;
          }

          break;
          
        case '3':
        
          Serial.println("Selected sample tube #1:");
          Serial.println("\ty) Proceed");
          Serial.println("\tn) Cancel");
          if(waitForUser()!='y') break;

          if(!SendChar('T','T',500,5)) {
            Serial1.print('S');
            Serial.println("\t\tCommunication failure! Returning HOME...\n\n");
            break;
          }
          
          Serial.println("\t\tHeating Sample Tube #1 to 80 degrees C...");
          Serial.println("\t\tWaiting on Teensy 2.0 for confirmation of completion...");
          Serial.println("\t\t(hit 'S' at any time for emergency stop)");
          if(waitForCompleteOrCancel('T')) {
            Serial.print("\t\tHeating complete.\n");
          } else {
            break;
          }
          
          Serial.println("\t\tBoring into ice block with Sample Tube #1...");
          Serial.println("\t\tWaiting on Teensy 2.0 for confirmation of completion...");
          Serial.println("\t\t(hit 'S' at any time for emergency stop)");
          if(waitForCompleteOrCancel('T')) {
            Serial.print("\t\tBoring complete.\n");
          } else {
            break;
          }

          Serial.println("\t\tHeating Sample Tube #1 to 100 degrees C...");
          Serial.println("\t\tWaiting on Teensy 2.0 for confirmation of completion...");
          Serial.println("\t\t(hit 'S' at any time for emergency stop)");
          if(waitForCompleteOrCancel('T')) {
            Serial.print("\t\tHeating complete.\n");
          } else {
            break;
          }
          
          Serial.println("\t\tSevering core...");
          Serial.println("\t\tWaiting on Teensy 2.0 for confirmation of completion...");
          Serial.println("\t\t(hit 'S' at any time for emergency stop)");
          if(waitForCompleteOrCancel('T')) {
            Serial.print("\t\tSevering complete.\n");
          } else {
            break;
          }

          Serial.println("\t\tHeating element off. Retracting Sample Tube #1 from ice");
          Serial.println("\t\tWaiting on Teensy 2.0 for confirmation of completion...");
          Serial.println("\t\t(hit 'S' at any time for emergency stop)");
          if(waitForCompleteOrCancel('T')) {
            Serial.print("\t\tRetracting complete.\n");
          } else {
            break;
          }
          
          break;
          
        default:
          Serial.println("Invalid selection. Returning HOME."); Serial.println();
      }
      break;
    case 'c':
    
      Serial.println("Selected 'c) Retract sample tube from ice'.");
      Serial.println("\ty) Proceed");
      Serial.println("\tn) Cancel");
      if(waitForUser()!='y') break;
      
      Serial.println("Select sample tube number:");
      Serial.println("\t1)\t2)\t3)");
      reading = waitForUser();

      switch(reading) {
        case '1':
        
          Serial.println("Selected Sample Tube #1:");
          Serial.println("\ty) Proceed");
          Serial.println("\tn) Cancel");
          if(waitForUser()!='y') break;

          Serial.println("Retracting Sample Tube #1 from ice...");
          Serial.println("Waiting on Teensy 2.0 for confirmation of completion...");
          Serial.println("(hit 'S' at any time for emergency stop)");Serial.println();
          delay(2000);
          Serial.println("Retraction complete. Returning HOME"); Serial.println();
          break;
          
        case '2':
        
          Serial.println("Selected Sample Tube #2:");
          Serial.println("\ty) Proceed");
          Serial.println("\tn) Cancel");
          if(waitForUser()!='y') break;

          Serial.println("Retracting Sample Tube #2 from ice...");
          Serial.println("Waiting on Teensy 2.0 for confirmation of completion...");
          Serial.println("(hit 'S' at any time for emergency stop)");Serial.println();
          delay(2000);
          Serial.println("Retraction complete. Returning HOME"); Serial.println();
          break;
        case '3':
        
          Serial.println("Selected Sample Tube #3:");
          Serial.println("\ty) Proceed");
          Serial.println("\tn) Cancel");
          if(waitForUser()!='y') break;

          Serial.println("Retracting Sample Tube #3 from ice...");
          Serial.println("Waiting on Teensy 2.0 for confirmation of completion...");
          Serial.println("(hit 'S' at any time for emergency stop)");Serial.println();
          delay(2000);
          Serial.println("Retraction complete. Returning HOME"); Serial.println();
          break;

        default:
          Serial.println("Invalid selection. Returning HOME..."); Serial.println();
      }
      break;
      
    case 'd':
    
      Serial.println("Selected 'd) Retract main body'.");
      Serial.println("\ty) Proceed");
      Serial.println("\tn) Cancel");
      Serial.println("(type letter and press enter)");
      if(waitForUser()!='y') break;
      
      Serial.println("Retracting main body away from ice...");
      Serial.println("Waiting on Teensy 2.0 for confirmation of completion...");
      Serial.println("(hit 'S' at any time for emergency stop)");Serial.println();
      delay(2000);
      Serial.println("Retraction complete. Returning HOME"); Serial.println();
      break;
      
    case 'e':
    
      Serial.println("Selected 'e) Test heating element'.");
      Serial.println("\ty) Proceed");
      Serial.println("\tn) Cancel");
      if(waitForUser()!='y') break;
      
      Serial.println("Select sample tube number:");
      Serial.println("\t1)\t2)\t3)");
      reading = waitForUser();

      switch(reading) {
        case '1':
        
          Serial.println("Selected Sample Tube #1:");
          Serial.println("\ty) Proceed");
          Serial.println("\tn) Cancel");
          if(waitForUser()!='y') break;

          Serial.println("Heating Sample Tube #1's coil to 30 degrees C...");
          Serial.println("(hit 'S' at any time for emergency stop)");Serial.println();
          delay(2000);
          Serial.println("Cooling Sample Tube #1's coil to ambient temperature...");
          Serial.println("(hit 'S' at any time for emergency stop)");Serial.println();
          delay(2000);
          Serial.println("Testing complete. Returning HOME"); Serial.println();
          break;
          
        case '2':
        
          Serial.println("Selected Sample Tube #2:");
          Serial.println("\ty) Proceed");
          Serial.println("\tn) Cancel");
          if(waitForUser()!='y') break;

          Serial.println("Heating Sample Tube #2's coil to 30 degrees C...");
          Serial.println("(hit 'S' at any time for emergency stop)");Serial.println();
          delay(2000);
          Serial.println("Cooling Sample Tube #2's coil to ambient temperature...");
          Serial.println("(hit 'S' at any time for emergency stop)");Serial.println();
          delay(2000);
          Serial.println("Testing complete. Returning HOME"); Serial.println();
          break;
        case '3':
        
          Serial.println("Selected Sample Tube #3:");
          Serial.println("\ty) Proceed");
          Serial.println("\tn) Cancel");
          if(waitForUser()!='y') break;

         Serial.println("Heating Sample Tube #3's coil to 30 degrees C...");
          Serial.println("(hit 'S' at any time for emergency stop)");Serial.println();
          delay(2000);
          Serial.println("Cooling Sample Tube #3's coil to ambient temperature...");
          Serial.println("(hit 'S' at any time for emergency stop)");Serial.println();
          delay(2000);
          Serial.println("Testing complete. Returning HOME"); Serial.println();
          break;

        default:
          Serial.println("Invalid selection. Returning HOME."); Serial.println();
      }
      break;
      
    case 'f':
      Serial.println("EMERGENCY STOP ACTIVATED: Waiting for confirmation from Teensy...\n");
      if(!SendChar('S','S',500,5)) {
        Serial1.print('S');
        Serial.println("\t\tCommunication failure! Returning HOME...\n\n");
        break;
      }
      Serial.println("All systems deactivated. Returning HOME...\n");
      break;

    default:
      Serial.println("Invalid selection. Returning HOME."); Serial.println();
  }
  
  /*Serial.println("Attempting to establish communication HIGH...");
  if(SendChar('F','A',100,10)) Serial.println("Success!");
  else Serial.println("Failed!");
  Serial.println();
  delay(1000);*/
  
}

char waitForUser() {
  while(!Serial.available());
  char r = Serial.read();
  Serial.print("\t\t\t\t\t\t\t");
  Serial.println(r);
  Serial.println();
  return r;
}

bool SendChar(char t_char, char r_char, int t_out, int num_tries) {
  
  int counter = 0; //Keeps track of number of tries so far
  char reading;
  
  do {
    Serial1.print(t_char); //Send data
    Serial.print("\t\tCom Trial "); Serial.print(counter + 1); Serial.print(": ");
    long int startTime = millis();
    while((!Serial1.available())&&((millis()-startTime)<t_out)); //Wait til data is recieved or timeout
    
    if(Serial1.available()) {
      reading = Serial1.read();
      //Serial.println(reading);
      if(reading==r_char) {
        Serial.println("success!\n");
        return true; //Expected response, i.e transmitted successfully, so exit function
      }
      else {
        counter++;
        Serial.println("wrong response");
      }
    } else {
      Serial.println("timeout");
      counter++;
    }
  } while(counter<num_tries); //Exits after completing num_tries
  
  return false; //If completed num_tries, was unsuccessful
}

bool waitForCompleteOrCancel(char code) {
  while(1) {
    while((!Serial.available())&&!Serial1.available()); //Wait for data from one of the serials
    
    if(Serial1.available()) { //Message from Teensy...
      if(Serial1.read()==code) { //If Teensy sends correct completion code, return home
        return true;
      } else { //If Teensy sends incorrect completion code, there is an error!
        Serial.println("\t\tTeensy sent an incorrect code!");
        Serial.println("\t\tEMERGENCY STOP ACTIVATED: Waiting for confirmation from Teensy...");
        if(!SendChar('S','S',500,5)) { //Try to send emergency stop
          Serial.println("\t\tCommunication failure! Returning HOME...\n\n"); //Unsuccessful stop
          return false;
        } else {
          Serial.println("\t\tAll systems deactivated. Returning HOME...\n\n"); //Successful stop
          return false;
        }
      }
    }
    
    else if(Serial.available()) { //Message from user...
      if(Serial.read()=='S') { //User requests emergency stop...
        Serial.println("\t\tEMERGENCY STOP ACTIVATED: Waiting for confirmation from Teensy...");
        if(!SendChar('S','S',500,5)) {
          Serial.println("\t\tCommunication failure! Returning HOME...\n\n"); //Unsuccessful stop
          return false;
        } else {
          Serial.println("\t\tAll systems deactivated. Returning HOME...\n\n"); //Successful stop
          return false;
        }
        //If user sends a different code, while loop should repeat (i.e. nothing should happen
      }
    }
  }
}
