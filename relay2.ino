const int stepPin = 15; 
const int dirPin = 14; 
const int enPin = 13;
const int in1=9;
const int in2=10;
const int in3=11;
const int in4=12;

const int stepPin0 = 5; 
const int dirPin0 = 2; 
const int enPin0 = 8;


void setup() {

   pinMode(stepPin0,OUTPUT); 
  pinMode(dirPin0,OUTPUT);
  pinMode(enPin0,OUTPUT);
  digitalWrite(dirPin0,LOW); //

  pinMode(stepPin,OUTPUT); 
  pinMode(dirPin,OUTPUT);
  pinMode(enPin,OUTPUT);
  pinMode(in1,OUTPUT); 
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
  digitalWrite(dirPin,LOW); //
  digitalWrite(in1,LOW); //
  digitalWrite(in2,LOW); //
  digitalWrite(in3,LOW); //
  digitalWrite(in4,LOW); //



  
  
  
}

void loop() {

  

 for(int x = 0; x < 3500; x++) {
    digitalWrite(stepPin,HIGH); 
     digitalWrite(stepPin0,HIGH); 
    delayMicroseconds(1500); 
    digitalWrite(stepPin,LOW); 
    digitalWrite(stepPin0,LOW); 
    delayMicroseconds(1500); 
  }


  
  //digitalWrite(enPin,HIGH);
  //delay(3000) ;//;
    digitalWrite(enPin,LOW);
      digitalWrite(enPin0,LOW);
      for(int x = 0; x < 3500; x++) {
    digitalWrite(stepPin,HIGH); 
     digitalWrite(stepPin0,HIGH); 
    delayMicroseconds(1500); 
    digitalWrite(stepPin,LOW); 
     digitalWrite(stepPin0,LOW); 
    delayMicroseconds(1500); 
  }
 
    
  

  

}