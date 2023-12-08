#include <Nextion.h>

#include <Servo.h>

bool pp=0;
bool vv=0;
bool ss=0;
bool cc=0;

Servo servo;
int angle = 10;

const int relayIN4Pin = 12;

const int stepPin3 = 22; 
const int dirPin3  = 23; 
const int enPin3   = 24;
const int in3      = 25;

const int stepPin4 = 26; 
const int dirPin4  = 27; 
const int enPin4   = 28;
const int in4      = 29;

const int stepPin2 = 30; 
const int dirPin2  = 31; 
const int enPin2   = 32;
const int in2      = 33;

const int stepPin1 = 34; 
const int dirPin1  = 8; 
const int enPin1   = 36;
const int in1      = 37;

void setup() {
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

//********************************************************************//
  digitalWrite(in1,LOW); 
  digitalWrite(in2,LOW); 
  digitalWrite(in3,LOW); 
  digitalWrite(in4,LOW);
  digitalWrite(in4,HIGH);

  digitalWrite(enPin1,HIGH); 
  digitalWrite(enPin2,HIGH); 
  digitalWrite(enPin3,HIGH); 
  digitalWrite(enPin4,HIGH);
  
  digitalWrite(dirPin1,LOW); 
  digitalWrite(dirPin2,LOW); 
  digitalWrite(dirPin3,LOW); 
  digitalWrite(dirPin4,LOW); 
}

void loop() {


  digitalWrite(enPin1,LOW); 
  digitalWrite(in1,HIGH); 
    digitalWrite(dirPin1,HIGH); 
   for(int x = 0; x < 3280; x++)
      {
       digitalWrite(stepPin1,HIGH); 
       delayMicroseconds(1500); 
       digitalWrite(stepPin1,LOW); 
       delayMicroseconds(1500); 
      }
      for(int x = 0; x < 3280; x++)
      {
       digitalWrite(stepPin1,HIGH); 
       delayMicroseconds(1500); 
       digitalWrite(stepPin1,LOW); 
       delayMicroseconds(1500); 
      }
  
}