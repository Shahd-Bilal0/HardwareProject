#include <max6675.h>

#include "max6675.h"

int thermoDO = 4;
int thermoCS = 5;
int thermoCLK = 6;

MAX6675 thermocouple(thermoCLK, thermoCS, thermoDO);

const int stepPin4 = 26; 
const int dirPin4  = 27; 
const int enPin4   = 28;
const int in4      = 29;

const int stepPin3 = 26; 
const int dirPin3  = 27; 
const int enPin3   = 28;
const int in3      = 29;

const int stepPin2 = 30; 
const int dirPin2  = 31; 
const int enPin2   = 32;
const int in2      = 33;

const int stepPin1 = 34; 
const int dirPin1  = 35; 
const int enPin1   = 36;
const int in1      = 37;
int relayIN4Pin = 7;

void setup() {
  Serial.begin(9600);

  Serial.println("MAX6675 test");
  // wait for MAX chip to stabilize
  delay(500);
   pinMode(relayIN4Pin, OUTPUT);
  digitalWrite(relayIN4Pin, LOW);
  // put your setup code here, to run once:
  pinMode(stepPin4,OUTPUT); 
  pinMode(dirPin4,OUTPUT);
  pinMode(enPin4,OUTPUT);
  pinMode(in4,OUTPUT);

  pinMode(stepPin3,OUTPUT); 
  pinMode(dirPin3,OUTPUT);
  pinMode(enPin3,OUTPUT);
  pinMode(in3,OUTPUT);

  pinMode(stepPin2,OUTPUT); 
  pinMode(dirPin2,OUTPUT);
  pinMode(enPin2,OUTPUT);
  pinMode(in2,OUTPUT);
   
  pinMode(stepPin1,OUTPUT); 
  pinMode(dirPin1,OUTPUT);
  pinMode(enPin1,OUTPUT);
  pinMode(in1,OUTPUT);
  digitalWrite(in1,HIGH);
  digitalWrite(dirPin2,HIGH); 
  digitalWrite(enPin2,HIGH); 
  digitalWrite(enPin3,HIGH); 
  digitalWrite(enPin4,HIGH); 
  digitalWrite(enPin1,LOW); 
    

}

void loop() {

     digitalWrite(enPin4,LOW); 
     digitalWrite(in4,LOW); 
    for(int x = 0; x < 500; x++) {
    digitalWrite(stepPin4,HIGH); 
     //digitalWrite(stepPin2,HIGH); 
     //digitalWrite(stepPin3,HIGH); 
     //digitalWrite(stepPin4,HIGH); 
    delayMicroseconds(7000); 
    digitalWrite(stepPin4,LOW); 
   // digitalWrite(stepPin2,LOW); 
    //digitalWrite(stepPin3,LOW); 
    //digitalWrite(stepPin4,LOW); 
    delayMicroseconds(7000); 
   
  }
   Serial.print("C = "); 
  Serial.println(thermocouple.readCelsius());
if(thermocouple.readCelsius()>48.5)Serial.println("high");
  
 
  // For the MAX6675 to update, you must delay AT LEAST 250ms between reads!
  delay(1000);
  // put your main code here, to run repeatedly:

}
